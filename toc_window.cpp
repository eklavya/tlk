#include "toc_window.h"
#include "pal.h"
#include "palwindow.h"

#ifdef c_plus_plus
extern "C" {
#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifdef c_plus_plus
}
#endif

TocWindow::TocWindow ( QWidget *parent ) : QDialog ( parent )
{
    menuBar       = new QMenuBar;
	topLayout     = new QHBoxLayout;
	mainLayout    = new QVBoxLayout;
	
	recThread     = new RecThread       ( this );
	nameEdit      = new QLineEdit       ( tr ( "Whats your name ?" ));
	refreshButton = new QPushButton     ( tr ( "&Refresh" ));
	fileMenu      = menuBar->addMenu    ( tr ( "&File" ));
	helpMenu      = menuBar->addMenu    ( tr ( "&Help" ));
	exitAction    = fileMenu->addAction ( tr ( "&Exit" ));
	aboutAction   = helpMenu->addAction ( tr ( "&About" ));
	
	topLayout->addWidget  ( nameEdit );
	topLayout->addWidget  ( refreshButton );
	mainLayout->addWidget ( menuBar );
	mainLayout->addLayout ( topLayout );
	this->setLayout       ( mainLayout );
	
	QObject::connect ( refreshButton, SIGNAL( clicked() ), this, SLOT( refreshList() ));
	QObject::connect ( exitAction, SIGNAL( triggered() ), qApp, SLOT ( quit() ));
	QObject::connect ( aboutAction, SIGNAL( triggered() ), this, SLOT ( aboutTriggered() ));
	
	this->show();
	
	//Broadcast our presence on LAN.
	sayHello ( htonl ( INADDR_BROADCAST ) , 1, FALSE);
	
	this->recThread->start();
}

//This function broadcasts our presence on LAN.
//First argument is network byte ordered IP Address to which we want to register our presence.
//In case of broadcasting we set it to INADDR_BROADCAST and set broadcast_enabled to 1
//force_reply forces receivers of our hello message to respond back with their name.
void TocWindow::sayHello ( in_addr_t sayto, int broadcast_enabled, bool force_reply )
{
    int                 sockfd;
	struct sockaddr_in  server;
	memset ( &server, 0, sizeof ( server ));
	
	if ( ( sockfd = socket ( PF_INET, SOCK_DGRAM, 0 )) < 0 ) {
		perror ( "Socket can't be created:" );
		return;
	}
	
	if ( broadcast_enabled ) {
	    if ( setsockopt ( sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast_enabled, sizeof ( int )) != 0 ) {
	        perror ( "Broadcasting failed." );
	        return;
	    }
	}
	
	server.sin_family      = PF_INET;
	server.sin_port        = htons(22127);
	server.sin_addr.s_addr = sayto;
	
	char *my_name = new char[200];
    memset ( my_name, 0, 200 );
    
    //set msg type to 1 to tell we are messaging our name
    my_name[0] = 0x01;
    //we are telling our name and we want receivers to respond back with theirs
    if ( force_reply ) my_name[0] = 0x03;
    //check if supplied name is within limits otherwise truncate it
    strncpy ( my_name+1, nameEdit->text().toAscii(), ( nameEdit->text().length() < 199 ? nameEdit->text().length() : 199 ));
    ::sendto(sockfd, my_name, 200, 0, (struct sockaddr*)&server, sizeof(server));
    delete my_name;
}

//This function spwans a new pal window for chatting or updates already opened window with incoming msg
//If we don't have info about the messager, we ask him and then update our list
void TocWindow::newMsgArrived(QString msg, quint32 from) 
{
        if ( msg[0] == 0x01 ) { 
            
            //Someone says hello, see if we know their name
            if ( !palList.contains(from) ) {
	            Pal *pal = new Pal ( this, msg.mid(1) );
	            this->mainLayout->addWidget(pal);
	            palList.insert(from, pal);
	            sayHello(from, 0, FALSE);
	        }
	        
	        //update name
	        else {
	            ((Pal*)palList.value(from))->setText(msg.mid(1));
	        }    
	    } 
	    
	    //new msg, see if we know from whom             
        if ( msg[0] == 0x02 ) {
            //we know them
            if ( palList.contains(from) ) {
                if(windowList.contains(from)) {
	                ((PalWindow*)windowList.value(from))->chatHistory->append(((Pal*)palList.value(from))->text() + " : " + msg.mid(1));
	            }
	    
	            else {
	                PalWindow *palWindow = new PalWindow(this, from);
	                windowList.insert(from, palWindow);
	                palWindow->chatHistory->append(((Pal*)palList.value(from))->text() + " : " + msg.mid(1));
	            }
	        }
	        
	        //we don't know them, ask their identity
	        else {
	            PalWindow *palWindow = new PalWindow(this, from);
	            windowList.insert(from, palWindow);
	            sayHello(from, 0, TRUE);
	            palWindow->chatHistory->append(((Pal*)palList.value(from))->text() + " : " + msg.mid(1));
	        }
	    }
	    
	    ////Someone says hello, and wants us to respond back
	    if ( msg[0] == 0x03 ) {
	        sayHello(from, 0, FALSE);
	    }
	                                   
	return;
}

void TocWindow::mousePressed(Pal *clickedPal)
{
    //check if there's already a window opened with this pal, if not spwan a new one
    if (!(this->windowList.contains(palList.key(clickedPal)))) {
    	PalWindow *newPalWindow = new PalWindow(this, palList.key(clickedPal));
	    this->windowList.insert(palList.key(clickedPal), newPalWindow);
	}
}

//update window list 
void TocWindow::palWindowClosed(QWidget *window)
{
    windowList.remove(windowList.key(window));
}

//delete pal list, tell everyone to send their names
void TocWindow::refreshList()
{
    QHashIterator<quint32, QWidget*> i(palList);
    
    //remove all pals from window, clear list
    while (i.hasNext()) {
        i.next();
        mainLayout->removeWidget(i.value());
        ((Pal*)i.value())->~Pal();
    }
    
    palList.clear();
    sayHello(htonl(INADDR_BROADCAST), 1, TRUE);
}

void TocWindow::aboutTriggered()
{
    AboutDialog  *aboutDialog = new AboutDialog(this);
}


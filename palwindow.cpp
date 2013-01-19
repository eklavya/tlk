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

PalWindow::PalWindow(QWidget *parent, in_addr_t ip) : QDialog(parent)
{
	sendButton   = new QPushButton(tr("&Send"));
	chatHistory  = new QTextEdit;
	msgOutbox    = new QLineEdit;
	lowerLayout  = new QHBoxLayout;
	mainLayout   = new QVBoxLayout;
	remote_ip    = ip;
	
	lowerLayout->addWidget(msgOutbox);
	lowerLayout->addWidget(sendButton);
	mainLayout->addWidget(chatHistory);
	mainLayout->addLayout(lowerLayout);
	this->setLayout(mainLayout);
	
    chatHistory->setReadOnly(1);
	
	QObject::connect(sendButton, SIGNAL(clicked()), this, SLOT(msgSent()));
	QObject::connect(msgOutbox, SIGNAL(returnPressed()), this, SLOT(msgSent()));
	QObject::connect(this, SIGNAL(windowClosed(QWidget*)), parent, SLOT(palWindowClosed(QWidget*)));
	
	this->show();
}

//sends message and updates local chat history
void PalWindow::msgSent()
{
	if (this->msgOutbox->text().isEmpty())
	    return;
	
	//update locally
	QString you("You : ");
	you += this->msgOutbox->text();
	this->chatHistory->append(you);
	
	//send message
	int                 cli_sock;
	char                msg[200];
	struct sockaddr_in  server;
	
	::memset ( &server, 0, sizeof(server) );
	
	server.sin_family      = PF_INET;
	server.sin_port        = htons(22127);
	server.sin_addr.s_addr = remote_ip;
	
	if ( cli_sock = socket(PF_INET, SOCK_DGRAM, 0) < 0 )
	    perror("Socket could not be created.");
	
	::memset(msg, 0, 200);
	msg[0] = 0x02;
    strncpy(msg+1, this->msgOutbox->text().toLocal8Bit(), this->msgOutbox->text().length());
	
	::sendto(cli_sock, &msg, 200, 0, (struct sockaddr*)&server, sizeof(server));
	::close(cli_sock);
	
	this->msgOutbox->clear();
	return;
}

void PalWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed(this);
    this->~PalWindow();
}

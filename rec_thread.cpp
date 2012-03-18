#include "rec_thread.h"

RecThread::RecThread ( QWidget *parent ) : QThread()
{
	this->myParent = parent;
	QObject::connect((QObject*)this, SIGNAL( newMsgArrived ( QString, quint32 )), (QObject*)myParent, SLOT ( newMsgArrived ( QString, quint32 )));
}

void RecThread::run()
{
	int                 serv_sock;
	struct sockaddr_in  server, client;
	
	memset ( &server, 0, sizeof(server));
	memset ( &client, 0, sizeof(client));
	
	if ( ( serv_sock = socket ( PF_INET, SOCK_DGRAM, 0 )) < 0 ) {
		perror ( "Socket can't be created:" );
	}
	
	server.sin_family       = PF_INET;
	server.sin_port         = htons(22127);
	server.sin_addr.s_addr  = 0;
	
	if ( ::bind ( serv_sock, (struct sockaddr *) &server, sizeof(server)) != 0 ) {
		perror("Socket could not be bound:");
	}

	for (;;) {
		int incoming;
		socklen_t client_size = sizeof(client);
		char msg[200];
		memset(msg, 0, 200);
		::recvfrom ( serv_sock, msg, 200, 0, (struct sockaddr*)&client, &client_size );
		QString msg_string(msg);
		emit newMsgArrived ( msg, client.sin_addr.s_addr );
		::close(incoming);
	}
	return;
}


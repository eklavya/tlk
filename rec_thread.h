#ifndef REC_THREAD_H
#define REC_THREAD_H

#ifdef c_plus_plus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#ifdef c_plus_plus
}
#endif

#include <QThread>

class RecThread : public QThread
{
	Q_OBJECT
	
public:
	QWidget    *myParent;
	RecThread ( QWidget* );
	void run();
	
signals:
    void newMsgArrived ( QString, quint32 );
};

#endif

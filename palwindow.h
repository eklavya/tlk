#ifndef PALWINDOW_H
#define PALWINDOW_H

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

#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

//Chat Window
class PalWindow : public QDialog
{
	Q_OBJECT
	
public:
	PalWindow ( QWidget *parent, in_addr_t remote_ip );

	in_addr_t      remote_ip;
	QPushButton    *sendButton;
	QTextEdit      *chatHistory;
	QLineEdit      *msgOutbox;
	QHBoxLayout    *lowerLayout;
	QVBoxLayout    *mainLayout;

    void closeEvent ( QCloseEvent *event );
	
signals:
    void windowClosed ( QWidget* );
    
private slots:
	void msgSent();
};

#endif

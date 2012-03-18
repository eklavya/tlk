#ifndef TOC_WINDOW_H
#define TOC_WINDOW_H

#ifdef c_plus_plus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#ifdef c_plus_plus
}
#endif

#include <QHash>
#include <QApplication>
#include <QtGui>
#include "rec_thread.h"
#include "pal.h"
#include "aboutdialog.h"

//main window
class TocWindow : public QDialog
{
	Q_OBJECT
	
public:
	TocWindow ( QWidget *parent = 0 );
	
public slots:
	void newMsgArrived   ( QString, quint32 );
	void mousePressed    ( Pal* );
	void palWindowClosed ( QWidget* );
	void refreshList();
	void aboutTriggered();
private:
    RecThread                 *recThread;
    QHash<quint32, QWidget*>  windowList;
    QHash<quint32, QWidget*>  palList;
    QMenuBar                  *menuBar;
    QMenu                     *fileMenu;
    QMenu                     *helpMenu;
    QAction                   *exitAction;
    QAction                   *aboutAction;
	QLineEdit                 *nameEdit;
	QPushButton               *refreshButton;
	QHBoxLayout               *topLayout;
	QVBoxLayout               *mainLayout;
	void sayHello ( in_addr_t, int, bool );
};

#endif

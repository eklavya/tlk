#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtGui>

class AboutDialog : public QDialog
{
    Q_OBJECT
    
public:
    AboutDialog ( QWidget *parent = 0 );
    QLabel      *aboutLabel;
    QVBoxLayout *mainLayout;
    void closeEvent ( QCloseEvent * e );
};

#endif

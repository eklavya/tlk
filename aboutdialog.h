#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

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

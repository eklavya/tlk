#include "aboutdialog.h"

AboutDialog::AboutDialog( QWidget *parent ) : QDialog ( parent )
{
    aboutLabel  = new QLabel ( "<p><b>tlk 0.1</b></p><p><b>The LAN Kommunicator.</b></p><p>TLK pronounced as \"talk\".  Happy chatting :)</p><p>This software is GPLv3 licensed.</p><p>For any queries, bugs, feature requests, please feel free to contact me-</p><p>I am Saurabh Rawat.</p><p>Email : sr.eklavya@gmail.com</p><p>Project URL : https://github.com/eklavya/tlk</p>");
    mainLayout  = new QVBoxLayout;
    mainLayout->addWidget(aboutLabel);
    this->setLayout(mainLayout);
    this->show();
}

void AboutDialog::closeEvent ( QCloseEvent * e )
{
    this->~AboutDialog();
}


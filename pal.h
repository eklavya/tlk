#ifndef PAL_H
#define PAL_H

#include <QtWidgets/QLabel>

class Pal : public QLabel
{
    Q_OBJECT
public:
    Pal(QWidget *parent, QString palName);
	void mousePressEvent(QMouseEvent * event);
signals:
    void mousePressed(Pal*);
};

#endif

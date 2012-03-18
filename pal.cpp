#include "pal.h"

Pal::Pal(QWidget *parent, QString palName) : QLabel(palName, parent)
{
    QObject::connect(this, SIGNAL(mousePressed(Pal*)), parent, SLOT(mousePressed(Pal*)));
}

void Pal::mousePressEvent(QMouseEvent * event)
{
    emit mousePressed(this);
}

#include <QtWidgets/QApplication>
#include "toc_window.h"

int main(int argc, char *argv[])
{
    QApplication  app ( argc, argv );
    TocWindow     mainWindow;
    return app.exec();
}

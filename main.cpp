#include <QApplication>
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MainWindow mainWnd;
    mainWnd.show();

    return app.exec();
}

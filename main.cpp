#include "mainwindow.h"
#include <QApplication>

// apk zaczyna tu działać
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // uruch gł pętlę apk
    return a.exec();
}

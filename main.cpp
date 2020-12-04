#include "Struct.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}

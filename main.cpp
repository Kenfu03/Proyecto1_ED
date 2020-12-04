#include "Struct.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
    /*
    Banda * banda = new Banda(3);
    banda->addBanda(100);
    banda->addBanda(200);
    banda->addBanda(300);
    if (!banda->addBanda(400)){
         qDebug() << "Excedio el maximo";
    }
    banda->estadisticas();
    int dato = banda->entregar();
    */

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
};

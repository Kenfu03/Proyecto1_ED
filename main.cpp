#include "Struct.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
    Banda * banda = new Banda(1000);
    banda->addBanda(100);
    banda->addBanda(200);
    banda->addBanda(300);
    banda->addBanda(400);
    banda->addBanda(600);
    banda->addBanda(1000);
    banda->estadisticas();
    //cout << "La banda entrego: " << banda->entregar()<<endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
};

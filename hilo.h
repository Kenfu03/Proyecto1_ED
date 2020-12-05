#ifndef HILO_H
#define HILO_H
#include <QtCore>
#include <QLabel>
#include <qstring.h>
#include <QPixmap>

class Hilo : public QThread{
public:
    bool running = true;
    int sleepTime = 1;
    int x = 4;
    int b = 0;
    Hilo(){ }

    void __init__(int tiempo){
        sleepTime = tiempo;
    }

    void run(){
        while(running){
            qDebug() << "Soy un Hilo y esto corriendo cada" << sleepTime<<"s";
            if(b==x){
                qDebug() << "Me detuve";
                stop();
            }else{
                qDebug() << "Ejecucion" << ++b;
            }
            sleep(sleepTime);
        }
    }
    void stop(){
        running = false;
    }

    void play(){
        running = true;
    }
};

#endif //HILO_H

#include "Struct.h"

bool Carrito::isEmpty(){
    if (cantCho == 0 || cantMasa == 0){
        return true;
    }
    else{
        return false;
    }
}

int Carrito::getCantCho(){
    return cantCho;
}

int Carrito::getCantMasa(){
    return cantMasa;
}


void Carrito::recargarMasa(int _Masa){
    cantMasa = _Masa;
    qDebug() << "Se devolvio masa al carrito:" << _Masa;
}

void Carrito::recargarCho(int _Cho){
    cantMasa = _Cho;
    qDebug() << "Se devolvio chocolate al carrito:" <<_Cho;
}

void Carrito::solicitarCarga(int _Mezc){
    if (!listaSolicitud->isIn(_Mezc)){
        listaSolicitud->push(_Mezc);
        qDebug() << "Se a;adio la mez: " << _Mezc;
        verificarCarga();
    }
}

void Carrito::verificarCarga(){
    if (listaSolicitud->isEmpty()){

    }
    else{
        if (listaSolicitud->vFirst()->data == 111){
            qDebug() << "Se relleno la mez: " << "111";
            Mezcladora1->recargar(cantMasa);
        }
        else if (listaSolicitud->vFirst()->data == 222){
            qDebug() << "Se relleno la mez: " << "222";
            Mezcladora2->recargar(cantMasa);
        }
        else{
            qDebug() << "Se relleno la mez: " << "333";
            MezcladoraCho->recargar(cantCho);
        }
    }
}

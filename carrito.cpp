#include "Struct.h"

bool Carrito::isEmpty(){
    if (cantCho == 0 || cantMasa == 0){
        return true;
    }
    else{
        return false;
    }
}

void Carrito::recargar(int _Cho, int _Masa){
    cantCho += _Cho;
    cantMasa += _Masa;
}

void Carrito::solicitarCarga(int _Mezc){
    if (!listaSolicitud->isIn(_Mezc)){
        listaSolicitud->push(_Mezc);
    }
}

void Carrito::verificarCarga(){
    if (listaSolicitud->isEmpty()){

    }
    else{
        if (listaSolicitud->vFirst()->dato == 111){

        }
    }
}

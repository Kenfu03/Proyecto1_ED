#include <cstdlib>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


using namespace std;

struct Paquetes;
template <typename Data>
struct NodoC;
template <typename Data>
struct Cola;
struct NodoLista;
struct ListaCircular;
struct Receta;
struct Galleta;
struct Repartidor;
struct Mez1;
struct Carrito;
struct Banda;
struct Mez1;
struct planificador;

template <typename Data>
struct NodoC{
    Data data;
    NodoC * next;

    NodoC(){          
	}
	
    NodoC(Data d){
        data = d;
        next = NULL;
                
	}

    NodoC(Data _data, NodoC<Data> * _next){
        data = _data;
        next = _next;
    }

	void print(){
        qDebug() <<  "Dato: " << data;
	}


};

template <typename Data>
struct Cola{
    NodoC<Data> * first;
    
    Cola(){
        first = NULL;
    }
    
    void push (Data dato){
        if (isEmpty()){
            first = new NodoC<Data>(dato);
        }
        else{
            NodoC<Data> * tmp = first;
            while (tmp->next != NULL){
                tmp = tmp->next;
            }
            NodoC<Data>* _new = new NodoC<Data>(dato);

            tmp->next = _new;
        }
    }

    NodoC<Data> * pull(){
        if (isEmpty()){
             return NULL;
        }
        else{

            NodoC<Data>* _del = first;
            first = first->next;
            _del->next = NULL;
            return _del;
        }
    }

    bool isEmpty(){
        if (first == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void print(){
        qDebug() <<  "First";
        NodoC<Data>* tmp = first;
        while (tmp != NULL){
            tmp->print();
            tmp = tmp->next;
        }
         qDebug() << "Final";
    }

    NodoC<Data>* vFirst(){
          return first;
    }
    
    bool isIn(int _dat){
        NodoC<Data>* tmp = first;

        while (tmp != NULL){
            if (tmp->data == _dat){
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }


    int tamano(){
        int tama = 0;
        NodoC<Data>* tmp = first;
        while (tmp != NULL){
            tama++;
            tmp = tmp->next;
        }
        return tama;
    }
};

struct Paquetes{
	string nombre;
	int cantGalle;

	Paquetes(string nombre, int cantGalle){
		this->nombre = nombre;
		this->cantGalle = cantGalle;
	}
	
	void impPaquete(){
		cout << "Tipo: " << nombre << " cantidad ->" << cantGalle;
	}
};

struct NodoLista{
	Paquetes * paquete;
	NodoLista * siguiente;
	NodoLista * anterior;
	
	NodoLista(Paquetes * tp)
	{
		paquete = tp;
		siguiente = anterior = NULL;
	}
	
	NodoLista()
	{
		paquete = NULL;
		siguiente = anterior = NULL;
	}
	
	void imprimir ()
	{
		paquete->impPaquete();
		cout << "\n";
	}
	
};

struct ListaCircular{
	NodoLista * primerNodo;
	ListaCircular(){ 
		primerNodo = NULL;
	}	
	// INSERTAR AL INICIO
	void insertarAUX(Paquetes * tipo)
	{
		if (primerNodo == NULL){
			primerNodo = new NodoLista(tipo);
			primerNodo->siguiente= primerNodo;
			primerNodo->anterior = primerNodo;
		}
		else{
			NodoLista * nuevo = new NodoLista (tipo);
			nuevo->siguiente = primerNodo;
			nuevo->anterior = primerNodo->anterior;
			primerNodo->anterior->siguiente = nuevo;
			primerNodo->anterior = nuevo;
		}
	}
	
	void insertar(string nombre, int cantidad){
		if(nombre == "Paquetico"){
			for(int i = 0;i<cantidad;i++){
                insertarAUX( new Paquetes(nombre,4) );
			}
		}
		if(nombre == "Tubo"){
			for(int i = 0;i<cantidad;i++){
				insertarAUX(new Paquetes(nombre,16));
			}
		}
		if(nombre == "Paquete"){
			for(int i = 0;i<cantidad;i++){
				insertarAUX(new Paquetes(nombre,40));
			}
		}		
	}
	
	int totalGalletas(){
		int total = 0 ;
		if (primerNodo != NULL){
			NodoLista * tmp = primerNodo;
			do{
				total += tmp->paquete->cantGalle;
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			cout << endl;
			}
		return total;
	}

	// IMPRIMIR LISTA
	void imprimir()
	{
		if (primerNodo != NULL){
			NodoLista * tmp = primerNodo;
			do{
				tmp->imprimir();
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			cout << endl;
		}
	}
	
	// IMPRIMIR LISTA
    NodoLista * buscar(string nombre)
	{
		if (primerNodo != NULL){
			
			NodoLista * tmp = primerNodo;
			do{
                if (tmp->paquete->nombre == nombre)
					return tmp;
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			
		}
		return NULL;
	}

    NodoLista * eliminar(string nombre){
        NodoLista * eliminado = buscar(nombre);
		
		if (eliminado != NULL){ // s� lo encontr�
			if (primerNodo->siguiente == primerNodo) // solo un elemento
				primerNodo = eliminado->siguiente = eliminado->anterior = NULL;
			else{
				if (eliminado == primerNodo)
					primerNodo = primerNodo->siguiente;
				
				NodoLista * tmp = eliminado->anterior;
				tmp->siguiente = tmp->siguiente->siguiente;
				tmp->siguiente->anterior = tmp;
				eliminado->siguiente = eliminado->anterior = NULL;
			} 
		}
		return eliminado;
	}
};

struct Receta{
	int masa;
	int choco;
	Receta(int masa, int choco){
		this->masa = masa;
		this->choco = choco;
	}
};

struct Banda{
    int tranporte;
    int carga;
    int limite;
    Cola<int> *  cbanda = new Cola<int>();

    Banda(int _limite){
        limite = _limite;
    }

    bool addBanda(int dato){//True si lo agrego Falso en otro caso
        if (cbanda->tamano() < limite){
            cbanda->push(dato);
            carga += dato;
            return true;
        }
        return false;
    }

    int entregar(){
       if(cbanda->vFirst() != NULL){
            return cbanda->pull()->data;
       }
       return 0;
    }
    void setLimite(int newlimite){
        limite = newlimite;
    }
    void estadisticas(){
        cout << "Maximo de galletas: " << limite << "Cantidad traspotada al momento: "<< cbanda->tamano() << endl;
    }
};

struct Carrito{
    int cantCho;
    int cantMasa;
    Cola<int> * listaSolicitud = new Cola<int>();
    Mez1 *Mezcladora1, *Mezcladora2, *MezcladoraCho;

    Carrito(){
    }

    Carrito(int _Cho, int _Masa, Mez1 *_Mez1, Mez1 *_Mez2, Mez1 *_MezCho ){
        this->cantCho = _Cho;
        this->cantMasa = _Masa;
        Mezcladora1 = _Mez1;
        Mezcladora1 = _Mez2;
        Mezcladora1 = _MezCho;

    }

    bool isEmpty();
    void recargar(int _Cho, int _Masa);
    void solicitarCarga(int _Mezc);
    void verificarCarga();//Esta parte ira en el hilo
    int getCantCho();
    int getCantMasa();

};

struct Mez1{
    int max;
    int cantAct = 0;
    int numMez;
    Carrito * Carro;
    Banda * banda;

    Mez1(){

    }

    Mez1(int max, Carrito * carro, int numMez){
        this->max = max;
        this->Carro = carro;
        this->numMez = numMez;
    }

    Mez1(int max, Carrito * carro, Banda * _banda, int numMez){
        this->max = max;
        this->Carro = carro;
        this->numMez = numMez;
        banda = _banda;
    }

    int recargar(int _masa){
        int cantSum = cantAct += _masa;

        if (cantSum > max && numMez == 333){
            int devolver = cantSum - max;
            cantAct = max;
            Carro->recargar(Carro->getCantMasa(), devolver);
            return devolver;
        }
        else{
            int devolver = cantSum - max;
            cantAct = max;
            Carro->recargar(devolver, Carro->getCantCho());
            return devolver;
        }
    }
    bool isInsuficiente(int _masaMin){
        if (cantAct < _masaMin){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        if (cantAct == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void mezclar(int _masa){
        if (isInsuficiente(_masa)){
            Carro->solicitarCarga(numMez);
        }else{
            if(!banda->addBanda(_masa)){
                qDebug() << "Pause";
            }
        }
    }
};

struct Ensambladora{
    Banda * bRecep;
    Banda * bEntrega;
    Ensambladora(Banda * _bRecep){
        bRecep = _bRecep;
    }
    void procesar(){
        qDebug() << "Procesando... " << bRecep->entregar();
    }
};

struct planificador{
	ListaCircular * lc;
    Receta * receta;
    Mez1 * Mezcladora1;
    Mez1 * Mezcladora2;
    Mez1 * MezcladoraCho;
    Ensambladora * ensam;
    Carrito * Carro;
    int capacMez1, capacMez2, capacMezCho, capacCarrito;
    int capacBandaMez,capacBandaCho,capacBandaHorno,capacBandaEmpaca;

    planificador(int tito, int te, int tubo, int capMez1, int capMez2, int capMezCho, int capCarrito){
		lc = new ListaCircular();
        lc->insertar("Paquetico",tito);
        lc->insertar("Paquete",te);
        lc->insertar("Tubo",tubo);
        capacMez1 = capMez1;
        capacMez2 = capMez2;
        capacMezCho = capMezCho;
        capacCarrito = capCarrito;
	}

    planificador(int tito, int te, int tubo, int capMez1, int capMez2, int capMezCho, int capCarrito, int capBandaMez,int capBandaHorno, int masa, int chocolate){
        lc = new ListaCircular();
        lc->insertar("Paquetico",tito);
        lc->insertar("Paquete",te);
        lc->insertar("Tubo",tubo);
        capacMez1 = capMez1;
        capacMez2 = capMez2;
        capacMezCho = capMezCho;
        capacCarrito = capCarrito;
        capacBandaMez = capBandaMez;
        capacBandaHorno = capBandaHorno;
        receta = new Receta(masa,chocolate);
    }

    void insertarMas(){
        //Aqui debe de tener algo en pantalla que me pida el tipo y la canitidad a sumar;
        lc->insertar("Paquete",4);
    }

    int totalGalle(){
        return lc->totalGalletas();
    }

    void crearProduccion(){
        Carro = new Carrito(capacCarrito, capacCarrito, Mezcladora1, Mezcladora2, MezcladoraCho);
        Banda * bandaMz = new Banda(capacBandaMez);
        Mezcladora1 = new Mez1(capacMez1, Carro,bandaMz, 111);
        Mezcladora2 = new Mez1(capacMez2, Carro,bandaMz, 222);
        MezcladoraCho = new Mez1(capacMezCho, Carro,new Banda(capacBandaCho), 333);
        ensam = new Ensambladora(bandaMz);
    }

    void empezarProduccion(){
        Mezcladora1->mezclar(receta->masa);
        ensam->procesar();
    }

};

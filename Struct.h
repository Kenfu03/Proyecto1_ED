#include <cstdlib>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

struct Paquetes;
struct NodoC;
struct NodoLista;
struct ListaCircular;
struct Cola;
struct ColaPrioridad;
struct Galleta;

struct NodoC{
	int dato; 
    NodoC* next;
    
    NodoC(){          
	}
	
    NodoC(int d){
		dato = d;
        next = NULL;
                
	}
	void print(){
		cout << "Dato: " << dato << endl;
	}
};
struct Cola{
    NodoC * first;
    
    Cola(){
        first = NULL;
    }
    
    void push (int dato);
    NodoC* pull();
    NodoC* vFirst();
    bool isEmpty(void);
    void print(void);
    bool isIn(int dato);
    
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
				insertarAUX( new Paquetes("Paquetico",4) );
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

struct planificador{
	ListaCircular * lc;

    planificador(int tito, int te, int tubo){
		lc = new ListaCircular();
        lc->insertar("Paquetico",tito);
        lc->insertar("Paquete",te);
        lc->insertar("Tubo",tubo);
	}

	void insertarMas(){
		//Aqui debe de tener algo en pantalla que me pida el tipo y la canitidad a sumar;
		lc->insertar("Paquete",4);
	}

    int totalGalle(){
        return lc->totalGalletas();
    }
};

//El carrito debe de ser configurable en sus cantidades y este debe de ser un hilo
struct Mez1{
	int max;
    int cantAct;

    Mez1(int max){
		this->max = max;
	}

    int recargar(int _masa, int _masaMin){
        int cantSum = cantAct += _masa;

        if (isEmpty() || isInsuficiente(_masaMin)){
            if (cantSum > max){
                int devolver = cantSum - max;
                cantAct = max;
                return devolver;
            }
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
};

struct MezChocolate{
	int min;
	int max;
	MezChocolate(int min, int max){
		this->min = min;
		this->max = max;
	}
};


struct Ensambladora{
	
};

struct Carrito{
    int cantCho;
    int cantMasa;
    Cola * listaSolicitud = new Cola();

    Carrito(){
    }

    Carrito(int _Cho, int _Masa){
        this->cantCho = _Cho;
        this->cantMasa = _Masa;
    }

    bool isEmpty();
    void recargar(int _Cho, int _Masa);
    void solicitarCarga(int _Mezc);
    void verificarCarga();

};

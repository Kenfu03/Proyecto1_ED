#include <cstdlib>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

struct Paquetes;
template <typename Data>
struct NodoC;
template <typename Data>
struct Cola;
struct NodoLista;
struct ListaCircular;
struct Galleta;
struct Repartidor;
struct Carrito;
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
        cout << "Dato: " << data << endl;
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
            NodoC<Data>* tmp = first;
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
            NodoC<Data> * _del = first;
            cout <<"Dato eliminado: " << _del->data;
            _del->next = NULL;
            first = first->next;
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
        cout << "First" << endl;
        NodoC<Data>* tmp = first;
        while (tmp != NULL){
            tmp->print();
            tmp = tmp->next;
        }
        cout << "Final" << endl;
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

    int galleEnbanda(){
        NodoC<Data> * tmp = first;
        int galletas = 0;
        while (tmp != NULL){
            galletas += tmp->data;
            tmp = tmp->next;
        }
        return galletas;
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

struct Mez1{
	int max;
    int cantAct;
    Carrito * carro;
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

struct Carrito{
    int cantCho;
    int cantMasa;
    Cola<int> * listaSolicitud = new Cola<int>();

    Carrito(){
    }

    Carrito(int _Cho, int _Masa){
        this->cantCho = _Cho;
        this->cantMasa = _Masa;
    }

    bool isEmpty();
    void recargar(int _Cho, int _Masa);
    void solicitarCarga(int _Mezc);
    void verificarCarga();//Esta parte ira en el hilo
};

struct Banda{
    int tranporte;
    int carga;
    int limite;
    Cola<int> *  banda = new Cola<int>();

    Banda(int _limite){
        limite = _limite;
    }

    void addBanda(int dato){
        if (carga < limite){
            banda->push(dato);
            carga += dato;
        }
    }
    int entregar(){
       if(banda->pull() != NULL){
            int descarga = banda->pull()->data;
            carga -= descarga;
            return descarga;
       }
       return 0;
    }


    void estadisticas(){
        banda->print();
        //cout << "Maximo de galletas: " << limite << "Cantidad traspotada al momento: "<< banda->galleEnbanda() << endl;
    }

    void setLimite(int newLimite){
        limite = newLimite;
    }

};

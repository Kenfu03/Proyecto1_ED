#include <cstdlib>
#include <iostream>

using namespace std;

struct NodoC;
struct NodoLista;
struct ListaCircular;
struct Cola;
struct ColaPrioridad;
struct Galletas;
struct Paqueticos;
struct Tubos;
struct Paquete;
struct planificador;
// estructura nodo para lista simple

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
    
};


struct NodoLista{
	int dato;
	NodoLista * siguiente;
	NodoLista * anterior;
	
	NodoLista(int d)
	{
		dato = d;
		siguiente = anterior = NULL;
	}
	
	NodoLista()
	{
		dato = 0;
		siguiente = anterior = NULL;
	}
	
	void imprimir ()
	{
		cout << "<-|" << dato << "|-> ";
	}
};

struct ListaCircular{
	NodoLista * primerNodo;

	ListaCircular(){ 
		primerNodo = NULL;
	}	
	
	// INSERTAR AL INICIO
	void insertar(int d)
	{
		if (primerNodo == NULL){
			primerNodo = new NodoLista(d);
			primerNodo->siguiente= primerNodo;
			primerNodo->anterior = primerNodo;
		}
		else{
			NodoLista * nuevo = new NodoLista (d);
			nuevo->siguiente = primerNodo;
			nuevo->anterior = primerNodo->anterior;
			primerNodo->anterior->siguiente = nuevo;
			primerNodo->anterior = nuevo;
		}
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
	NodoLista * buscar(int _dato)
	{
		if (primerNodo != NULL){
			
			NodoLista * tmp = primerNodo;
			do{
				if (tmp->dato == _dato)
					return tmp;
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			
		}
		return NULL;
	}
	
	NodoLista * eliminar(int _dato){
		NodoLista * eliminado = buscar(_dato);
		
		if (eliminado != NULL){ // sí lo encontró
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

/*struct ColaPrioridad {
       // solo con pN es suficiente
       Cola * colaRegular;
       Cola * colaEspecial;
       
       ColaPrioridad()
       {
            colaRegular = new Cola();
            colaEspecial = new Cola();
       }
       
       // encabezados de funcion
       void encolar (Persona * p){
       		if (p->priority == 1)
       			colaRegular->encolarPersona(p);
       		else
       			colaEspecial->encolarPersona(p);
	   }
       Nodo* desencolar (){
       		if (!colaEspecial->vacia())
       			return colaEspecial->desencolar();
       		else
       			return colaRegular->desencolar();
	   }
	   
	   void imprimir(){
	   	cout <<"Cola prioridad: " << endl;
	   	colaEspecial->imprimir();
	   	cout << endl << endl << "Cola: ";
	   	colaRegular->imprimir();
	   }
};*/

struct Galleta{
	int masa;
	int choco;
	galleta(int masa, int choco){
		this.masa = masa;
		this.choco = choco
	}
};


struct Paqueticos{
	Galletas unidad;
	
};
struct Tubos{
	Galletas unidad;
};

struct Paquete{
	Galletas unidad;
};

struct planificador{
	//Define la cantidad de paquetes que se van a crear
	Paquete pk;
	Paqueticos litpk;
	Tubos tb;
	planificador(Paquete pk,Paqueticos litpk,Tubos tb){
		this.pk = pk;
		this.litpk = litpk;
		this.tb = tb;
	}
	
};


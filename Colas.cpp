
#include "Struct.h"

void Cola::push (int dato){
	
	if (isEmpty()){
		first = new NodoC(dato);
	}
    else{
     		
        NodoC* tmp = first;
        while (tmp->next != NULL){
			tmp = tmp->next; 
		}
		
        NodoC* _new = new NodoC(dato);
        tmp->next = _new;
            
    }
}

NodoC* Cola::pull(){
	
    if (isEmpty()){
         return NULL;
    }
    
    else{
    	
      	NodoC* _del = first;     
      	first = first->next;
      	_del->next = NULL;
      	return _del;
    }
}

bool Cola::isEmpty(){
	
    if (first == NULL){
    	return true;
	} 
	
    else{
    	return false;
	} 
}

void Cola::print(){
	
    cout << "First" << endl;
    NodoC* tmp = first;
    
    while (tmp != NULL){
     	
        tmp->print();
        tmp = tmp->next;
    }
    
    cout << "Final" << endl;
}

bool Cola::isIn(int dato){
    NodoC* tmp = first;

    while (tmp != NULL){

        if (tmp->dato == dato){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

NodoC* Cola::vFirst(){
	
      return first;      
}


/*
	Name: Agenda con listas y nodo de encabezamiento
	Copyright: POLI JIC
	Author: Algoritmos y Programacion2 - DAVID LONDOÑO, SANTIAGO OLEMDO, TOMAS PINEDA, CARLOS GONZALEZ
	Date: 09/11/20 
	Description: 
	- Punto 3 del taller #2 Colaborativo 
*/
/******************************
***   OPERACONES CON LISTAS LINEALES DOBLES con nodo de encabezamiento 
*****************************************/

#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo
{
       string info; 
	   struct nodo *ante;       // en este caso es un string de caracteres
       struct nodo *sgte;
}*primero, *ultimo;


nodo * crearLista()
{
	struct nodo *cabeza;
    cabeza = new(struct nodo);
    cabeza->sgte=NULL;
    cabeza->ante=NULL;
    cabeza->info="\t\nSoy el Nodo cabecera";
    return cabeza;
	
}


 void insertarInicio(struct nodo *cabeza, string valor)
{
    struct nodo *nuevo,*p;
    
		
	
	nuevo = new(struct nodo);
	nuevo->info = valor;
	nuevo->sgte = cabeza->sgte;
	nuevo->ante=cabeza;
	
	
	p=cabeza->sgte;
	cabeza->sgte=nuevo;
    
	if(p!=NULL) {
    	p->ante=nuevo;
		
	}
         
}
 
 
void insertarFinal(nodo *cabeza, string valor)
{
	nodo *t, *q;
    cout<< "\t\nEntrada a insertar "<<valor;
	
	q = new(struct nodo);
    q->info  = valor;
    q->sgte = NULL;
    q->ante = NULL;
    
        t = cabeza;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
        q->ante=t;
    }
  


void mostrarListaD(struct nodo *cabeza)
{
    int i = 0;
     
 	struct nodo *p;
 	p=cabeza->sgte;
 	cout<<"\t\nEntrada lista "<<endl;
     while(p != NULL)
	 {
		  cout <<' '<< i+1 <<") "<< p->info <<endl;
          p = p->sgte;
          i++;
     }
}

int contarNodosRepetidos(struct nodo * cabeza, string valor){
	
	nodo * p;
	int Cont;
	p = cabeza->sgte;
	Cont = 0;
	while (p != NULL){
		if(p->info == valor){
			Cont++;
		}
		p = p->sgte;
	}
	cout<<"\t\n Total de nodos: "<<Cont<<endl;
	
	return Cont;
}


void eliminarNodo(struct nodo* cabeza, string NomEstudiante)
{
	struct nodo *actual, *anterior;
	actual = cabeza->sgte;
	anterior = NULL;
	int Cont, i;
	bool encnt = false;
	

	Cont = contarNodosRepetidos(cabeza, NomEstudiante);
	
	cout<<"\n Veces eliminado el nombre de "<<NomEstudiante<<": "<<Cont<<endl;
	
	cout<<"si";
	//for(int i=0 ; i < Cont ; i++){
		while(actual != cabeza  && encnt!=false)
		{
			if(actual->info ==  NomEstudiante){
				if (cabeza->sgte == actual ){
					anterior = actual->sgte;
					cabeza->sgte = anterior;
					delete (actual);
					cout<< "\n\tNodo eliminado con exito\n\n";
					encnt = true;
				}
				else{
					anterior->sgte = actual->sgte;
					delete (actual);
					cout<< "\n\tNodo eliminado con exito\n\n";
					encnt = true;
				}
			}
			anterior = actual;
			actual = actual -> sgte; 
		}
		if(!encnt){
			cout<<"\n\tNodo no encontrado.";
		}
		
	//}
}

/*void eliminarNodo(struct nodo * cabeza, string valor)
{
	nodo *primero, *actual, *anterior;
	actual = primero;
	short i;
	short Cont;
	bool encnt = false;
	primero = cabeza->sgte;
	Cont = contarNodosRepetidos(cabeza, valor);
	for(i = 0; i < Cont ; i++){
		if(cabeza->sgte != NULL)
		{
			while(actual != NULL && encnt!=true)
			{
				
				if(actual->info == valor){
				cout<<"\n Nodo con el dato " <<valor<<" encontrado.\n\n"<<endl;
			
				if (actual == primero){
					delete (primero);
					primero = primero->sgte;
				}else if(actual == ultimo){
					delete (ultimo);
					anterior->sgte = NULL;
					ultimo = anterior;
				}else{
					delete (anterior);
					anterior->sgte = actual->sgte;
					actual->sgte->ante = anterior;
				}
			
				cout<< "\n Nodo eliminado con exito\n\n";
			
				encnt = true;
				}
				anterior = actual;
				actual = actual -> sgte; 
			}
			if(!encnt){
				cout<<"\nNodo no encontrado.";
			}
		}
		else
		{
			cout<<"\n La lista se encuentra vacia\n\n";
		}
	}	
	if(Cont == 0){
		cout<<" Lista vacia..!";
	}
}
*/



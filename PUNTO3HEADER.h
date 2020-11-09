#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo
{
       string info; 
	   struct nodo *ante;       
       struct nodo *sgte;
}*primero, *ultimo;


nodo * crearLista()
{
	struct nodo *cabeza;
    cabeza = new(struct nodo);
    cabeza->sgte=NULL;
    cabeza->ante=NULL;
    cabeza->info="Soy el Nodo cabecera";
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
    cout<< "Entrada a insertar "<<valor;
	
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
 	cout<<" entrada lista "<<endl;
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
	cout<<"\n Total de nodos: "<<Cont<<endl;
	
	return Cont;
}



void eliminarNodo(struct nodo * cabeza, string valor)
{
	nodo *p, *q, *ant;
	int Cont=0, l;
	
	p= cabeza->sgte;
	ant= cabeza;
	
	
	while (p != NULL){
		if(p->info == valor){
			Cont++;
		}
		p = p->sgte;
	}
	
	cout<<"\n Total de datos repetidos: "<<Cont<<endl;
	
	for(int i=0 ; i < Cont ; i++){
		if (cabeza->sgte != NULL){
			while (p != NULL){
				if (p->info == valor){
					ant->sgte= p->sgte;
					q=p->sgte;
					q->ante= p->ante;
					delete (p);
					
					l= 0;
					break;
				}
				else{
					ant= p;
					p= p->sgte;
				}
			}
		}
		else{
			cout << "La lista esta vacia: " << endl;
			l= 1; 
		}
	}
	
	if (l==0){
		cout << "Elementos eliminados...";
	}
	if (l==1){
		cout << "Elementos no encontrados...";
	}
}




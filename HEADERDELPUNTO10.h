/*
	Name: Agenda con listas y nodo de encabezamiento
	Copyright: POLI JIC 2020-02 & Archivos Maryem Clase Practica Alg. y programación #2.
	Author: Algoritmos y Programacion2 - DAVID LONDOÑO, SANTIAGO OLEMDO, TOMAS PINEDA, CARLOS GONZALEZ
	Date: 09/11/20 
	Description: 
	- Desarrollo del Punto 10 del taller #2 Colaborativo 
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

struct informacion{
	string Nombre;
	unsigned long int Numero;
	string TipodeCont;
};

struct nodo{
	struct informacion info;
	struct nodo *sgte;
	struct nodo *ante;
} *primero, *ultimo;

struct nodo * crearLista()
{
	struct nodo * cabeza;
	cabeza= new(struct nodo);
	cabeza->sgte=cabeza;
	cabeza->ante=cabeza;
	cabeza->info.Nombre=" ";
	return cabeza;
}

void insertarInicio(struct nodo *cabeza, struct informacion valores)
{
	struct nodo *nuevo,*p;
	p=cabeza->sgte;
	nuevo = new(struct nodo);
	nuevo->info = valores;
	nuevo->ante = p;
	nuevo->sgte = p->sgte;
	p->sgte=nuevo;


}

int contarNodos(struct nodo* cabeza)
{
	struct informacion dato;
	int Cont;
	Cont = 0;
	ifstream archivo;
	archivo.open("Lista.txt");
	if (archivo.is_open()){
		while(!archivo.eof()){
			archivo>>dato.Nombre>>dato.TipodeCont>>dato.Numero;
			Cont++;
		}
		archivo.close();
	}
	return Cont;
}

void insertardesdeArchivo(struct nodo* cabeza, int Cont1)
{
	struct informacion dato;
	int i;
	ifstream archivo;
	archivo.open("Lista.txt");
	if (archivo.is_open()){
		for(i = 0 ; i < Cont1 ; i++){
			archivo>>dato.Nombre>>dato.TipodeCont>>dato.Numero;
			insertarInicio(cabeza,dato);
		}
		archivo.close();
	}
	else{
		cout<<"\tArchivo no encontrado"<<endl;
	}

}

void GuardarArchivo(struct nodo* cabeza)
{
	struct nodo *p;
	p=cabeza->sgte;
	struct informacion dato;
	ofstream archivo;
	archivo.open("Lista.txt");
	if (archivo.is_open()){
		while (p != cabeza){
			archivo<<p->info.Nombre<<" "<<p->info.TipodeCont<<" "<<p->info.Numero<<endl;
			p=p->sgte;
		}
		archivo.close();
		cout<<"\t\t\nArchivo guardado con exito"<<endl;
	}
	else{
		cout<<"\t\nArchivo no encontrado"<<endl;
	}
	system("pause");
	system("cls");
}

void mostrarLista(struct nodo* cabeza, int Cont1)
{
	struct nodo *p;
	int i;
	p=cabeza->sgte;

	if (p==cabeza){
		cout<<"\tLista vacia"<<endl;
	}
	for(i = 0; i < Cont1 ; i++)
	{
		cout<<"\n\t\t\t"<<p->info.Nombre<<"\t\t\t"<<p->info.TipodeCont<<"\t\t\t"<<p->info.Numero<<"\t\t\t"<<"\n\n";
		p=p->sgte;
	}

}

void BuscarLista(struct nodo* cabeza)
{
	struct nodo *p;
	unsigned long int Num,i=0;
	cout<<"\tDigite el numero telefonico que desea buscar: ";
	cin>>Num;
	p=cabeza->sgte;
	do
	{
		if (Num==p->info.Numero){
			cout<<p->info.Nombre<<"\t"<<p->info.TipodeCont<<"\t"<<p->info.Numero<<"\t"<<"\n";
			i=1;
			break;
		}
		p=p->sgte;
	}while (p!=cabeza);
	if (i==0)
	{
		cout<<"\t\t\nNo existe el numero telefonico\n"<<endl;
	}
	system("Pause");
}

int eliminarNodo(struct nodo* cabeza, unsigned long int NumAeliminar)
{
	struct nodo *actual, *anterior;
	int Cont5;
	actual = cabeza->sgte;
	anterior = NULL;
	Cont5 = 0;
	bool encnt = false;
		while(actual != cabeza  && encnt!=true)
		{
			if(actual->info.Numero ==  NumAeliminar){
			cout<<"\n\tContacto con el numero " <<actual->info.Numero<<" encontrado.\n\n"<<endl;
			anterior->sgte = actual->sgte;
			delete (actual);
			cout<< "\n\tNumero telefonico eliminado con exito\n\n"<<endl;
			encnt = true;
			}
			anterior = actual;
			actual = actual -> sgte; 
		}
		if(!encnt){
			cout<<"\n\tNumero telefonico no encontrado."<<endl;
		}
	Cont5++;
	system("pause");
	return Cont5;
}

void OrganizarTipoC(struct nodo* cabeza, int Cont4)
{
    nodo *actual, *siguiente , * aux;
    string NombreAux;
	unsigned long int NumeroAux;
	string TipodeContAux;
	Cont4++;
    if(cabeza != NULL)
    {
        actual = cabeza->sgte;
        do
        {
            siguiente = actual->sgte;
            while(siguiente != cabeza)
            {
            	if(actual->info.TipodeCont != "Amigos" & siguiente->info.TipodeCont == "Amigos")
                {
                    NombreAux = actual->info.Nombre;
					NumeroAux = actual->info.Numero;  
                    TipodeContAux = actual->info.TipodeCont;                  
                    actual->info.Nombre = siguiente->info.Nombre;	
                    actual->info.Numero = siguiente->info.Numero;
                    actual->info.TipodeCont = siguiente->info.TipodeCont;
                    siguiente->info.Nombre = NombreAux;
                    siguiente->info.Numero = NumeroAux;
                    siguiente->info.TipodeCont = TipodeContAux;
                }
                if(actual->info.TipodeCont != "Familia" & siguiente->info.TipodeCont == "Familia")
                {
                    NombreAux = actual->info.Nombre;
					NumeroAux = actual->info.Numero;  
                    TipodeContAux = actual->info.TipodeCont;                  
                    actual->info.Nombre = siguiente->info.Nombre;	
                    actual->info.Numero = siguiente->info.Numero;
                    actual->info.TipodeCont = siguiente->info.TipodeCont;
                    siguiente->info.Nombre = NombreAux;
                    siguiente->info.Numero = NumeroAux;
                    siguiente->info.TipodeCont = TipodeContAux;
                }
                if(actual->info.TipodeCont != "Estudio" & siguiente->info.TipodeCont == "Estudio")
                {
                    NombreAux = actual->info.Nombre;
					NumeroAux = actual->info.Numero;  
                    TipodeContAux = actual->info.TipodeCont;                  
                    actual->info.Nombre = siguiente->info.Nombre;	
                    actual->info.Numero = siguiente->info.Numero;
                    actual->info.TipodeCont = siguiente->info.TipodeCont;
                    siguiente->info.Nombre = NombreAux;
                    siguiente->info.Numero = NumeroAux;
                    siguiente->info.TipodeCont = TipodeContAux;
                } 
                if(actual->info.TipodeCont != "Trabajo" & siguiente->info.TipodeCont == "Trabajo")
                {
                    NombreAux = actual->info.Nombre;
					NumeroAux = actual->info.Numero;  
                    TipodeContAux = actual->info.TipodeCont;                  
                    actual->info.Nombre = siguiente->info.Nombre;	
                    actual->info.Numero = siguiente->info.Numero;
                    actual->info.TipodeCont = siguiente->info.TipodeCont;
                    siguiente->info.Nombre = NombreAux;
                    siguiente->info.Numero = NumeroAux;
                    siguiente->info.TipodeCont = TipodeContAux;
                }   
                siguiente = siguiente->sgte;
            }
            
            actual = actual->sgte;
            siguiente = actual->sgte;
        }
        while(siguiente != cabeza);
    }
    if(Cont4 > 1){
   		cout<<"\n\tLista organizada "<<endl;		
   	}
  
}

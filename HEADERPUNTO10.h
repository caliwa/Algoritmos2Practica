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
	cabeza->info.Nombre="El nodo cabecera ";
	return cabeza;
}

void insertarInicio(struct nodo *cabeza, struct informacion valores)
{
	struct nodo * nuevo, *p;
	p=cabeza;
	nuevo = new(struct nodo);
	nuevo->info = valores;
	nuevo->ante = p;
	nuevo->sgte = p->sgte;
	p->sgte=nuevo;
}

void insertardesdeArchivo(struct nodo* cabeza)
{
	struct informacion dato;
	ifstream archivo;
	archivo.open("Lista.txt");
	if (archivo.is_open()){
		while(!archivo.eof()){
			archivo>>dato.Nombre>>dato.TipodeCont>>dato.Numero;
			insertarInicio(cabeza,dato);
		}
		archivo.close();
	}
	else {
		cout<<"\tArchivo no encontrado";
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
		while (p != cabeza ) {
			archivo<<p->info.Nombre<<" "<<p->info.Numero<<" "<<p->info.TipodeCont<<endl;
			p=p->sgte;
		}
		archivo.close();
		cout<<"\tArchivo guardado con exito";
	}
	else{
		cout<<"\tArchivo no encontrado";
	}
}

void mostrarLista(struct nodo* cabeza)
{
	struct nodo *p;
	p=cabeza->sgte;
	char Contacto;  
	cout<<"\tQue filtro de contacto desea ver? Ponga (T = Trabajo / E =Estudio / F = Familia / A = Amigos / L = Lista Completa)"<<endl;
	cin>>Contacto;
	if (p==cabeza){
		cout<<"\tLista vacia";
	}
	if(Contacto == 'L')
	{
		while (p != cabeza)
		{
			cout<<"\n\t\t\t"<<p->info.Nombre<<"\t\t\t"<<p->info.TipodeCont<<"\t\t\t"<<p->info.Numero<<"\t\t\t"<<"\n\n";
			p=p->sgte;
		}
	}
	if(Contacto == 'T'){
		while (p != cabeza)
		{
			if(p->info.TipodeCont == "Trabajo"){
				cout<<"\n\t\t\t"<<p->info.Nombre<<"\t\t\t"<<p->info.TipodeCont<<"\t\t\t"<<p->info.Numero<<"\t\t\t"<<"\n\n";
				p=p->sgte;
			}
		}
	}
	if(Contacto == 'E'){
		while (p != cabeza)
		{
			if(p->info.TipodeCont == "Estudio"){
				cout<<"\n\t\t\t"<<p->info.Nombre<<"\t\t\t"<<p->info.TipodeCont<<"\t\t\t"<<p->info.Numero<<"\t\t\t"<<"\n\n";
				p=p->sgte;
			}
		}
	}
	if(Contacto == 'F'){
		while (p != cabeza)
		{
			if(p->info.TipodeCont == "Familia"){
				cout<<"\n\t\t\t"<<p->info.Nombre<<"\t\t\t"<<p->info.TipodeCont<<"\t\t\t"<<p->info.Numero<<"\t\t\t"<<"\n\n";
				p=p->sgte;
			}
		}		
	}
	if(Contacto == 'A'){
		while (p != cabeza)
		{
			if(p->info.TipodeCont == "Amigos"){
				cout<<"\n\t\t\t"<<p->info.Nombre<<"\t\t\t"<<p->info.TipodeCont<<"\t\t\t"<<p->info.Numero<<"\t\t\t"<<"\n\n";
				p=p->sgte;
			}
		}		
	}
	system("Pause");	
	system("cls");
}

void BuscarLista(struct nodo* cabeza)
{
	struct nodo *p;
	unsigned long int Num,i=0;
	cout<<"\tDigite el numero que desea buscar ";
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
		cout<<"\tNo existe el numero\n";
	}
	system("Pause");
}

void eliminarNodo(struct nodo* cabeza, unsigned long int NumAeliminar)
{
	struct nodo *actual, *anterior;
	actual = cabeza->sgte;
	anterior = NULL;
	
	bool encnt = false;
		while(actual != cabeza  && encnt!=true)
		{
			if(actual->info.Numero ==  NumAeliminar){
			cout<<"\n\tNodo con el dato " <<actual->info.Numero<<" encontrado.\n\n"<<endl;
			anterior->sgte = actual->sgte;
			delete (actual);
			cout<< "\n\tNodo eliminado con exito\n\n";
			encnt = true;
			}
			anterior = actual;
			actual = actual -> sgte; 
		}
		if(!encnt){
			cout<<"\n\tNodo no encontrado.";
		}
}

void OrganizarTipoC(struct nodo* cabeza)
{
    nodo *actual, *siguiente , * aux;
    string NombreAux;
	unsigned long int NumeroAux;
	string TipodeContAux;
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
    cout<<"\n\tLista organizada ";
    system("pause");
}

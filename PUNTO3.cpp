#include "PUNTO3HEADER.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	struct nodo *cabeza = NULL;
	int opcion;
	string NomEstudiante;
	cabeza=crearLista();
	
	do
	{
		
		cout <<"\t. :Menu:\n";
		cout <<"\t.1.Insertar elementos al inicio\n";
		cout <<"\t.2.Insertar elementos al final\n";
		cout <<"\t.3.Mostrar elementos de la lista al derecho\n";
		cout <<"\t.4.Eliminar elemento repetido \n";
		cout <<"\t.5.Salir\n";
		cout <<"\t.Digite la opcion: ";
		cin >>opcion;
		
		switch(opcion)
		{
			case 1: cout <<"Digite el nombre a insertar: ";
					cin>>NomEstudiante;
					insertarInicio(cabeza,NomEstudiante);
					system("pause");
					cout <<"\n";
					break;
			case 2: cout <<"Digite el nombre a insertar: ";
					cin>>NomEstudiante;
					insertarFinal(cabeza,NomEstudiante);
					system("pause");
					cout <<"\n";
					break;
			case 3: mostrarListaD(cabeza);
					system("pause");
					cout <<"\n";
					break;
			case 4: cout <<"Digite un nombre de la lista de estudiantes a eliminar: ";
					cin>>NomEstudiante;
					eliminarNodo(cabeza,NomEstudiante);
					system("pause");
					cout <<"\n";
					break;
			}
		system("cls");
	}
	while(opcion < 5 and opcion > 0);
	
	return 0;
}

/*
	Name: Agenda con listas y nodo de encabezamiento
	Copyright: POLI JIC
	Author: Algoritmos y Programacion2 - DAVID LONDOÑO, SANTIAGO OLEMDO, TOMAS PINEDA, CARLOS GONZALEZ
	Date: 09/11/20 
	Description: 
	- Punto 3 del taller #2 Colaborativo 
*/



#include "HEADERDELPUNTO3.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	struct nodo *cabeza = NULL;
	int opcion;
	char S;
	string NomEstudiante;
	cabeza=crearLista();
	
	do
	{
		cout<<"\n\n\n \t\t___________________________________________________ \n";
  		cout<<"         	        _____________________________________	 "<<endl; 
  		cout<<" \t\t|       |				    |     |"; 
  	  	cout<<"\n\t\t|       | 	  MENU ESTUDIANTES          |     |\n"; 
 		cout<<" \t\t|       |___________________________________|     |"<<endl; 
 		cout<<"\t\t___________________________________________________ \n";
 		cout<<" \t\t|   | 					          |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
  		cout<<" \t\t|1. | \tINSERTAR ELEMENTOS AL INICIO   	          |"<<endl;
   		cout<<" \t\t|___|_____________________________________________| \n";
   		cout<<" \t\t|2. | \tINSERTAR ELEMENTOS AL FINAL               |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
  		cout<<" \t\t|3. | \tMOSTRAR ELEMENTOS DE LA LISTA             |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
   		cout<<" \t\t|4. | \tELIMINAR ELEMENTO REPETIDO                |"<<endl;
  	 	cout<<" \t\t|___|_____________________________________________| \n";
  		cout<<" \t\t|5. | \tSALIR	                                  |"<<endl;
   		cout<<" \t\t|___|_____________________________________________| \n";
   		cout<<" \t\t|   | 					          |"<<endl;
 		cout<<" \t\t|___|_____________________________________________| \n";
   		cout<<" \t\t|   | \tESPERANDO A INGRESO DE OPCION....         |"<<endl;
		cout<<" \t\t|___|_____________________________________________| \n";
		cout<<"\n";
        do{
        cout<<"\t\tOPCION A INGRESAR: ";
			cin>>opcion;
		}while(opcion <0 || opcion > 5);  
		cout<<"\n";
		
		switch(opcion)
		{
			case 1: cout <<"\tDigite un nombre: ";
					cin>>NomEstudiante;
					insertarInicio(cabeza,NomEstudiante);
					cout<<"\n";
					system("pause");
					break;
			case 2: cout <<"\tDigite un nombre; ";
					cin>>NomEstudiante;
					insertarFinal(cabeza,NomEstudiante);
					cout<<"\n";
					system("pause");
					break;
			case 3: mostrarListaD(cabeza);
					cout<<"\n";
					system("pause");
					break;
			case 4: cout <<"\tDigite un nombre de la lista de estudiantes a eliminar:";
					cin>>NomEstudiante;
					eliminarNodo(cabeza,NomEstudiante);
					cout <<"\n";
					system("pause");
					break;
			case 5:	
					cout<<"\t\tEsta seguro de cerrar el programa? Ponga S mayuscula, de lo contario digite otra letra."<<endl;
					cout<<"\t\tDigite: ";
					cin>>S;
					if(S == 'S'){
						cout<<"\t\tCerrando el programa."<<endl;
						exit(EXIT_FAILURE);
					}else{
						break;
					}
			}
		system("cls");
	}while(opcion != 6);
	
	return 0;
}

/*
	Name: Agenda con listas y nodo de encabezamiento
	Copyright: POLI JIC
	Author: Algoritmos y Programacion2 - DAVID LONDOÑO, SANTIAGO OLEMDO, TOMAS PINEDA, CARLOS GONZALEZ
	Date: 09/11/20 
	Description: 
	- Punto 10 del taller #2 Colaborativo 
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "HEADERPUNTO10.h"


using namespace std;


/**  PROTOTIPOS DE FUNCIONES **/

void menu1();

/**  FUNCION PRINCIPAL       **/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv){

    struct nodo  *cabeza;
    struct informacion dato;
    short op;     // opcion del menu
    int i=0;
    int andes;
    int Cont;
    char S, SS;
    unsigned long int NumAeliminar;
    cabeza=crearLista();
    //insertardesdeArchivo(cabeza);
    system("color b3");
    Cont = 0;
        do 
        {
      		menu1();
      		cout<<"\n";
        	cout<<"\t\tOPCION A INGRESAR: ";cin>>op;
        	cout<<"\n";
            switch (op){
                case 1:
        			cout<<"\tInformacion a insertar: Nombre, Numero, Tipo de contacto. "<<endl<<endl;
        			cout<<"\tNombre: ";
        			cin>>dato.Nombre;
        			cout<<"\tNumero: ";
					cin>>dato.Numero;
					cout<<"\tTipo de contacto - Con mayuscula inicial (Trabajo / Estudio / Familia / Amigos): ";
					cin>>dato.TipodeCont;
                	insertarInicio(cabeza, dato);
                	cout<<"\tDesea ordenar todos sus contactos?, o despues? Digite S mayuscula para ordenar, de lo contario N o cualquier otra letra."<<endl;
                	cout<<"Digite: ";
                	cin>>SS;
                	if(SS == 'S')
                	{
                		cout<<"\tOrdenando los datos..."<<endl;
                		OrganizarTipoC(cabeza);
                		cout<<"\t\tDatos ordenados correctamente.\n\n"<<endl;
             	    }
             	    else
             	  	{
             	   	cout<<"\tVolviendo al menu sin ordenar los datos"<<endl;
					}
					break;
                case 2:
                	BuscarLista(cabeza);
                	system("cls");
        			break;
                case 3:
                	cout<<"\tIngrese el numero telefonico del contacto a eliminar: "<<endl;
                	cin>>NumAeliminar;
                	eliminarNodo(cabeza, NumAeliminar);
        			break;
        		case 4:
                	OrganizarTipoC(cabeza);
                	system("cls");
                	break;
               	case 5:
                	GuardarArchivo(cabeza);
                	Cont++;
        			break;
        		case 6:
        			mostrarLista(cabeza);
                	system("cls");
        			break;
                case 7:
                	if(Cont == 0){
             			cout<<"\tEste mensaje se genera debido que no ha guardado el archivo, desea proseguir sin guardar?"<<endl;
             			cout<<"\tDigite la letra S mayuscula para guardar, de lo contrario cualquier otra letra."<<endl<<endl;
             			cout<<"\t\tDigite: ";
             			cin>>S;
             			if(S == 'S'){
             				GuardarArchivo(cabeza);
						}
                	}
					else
					{
						cout<<"\tPrograma cerrado."<<endl;
                		exit(EXIT_FAILURE);
						}
                	cout<<"\t\tEl programa ha sido o habia sido guardado con exito, autodeteniendose..."<<endl;
                	exit(EXIT_FAILURE);
                		
                	
                default:
                	cout<<"\tError"<<endl;
            }
        }while (op!=8);
      system("pause");
      
   return 0;
}

void menu1()
{  
    cout<<"\n \t\t___________________________________________________ \n";
    cout<<"         	        _____________________________________	 "<<endl; 
    cout<<" \t\t|       |				    |     |"; 
    cout<<"\n\t\t|       | AGENDA TELEFONICA EDICION 2020-02 |     |\n"; 
    cout<<" \t\t|       |___________________________________|     |"<<endl; 
    cout<<"\t\t___________________________________________________ \n";
    cout<<" \t\t|   | 					          |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|1. | \tINSERTAR DATOS ORDENADOS   	          |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|2. | \tBUSCAR CONTACTO                   	  |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|3. | \tELIMINAR CONTACTO                         |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|4. | \tORGANIZAR POR TIPO DE CONTACTO            |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|5. | \tGUARDAR ARCHIVO		                  |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|6. | \tMOSTRAR LA AGENDA COMPLETA                |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|7. | \tSALIR DE LA AGENDA TELEFONICA 2020-02     |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|   | 					          |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|   | \tESPERANDO A INGRESO DE OPCION....         |"<<endl;
	cout<<" \t\t|___|_____________________________________________| \n";
 
 
}

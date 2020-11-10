/*
	Name: Agenda con listas y nodo de encabezamiento
	Copyright: POLI JIC 2020-02 & Archivos Maryem Clase Practica Alg. y programación #2.
	Author: Algoritmos y Programacion2 - DAVID LONDOÑO, SANTIAGO OLEMDO, TOMAS PINEDA, CARLOS GONZALEZ
	Date: 09/11/20 
	Description: 
	- Desarrollo del Punto 10 del taller #2 Colaborativo 
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "HEADERDELPUNTO10.h"


using namespace std;


/**  PROTOTIPOS DE FUNCIONES **/

void menu1();

/**  FUNCION PRINCIPAL       **/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv){

    struct nodo  *cabeza;
    struct informacion dato;
    short op;     // opcion del menu
    int andes;
    int Cont, Cont1, Cont2, Cont3, Cont4;
    char S, Cerrar, C;
    unsigned long int NumAeliminar;
    Cont = 0;
    Cont1 = 0;
    Cont2 = 0;
    Cont3 = 0;
    Cont4 = 0;
    cabeza=crearLista();
    contarNodos(cabeza);
    OrganizarTipoC(cabeza, Cont4);
    Cont1 = contarNodos(cabeza) - 1;
   	insertardesdeArchivo(cabeza, Cont1);
    system("color b3");

        do 
        {
        	Cont4++;
      		menu1();
      		Cont1 = Cont1 + Cont2;
        	Cont1 = Cont1 - Cont3;
        	do{

        	    cout<<"\n";
        		cout<<"\t\tOPCION A INGRESAR: ";
				cin>>op;
			}while(op < 0 || op > 6);  
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
                	cout<<"\tOrdenando los datos..."<<endl;
                	OrganizarTipoC(cabeza, Cont4);
                	cout<<"\t\tDatos ordenados correctamente.\n\n"<<endl;
                	Cont2++;
                	system("Pause");
                	system("cls");
					break;
                case 2:
                	BuscarLista(cabeza);
                	system("cls");
        			break;
                case 3:
                	cout<<"\tDesea visualizar su agenda para saber exactamente el numero a eliminar?"<<endl;
                	cout<<"\tSi es asi, digite S mayuscula para verla, de lo contrario cualquier otra letra para eliminar directamente: ";
                	cin>>C;
					if(C == 'S')
					{
						cout<<"\t\nDesplegando lista..."<<endl;	
        				mostrarLista(cabeza, Cont1);
					}
                	cout<<"\tIngrese el numero telefonico del contacto a eliminar: ";
                	cin>>NumAeliminar;
                	eliminarNodo(cabeza, NumAeliminar);
                	Cont3 = Cont3 + eliminarNodo(cabeza, NumAeliminar);
                	system("cls"); 
        			break;
               	case 4:
                	GuardarArchivo(cabeza);
                	Cont++;
        			break;
        		case 5:

        			mostrarLista(cabeza, Cont1);
        			system("Pause");
                	system("cls");  		
        			break;
                case 6:
					cout<<"\t\tEsta seguro de cerrar el programa? Ponga S mayuscula, de lo contrario digite la letra N"<<endl;
					cout<<"\t\tDigite: ";
					cin>>Cerrar;
					if(Cerrar == 'S'){
                		if(Cont == 0){
             				cout<<"\t\tEste mensaje se genera debido que no ha guardado el archivo, desea proseguir sin guardar?"<<endl;
             				cout<<"\t\tDigite la letra S mayuscula para guardar, de lo contrario cualquier otra letra."<<endl<<endl;
             				cout<<"\t\tDigite: ";
             				cin>>S;
             					if(S == 'S'){
             						GuardarArchivo(cabeza);
             						exit(EXIT_FAILURE);
             					}
						}
						else if(Cont > 0)
						{
							cout<<"\t\tPrograma cerrado."<<endl;
							cout<<"\n\n\t\tAutodeteniendose..."<<endl;
                			exit(EXIT_FAILURE);
						}
					}
					if(Cerrar == 'N'){
						break;
					}

                		 	
                default:
                	cout<<"\tError"<<endl;
            }
        }while(op!=7);
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
    cout<<" \t\t|4. | \tGUARDAR ARCHIVO		                  |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|5. | \tMOSTRAR LA AGENDA COMPLETA                |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|6. | \tSALIR DE LA AGENDA TELEFONICA 2020-02     |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|   | 					          |"<<endl;
    cout<<" \t\t|___|_____________________________________________| \n";
    cout<<" \t\t|   | \tESPERANDO A INGRESO DE OPCION....         |"<<endl;
	cout<<" \t\t|___|_____________________________________________| \n";
 
 
}

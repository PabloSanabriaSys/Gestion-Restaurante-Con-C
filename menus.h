#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

using namespace std;


void nombre(){
	cout<<"\t\t\t\t ___________    __       __    ____________    ___________    ____________    __________   "<<endl;
	cout<<"\t\t\t\t|   _____   |  |  |     |  |  |____    ____|  |   _____   |  |____    ____|  |   ____   |  "<<endl;
	cout<<"\t\t\t\t|  |     |  |  |  |     |  |       |  |       |  |     |  |       |  |       |  |    |  |  "<<endl;
	cout<<"\t\t\t\t|  |     |  |  |  |     |  |       |  |       |  |     |  |       |  |       |  |____|  |  "<<endl;
	cout<<"\t\t\t\t|  |     |  |  |  |     |  |       |  |       |  |     |  |       |  |       |   ____   |  "<<endl;
	cout<<"\t\t\t\t|  |  __ |  |  |  |     |  |       |  |       |  |     |  |       |  |       |  |    |  |  "<<endl;
	cout<<"\t\t\t\t|  |__\\ \\|  |  |  |_____|  |   ____|  |____   |  |     |  |       |  |       |  |    |  |  "<<endl;
	cout<<"\t\t\t\t|______\\ \\__|  |___________|  |____________|  |__|     |__|       |__|       |__|    |__|  "<<endl;
	cout<<"\t\t\t\t        \\_\\   \n\n"<<endl;
	cout<<"\t ____________    __       __    ____________   __       __    ______________    ____________    ____________    __________    __________   "<<endl;
	cout<<"\t|____    ____|  |  |     |  |  |____    ____| |  |     |  |  |   __    __   |  |____    ____|  |____    ____|  |   ____   |  |   _______| "<<endl;
	cout<<"\t     |  |       |  |     |  |       |  |      |  |     |  |  |  |  |  |  |  |       |  |            |  |       |  |    |  |  |  |              "<<endl;
	cout<<"\t     |  |       |  |     |  |       |  |      |  |     |  |  |  |  |  |  |  |       |  |            |  |       |  |____|  |  |  |_______     "  <<endl;
	cout<<"\t     |  |       |  |     |  |       |  |      |  |     |  |  |  |  |  |  |  |       |  |            |  |       |   ____   |  |_______   |   "<<endl;
	cout<<"\t     |  |       |  |     |  |       |  |      |  |     |  |  |  |  |__|  |  |       |  |            |  |       |  |    |  |          |  |    "<<endl;
	cout<<"\t     |  |       |  |_____|  |       |  |      |  |_____|  |  |  |        |  |   ____|  |____        |  |       |  |    |  |   _______|  |   "<<endl;
	cout<<"\t     |__|       |___________|       |__|      |___________|  |__|        |__|  |____________|       |__|       |__|    |__|  |__________| "<<endl;
	cout<<"\n\n----------------------------------------------------------------- SISTEMA OPERATIVO-----------------------------------------------------------------\n";
    system ("pause");
}

void menusito()
{
    cout<<"\t\t\t________________________\n";
	cout<<"\t\t\t| OPCIONES:            |\n";
	cout<<"\t\t\t|                      |\n";
	cout<<"\t\t\t|    1. EMPLEADOS      |\n";
	cout<<"\t\t\t|    2. PRODUCTOS      |\n";
	cout<<"\t\t\t|    3. SALIR          |\n";
	cout<<"\t\t\t|______________________|\n";
	cout<<"\t\t\tIngrese una opción: ";
}

void menusitoemp()
{
	//OPCIONES DE EPLEADOS
    cout<<"____________________________\n";
    cout<<"| OPCIONES DE EMPLEADOS:   |\n";
    cout<<"|                          |\n";
	cout<<"| 1. CONTRATAR             |\n";
	cout<<"| 2. REGISTRO DE EMPLEADOS |\n";
	cout<<"| 3. EMPLEADO DEL MES      |\n";
	cout<<"| 4. SALIR                 |\n";
	cout<<"|__________________________|\n";
	cout<<"Ingrese una opción: ";
}

void menucomidas()
{
	//OPCIONES DE LAS COMIDAS
	cout<<"\t\t\t___________________\n";
	cout<<"\t\t\t| 1. MENU GENERAL |\n";
	cout<<"\t\t\t| 2. OFERTAS      |\n";
	cout<<"\t\t\t| 3. SALIR        |\n";
	cout<<"\t\t\t|_________________|\n";
	cout<<"\t\t\tIngrese una opción: ";
}


void menugeneral()
{
	cout<<"\t\t\t___________________________________________________\n";
	cout<<"\t\t\t|                                                 |\n";
	cout<<"\t\t\t|                       MENU                      |\n";
	cout<<"\t\t\t|_________________________________________________|\n";
	cout<<"\t\t\t|                                                 |\n";
	cout<<"\t\t\t|  + PLATOS NACIONALES                 PRECIO     |\n";
	cout<<"\t\t\t|                                                 |\n";
	cout<<"\t\t\t|    1. PIQUE MACHO                     80 Bs     |\n";
	cout<<"\t\t\t|    2. PLANCHITA                      100 Bs     |\n";
	cout<<"\t\t\t|    3. KALAPURKA POTOSINA              50 Bs     |\n";
	cout<<"\t\t\t|    4. CHARQUE DE LLAMA                60 Bs     |\n";
	cout<<"\t\t\t|                                                 |\n";
	cout<<"\t\t\t|  + BEBIDAS                           PRECIO     |\n";
	cout<<"\t\t\t|                                                 |\n";
	cout<<"\t\t\t|    5. COCA COLA 1 1/2 L                7 Bs     |\n";
	cout<<"\t\t\t|    6. COCA COLA 2 L                   10 Bs     |\n";
	cout<<"\t\t\t|    7. COCA COLA 3 L                   15 Bs     |\n";
	cout<<"\t\t\t|                                                 |\n";
	cout<<"\t\t\t|                                                 |\n";
	cout<<"\t\t\t|_________________________________________________|\n";
}

void oferta(){
	int op;
	cout<<"\t\t\t _____________________________________________________"<<endl;
	cout<<"\t\t\t|                                                     |"<<endl;
	cout<<"\t\t\t|        MENU DE COMBOS DOMINGO DE RESURECCION        |"<<endl;
    cout<<"\t\t\t|_____________________________________________________|"<<endl;
    cout<<"\t\t\t|                                                     |"<<endl;
    cout<<"\t\t\t|   +PLATOS NACIONALES                     PRECIO     |"<<endl;
    cout<<"\t\t\t|                                                     |"<<endl;
    cout<<"\t\t\t|   1.COMBO TUSA                            100 Bs    |"<<endl;
    cout<<"\t\t\t|   2.COMBA INTENDENTE                      90  Bs    |"<<endl;
    cout<<"\t\t\t|   3.COMBO BIG MAMA                        225 Bs    |"<<endl;
    cout<<"\t\t\t|   4.COMBO LA CHISPEANTE                   180 Bs    |"<<endl;
    cout<<"\t\t\t|   5.COMBO EL K'ENCHA                      300 Bs    |"<<endl;
    cout<<"\t\t\t|   6.COMBO LA SECRETARIA                   120 Bs    |"<<endl;
    cout<<"\t\t\t|   7.COMBO EL BICHO                        380 Bs    |"<<endl;
    cout<<"\t\t\t|_____________________________________________________|"<<endl;
    cout<<"Elija una opción: ";
	do{
        cin>>op;
        if(op<1 || op>7) cout<<"\nINNGRESE UNA OPCION QUE SE ENCUENTRE EN EL MENU\n";
	}while(op<1 || op>7);
    switch(op){
    	case 1:{
    		cout<<"\t\t\t**********************"<<endl;
    		cout<<"\t\t\t      COMBO TUSA      "<<endl;
    		cout<<"\t\t\t**********************"<<endl;
    		cout<<"\t\t\t-x2 Guarapo           "<<endl;
    		cout<<"\t\t\t-x1 Pique Macho       "<<endl;
    		cout<<"\t\t\t-x1 CocaCola          "<<endl;
    		cout<<"\t\t\t**********************"<<endl;
			break;
		}
		case 2:{
    		cout<<"\t\t\t************************"<<endl;
    		cout<<"\t\t\t     COMBO INTENDENTE   "<<endl;
    		cout<<"\t\t\t************************"<<endl;
    		cout<<"\t\t\t-x1 CHARQUE             "<<endl;
    		cout<<"\t\t\t-x1 Coca Cola 3L        "<<endl;
    		cout<<"\t\t\t-x2 BALDES DE GARAPIÃ‘A  "<<endl;
    		cout<<"\t\t\t************************"<<endl;
			break;
		}
		case 3:{
    		cout<<"\t\t\t***********************"<<endl;
    		cout<<"\t\t\t    COMBO BIG MAMA     "<<endl;
    		cout<<"\t\t\t***********************"<<endl;
    		cout<<"\t\t\t-x2 GUARAPO            "<<endl;
    		cout<<"\t\t\t-x3 PIQUE MACHO        "<<endl;
    		cout<<"\t\t\t-x1 CocaCola           "<<endl;
    		cout<<"\t\t\t-x1 BALDE DE CHICHA    "<<endl;
    		cout<<"\t\t\t***********************"<<endl;
			break;
		}
		case 4:{
    		cout<<"\t\t\t****************************"<<endl;
    		cout<<"\t\t\t    COMBO LA CHISPEANTE     "<<endl;
    		cout<<"\t\t\t****************************"<<endl;
    		cout<<"\t\t\t-x1 PLANCHITAS              "<<endl;
    		cout<<"\t\t\t-x1 KALAPURKA POTOSINA      "<<endl;
    		cout<<"\t\t\t-x2 COCA COLA               "<<endl;
    		cout<<"\t\t\t-x1 BALDE DE AGUA           "<<endl;
    		cout<<"\t\t\t****************************"<<endl;
			break;
		}
		case 5:{
    		cout<<"\t\t\t****************************"<<endl;
    		cout<<"\t\t\t    COMBO EL K'ENCHA       "<<endl;
    		cout<<"\t\t\t****************************"<<endl;
    		cout<<"\t\t\t-x1 PIQUE                   "<<endl;
    		cout<<"\t\t\t-x1 PLANCHITA               "<<endl;
    		cout<<"\t\t\t-x2 COCA COLA               "<<endl;
    		cout<<"\t\t\t-x1 FLOR DE CAÑA (RON)      "<<endl;
    		cout<<"\t\t\t****************************"<<endl;
			break;
		}
		case 6:{
    		cout<<"\t\t\t*****************************"<<endl;
    		cout<<"\t\t\t     COMBO LA SECRETARIA     "<<endl;
    		cout<<"\t\t\t*****************************"<<endl;
    		cout<<"\t\t\t-x1 CHARQUE DE LLAMA         "<<endl;
    		cout<<"\t\t\t-x3 CUBA LIBRE               "<<endl;
    		cout<<"\t\t\t-x1 COCA COLA                "<<endl;
    		cout<<"\t\t\t-x1 SPRITE                   "<<endl;
    		cout<<"\t\t\t*****************************"<<endl;
			break;
		}
		case 7:{
    		cout<<"\t\t\t****************************"<<endl;
    		cout<<"\t\t\t      COMBO EL BICHO        "<<endl;
    		cout<<"\t\t\t****************************"<<endl;
    		cout<<"\t\t\t-x1 PLANCHITAS              "<<endl;
    		cout<<"\t\t\t-x1 CHARQUE                 "<<endl;
    		cout<<"\t\t\t-x2 JUGO DE TUMBO           "<<endl;
    		cout<<"\t\t\t-x1 PELOTA DE FOTBOL        "<<endl;
    		cout<<"\t\t\t-x2 JUGO DEL VALLE          "<<endl;
    		cout<<"\t\t\t****************************"<<endl;
			break;
		}
	}
}

void menu_empleado_registro()
{
    cout<<"\n¿QUE OPERACION DESEA REALIZAR CON EL REGISTRO DE EMPLEADOS CONTRATADOS?\n";
    cout<<"1. EDITAR REGISTRO\n";
    cout<<"2. ELIMINAR REGISTRO\n";
    cout<<"3. MOSTRAR REGISTRO\n";
    cout<<"4. SALIR\n";
    cout<<"Ingrese una opción: ";
}
void menualmacen()
{
    cout<<"-------------------------------------"<<endl;
    cout<<"           MENU DE ALMACEN           "<<endl;
    cout<<"_____________________________________"<<endl;
    cout<<" 1.- Guardar productos en el almacen "<<endl;
    cout<<" 2.- Mostrar datos del almacen       "<<endl;
    cout<<" 3.- Modificar datos del almacen     "<<endl;
    cout<<" 4.- Borrar datos del almacen        "<<endl;
    cout<<" 5.- Salir                           "<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Elija una opcion del menu: ";
}
void menu_alimentos()
{
    cout<<"_________________________________________\n";
    cout<<"|          OPCINES DE ALIMENTOS         |\n";
    cout<<"|                                       |\n";
    cout<<"| 1. ALMACENES                          |\n";
    cout<<"| 2. MENUS DE COMIDAS (FACTURACIÓN)     |\n";
    cout<<"| 3. SALIR                              |\n";
    cout<<"|_______________________________________|\n";
    cout<<"Ingrese una opción del menú:\n";

}

#endif // MENUS_H_INCLUDED

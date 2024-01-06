#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "menus.h"
#include "facturacion.h"

using namespace std;

float monto_total=0;
float *detalle_cliente_diez;
string names[15]={"PIQUE MACHO","PLANCHITA","KALAPURKA POTOSINA",
"CHARQUE DE LLAMA ","COCA COLA 1/2 ","COCA COLA 2 L ","COCA COLA 3 ",
"COMBO TUSA ","COMBO INTENDENTE ","COMBO BIG MAMA ","COMBO LA CHISPEANTE ",
"COMBO EL K'ENCHA ","COMBO LA SECRETARIA ","COMBO EL BICHO "};
struct restaurant{
    string producto;
    int pro;
    float precio;
};

struct Contratacion
{
    int carnet;
    char nombre[100];
    char turno[10];
    int antiguedad;
    int edad;
    char sexo[10];
};
struct Almacen
{
    int num;
    char codigo[10];
    char nombre[20];
    char unidad[10];
    float precio;
    int stock;
    char proovedor[50];
};
void crear_fichero(FILE* f, Contratacion c)
{
int ver;

if((f=fopen("REGISTRO_EMPLEADOS.dat","ab"))==NULL)
{
    cout<<"error en apertura";
}
else
{
    cout<<endl;
	cout<<"INGRESE EL NOMBRE DEL POSTULANTE: "; fflush(stdin);gets(c.nombre);fflush(stdin);
	cout<<"INGRESE EL TURNO AL QUE POSTULA\n(maniana, tarde o noche): ";
	do{
        fflush(stdin); gets(c.turno); fflush(stdin);
        ver = strcmp(c.turno, "maniana");
        if(ver!=0)
        {
            ver = strcmp(c.turno, "tarde");
            if(ver!=0)
            {
                ver = strcmp(c.turno, "noche");
            }
        }
        if(ver!=0) cout<<"¡Ingrese un turno valido!\n(maniana, tarde o noche)\n";
	}while(ver!=0);

	cout<<"INGRESE LOS AÑOS DE EXPERIENCIA DEL POSTULANTE: ";
    do{
        cin>>c.antiguedad;
        if(c.antiguedad<0) cout<<"¡INGRESE UN DATO VALIDO!\n(mayor a 0)\n";
    }while(c.antiguedad<0);

	cout<<"INGRESE LA EDAD DEL POSTULANTE: ";
	do{
      cin>>c.edad;
      if(c.edad<0) cout<<"¡Ingrese una edad valida!\n(mayor a 0)\n";
	}while(c.edad<0);

	cout<<"INGRESE EL SEXO (masculino) o (femenino): ";
	do{
      fflush(stdin);gets(c.sexo);fflush(stdin);
      ver = strcmp(c.sexo, "masculino");
      if(ver!=0)
      {
          ver = strcmp(c.sexo, "femenino");
      }
      if(ver!=0) cout<<"¡Ingrese algunas de las 2 opciones validas!\n";
	}while(ver!=0);
	cout<<"INGRESE EL CARNET DEL POSTULANTE: ";
	do{
      cin>>c.carnet;
      if(c.carnet<0) cout<<"¡Ingrese una edad valida!\n(mayor a 0)\n";
	}while(c.carnet<0);
	cout<<endl;
	if(c.edad>=18)
                {
                    cout<<"\t\t\t|-----------------------------------------------------|\n";
                    cout<<"\t\t\t| ¡Empleado Contratado! (Tiene 18 o más años de edad) |\n";
                    cout<<"\t\t\t|-----------------------------------------------------|\n";
                    fwrite(&c,sizeof(c),1,f);
                }
                else
                {
                    cout<<"El empleado no cumple con la edad de requisito (18 años cumplidos)\n";
                }
} fclose(f);
}

void editar_empleado(FILE *quin, Contratacion c){
int i,pos;
int co, ver;
bool bandera=false;
	if((quin=fopen("REGISTRO_EMPLEADOS.dat","r+b"))==NULL) {
		cout<<"error en apertura!!";
	}
	else {
		cout<<"Ingrese el carnet del empleado que desea modificar: "<<endl;
		cin>>co;
		fread(&c,sizeof(c),1,quin);
		while(!feof(quin)&& bandera ==false){
                if(co==c.carnet)
                {
                    cout<<"Nuevo Turno de Trabajo: ";
                    do{
                        fflush(stdin); gets(c.turno); fflush(stdin);
                        ver = strcmp(c.turno, "maniana");
                        if(ver!=0)
                        {
                            ver = strcmp(c.turno, "tarde");
                            if(ver!=0)
                            {
                                ver = strcmp(c.turno, "noche");
                            }
                        }
                        if(ver!=0) cout<<"¡Ingrese un turno valido!\n(maniana, tarde o noche)\n";
                    }while(ver!=0);

                    cout<<"Antiguedad Actualizada (en años): ";
                    do{
                        cin>>c.antiguedad;
                        if(c.antiguedad<0) cout<<"¡INGRESE UN DATO VALIDO!\n(mayor a 0)\n";
                    }while(c.antiguedad<0);
                    pos=ftell(quin)-sizeof(c);
                    fseek(quin,pos,SEEK_SET);
                    fwrite(&c,sizeof(c),1,quin);
                    bandera=true;
                    cout<<"!Los datos del empleado fueron modificados exitosamente!"<<endl;
                    break;
                }
                fread(&c,sizeof(c),1,quin);
		}
		if(bandera==false)
                    cout<<"!El Carnet ingresado no es de un empleado contratado!"<<endl;
		fclose(quin);
	}
}

void eliminar_empleado(FILE *a, FILE *b, Contratacion c)
{
    int car;
    a=fopen("REGISTRO_EMPLEADOS.dat","rb");
    b=fopen("REGISTRO_EMPLEADOS_AUX.dat","wb");
    if(a==NULL)
    {
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        if(b==NULL)
        {
            cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        }
        else
        {
            cout<<"Ingrese el carnet del empleado a despedir: ";
            cin>>car;
            fread(&c,sizeof(c),1,a);
            while(!feof(a))
            {
                if(car!=c.carnet)
                {
                    fwrite(&c,sizeof(c),1,b);
                }
                else
                {
                    cout<<"EL EMPLEADO CON C.I.: "<<c.carnet<<" DE NOMBRE "<<c.nombre<<" SE ELIMINO."<<endl;
                }
                fread(&c,sizeof(c),1,a);
            }
        }
    }
    fclose(a);
    fclose(b);
    a = fopen("REGISTRO_EMPLEADOS.dat","w+b");
    b = fopen("REGISTRO_EMPLEADOS_AUX.dat","r+b");
    if(a==NULL)
    {
        cout<<"ERROR AL ABRIR EL REGISTRO"<<endl;
    }
    else
    {
        if(b==NULL)
        {
            cout<<"ERROR AL ABRIR EL REGISTRO"<<endl;
        }
        else
        {
            fread(&c,sizeof(c),1,b);
            while(!feof(b))
            {
                fwrite(&c,sizeof(c),1,a);
                fread(&c,sizeof(c),1,b);
            }
            cout<<endl<<endl;
        }
    }
    fclose(a);
    fclose(b);
}

void mostrarfi(FILE *f,Contratacion c){
	if((f=fopen("REGISTRO_EMPLEADOS.dat","rb"))==NULL){
		cout<<"Error en la apertura "<<endl;
	}
	else{
		cout<<" ______________________________________________________________________________ "<<endl;
		cout<<"|                              LISTA DE REGISTRO                               |"<<endl;
		cout<<"|______________________________________________________________________________|"<<endl;
		cout<<"| NOMBRE \tEDAD \tNro CARNET \tANTIGUEDAD \tSEXO \t\tTURNO  |"<<endl;
		fread(&c,sizeof(c),1,f);
		while(!feof(f)){
            cout<<"| "<<c.nombre<<"\t "<<c.edad<<"\t"<<c.carnet<<" \t     "<<c.antiguedad<<"\t\t"<<c.sexo<<"\t"<<c.turno<<"  |"<<endl;
            fread(&c,sizeof(c),1,f);
		}
		cout<<"|______________________________________________________________________________|\n\n";
	}
	fclose(f);
}


void empleado_de_mes(FILE *a, Contratacion c, nodo *&frente1, nodo *&fin1, char employed[])
{
    a = fopen("REGISTRO_EMPLEADOS.dat", "rb");
    if(a==NULL)
    {
        cout<<"ERROR AL ABRIR EL ARCHIVO\n";
    }
    else
    {
        fread(&c, sizeof(c), 1, a);
        strcmp(employed, c.nombre);
        while(!feof(a))
        {
            push(frente1, fin1, c.carnet);
            fread(&c, sizeof(c), 1, a);
        }
        fclose(a);
    }
}
void nombree(FILE *a, Contratacion c, int ca)
{
    a = fopen("REGISTRO_EMPLEADOS.dat", "rb");
    if(a==NULL)
    {
        cout<<"ERROR AL ABRIR EL ARCHIVO\n";
    }
    else
    {
        fread(&c, sizeof(c), 1, a);
        while(!feof(a))
        {
            if (ca==c.carnet) cout<<c.nombre;
            fread(&c, sizeof(c), 1, a);
        }
        fclose(a);
    }
}
void reporteEmpleados()
{
    Contratacion c;
    FILE *a;
    FILE *b;
	int n,opi, cm;
	char nomb[100];
	string cade, cadeo;
	do{
        nodo *frente1=NULL;
        nodo *fin1=NULL;
        menusitoemp();
        do{
            cin>>n;
            if(n<1 ||n>3) cout<<"\nIngrese una opción válida\n\n";
        }while(n<1 || n>3);
        switch(n)
        {
        case 1:
            crear_fichero(a, c);
            cout<<endl;
            break;
        case 2:
            do{
                menu_empleado_registro();
                cin>>opi;
                 switch(opi)
                {
                case 1:
                    editar_empleado(a,c);
                    cout<<endl;
                    break;
                case 2:
                    eliminar_empleado(a,b,c);
                    cout<<endl;
                    break;
                case 3:
                    mostrarfi(a,c);
                    cout<<endl;
                    break;
                case 4:
                    break;
                }
            }while(opi!=4);
            break;
        case 3:
            cout<<"\n¡EL PROCESO DE SELECCIÓN DE EMPLEADO DEL MES ES DE ACUERDO A LA ANTIGUEDAD Y CONTRATACIÓN!\n";
            char empm[20];
            empleado_de_mes(a, c, frente1, fin1, empm);
            pop(frente1, fin1, cm);
            cout<<"El empleado de carnet: "<<cm<<endl;
            cout<<"\t____________________________\n";
            cout<<"\t|\t    "; nombree(a,c,cm); cout<<"\t   |\n";
            cout<<"\t| ¡ES EL EMPLEADO DEL MES! |\n";
            cout<<"\t|__________________________|\n";
            break;
        }
        cout<<"¿Desea continuar con los empleados?\nIngrese (si) o (no)\n";
        cin>>cadeo;
	}while(cadeo=="si");
	cout<<endl;
}

void menu(int &op)
{
	cout<<"*****************************\n";
	cout<<"1.- ANOTAR PEDIDO \n";
	cout<<"2.- Mostrar PEDIDO\n";
	cout<<"3.- Dejar de PEDIR\n";
	cout<<"*****************************\n";
	cout<<"Ingrese la opción que desea realizar: "; cin>>op;
}
void escribir_pedido(FILE *quin, restaurant o)
{
	int i, n, opi, opimen;
	if ((quin=fopen("datos_pedidos.txt", "wb"))==NULL){
		cout<<"ERROR EN APERTURA :)";
	}
	else{
		cout<<"INGRESE LA CANTIDAD DE PEDIDOS: "; cin>>n;
		for(int j=0;j<n;j++)
        {
            cout<<"\t\t\t¿DE QUÉ MENÚ SERÁ SU PEDIDO "<<j+1<<"?\n";
            cout<<"\t\t\t 1. GENERAL\t2. OFERTAS\n";
            do{
                cin>>opi;
                if(opi!=1 && opi!=2) cout<<"\nINGRESE UNA OPCIÓN VALIDA\n";
            }while(opi!=1 && opi!=2);
            switch (opi)
            {
            case 1:
                cout<<"¿Qué número del menú ordenará?: ";
                do{
                    cin>>opimen;
                    if(opimen<1 || opimen>7) cout<<"\nIngrese una opción del menú general (DEL 1 AL 7)\n";
                }while(opimen<1 || opimen>7);
                switch(opimen)
                {
                case 1: {
                    monto_total = monto_total + 80;
                    o.producto="PIQUE_MACHO";
                    o.precio=80;
                    o.pro=0;
                    break;
                }
                case 2: {
                    monto_total = monto_total + 100;
                    o.producto="PLANCHITA";
                    o.precio=100;
                    o.pro=1;
                    break;
                }
                case 3: {
                    monto_total = monto_total + 50;
                    o.producto="KALAPURKA POTOSINA";
                    o.precio=50;
                    o.pro=2;
                    break;
                }
                case 4: {
                    monto_total = monto_total + 60;
                    o.producto="CHARQUE DE LLAMA";
                    o.precio=60;
                    o.pro=3;
                    break;
                }
                case 5: {
                    monto_total = monto_total + 7;
                    o.producto="COCA COLA 1 1/2 L";
                    o.precio=7;
                    o.pro=4;
                    break;
                }
                case 6: {
                    monto_total = monto_total + 10;
                    o.producto="COCA COLA 2 L";
                    o.precio=10;
                    o.pro=5;
                    break;
                }
                case 7: {
                    monto_total = monto_total + 15;
                    o.producto="COCA COLA 3 L";
                    o.precio=15;
                    o.pro=6;
                    break;
                }
                }
                break;
            case 2:
                cout<<"¿Qué número del menú ordenará?: ";
                do{
                    cin>>opimen;
                    if(opimen<1 || opimen>7) cout<<"\nIngrese una opción del menú de Ofertas (DEL 1 AL 7)\n";
                }while(opimen<1 || opimen>7);
                switch(opimen)
                {
                case 1: {
                    monto_total = monto_total + 100;
                    o.producto="COMBO TUSA";
                    o.precio=100;
                    o.pro=7;
                    break;
                }
                case 2: {
                    monto_total = monto_total + 90;
                    o.producto="COMBA INTENDENTE";
                    o.precio=90;
                    o.pro=8;
                    break;
                }
                case 3: {
                    monto_total = monto_total + 225;
                    o.producto="COMBO BIG MAMA";
                    o.precio=225;
                    o.pro=9;
                    break;
                }
                case 4: {
                    monto_total = monto_total + 180;
                    o.producto="COMBO LA CHISPEANTE";
                    o.precio=180;
                    o.pro=10;
                    break;
                }
                case 5: {
                    monto_total = monto_total + 300;
                    o.producto="COMBO EL K'ENCHA";
                    o.precio=300;
                    o.pro=11;
                    break;
                }
                case 6: {
                    monto_total = monto_total + 120;
                    o.producto="COMBO LA SECRETARIA";
                    o.precio=120;
                    o.pro=12;
                    break;
                }
                case 7: {
                    monto_total = monto_total + 120;
                    o.producto="COMBO EL BICHO";
                    o.precio=120;
                    o.pro=13;
                    break;
                }
                }
            }
            cout<<o.producto<<endl;
            fwrite(&o,sizeof(o),1,quin);
        }
		fclose(quin);
	}
}
void mostrar_pedido(FILE *quin, restaurant o)
{
	if((quin=fopen("datos_pedidos.txt", "rb"))==NULL){
		cout<<"ERROR EN APERTURA :)";
	}
	else{
		cout<<"_________________________________________________\n";
		cout<<"                        PEDIDOS                  \n";
		cout<<"_________________________________________________\n";
		cout<<" PEDIDO     -     PRECIO"<<endl;
		fread(&o, sizeof(o),1,quin);
		while(!feof(quin)){
			cout<<names[o.pro]<<"    "<<o.precio<<endl;
            cout<<"_________________________________________________\n";
			fread(&o, sizeof(o),1,quin);
		}
	}
	fclose(quin);
}
void guardar_datosa(FILE *f, Almacen w)
{
    int i,n;
    if((f=fopen("almacen.dat","ab"))==NULL)
    {
        cout<<"error en apertura";
    }
    else
    {
        cout<<"Cuantos datos desea guardar: ";
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cout<<"Producto "<<i<<":\n";
            cout<<"Ingrese el codigo del producto: ";
            fflush(stdin);
            gets(w.codigo);
            fflush(stdin);
            cout<<"Ingrese el nombre del producto: ";
            fflush(stdin);
            gets(w.nombre);
            fflush(stdin);
            cout<<"Ingrese la unidad del producto: ";
            fflush(stdin);
            gets(w.unidad);
            fflush(stdin);
            cout<<"Ingrese el precio del producto: ";
            cin>>w.precio;
            cout<<"Ingrese el stock (cantidad en almacen) del producto: ";
            cin>>w.stock;
            cout<<"Ingrese el proveedor del producto: ";
            fflush(stdin);
            gets(w.proovedor);
            fflush(stdin);
            cout<<endl;
            fwrite(&w, sizeof(w),1,f);
        }
    }
    fclose(f);
}

void facturita(FILE *quin, restaurant o)
{
    char nombre_cli[30];
    int carnet;
    cout<<"INGRESE SU NÚMERO DE CARNET PARA LA FACTURA: ";
    do{
        cin>>carnet;
        if(carnet<=99999) cout<<"¡Ingrese un carnet valido de 6 dígitos!\n";
    }while(carnet<=99999);
    cout<<"INGRESE EL NOMBRE PARA LA FACTURA: ";
    fflush(stdin); gets(nombre_cli); fflush(stdin);
	if((quin=fopen("datos_pedidos.txt", "rb"))==NULL){
		cout<<"ERROR EN APERTURA :)";
	}
	else{
        cout<<"\t\t\t_________________________________________________________\n";
        cout<<"\t\t\t|            FACTURA  - 'QUINTA TUTUMITAS'              |\n";
        cout<<"\t\t\t|_______________________________________________________|\n";
        cout<<"\t\t\t|  NOMBRE: "<<nombre_cli<<"\tC.I.: "<<carnet<<endl;
		cout<<"\t\t\t|_______________________________________________________|\n";
		cout<<"\t\t\t|                       PEDIDOS                         |\n";
		cout<<"\t\t\t|_______________________________________________________|\n";
		cout<<"\t\t\t| PEDIDO     -     PRECIO                               |\n";
        cout<<"\t\t\t|_______________________________________________________|\n";
		fread(&o, sizeof(o),1,quin);
		while(!feof(quin)){
			cout<<"\t\t\t|"<<names[o.pro]<<"\t\t"<<o.precio<<endl;
		cout<<"\t\t\t|_______________________________________________________|\n";

			fread(&o, sizeof(o),1,quin);
		}
		cout<<"\t\t\t|  MONTO TOTAL A PAGAR:\t"<<monto_total<<"            \n";
		cout<<"\t\t\t|_______________________________________________________|\n";
	}
	fclose(quin);
}

void leer_ficheroa(FILE* f,Almacen w)
{
    int i=1;
if((f=fopen("almacen.dat","rb"))==NULL)
{
    cout<<"error en apertura";
}
else
    {
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        cout<<"                          LISTA DE PRODUCTO EN EL ALMACEN"<<endl;
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        cout<<"|  NUMERO   |  CODIGO   |  NOMBRE  |   UNIDAD   |   PRECIO   |   STOCK   |   PROVEEDOR   |"<<endl;
        fread(&w, sizeof(w), 1, f);
        while(!feof(f))
        {
            cout<<"\t"<<i<<"\t"<<w.codigo<<"\t    "<<w.nombre<<"\t "<<w.unidad<<"\t    "<<w.precio<<"\t\t   "<<w.stock;
            cout<<"\t\t"<<w.proovedor<<endl;
            fread(&w, sizeof(w),1,f);
            i++;
        }

    }
fclose(f);
}
void eliminar_ficheroa(FILE *f,FILE *aux, Almacen w)
{
   int i, pos;
   char co[10];
   if((f=fopen("almacen.dat", "r+b"))==NULL || (aux=fopen("almacen_aux.dat","w+b"))==NULL){
       cout<<"error en apertura de alguno de los archivos\n";
   }
   else
   {
       cout<<"Ingrese el codigo del articulo a Eliminar: ";
       cin>>co;
       fread(&w,sizeof(w),1,f);
       while(!feof(f))
       {
           if(strcmp(co,w.codigo)==0)
           {
               cout<<"El Sigiente codigo se eliminara del fichero:\n";
               cout<<"Codigo: "; cout<<w.codigo<<endl;
               cout<<"Los datos fueron ELIMINADOS correctamente\n";
           }
           else{
                fwrite(&w, sizeof(w),1, aux);
                }
            fread(&w,sizeof(w),1,f);
       }
   }
   fclose(f);
   fclose(aux);
   f=fopen("almacen.dat", "wb");
   aux=fopen("almacen_aux.dat","rb");
	if((f==NULL) || (aux==NULL))
	{
		cout<<"error en apertura";
	}
	else
	{
		fread(&w,sizeof(w),1,aux);
		while(!feof(aux))
		{
			fwrite(&w,sizeof(w),1,f);
			fread(&w,sizeof(w),1,aux);
			cout<<"Hola"<<endl;
		}
	}
	fclose(f);
	fclose(aux);
}


void modificar_ficheroa (FILE *f, Almacen w)
{
    int i, pos;
   char co[10];
   bool bandera = false;
   if((f=fopen("almacen.dat", "r+b"))==NULL)
   {
       cout<<"error en apertura";
   }
   else
   {
       cout<<"Ingrese el codigo del articulo a modificar: ";
       cin>>co;
       fread(&w,sizeof(w),1,f);
       while(!feof(f) && bandera==false)
       {
           if(strcmp(co,w.codigo)==0)
           {
               cout<<"Los datos que puede modificar son:\n";
               cout<<"Precio: "; cin>>w.precio;
               cout<<"Stock: ";;cin>>w.stock;
               pos=ftell(f)-sizeof(w);
               fseek(f, pos, SEEK_SET);
               fwrite(&w, sizeof(w),1,f);
               bandera=true;
               cout<<"Los datos fueron modificados correctamente\n";
               break;
           }
           fread(&w,sizeof(w),1,f);
       }
       if(bandera==false)
       {
           cout<<"No se encontro el codigo."<<endl;
       }
   }
   fclose(f);
}


void reporteComida()
{
	string ji;
	int ni,n;

	FILE *rest;
    restaurant o;
	do{
	    menu_alimentos();
        cin>>ni;
        switch(ni)
        {
        case 1:
            FILE *arch;
            FILE *copi;
            Almacen w;
            int op;

            do
            {
                menualmacen();
                cin>>op;
                switch (op)
                    {
                        case 1: guardar_datosa(arch, w); break;
                        case 2: leer_ficheroa(arch, w); break;
                        case 3: modificar_ficheroa(arch, w); break;
                        case 4: eliminar_ficheroa(arch, copi, w); break;
                        case 5: break;
                    }
            }while(op!=5);
            break;
        case 2:
            do{
                menucomidas();
                cin>>n;
                if(n==1)
                {
                    menugeneral();
                }
                if(n==2)
                {

                    do{
                        oferta();
                        cout<<"¿Desea ver la consistencia de otro combo?\n";
                        cout<<"Ingrese (si) o (no): ";cin>>ji;
                        if(ji!="no" && ji!="No" && ji!="NO") cout<<"\n\t\t\tIngrese nuevammente una opcion de los combos:\n";
                    }while(ji!="no" && ji!="No" && ji!="NO");
                }
                if (n==3) break;
                int op=0; //entra con cero y nos retorna con un valor valido
                setlocale(LC_ALL, "spanish");
                do{
                    menu(op);
                    switch(op){
                        case 1: escribir_pedido(rest, o); break;
                        case 2: mostrar_pedido(rest, o); break;
                        case 3: cout<<"Su orden fue guardada :D\n";break;
                        }
                }while(op!=3);
                cout<<"¿Quiere seguir ordenando?\n";
                cout<<"ingrese (si) o (no)\n";
                cin>>ji;
                if(ji=="no")
                {
                    cout<<"\n\t\t\tFACTURACIÓN DEL PEDIDO\n";
                    facturita(rest, o);
                }
            }while(ji=="si");

            break;
        case 3:
            break;
        }
	}while(ni!=3);
}

int main()
{
    system("color 70");
    detalle_cliente_diez = new float [10];
	setlocale(LC_ALL,"spanish");
	int op;
	nombre();
	do{
		menusito();
		cin>>op;
		cout<<endl;
		switch(op)
		{
			case 1:
				reporteEmpleados();
				break;
			case 2:
				reporteComida();
				break;
			case 3:break;
			default:cout<<"\n\3 Ingrese una opción valida \3 \n\n"; break;
		}
	}while(op!=3);
	return 0;
}

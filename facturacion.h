#ifndef FACTURACION_H_INCLUDED
#define FACTURACION_H_INCLUDED

#include <iostream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <locale.h>
using namespace std;
//COLA PARA EL EMPLEADO DEL MES
struct nodo{
int dato;
nodo *sig;
};

struct nodo_caracter{
char dato[100];
nodo *sig;
};

bool cola_vacia(nodo *frente){
if(frente==NULL)return true;
else return false;
}

void push(nodo *&frente, nodo *&fin,int valor){
nodo *nuevo_nodo= new nodo();
nuevo_nodo->dato=valor;
nuevo_nodo->sig=NULL;
if (cola_vacia(frente)==true){
    frente=nuevo_nodo;
}
else
{
  fin->sig= nuevo_nodo;
}
fin=nuevo_nodo;
}
void pop(nodo *&frente, nodo *&fin,int &valor){
nodo *aux=frente;
valor = aux->dato;
if(frente==fin){
    frente=NULL;
    fin=NULL;

}
else{
    frente=frente->sig;
}
delete aux;
}
#endif // FACTURACION_H_INCLUDED

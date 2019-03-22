//
// Created by WilliamPC on 21/3/2019.
//


#include "Nodo.h"


Nodo::Nodo() : mes(-1), siguiente(0)
{
}

Nodo::Nodo(int d, int m) : mes{m}, dia(d), siguiente(0)
{
}


bool ListaEnlazadaSimple::esVacia() {
    return primero==0;
}

void ListaEnlazadaSimple::agregar(int d ,int m) {
    Nodo *nuevo=new Nodo;

    if(esVacia()){
        primero=nuevo;
        ultimo=nuevo;
    }else{
        ultimo=nuevo;
    }
}
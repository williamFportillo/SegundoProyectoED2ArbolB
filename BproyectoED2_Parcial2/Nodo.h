//
// Created by WilliamPC on 21/3/2019.
//

#ifndef BPROYECTOED2_PARCIAL2_NODO_H
#define BPROYECTOED2_PARCIAL2_NODO_H

struct arbol{
    int mes;
    int anio;
    //Nodo *sig;
};

class Nodo {
public:
    Nodo();
    Nodo(int,int);
    int mes;
    int dia;
    int anio;
    Nodo * siguiente;
    void setValor(int);
    int getValor();
    void setSiguiente(Nodo *);
    Nodo * getSiguiente();
};


class ListaEnlazadaSimple {
private:
    Nodo *primero;
    Nodo *ultimo;
public:
    void agregar(int,int);
    bool esVacia();
};


#endif //BPROYECTOED2_PARCIAL2_NODO_H

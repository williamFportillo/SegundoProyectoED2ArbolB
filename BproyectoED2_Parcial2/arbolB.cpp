//
// Created by WilliamPC on 21/3/2019.
//



#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "arbolB.h"

BTreeNode::BTreeNode(int t1, bool leaf1){
    nTeclas = t1;
    hoja = leaf1;

    clavesN = new Nodo[2*nTeclas-1];
    arrPaginas = new BTreeNode *[2*nTeclas];

    nLlaves = 0;
}
BTreeNode *BTreeNode::search(int k , int j , int h) {
    int i = 0 , i2=0;
    while (i < nLlaves && h > clavesN[i].anio){
        i++;
    }


    if (clavesN[i].anio==h) {
        while (i < nLlaves && j > clavesN[i].mes){
            i++;

        }
        if(clavesN[i].mes ==j)
            return this;

    }
    if (hoja == true)
        return NULL;

    return arrPaginas[i]->search(k , j,  h);
}
void BTreeNode::insertNonFull(Nodo nodo) {
    int i = nLlaves-1;
    if (hoja == true) {
        while(i >=0 && clavesN[i].anio > nodo.anio || clavesN[i].mes > nodo.mes){
            clavesN[i + 1] = clavesN[i];
            i--;

        }
        clavesN[i+1] = nodo;
        nLlaves = nLlaves+1;
    } else{
        while (i>=0 &&clavesN[i].anio > nodo.anio || clavesN[i].mes > nodo.mes)
            i--;

        if (arrPaginas[i+1]->nLlaves == 2*nTeclas-1) {
            splitChild(i+1, arrPaginas[i+1]);
            if (  clavesN[i+1].anio < nodo.anio||clavesN[i+1].mes < nodo.mes)
                i++;
        }
        arrPaginas[i+1]->insertNonFull(nodo);
    }
}
void BTreeNode::splitChild(int i, BTreeNode *actual) {
    BTreeNode *nuevo = new BTreeNode(actual->nTeclas, actual->hoja);
    nuevo->nLlaves = nTeclas - 1;

    for (int j = 0; j < nTeclas-1; j++)
        nuevo->clavesN[j] = actual->clavesN[j+nTeclas];

    if (actual->hoja == false) {
        for (int j = 0; j < nTeclas; j++)
            nuevo->arrPaginas[j] = actual->arrPaginas[j+nTeclas];
    }

    actual->nLlaves = nTeclas - 1;
    for (int j = nLlaves; j >= i+1; j--)
        arrPaginas[j+1] = arrPaginas[j];

    arrPaginas[i+1] = nuevo;

    for (int j = nLlaves-1; j >= i; j--)
        clavesN[j+1] = clavesN[j];

    clavesN[i]= actual->clavesN[nTeclas-1];

    nLlaves = nLlaves + 1;
}
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < nLlaves; i++) {
        if(hoja == false) {
            arrPaginas[i]->traverse();
        }
        cout  <<"Dia: "<<clavesN[i].dia<< "  Mes: " << clavesN[i].mes <<"  Año: "<<clavesN[i].anio<<"\n";
    }
    if (hoja == false) {
        arrPaginas[i]->traverse();
    }
}

void BTree::insert(int k) {
    ifstream data("data.dat", ios::in | ios::binary);
    if (!data) {
        cout << "Error al intentar abrir el archivo Empleados.dat" << endl;
        return;
    }

    int cont = 0;
    invoice temporal;
    data.seekg(0, ios::beg);
    data.read(reinterpret_cast<char *>(&temporal), sizeof(invoice));
    Nodo nodo;
    while (k!=cont) {
        nodo.dia=temporal.day;
        nodo.mes=temporal.month;
        nodo.anio=temporal.year;

        if (root == NULL) {
            root = new BTreeNode(nTecla2, true);
            root->clavesN[0]=nodo;
            root->nLlaves = 1;

        } else {
            if (root->nLlaves == 2 * nTecla2 - 1) {
                BTreeNode *nuevaRaiz = new BTreeNode(nTecla2, false);

                nuevaRaiz->arrPaginas[0] = root;

                nuevaRaiz->splitChild(0, root);

                int i = 0;
                if (nuevaRaiz->clavesN[0].anio < nodo.anio || nuevaRaiz->clavesN[0].mes < nodo.mes )
                    i++;
                nuevaRaiz->arrPaginas[i]->insertNonFull(nodo);
                root = nuevaRaiz;
            } else
                root->insertNonFull(nodo);
        }

        cout<<"Factura "<< cont <<" { codigo:" << temporal.code << ", Nombre:" << temporal.name << ", Salario: " << temporal.invoice_code
            << ", Fecha: " << temporal.date << ", Mes:" << temporal.day << ", Dia:" << temporal.month << ", Anio:" << temporal.year<< ", Tipo Pago:"
            << temporal.payment_type << ", Total:" << temporal.total << ", Nombre Negocio:" << temporal.business_name << ", Tipo Negocio:" << temporal.business_type
            <<" "+ sizeof(invoice) << "}\n\n";

        data.read(reinterpret_cast<char *>(&temporal), sizeof(invoice));
        cont++;
    }
    data.close();
}
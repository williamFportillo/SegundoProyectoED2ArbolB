//
// Created by WilliamPC on 21/3/2019.
//

#ifndef BPROYECTOED2_PARCIAL2_ARBOLB_H
#define BPROYECTOED2_PARCIAL2_ARBOLB_H


#include <iostream>
#include "Nodo.h"

using namespace std;

struct invoice{
    int code; //4
    char name[25]; //25
    char invoice_code[12]; //12
    char date[12]; //12
    short int day;  //2
    short int month; //2
    short int year; //2
    char payment_type[12]; //12
    double total; //8
    char business_type[20]; //20
    char business_name[60]; //60
}; //160

class BTreeNode{
    Nodo *clavesN;
    int nTeclas;
    BTreeNode **arrPaginas;
    int nLlaves;
    bool hoja;
    Nodo * dias , diasRepetidos;
public:
    BTreeNode(int _t, bool _leaf);
    void insertNonFull(Nodo nodo);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k , int , int);

    friend class BTree;
};

class BTree{
    BTreeNode *root;
    int nTecla2;
public:
    BTree(int _t){
        root = NULL;  nTecla2 = _t;
    }
    void traverse(){
        if (root != NULL) {
            root->traverse();
        }
    }
    BTreeNode* search(int k , int j , int l){
        return (root == NULL)? NULL : root->search(k, j , l);
    }
    void insert(int k);
};
#endif //BPROYECTOED2_PARCIAL2_ARBOLB_H

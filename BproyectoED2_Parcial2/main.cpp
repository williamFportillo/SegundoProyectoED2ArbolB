#include <cstdlib>
#include <iostream>
#include "arbolB.h"

using namespace std;

int main(){
    int val, opc, max;
    MM:
    cout<<"LLaves por paginas: ";
    cin>>max;
    if(max<=2) {
        cout << "Valor Invalido...\n";
        goto MM;
    }
    BTree t(max);

    do {
        cout<<"[1] Insertar\n";
        cout<<"[2] Buscar\n";
        cout<<"[3] Impresion (Inorden)\n";
        cout<<"[4] Salir\n Opcion: ";
        cin >> opc;
        cout << endl;

            if(opc==1) {
                cout << "Cuantos registro desea insertar:";
                cin >> val;
                t.insert(val);
            }
            if(opc==2) {
                int m, a;
                cout << "Dia:";
                cin >> val;
                cout << "Mes: ";
                cin >> m;
                cout << "Anio: ";
                cin >> a;
                (t.search(val, m, a) != NULL) ? cout << "\nExiste" : cout << "\nNo Existe";
                cout << endl;
            }
            if(opc==3) {
                t.traverse();
                cout << endl;
            }
            if(opc==4)
                return 0;

        cout << endl;
    }while(true);
}
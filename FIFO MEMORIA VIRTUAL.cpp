#include <iostream>
#include <queue>
#include <vector>
#include "NeriSosa.h"
#include <ctime>

using namespace std;

int main() {
    int capacidad_memoria, regis; 
    queue<int> memoria_virtual; 
    cout<<"Introduzca el numero de frames: ";cin>>capacidad_memoria;cout<<endl;
	cout<<"Introduzca el numero de registros de pagina: ";cin>>regis;
    int referencias_arr[regis];
    
    srand(time(NULL));
    for(int i=0;i<regis;i++){
		cin>>referencias_arr[i]; //= rand() % 10;
		cout<<referencias_arr[i]<<"  ";
	}
	cout<<endl;
	
	

    //int referencias_arr[] = {1, 1, 3, 4, 5, 6, 7, 7, 9, 10};
    vector<int> referencias(referencias_arr, referencias_arr + sizeof(referencias_arr) / sizeof(referencias_arr[0]));

    double fallos_pagina = 0;
    double hits_pagina = 0;

    for (size_t i = 0; i < referencias.size(); i++) {
        int pagina = referencias[i];
        bool pagina_en_memoria = false;
        queue<int> copia_memoria_virtual = memoria_virtual;

        while (!copia_memoria_virtual.empty()) {
            if (copia_memoria_virtual.front() == pagina) {
                pagina_en_memoria = true;
                hits_pagina++; 
                break;
            }
            copia_memoria_virtual.pop();
        }
        if (!pagina_en_memoria) {
            fallos_pagina++;

            if (memoria_virtual.size() >= capacidad_memoria) {
                int pagina_reemplazada = memoria_virtual.front();
                memoria_virtual.pop();
                //cout << "Reemplazada pagina " << pagina_reemplazada << " por pagina " << pagina << endl;
            }

            memoria_virtual.push(pagina);
            //cout << "Pagina " << pagina << " cargada en memoria virtual" << endl;
        }
        if (i == referencias.size() - 1) {
            cout << "Estado final de la memoria virtual: ";
            queue<int> copia_estado_memoria = memoria_virtual;
            while (!copia_estado_memoria.empty()) {
                cout << copia_estado_memoria.front() << " ";
                copia_estado_memoria.pop();
            }
            cout << endl;
        }
    }
	
	double pm = (fallos_pagina / regis) * (100.0);
	double ph = (hits_pagina/ regis) * (100.0);
	
	
    cout << "Numero total de page default de pagina: " << fallos_pagina << endl;
    cout << "Numero total de hits de pagina: " << hits_pagina << endl;
    cout << "Page miss: "<< pm <<" %"<<endl;
	cout << "Hits Ratio: "<< ph <<" %"<<endl;
    return 0;
}


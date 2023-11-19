#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include "NeriSosa.h"
using namespace std;

int main() {
    int capacidad_memoria, regis = 3;
    cout << "Introduzca el numero de frames: ";
    cin >> capacidad_memoria;
    cout << endl;
    //cout << "Introduzca el numero de registros de pagina: ";
    //cin >> regis;
    //int referencias_arr[regis];

    /*srand(time(NULL));
    for (int i = 0; i < regis; i++) {
    	//referencias_arr[i] = rand() % 10;
        cin >> referencias_arr[i];
        cout << referencias_arr[i] << "  ";
    }
    cout << endl;*/


	
    //int referencias_arr[] = {8,7,4,7,5,0,5,2,7,8,9,0,7,6,2,3};
    int referencias_arr[] = {8,7,4};
    vector<int> referencias(referencias_arr, referencias_arr + sizeof(referencias_arr) / sizeof(referencias_arr[0]));

    double fallos_pagina = 0;
    double hits_pagina = 0;

    vector<int> memoria_virtual;
    
    for (size_t i = 0; i < referencias.size(); i++) {
        int pagina = referencias[i];
        bool pagina_en_memoria = false;

        for (size_t j = 0; j < memoria_virtual.size(); j++) {
            if (memoria_virtual[j] == pagina) {
                pagina_en_memoria = true;
                hits_pagina++;
               
                int temp = memoria_virtual[j];
                memoria_virtual.erase(memoria_virtual.begin() + j);
                memoria_virtual.insert(memoria_virtual.begin(), temp);
                break;
            }
        }

        if (!pagina_en_memoria) {
            fallos_pagina++;

            if (memoria_virtual.size() >= capacidad_memoria) {
                
                memoria_virtual.pop_back();
            }
            memoria_virtual.insert(memoria_virtual.begin(), pagina);
        }

        if (i == referencias.size() - 1) {
            cout << "Estado final de la memoria virtual: ";
            for (const int& p : memoria_virtual) {
                cout << p << " ";
            }
            cout << endl;
        }
    }

    double pm = (fallos_pagina / regis) * (100.0);
    double ph = (hits_pagina / regis) * (100.0);

    cout << "Numero total de page faults de pagina: " << fallos_pagina << endl;
    cout << "Numero total de hits de pagina: " << hits_pagina << endl;
    cout << "Page miss: " << pm << " %" << endl;
    cout << "Hits Ratio: " << ph << " %" << endl;
    return 0;
}


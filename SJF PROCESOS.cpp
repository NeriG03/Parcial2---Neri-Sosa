#include <iostream>
#include <vector>
#include <algorithm>
#include "NeriSosa.h"
using namespace std;

struct Proceso {
    string nombre;
    int tiempo_llegada;
    int tiempo_ejecucion;
    int tiempo_inicio;
    int tiempo_final;
    int tiempo_espera;
};

int main() {
    color(14);
    int n = 4;
    //cout << "Ingrese la cantidad de procesos: ";
    //cin >> n;
    
    vector<Proceso> procesos(n);
    
   /*for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del proceso " << i + 1 << ": ";
        cin >> procesos[i].nombre;
        cout << "Ingrese el tiempo de llegada del proceso " << i + 1 << ": ";
        cin >> procesos[i].tiempo_llegada;
        cout << "Ingrese el tiempo de ejecucion del proceso " << i + 1 << ": ";
        cin >> procesos[i].tiempo_ejecucion;
    }*/
    
    procesos[0] = {"A", 0, 4, 0, 0, 0};
    procesos[1] = {"B", 1, 5, 0, 0, 0};
    procesos[2] = {"C", 2, 3, 0, 0, 0};
    procesos[3] = {"D", 3, 2, 0, 0, 0};
    
    /*procesos[0] = {"JAVA", 3, 7, 0, 0, 0};
    procesos[1] = {"APACHE", 4, 5, 0, 0, 0};
    procesos[2] = {"ECLIPSE", 5, 9, 0, 0, 0};
    procesos[3] = {"XAMPP", 6, 4, 0, 0, 0};
    procesos[4] = {"EXCEL", 0, 5, 0, 0, 0};*/
    

    sort(procesos.begin(), procesos.end(), [](const Proceso& a, const Proceso& b) {
        return a.tiempo_llegada < b.tiempo_llegada;
    });

    int tiempo_actual = 0;
    double tiempo_servicio_total = 0;
    double tiempo_espera_total = 0;
    
    for (int i = 0; i < n; i++) {
        if (tiempo_actual < procesos[i].tiempo_llegada) {
            tiempo_actual = procesos[i].tiempo_llegada;
        }

        
        int proceso_mas_corto = i;
        for (int j = i + 1; j < n; j++) {
            if (procesos[j].tiempo_llegada <= tiempo_actual && procesos[j].tiempo_ejecucion < procesos[proceso_mas_corto].tiempo_ejecucion) {
                proceso_mas_corto = j;
            }
        }

        
        swap(procesos[i], procesos[proceso_mas_corto]);

        procesos[i].tiempo_inicio = tiempo_actual;
        procesos[i].tiempo_final = tiempo_actual + procesos[i].tiempo_ejecucion;
        procesos[i].tiempo_espera = procesos[i].tiempo_inicio - procesos[i].tiempo_llegada;

        tiempo_actual = procesos[i].tiempo_final;

        cout << "Nombre del proceso " << i + 1 << ": " << procesos[i].nombre << endl;
        cout << "Tiempo de llegada del proceso " << i + 1 << ": " << procesos[i].tiempo_llegada << endl;
        //cout << "Tiempo en CPU (de ejecucion) del proceso " << i + 1 << ": " << procesos[i].tiempo_ejecucion << endl;
        //cout << "Tiempo de servicio del proceso " << i + 1 << ": " << (procesos[i].tiempo_final - procesos[i].tiempo_llegada) << endl;
        cout << "Tiempo en el que termina el proceso " << i + 1 << ": " << procesos[i].tiempo_final << endl;
        //cout << "Tiempo de espera del proceso " << i + 1 << ": " << procesos[i].tiempo_espera  << endl << endl;
        
        tiempo_servicio_total += procesos[i].tiempo_final - procesos[i].tiempo_llegada;
        tiempo_espera_total += procesos[i].tiempo_espera;
    }
    
    double promedio_tiempo_servicio = tiempo_servicio_total / n;
    double promedio_tiempo_espera = tiempo_espera_total / n;

    cout << "Promedio de tiempo de servicio: " << promedio_tiempo_servicio << endl;
    cout << "Promedio de tiempo de espera: " << promedio_tiempo_espera << endl;

    return 0;
}




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
    int n;
    cout << "Ingrese el numero de procesos: ";
    cin >> n;

    vector<Proceso> procesos(n);
    
    /*procesos[0] = {"WORD", 2, 3, 0, 0, 0};
    procesos[1] = {"POWER", 7, 5, 0, 0, 0};
    procesos[2] = {"EXCEL", 0, 4, 0, 0, 0};
    procesos[3] = {"JAVA", 3, 7, 0, 0, 0};
    procesos[4] = {"ECLIPSE", 4, 5, 0, 0, 0};*/

    for (int i = 0; i < n; i++) {
        cout << "Nombre del proceso " << i + 1 << ": ";
        cin >> procesos[i].nombre;
        cout << "Tiempo de llegada del proceso " << i + 1 << ": ";
        cin >> procesos[i].tiempo_llegada;
        cout << "Tiempo en CPU (de ejecucion) del proceso " << i + 1 << ": ";
        cin >> procesos[i].tiempo_ejecucion;
    }
    
    system("pause");
    system("cls");

    sort(procesos.begin(), procesos.end(), [](const Proceso& a, const Proceso& b) {
        return a.tiempo_llegada < b.tiempo_llegada;
    });

    int tiempo_actual = 0;
    float SUMTE = 0;
    float SUMTR = 0;
    for (int i = 0; i < n; i++) {
        if (tiempo_actual < procesos[i].tiempo_llegada) {
            tiempo_actual = procesos[i].tiempo_llegada;
        }

        procesos[i].tiempo_inicio = tiempo_actual;
        procesos[i].tiempo_final = tiempo_actual + procesos[i].tiempo_ejecucion;
        procesos[i].tiempo_espera = procesos[i].tiempo_inicio - procesos[i].tiempo_llegada;

        tiempo_actual = procesos[i].tiempo_final;

        cout << "Nombre del proceso " << i + 1 << ": " << procesos[i].nombre << endl;
        cout << "Tiempo de llegada del proceso " << i + 1 << ": " << procesos[i].tiempo_llegada << endl;
        cout << "Tiempo en CPU (de ejecucion) del proceso " << i + 1 << ": " << procesos[i].tiempo_ejecucion << endl;
        cout << "Tiempo en que inicia el proceso " << i + 1 << ": " << procesos[i].tiempo_inicio << endl;
        cout << "Tiempo en el que termina el proceso " << i + 1 << ": " << (procesos[i].tiempo_final - 1) << endl;
        cout << "Tiempo de espera del proceso " << i + 1<< ": " << procesos[i].tiempo_espera  << endl << endl;
        
        SUMTE += procesos[i].tiempo_espera;
        SUMTR += (procesos[i].tiempo_final - 1);
    }
    
    float TE = SUMTE / n;
    float TR = SUMTR / n;
    
    
    cout<<"El promedio del tiempo de espera es: ";color(12);cout << TE << endl;
    color(14);cout<<"El promedio del tiempo de respuesta es: ";color(12);cout << TR;
    
    
    return 0;
}







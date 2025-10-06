#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Resultado {
    double maximo;
    double minimo;
    int posicion_max;
    int posicion_min;
};

Resultado encontrarMaxMin(const vector<double>& arreglo) {
    if (arreglo.empty()) {
        throw invalid_argument("El arreglo no puede estar vacio");
    }
    
    Resultado resultado;
    resultado.maximo = arreglo[0];
    resultado.minimo = arreglo[0];
    resultado.posicion_max = 0;
    resultado.posicion_min = 0;
    
    for (int i = 1; i < arreglo.size(); i++) {
        if (arreglo[i] > resultado.maximo) {
            resultado.maximo = arreglo[i];
            resultado.posicion_max = i;
        }
        if (arreglo[i] < resultado.minimo) {
            resultado.minimo = arreglo[i];
            resultado.posicion_min = i;
        }
    }
    
    return resultado;
}

int main() {
    int n;
    cout << "=== BUSQUEDA DE MAXIMO Y MINIMO === <3" << endl;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: El tamaño debe ser mayor a cero" << endl;
        return 1;
    }
    
    vector<double> numeros(n);
    cout << "Ingrese " << n << " numeros decimales:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> numeros[i];
    }
    
    try {
        Resultado resultado = encontrarMaxMin(numeros);
        
        cout << "\n=== RESULTADOS ===" << endl;
        cout << "Valor maximo: " << resultado.maximo << " en la posicion " << resultado.posicion_max << endl;
        cout << "Valor minimo: " << resultado.minimo << " en la posicion " << resultado.posicion_min << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
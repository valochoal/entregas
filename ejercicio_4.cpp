#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Normas {
    double L1;
    double L2;
};

Normas calcularNormas(const vector<double>& arreglo) {
    if (arreglo.empty()) {
        throw invalid_argument("El arreglo no puede estar vacio");
    }
    
    Normas resultado;
    resultado.L1 = 0.0;
    resultado.L2 = 0.0;
    
    // Calcular norma L1 (suma de valores absolutos)
    for (double valor : arreglo) {
        resultado.L1 += abs(valor);
    }
    
    // Calcular norma L2 (raíz cuadrada de la suma de cuadrados)
    for (double valor : arreglo) {
        resultado.L2 += valor * valor;
    }
    resultado.L2 = sqrt(resultado.L2);
    
    return resultado;
}

// Función sobrecargada para matrices (vector de vectores)
Normas calcularNormasMatriz(const vector<vector<double>>& matriz) {
    if (matriz.empty() || matriz[0].empty()) {
        throw invalid_argument("La matriz no puede estar vacia");
    }
    
    Normas resultado;
    resultado.L1 = 0.0;
    resultado.L2 = 0.0;
    
    // Tratar la matriz como un vector plano
    for (const auto& fila : matriz) {
        for (double valor : fila) {
            resultado.L1 += abs(valor);
            resultado.L2 += valor * valor;
        }
    }
    resultado.L2 = sqrt(resultado.L2);
    
    return resultado;
}

int main() {
    int opcion;
    cout << "=== CALCULO DE NORMAS L1 Y L2 === <3" << endl;
    cout << "1. Vector (arreglo unidimensional)" << endl;
    cout << "2. Matriz (arreglo bidimensional)" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    
    try {
        if (opcion == 1) {
            int n;
            cout << "Ingrese el tamaño del vector: ";
            cin >> n;
            
            if (n <= 0) {
                cout << "Error: El tamaño debe ser mayor a cero" << endl;
                return 1;
            }
            
            vector<double> vector_datos(n);
            cout << "Ingrese " << n << " numeros decimales:" << endl;
            for (int i = 0; i < n; i++) {
                cout << "Elemento " << (i + 1) << ": ";
                cin >> vector_datos[i];
            }
            
            Normas resultado = calcularNormas(vector_datos);
            
            cout << "\n=== RESULTADOS ===" << endl;
            cout << fixed << setprecision(4);
            cout << "Norma L1: " << resultado.L1 << endl;
            cout << "Norma L2 (Euclidiana): " << resultado.L2 << endl;
            
        } else if (opcion == 2) {
            int filas, columnas;
            cout << "Ingrese el numero de filas: ";
            cin >> filas;
            cout << "Ingrese el numero de columnas: ";
            cin >> columnas;
            
            if (filas <= 0 || columnas <= 0) {
                cout << "Error: Las dimensiones deben ser mayores a cero" << endl;
                return 1;
            }
            
            vector<vector<double>> matriz(filas, vector<double>(columnas));
            cout << "Ingrese los elementos de la matriz " << filas << "x" << columnas << ":" << endl;
            
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    cout << "Elemento [" << i << "][" << j << "]: ";
                    cin >> matriz[i][j];
                }
            }
            
            Normas resultado = calcularNormasMatriz(matriz);
            
            cout << "\n=== RESULTADOS ===" << endl;
            cout << fixed << setprecision(4);
            cout << "Norma L1: " << resultado.L1 << endl;
            cout << "Norma L2 (Euclidiana): " << resultado.L2 << endl;
            
        } else {
            cout << "Opcion no valida" << endl;
            return 1;
        }
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
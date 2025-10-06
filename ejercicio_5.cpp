#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPSILON = 1e-10;

class MatrizCalculadora {
private:
    vector<vector<double>> matriz;
    int filas, columnas;
    
    // Función para calcular el determinante usando eliminación gaussiana
    double calcularDeterminante(vector<vector<double>> mat) {
        int n = mat.size();
        double det = 1.0;
        
        for (int i = 0; i < n; i++) {
            // Buscar el pivote más grande
            int maxRow = i;
            for (int k = i + 1; k < n; k++) {
                if (abs(mat[k][i]) > abs(mat[maxRow][i])) {
                    maxRow = k;
                }
            }
            
            // Intercambiar filas si es necesario
            if (maxRow != i) {
                swap(mat[i], mat[maxRow]);
                det *= -1;
            }
            
            // Si el elemento diagonal es cero, determinante es cero
            if (abs(mat[i][i]) < EPSILON) {
                return 0.0;
            }
            
            det *= mat[i][i];
            
            // Hacer ceros debajo del pivote
            for (int k = i + 1; k < n; k++) {
                double factor = mat[k][i] / mat[i][i];
                for (int j = i; j < n; j++) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
        
        return det;
    }
    
    // Función para calcular la inversa usando Gauss-Jordan
    vector<vector<double>> calcularInversa() {
        int n = filas;
        vector<vector<double>> aumentada(n, vector<double>(2 * n, 0.0));
        
        // Crear la matriz aumentada [A|I]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                aumentada[i][j] = matriz[i][j];
                aumentada[i][j + n] = (i == j) ? 1.0 : 0.0;
            }
        }
        
        // Aplicar eliminación de Gauss-Jordan
        for (int i = 0; i < n; i++) {
            // Buscar el pivote más grande
            int maxRow = i;
            for (int k = i + 1; k < n; k++) {
                if (abs(aumentada[k][i]) > abs(aumentada[maxRow][i])) {
                    maxRow = k;
                }
            }
            
            if (maxRow != i) {
                swap(aumentada[i], aumentada[maxRow]);
            }
            
            // Verificar si el pivote es cero
            if (abs(aumentada[i][i]) < EPSILON) {
                throw runtime_error("La matriz no tiene inversa (determinante = 0)");
            }
            
            // Normalizar la fila del pivote
            double pivote = aumentada[i][i];
            for (int j = 0; j < 2 * n; j++) {
                aumentada[i][j] /= pivote;
            }
            
            // Hacer ceros en la columna del pivote
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    double factor = aumentada[k][i];
                    for (int j = 0; j < 2 * n; j++) {
                        aumentada[k][j] -= factor * aumentada[i][j];
                    }
                }
            }
        }
        
        // Extraer la matriz inversa
        vector<vector<double>> inversa(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                inversa[i][j] = aumentada[i][j + n];
            }
        }
        
        return inversa;
    }
    
    // Función para calcular la pseudoinversa usando SVD simplificado
    vector<vector<double>> calcularPseudoInversa() {
        // Para matrices no cuadradas, calculamos A^T(AA^T)^-1 o (A^TA)^-1A^T
        if (filas > columnas) {
            // Matriz alta: pseudoinversa = (A^T * A)^-1 * A^T
            vector<vector<double>> At = transponer(matriz);
            vector<vector<double>> AtA = multiplicar(At, matriz);
            
            try {
                MatrizCalculadora calc;
                calc.matriz = AtA;
                calc.filas = calc.columnas = columnas;
                vector<vector<double>> AtA_inv = calc.calcularInversa();
                return multiplicar(AtA_inv, At);
            } catch (...) {
                throw runtime_error("No se puede calcular la pseudoinversa");
            }
        } else {
            // Matriz ancha: pseudoinversa = A^T * (A * A^T)^-1
            vector<vector<double>> At = transponer(matriz);
            vector<vector<double>> AAt = multiplicar(matriz, At);
            
            try {
                MatrizCalculadora calc;
                calc.matriz = AAt;
                calc.filas = calc.columnas = filas;
                vector<vector<double>> AAt_inv = calc.calcularInversa();
                return multiplicar(At, AAt_inv);
            } catch (...) {
                throw runtime_error("No se puede calcular la pseudoinversa");
            }
        }
    }
    
    vector<vector<double>> transponer(const vector<vector<double>>& mat) {
        int f = mat.size();
        int c = mat[0].size();
        vector<vector<double>> resultado(c, vector<double>(f));
        
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) {
                resultado[j][i] = mat[i][j];
            }
        }
        return resultado;
    }
    
    vector<vector<double>> multiplicar(const vector<vector<double>>& A, const vector<vector<double>>& B) {
        int f1 = A.size();
        int c1 = A[0].size();
        int c2 = B[0].size();
        
        vector<vector<double>> resultado(f1, vector<double>(c2, 0.0));
        
        for (int i = 0; i < f1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    resultado[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return resultado;
    }
    
public:
    void leerMatriz() {
        cout << "Ingrese el numero de filas: ";
        cin >> filas;
        cout << "Ingrese el numero de columnas: ";
        cin >> columnas;
        
        if (filas <= 0 || columnas <= 0) {
            throw invalid_argument("Las dimensiones deben ser mayores a cero");
        }
        
        matriz.resize(filas, vector<double>(columnas));
        
        cout << "Ingrese los elementos de la matriz " << filas << "x" << columnas << ":" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
        }
    }
    
    void procesarMatriz() {
        cout << "\n=== ANALISIS DE LA MATRIZ ===" << endl;
        
        // Verificar si es cuadrada
        if (filas != columnas) {
            cout << "La matriz no es cuadrada (" << filas << "x" << columnas << ")" << endl;
            cout << "Calculando pseudoinversa..." << endl;
            
            try {
                vector<vector<double>> pseudoinversa = calcularPseudoInversa();
                cout << "\nPseudoinversa calculada exitosamente:" << endl;
                imprimirMatriz(pseudoinversa);
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            return;
        }
        
        cout << "La matriz es cuadrada (" << filas << "x" << columnas << ")" << endl;
        
        // Calcular determinante
        double det = calcularDeterminante(matriz);
        cout << "Determinante: " << fixed << setprecision(6) << det << endl;
        
        if (abs(det) < EPSILON) {
            cout << "La matriz no tiene inversa porque su determinante es cero (matriz singular)" << endl;
            cout << "Esto significa que las filas/columnas son linealmente dependientes" << endl;
            
            cout << "\nCalculando pseudoinversa..." << endl;
            try {
                vector<vector<double>> pseudoinversa = calcularPseudoInversa();
                cout << "Pseudoinversa calculada exitosamente:" << endl;
                imprimirMatriz(pseudoinversa);
            } catch (const exception& e) {
                cout << "Error al calcular pseudoinversa: " << e.what() << endl;
            }
        } else {
            cout << "La matriz tiene inversa" << endl;
            
            try {
                vector<vector<double>> inversa = calcularInversa();
                cout << "\nMatriz inversa:" << endl;
                imprimirMatriz(inversa);
            } catch (const exception& e) {
                cout << "Error al calcular la inversa: " << e.what() << endl;
            }
        }
    }
    
    void imprimirMatriz(const vector<vector<double>>& mat) {
        cout << fixed << setprecision(4);
        for (const auto& fila : mat) {
            for (double elemento : fila) {
                cout << setw(10) << elemento << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== CALCULO DE INVERSA DE MATRIZ === <3" << endl;
    
    try {
        MatrizCalculadora calculadora;
        calculadora.leerMatriz();
        calculadora.procesarMatriz();
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
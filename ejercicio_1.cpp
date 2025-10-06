#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num1, num2;
    
    cout << "=== CALCULADORA BASICA <3 ===" << endl;
    cout << "Ingrese el primer numero entero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero entero: ";
    cin >> num2;
    
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Suma: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    cout << "Resta: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
    cout << "Multiplicacion: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
    
    // Manejo de división por cero
    if (num2 != 0) {
        cout << "Division: " << num1 << " / " << num2 << " = " << fixed << setprecision(2) 
             << (static_cast<double>(num1) / num2) << endl;
    } else {
        cout << "Division: No es posible dividir por cero" << endl;
    }
    
    return 0;
}
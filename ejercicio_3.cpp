#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int contarVocales(const string& cadena) {
    int contador = 0;
    string vocales = "aeiouAEIOU";
    
    for (char c : cadena) {
        if (vocales.find(c) != string::npos) {
            contador++;
        }
    }
    
    return contador;
}

void mostrarDetalleVocales(const string& cadena) {
    int contadores[5] = {0}; // a, e, i, o, u
    string vocales_lower = "aeiou";
    
    for (char c : cadena) {
        char lower_c = tolower(c);
        size_t pos = vocales_lower.find(lower_c);
        if (pos != string::npos) {
            contadores[pos]++;
        }
    }
    
    cout << "\nDetalle por vocal:" << endl;
    cout << "a: " << contadores[0] << endl;
    cout << "e: " << contadores[1] << endl;
    cout << "i: " << contadores[2] << endl;
    cout << "o: " << contadores[3] << endl;
    cout << "u: " << contadores[4] << endl;
}

int main() {
    string texto;
    
    cout << "=== CONTADOR DE VOCALES === <3" << endl;
    cout << "Ingrese una cadena de caracteres: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, texto);
    
    int totalVocales = contarVocales(texto);
    
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Cadena ingresada: \"" << texto << "\"" << endl;
    cout << "Numero total de vocales: " << totalVocales << endl;
    
    mostrarDetalleVocales(texto);
    
    return 0;
}
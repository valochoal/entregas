# Trabajo Práctico 01 - Programación Avanzada

## Universidad Nacional de Colombia, sede de La Paz

**Estudiantes:** Andrés Amaya, Jhoel Ospino y Valery Ochoa
**Profesor:** Ing. Mauro Baquero-Suárez
**Curso:** Programación Avanzada- Ingeniería Mecatrónica
**Fecha:** Octubre 2025

---

## Descripción del Proyecto

Este repositorio contiene las soluciones a los cinco ejercicios de repaso de programación en C++ correspondientes al primer trabajo práctico del curso **Programación Avanzada**.
Cada ejercicio aborda un problema diferente con un enfoque progresivo en complejidad algorítmica, estructura de datos y buenas prácticas de programación en C++ moderno.

---

## Estructura del Proyecto

```
Trabajo-Practico-01/
├── ejercicio1.cpp          # Operaciones básicas (10%)
├── ejercicio2.cpp          # Máximo y mínimo en arreglo (20%)
├── ejercicio3.cpp          # Contador de vocales (10%)
├── ejercicio4.cpp          # Normas L1 y L2 (20%)
├── ejercicio5.cpp          # Inversa de matriz (40%)
├── README.md               # Este archivo


---

## Compilación y Ejecución

### Requisitos

* Compilador compatible con C++11 o superior (g++, clang++, MinGW, etc.)
* Sistema operativo: Linux, Windows o macOS

### Compilación individual

```bash
g++ -std=c++11 -Wall -o ejercicio1 ejercicio1.cpp
g++ -std=c++11 -Wall -o ejercicio2 ejercicio2.cpp
g++ -std=c++11 -Wall -o ejercicio3 ejercicio3.cpp
g++ -std=c++11 -Wall -o ejercicio4 ejercicio4.cpp
g++ -std=c++11 -Wall -o ejercicio5 ejercicio5.cpp
```

### Ejecución

```bash
./ejercicio1
./ejercicio2
./ejercicio3
./ejercicio4
./ejercicio5

---
# Descripción de Cada Ejercicio

#  Ejercicio 1: Calculadora Básica (10%)

Archivo: `ejercicio1.cpp`
Funcionalidad: Solicita dos números enteros y realiza las operaciones básicas de suma, resta, multiplicación y división, manejando el caso de división por cero.
Metodología:

* Entrada de datos con `cin`
* Validación de división
* Resultados formateados con `setprecision()`

---

#  Ejercicio 2: Búsqueda de Máximo y Mínimo (20%)

Archivo: `ejercicio2.cpp`
Funcionalidad: Encuentra el valor máximo y mínimo de un arreglo de números decimales y sus posiciones.
Metodología:

* Uso de `std::vector<double>`
* Búsqueda lineal O(n)
* Manejo de excepciones y validación de entrada

---

# Ejercicio 3: Contador de Vocales (10%)

Archivo: `ejercicio3.cpp`
Funcionalidad: Cuenta el número total de vocales en una cadena, diferenciando mayúsculas y minúsculas.
Metodología:

* Manejo de cadenas con `std::string`
* Uso de funciones `find()` y `tolower()`
* Conteo total y por tipo de vocal

---

#  Ejercicio 4: Cálculo de Normas L1 y L2 (20%)

Archivo: `ejercicio4.cpp`
Funcionalidad: Calcula las normas L1 (Manhattan) y L2 (Euclidiana) de un vector o matriz.
Metodología:

* Cálculo de sumas absolutas y raíces cuadradas
* Implementación genérica para vectores y matrices
* Uso de estructuras para encapsular resultados

---

#  Ejercicio 5: Inversa de Matriz (40%)

Archivo: `ejercicio5.cpp`
Funcionalidad: Calcula la inversa de una matriz cuadrada o la pseudoinversa de matrices no cuadradas.
Metodología:

* Eliminación de Gauss-Jordan con pivoteo parcial
* Verificación de determinante
* Implementación de la pseudoinversa de Moore-Penrose
* Manejo de errores para matrices singulares

---

# Librerías Utilizadas

cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
#include <cctype>
```

---


# Ejemplo de Ejecución

# Ejercicio 3 - Contador de Vocales


=== CONTADOR DE VOCALES ===
Ingrese una cadena de caracteres: Programacion Avanzada

=== RESULTADOS ===
Cadena ingresada: "Programacion Avanzada"
Numero total de vocales: 8
Detalle por vocal:
a: 5
e: 0
i: 1
o: 2
u: 0
```

---

# Validaciones Implementadas

* División por cero
* Arreglos vacíos o de tamaño inválido
* Lectura robusta de cadenas con espacios
* Dimensiones válidas en vectores y matrices
* Manejo de matrices singulares o no cuadradas


## Notas Finales

* Todos los programas han sido probados con múltiples casos de prueba.
* El código sigue buenas prácticas de C++ moderno (uso de STL, const-correctness, manejo de errores).
* El proyecto busca fomentar la comprensión profunda de los algoritmos y estructuras base de la programación avanzada.


// AUTOR: Javier González Brito
// FECHA: 17/02/2023
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t


#include <iostream>
#include <cmath>
#include "rational_t.hpp"

using namespace std;

int main() { // Inicio de la función main
  Rational a(1, 2), b(1), c; //Inicializacion de los valores a, b y c

  cout << "a.value()= " << a.value() << endl; // Inprime el valor de a
  cout << "b.value()= " << b.value() << endl; // Inprime el valor de b
  cout << "c.value()= " << c.value() << endl; // Inprime el valor de c

  cout << "a: "; // Inprime el valor de a
  a.write();
  cout << "b: "; // Inprime el valor de b
  b.write();

  c.read(); //LLama al procedimiento read
  cout << "c: ";// Inprime el nuevo valor de c
  c.write();

  // FASE II
  Rational x(1, 3), y(2, 3); //Inicializacion de los valores x e y
  x.write(); // Imprime el valor de x
  y.write(); // Imprime el valor de y
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl; //Muestra en consola si el x es igual a la y
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl; // Muestra en consola si la x es más pequeña que la y
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl; // Muestra en consola si la x es más grande
  cout << "x == 0 " << (x.equal_cero(y) ? "true" : "false") << endl; //Muestra en consola si la x es igual a 0
  // FASE III
  cout << "a + b: "; // Esto muestra en consola el resultado de sumar a + b 
  a.add(b).write();
  cout << "b - a: "; // Esto muestra en consola el resultado de restar a - b
  b.substract(a).write();
  cout << "a * b: "; // Esto muestra en consola el resultado de multiplicar a * b 
  a.multiply(b).write(); 
  cout << "a / b: "; // Esto muestra en consola el resultado de dividir a entre b
  a.divide(b).write(); 
  
  return 0;
}
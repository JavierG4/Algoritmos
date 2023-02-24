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
  Rational a(1, 2), b(1), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  Rational x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl; //Muestra en consola si el x es igual a la y
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl; // Muestra en consola si la x es más pequeña que la y
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl; // Muestra en consola si la x es más grande

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
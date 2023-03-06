// AUTOR: Javier González Brtio
// FECHA: 03/03/2023
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g Rational.cpp main_p2.cpp -o main_p2

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main() {
  Rational a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a+b).write();

  cout << "b - a: ";
  (b-a).write();

  cout << "a * b: ";
  (a*b).write();
  
  cout << "a / b: ";
  (a/b).write();
  
  cout << endl;

  // FASE II
  Vector<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de Vector<double>: " << scal_prod(v, w) << endl << endl;
  
  Vector<Rational> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de Vector<Rational>: " << scal_prod(x, y) << endl << endl;
  
  // FASE III
  Matrix<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();
  
  return 0;
}


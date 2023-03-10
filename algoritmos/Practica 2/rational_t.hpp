// AUTOR: Javier González Brtio
// FECHA: 03/03/2023
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class Rational {
 public:
  Rational(const int = 0, const int = 1); // Constructor de la clase Rational
  ~Rational(){} // Destructor de la clase Rational
  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;
  Rational opposite(void) const;
  Rational reciprocal(void) const;

  bool is_equal(const Rational&, const double precision = EPSILON) const;
  bool is_greater(const Rational&, const double precision = EPSILON) const;
  bool is_less(const Rational&, const double precision = EPSILON) const;

  Rational add(const Rational&) const;
  Rational substract(const Rational&) const;
  Rational multiply(const Rational&) const;
  Rational divide(const Rational&) const;

  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private:
  int numerador_, denominador_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const Rational&);
istream& operator>>(istream& is, Rational&);

// FASE I: operadores
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

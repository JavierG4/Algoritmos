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

#include "rational_t.hpp"

Rational::Rational(const int numerador, const int denominador) { // Contructor de la clase Rational
  assert(denominador != 0);
  numerador_ = numerador, denominador_ = denominador;
}

inline int Rational::get_num() { // Retorna el valor del atributo
  return numerador_;
}

inline int Rational::get_den() { // Retorna el valor del atributo
  return denominador_;
}

void Rational::set_num(const int numerador) { // Procedimiento que asigna el valor del atributo de la clase a la variable
  numerador_ = numerador;
}

void Rational::set_den(const int denominador) { // Procedimiento que asigna el valor del atributo de la clase a la variable
  assert(denominador != 0);
  denominador_ = denominador;
}

inline double Rational::value() {  // Método que retorna el valor de la división entre el numerador y el denominador
  return double(get_num()) / get_den();
}

Rational Rational::opposite() {  // Función que devuelve el valor en negativo del obejeto de clase Rational
  return Rational((-1)*get_num(), get_den());
}

Rational Rational::reciprocal() { // Función que devuelve un valoe de clase rational en el que se intercambian el numerador y el denominador
  return Rational(get_den(), get_num());
}

// comparaciones
bool Rational::is_equal(const Rational& r, const double precision) { // Método que que te dice si son iguales
  return fabs(value() - r.value()) < precision;
}

bool Rational::is_greater(const Rational& r, const double precision) { // Método que que te dice si y es mayor que x
  return (value() - r.value()) > precision;
}

bool Rational::is_less(const Rational& r, const double precision) { // Método que que te dice si y es menor que la x
  return r.is_greater(*this, precision);
}

// operaciones
Rational Rational::add(const Rational& r) { // Método que devuelve la suma de a + b en forma de clase Rational
  return Rational(get_num() * r.get_den() + get_den() * r.get_num(), get_den() * r.get_den());
}

Rational Rational::substract(const Rational& r) { // Método que devuelve la resta de b-a en forma de clase Rational
  return add(r.opposite());
}

Rational Rational::multiply(const Rational& r) { // Método que devuelve la multiplicación de a * b en forma de clase Rational
  return Rational(get_num() * r.get_num(), get_den() * r.get_den());
}

Rational Rational::divide(const Rational& r) { // Método que devuelve la división entre a y b en forma de clase Rational
  return multiply(r.reciprocal());
}

// FASE I: operadores
Rational operator+(const Rational& a, const Rational& b) { // La suma mediante operadores de a y b
  return Rational((a.get_num() * b.get_den()) + (a.get_den() * b.get_num()), a.get_den() * b.get_den());
}

Rational operator-(const Rational& a, const Rational& b) { // La resta mediante operadores de a y b
  return Rational((a.get_num() * b.get_den()) - (b.get_num() * a.get_den()), a.get_den() * b.get_den());
}

Rational operator*(const Rational& a, const Rational& b) { // La multiplicación mediante operadores de a y b
  return Rational (b.get_num() * a.get_num(), a.get_den() * b.get_den());
}

Rational operator/(const Rational& a, const Rational& b) { // La división mediante operadores entre a y b
  return Rational (a.get_num() * b.get_den(), a.get_den() * b.get_num());
}

// E/S
void Rational::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void Rational::read(istream& is) { //Procedimiento que recoge el valor de  numerador y denominador
  is >> numerador_ >> denominador_;
  assert(denominador_ != 0);
}

ostream& operator<<(ostream& os, const Rational& r) {
  r.write(os);
  return os;
}

istream& operator>>(istream& is, Rational& r) {
  r.read(is);
  return is;
}
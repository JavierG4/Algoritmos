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

Rational::Rational(const int numerador, const int denominador) {
  assert(denominador != 0);
  numerador_ = numerador, denominador_ = denominador;
}

inline int Rational::get_num() {
  return numerador_;
}

inline int Rational::get_den() {
  return denominador_;
}

void Rational::set_num(const int numerador) {
  numerador_ = numerador;
}

void Rational::set_den(const int denominador) {
  assert(denominador != 0);
  denominador_ = denominador;
}

inline double Rational::value() { 
  return double(get_num()) / get_den();
}

Rational Rational::opposite() { 
  return Rational((-1)*get_num(), get_den());
}

Rational Rational::reciprocal() { 
  return Rational(get_den(), get_num());
}

// comparaciones
bool Rational::is_equal(const Rational& r, const double precision) { 
  return fabs(value() - r.value()) < precision;
}

bool Rational::is_greater(const Rational& r, const double precision) {
  return (value() - r.value()) > precision;
}

bool Rational::is_less(const Rational& r, const double precision) {
  return r.is_greater(*this, precision);
}

// operaciones
Rational Rational::add(const Rational& r) {
  return Rational(get_num() * r.get_den() + get_den() * r.get_num(), get_den() * r.get_den());
}

Rational Rational::substract(const Rational& r) {
  return add(r.opposite());
}

Rational Rational::multiply(const Rational& r) {
  return Rational(get_num() * r.get_num(), get_den() * r.get_den());
}

Rational Rational::divide(const Rational& r) {
  return multiply(r.reciprocal());
}


// FASE I: operadores
Rational operator+(const Rational& a, const Rational& b) {
  // rellenar código
}

Rational operator-(const Rational& a, const Rational& b) {
  // rellenar código
}

Rational operator*(const Rational& a, const Rational& b) {
  // rellenar código
}

Rational operator/(const Rational& a, const Rational& b) {
  // rellenar código
}

// E/S
void Rational::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void Rational::read(istream& is) {
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
// AUTOR: Javier González Brito
// FECHA: 17/02/2023
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include "rational_t.hpp"

Rational::Rational(const int numerador, const int denominador) { //Contructor de la clase Rational
  assert(denominador != 0);
  numerador_ = numerador, denominador_ = denominador;
}

const int Rational::get_numerador() { // Retorna el valor del atributo
  return numerador_;
}

const int Rational::get_denominador() { // Retorna el valor del atributo
  return denominador_;
}

void Rational::set_numerador(const int numerador) { // Procedimiento que asigna el valor del atributo de la clase a la variable
  numerador_ = numerador;
}

void Rational::set_denominador(const int denominador) { // Procedimiento que asigna el valor del atributo de la clase a la variable
  assert(denominador != 0);
  denominador_ = denominador;
}

const double Rational::value() { // Método que retorna el valor de la división entre el numerador y el denominador
  return double(get_numerador()) / get_denominador(); 
}

bool Rational::is_equal(Rational& r, const double precision) { // Método que que te dice si son iguales
  bool result = fabs (value() - r.value()) < precision ;
  return result;
}

bool Rational::is_greater(Rational& r, const double precision) { // Método que que te dice si y es mayor que x
  bool result = (r.value() - value()) > precision;
  return result;
}

bool Rational::is_less(Rational& r, const double precision) { // Método que que te dice si y es menor que la x
  bool result = (value() - r.value()) > precision;
  return result;
}

bool Rational::equal_cero(Rational& r, const double precision) {// Método booleana que indica si la primera fracción es igual a cero
  bool result = fabs(value()) < precision;
  return result;
}

//fase 3
Rational Rational::add(Rational& r) { // Método que devuelve la suma de a + b en forma de clase Rational
  return Rational ((numerador_ * r.get_denominador()) + (denominador_ * r.get_numerador()), denominador_ * r.get_denominador());
}

Rational Rational::substract(Rational& r) { // Método que devuelve la resta de b-a en forma de clase Rational
  return Rational ((numerador_ * r.get_denominador()) - (get_numerador() * denominador_) , denominador_ * r.get_denominador());
}

Rational Rational::multiply(Rational& r) { // Método que devuelve la multiplicación en forma de clase Rational
  return Rational ((get_numerador() * numerador_ ), denominador_ * r.get_denominador());
}

Rational Rational::divide(Rational& r) { // Método que devuelve la suma de a + b en forma de clase Rational
  return Rational (denominador_ * get_numerador(),numerador_ * get_denominador());
}

void Rational::write() { // Procedimiento que imprime en pantalla la divison entre el num y el denominador y su resultado
  cout << get_numerador() << "/" << get_denominador() << "=" << value() << endl;
}

void Rational::read() { //Procedimiento que imprime en pantalla y recoge el valor de denominador y numerador
  cout << "Numerador? ";
  cin >> numerador_;
  cout << "Denominador? ";
  cin >> denominador_;
  assert(denominador_ != 0);
}

// AUTOR: Javier Gonzalez Brito
// FECHA: 10/03/2023 
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public Vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : Vector_t<double>(n) {};
  Polynomial(const Polynomial& pol): Vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_Vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_Vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_Vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const { // Procedimiento que que encarga de mostrar en consola los resultados
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i) << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1) os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) { // Operador para imprimir el procedimiento write
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const { // Método que te evaulua el polinómio
  double result{0.0};
  for(int i = 0; i < get_size(); i++){
    result += get_val(i) * pow(x,i);
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const { // Método que devuelve true o false dependiendo de si dos polinomios densos son iguales
  bool differents = false;
  for(int i = 0; i < pol.get_size() -1; i++) {
    if (at(i) != pol.at(i)) {
     return differents;
    }
  }
  return !differents;
}
// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const { // Función que evalua n plonomio disperso
  double result{0.0};
  for(int i = 0; i < get_nz(); i++) {
    result += at(i).get_val() * pow(x, at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const { // Método que devuelve true o false dependiendo de si dos polinomios dispersos son iguales
  bool differents = false;
    if(get_nz() != spol.get_nz()) {
      return differents;
    }
    for (int i = 0; i < get_nz(); i++) {
      if (at(i).get_val() != spol.at(i).get_val()) {
        return differents;
      }
    }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  SparsePolynomial other_pol{pol};
  if (IsEqual(other_pol) == false) {
    return differents;
  }
  return !differents;
  
}


#endif  // POLYNOMIAL_H_


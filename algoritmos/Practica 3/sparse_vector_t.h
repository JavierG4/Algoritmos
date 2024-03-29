// AUTOR: Javier Gonzalez Brito 
// FECHA: 10/03/2023 
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef Pair_t<double> pair_double_t;
typedef Vector_t<pair_double_t> pair_Vector_t;

class sparse_Vector_t {
 public:
  // constructores
  sparse_Vector_t(const int = 0);
  sparse_Vector_t(const Vector_t<double>&, const double = EPS); // constructor normal
  sparse_Vector_t(const sparse_Vector_t&);  // constructor de copia

  // operador de asignación
  sparse_Vector_t& operator=(const sparse_Vector_t&);

  // destructor
  ~sparse_Vector_t();
  
  // getters
  int get_nz(void) const;
  int get_n(void) const;

  // getters-setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  
  // getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;

  // E/S
  void write(std::ostream& = std::cout) const;

 private:
  pair_Vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};


bool IsNotZero(const double val, const double eps = EPS) { // Función que te dice si es 0 o no dandole un valor
  return fabs(val) > eps;
}

sparse_Vector_t::sparse_Vector_t(const int n) : pv_(n), nz_(0), n_(n) {} // constructor de la clase sparse_Vector_t

// FASE II
sparse_Vector_t::sparse_Vector_t(const Vector_t<double>& v, const double eps) : pv_(), nz_(0), n_(0) { // constructor de la clase sparse_Vector_t
  n_ = v.get_size();
  for(int i = 0; i < v.get_size(); i++) {
    if (IsNotZero(v.get_val(i))) {
      ++nz_;
    }
  }
  pv_.resize( nz_);
  for (int i = 0, j = 0; i < v.get_size(); i++) {
    if (IsNotZero(v.get_val(i))) {
      pair_double_t actual_pair {v.get_val(i), i};
      pv_[j] = actual_pair;
      ++j;
    }
  }

}

// constructor de copia
sparse_Vector_t::sparse_Vector_t(const sparse_Vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

// operador de asignación
sparse_Vector_t& sparse_Vector_t::operator=(const sparse_Vector_t& w) { // Operador que hace la igualdad entre dos vectores dispersos
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

sparse_Vector_t::~sparse_Vector_t() {} // Destructor de la clase

inline int sparse_Vector_t::get_nz() const { // getter que devuelve nz_
  return nz_;
}

inline int sparse_Vector_t::get_n() const { // getter que devuelve n
  return n_;
}

pair_double_t& sparse_Vector_t::at(const int i) { // Función que devuelve el valor en la posición i
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

pair_double_t& sparse_Vector_t::operator[](const int i) { // operador que devuelve el valor en la posición i
  return at(i);
}

const pair_double_t& sparse_Vector_t::at(const int i) const {// Función que devuelve el valor en la posición i
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

const pair_double_t& sparse_Vector_t::operator[](const int i) const { // operador que devuelve el valor en la posición i
  return at(i);
}

// E/S
void sparse_Vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const sparse_Vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_

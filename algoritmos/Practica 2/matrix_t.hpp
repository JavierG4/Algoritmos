// AUTOR: Javier González Brtio
// FECHA: 03/03/2023
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class Matrix {
 public:
  Matrix(const int = 0, const int = 0);
  ~Matrix();
  
  void resize(const int, const int);
  // getters

  int get_filas(void) const;
  int get_columnas(void) const;

  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);

  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const Matrix<T>&, const Matrix<T>&);
  void write(ostream& = cout);
  void read(istream& = cin);

private:
  int filas_, columnas_;
  Vector<T> vector_;
  int pos(const int, const int) ;
};



template<class T>
Matrix<T>::Matrix(const int filas, const int columnas) { 
  filas_ = columnas;
  columnas_ = columnas;
  vector_.resize(filas_ * columnas_);
}

template<class T>
Matrix<T>::~Matrix() {}

template<class T>
void Matrix<T>::resize(const int filas, const int columnas)
{
  assert(filas > 0 && columnas > 0);
  filas_ = filas;
  columnas_ = columnas;
  vector_.resize(filas_ * columnas_);
}

template<class T>
inline int Matrix<T>::get_filas() {
  return filas_;
}

template<class T>
inline int Matrix<T>::get_columnas() {
  return columnas_;
}

template<class T>
T& Matrix<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_filas());
  assert(j > 0 && j <= get_columnas());
  return vector_[pos(i, j)];
}

template<class T>
T& Matrix<T>::operator()(const int i, const int j) {
  return at(i, j);
}

template<class T>
const T& Matrix<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_filas());
  assert(j > 0 && j <= get_columnas());
  return vector_[pos(i, j)];
}

template<class T>
const T& Matrix<T>::operator()(const int i, const int j) {
  return at(i, j);
}

template<class T>
void Matrix<T>::write(ostream& os) const
{ 
  os << get_filas() << "x" << get_columnas() << endl;
  for (int i = 1; i <= get_filas(); ++i) {
    for (int j = 1; j <= get_columnas(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

template<class T>
void Matrix<T>::read(istream& is) {
  is >> filas_ >> columnas_;
  resize(filas_, columnas_);
  for (int i = 1; i <= get_filas(); ++i) {
    for (int j = 1; j <= get_columnas(); ++j) {
      is >> at(i, j);
    }
  }
}

template<class T>
inline int Matrix<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_filas());
  assert(j > 0 && j <= get_columnas());
  return (i - 1) * get_columnas() + (j - 1);
}

// FASE III: producto matricial
template<class T> 
void Matrix<T>::multiply(const Matrix<T>& A, const Matrix<T>& B) {
  // rellenar código
}
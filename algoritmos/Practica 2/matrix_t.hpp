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

template<class T> // Plantilla
class Matrix { // Inicio de la clase Matrix
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

  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  int filas_, columnas_;
  Vector<T> vector_;
  int pos(const int, const int) const;
};



template<class T>
Matrix<T>::Matrix(const int filas, const int columnas) { //Constructor de la clase Matrix
  filas_ = columnas;
  columnas_ = columnas;
  vector_.resize(filas_ * columnas_);
}

template<class T>
Matrix<T>::~Matrix() {} // Destructor de la clase Matrix

template<class T>
void Matrix<T>::resize(const int filas, const int columnas) { // Procedimiento que te actualiza el tamaño de las columnas y las filas
  assert(filas > 0 && columnas > 0);
  filas_ = filas;
  columnas_ = columnas;
  vector_.resize(filas_ * columnas_);
}

template<class T>
inline int Matrix<T>::get_filas() const{ // Función que devuelve las filas
  return filas_;
}

template<class T>
inline int Matrix<T>::get_columnas() const{ // Función que devuelve las columnas
  return columnas_;
}

template<class T>
T& Matrix<T>::at(const int i, const int j) { // Función que devuelve el valor de la matriz en (i,j)
  assert(i > 0 && i <= get_filas());
  assert(j > 0 && j <= get_columnas());
  return vector_[pos(i, j)];
}

template<class T>
T& Matrix<T>::operator()(const int i, const int j) { // Operador que al usar (i,j) Te devuelve su valor en esa posición
  return at(i, j);
}

template<class T>
const T& Matrix<T>::at(const int i, const int j) const{ // Función que devuelve el valor de la matriz en (i,j)
  assert(i > 0 && i <= get_filas());
  assert(j > 0 && j <= get_columnas());
  return vector_[pos(i, j)];
}

template<class T>
const T& Matrix<T>::operator()(const int i, const int j) const{ // Operador que al usar (i,j) Te devuelve su valor en esa posición
  return at(i, j);
}

template<class T>
void Matrix<T>::write(ostream& os) const { // Procedimiento que imprime en pantalla filas x columnas y devuelve los valores de la matriz
  os << get_filas() << "x" << get_columnas() << endl;
  for (int i = 1; i <= get_filas(); ++i) {
    for (int j = 1; j <= get_columnas(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

template<class T>
void Matrix<T>::read(istream& is) { // Procedimiento que lee el tamaño de filas y columnas y al meter valores los mete en la matriz
  is >> filas_ >> columnas_;
  resize(filas_, columnas_);
  for (int i = 1; i <= get_filas(); ++i) {
    for (int j = 1; j <= get_columnas(); ++j) {
      is >> at(i, j);
    }
  }
}

template<class T>
inline int Matrix<T>::pos(const int i, const int j) const{ //Te devuelve la posicion en la matriz 
  assert(i > 0 && i <= get_filas());
  assert(j > 0 && j <= get_columnas());
  return (i - 1) * get_columnas() + (j - 1);
}

// FASE III: producto matricial
template<class T> 
void Matrix<T>::multiply(const Matrix<T>& A, const Matrix<T>& B) { // Producto entre dos matrices
  assert (A.get_columnas() == B.get_filas()); 
  resize(A.get_filas(), B.get_columnas());
  for(int i = 1; i <= A.get_filas(); i++) {
    for (int j = 1; j <= B.get_columnas(); j++){
      for(int z = 1; z <= A.get_columnas(); z++)
        at(i,j) += (A.at(i,z) * B.at(z,j));
    }
  }
}
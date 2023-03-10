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

using namespace std;

template<class T> // Plantilla
class Vector { // Inicio de la clase Vector
 public:
  Vector(const int = 0);
  ~Vector();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

 private:
  T *vector_;
  int size_;
  
  void build(void);
  void destroy(void);
};

template<class T>
Vector<T>::Vector(const int n) { // Constructor de la clase
  size_ = n;
  build();
}

template<class T>
Vector<T>::~Vector() { // Destructor de la clase Vector
  destroy();
}

template<class T>
void Vector<T>::build() { // Procedimiento que contruye el vector 
  vector_ = NULL;
  if (size_ != 0) {
    vector_ = new T[size_];
    assert(vector_ != NULL);
  }
}

template<class T>
void Vector<T>::destroy() { // Procedimiento que se encarga de hacer el delete del vector construido y se usa en el destructor
  if (vector_ != NULL) {
    delete[] vector_;
    vector_ = NULL;
  }
  size_ = 0;
}

template<class T>
void Vector<T>::resize(const int n) { // Procedimiento que destruye el anterior vector, cambia su tamaño y genera uno nuevo
  destroy();
  size_ = n;
  build();
}

template<class T>
inline T Vector<T>::get_val(const int i) const{ //Getter que devuelve el valor del vector en i
  assert(i >= 0 && i < get_size());
  return vector_[i];
}

template<class T>
inline int Vector<T>::get_size() const{ // Devuelve el tamaño del vector
  return size_;
}

template<class T>
void Vector<T>::set_val(const int i, const T d) { // Setter del valor en i
  assert(i >= 0 && i < get_size());
  vector_[i] = d;
}

template<class T>
T& Vector<T>::at(const int i) { // Función que devuelve el valor de i en el vector
  assert(i >= 0 && i < get_size());
  return vector_[i];
}

template<class T>
T& Vector<T>::operator[](const int i) { // Operador que al usar [] devuelve el valor en i
  return at(i);
}

template<class T>
const T& Vector<T>::at(const int i) const{ // Función que devuelve el valor de i en el vector
  assert(i >= 0 && i < get_size());
  return vector_[i];
}

template<class T>
const T& Vector<T>::operator[](const int i) const{ // Operador que al usar [] devuelve el valor en i
  return at(i);
}

template<class T>
void Vector<T>::write(ostream& os) const{ // Procedimiento que imprime en pantalla el size y el valor en i
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++) {
    os << at(i) << "\t";
    os << endl;
  }
}

template<class T>
void Vector<T>::read(istream& is) { // Procedimiento que lee valor de size e introduce valores en el vector
  is >> size_;
  resize(size_);
  for (int i = 0; i < size_; ++i) {
    is >> at(i);
  }
}

// FASE II: producto escalar
template<class T>
T scal_prod(const Vector<T>& v, const Vector<T>& w) { // Producto escalar entre dos vectores de tipo double
  double resultado = 0;
  assert(v.get_size() == w.get_size());
  for(int i = 0 ;i < v.get_size(); i++) {
    resultado += v.at(i) * w.at(i);
  }
  return resultado;
}

double scal_prod(const Vector<Rational>& v, const Vector<Rational>& w) { // Producto escalar entre dos vectores de tipo Rational
  double resultado;
  assert(v.get_size() == w.get_size());
  for(int i = 0 ;i < v.get_size(); i++) {
    resultado += v.at(i).value() * w.at(i).value();
  }
  return resultado;
}
// AUTOR: Javier Gonzalez Brito 
// FECHA: 10/03/2023 
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class Vector_t {
 public:
  // constructores
  Vector_t(const int = 0);
  Vector_t(const Vector_t&); // constructor de copia

  // operador de asignación
  Vector_t<T>& operator=(const Vector_t<T>&);

  // destructor
  ~Vector_t();
  
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

  // Redimensionado
  void resize(const int);
  
  // E/S
  void read(std::istream& = std::cin);
  void write(std::ostream& = std::cout) const;

 private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};


template<class T> Vector_t<T>::Vector_t(const int n) : v_(NULL), sz_(n) { // contructor de la clase vector
  build();
}

// constructor de copia
template<class T> Vector_t<T>::Vector_t(const Vector_t<T>& w) : v_(NULL), sz_(0) {
  *this = w; // se invoca directamente al operator=
}

// operador de asignación
template<class T> Vector_t<T>& Vector_t<T>::operator=(const Vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}

template<class T> Vector_t<T>::~Vector_t() { // Destructor de la clase vector_t
  destroy();
}

template<class T> void Vector_t<T>::build() { // Procedimiento que te contruye el vector
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template<class T> void Vector_t<T>::destroy() { // Procedimiento que libera el espacio creado en el build
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template<class T> void Vector_t<T>::resize(const int n) { // Procedimiento que reajusta el tamaño del vector
  destroy();
  sz_ = n;
  build();
}

template<class T> inline T Vector_t<T>::get_val(const int i) const { //getter que te devuelve el val en i
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> inline int Vector_t<T>::get_size() const { // getter que te devuelve el size
  return sz_;
}

template<class T> void Vector_t<T>::set_val(const int i, const T d) { // Setter que escribe el valor en una posición i con un valor d
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template<class T> T& Vector_t<T>::at(const int i) { // Función que devuelve el valor de la posición i en el vector v_
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> T& Vector_t<T>::operator[](const int i) { // operador que devuelve el at(i)
  return at(i);
}

template<class T> const T& Vector_t<T>::at(const int i) const { // Función que devuelve el valor de la posición i en el vector v_
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template<class T> const T& Vector_t<T>::operator[](const int i) const { // operador que devuelve el at(i)
  return at(i);
}

template<class T> void Vector_t<T>::read(std::istream& is) { // Procedimiento que lee datos y los mete en el vector
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}

template<class T> void Vector_t<T>::write(std::ostream& os) const { // Procedimiento que imprime en pantalla
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

template<class T> std::istream& operator>>(std::istream& is, Vector_t<T>& v) { // Operador para hacer el read
  v.read(is);
  return is;
}

template<class T> std::ostream& operator<<(std::ostream& os, const Vector_t<T>& v) { // operador para hacer el write
  v.write(os);
  return os;
}

#endif  // VECTORT_H_

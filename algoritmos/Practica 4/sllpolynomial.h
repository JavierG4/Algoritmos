// AUTOR: Javier González Brito 
// FECHA: 01/04/2023
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
  double Sumpol(void) const;
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) { 
  for(int i = v.get_size() -1; i >= 0; i--) {
    if (IsNotZero(v.get_val(i))) {
      push_front(new SllPolyNode(pair_double_t(v[i],i)));
    }
  }
}

// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  sll_node_t<pair_double_t>* aux = get_head();
  while (aux != NULL) {
    int inx = aux->get_data().get_inx();
    double val = aux->get_data().get_val();
    result += val * pow(x,inx);
    aux = aux->get_next();
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol, const double eps) const {
  bool differents = false;
  sll_node_t<pair_double_t>* aux1 = get_head();
  sll_node_t<pair_double_t>* aux2 = sllpol.get_head();
  while(aux1 != NULL || aux2 != NULL){
    if(aux1->get_data().get_val() != aux2->get_data().get_val()){
      return differents;
    }
    aux1 = aux1->get_next();
    aux2 = aux2->get_next();
  }

  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum, const double eps) {
  double suma = 0.0;
  sll_node_t<pair_double_t>* aux1 = get_head();
  sll_node_t<pair_double_t>* aux2 = sllpol.get_head();
  SllPolynomial lista;
  int inx1, inx2;
  double val1, val2;
  while(aux1 != NULL and aux2 != NULL) {
    // Obtener los exponentes de las x
    inx1 = aux1 -> get_data().get_inx();
    inx2 = aux2 -> get_data().get_inx();

    if(inx1 == inx2) { // Si los exponentes son iguales sumar los coeficientes
      val1 = aux1 -> get_data().get_val();
      val2 = aux2 -> get_data().get_val();
      suma = val1 + val2;
      if(IsNotZero(suma)) { // Si el resultado de la suma es igual a 0 no colocarlo en la lista
        lista.push_front(new sll_node_t<pair_double_t>(pair_double_t(suma,inx1)));
      }
      // Siguientes elementos
      aux1 = aux1 -> get_next();
      aux2 = aux2 -> get_next();
    }
    // Si la lista de una se acaba, insertar el/los elemento/s de la otra
    if(aux1 == NULL and aux2 != NULL) {
      lista.push_front(new sll_node_t<pair_double_t>(pair_double_t(aux2 -> get_data().get_val(), aux2 -> get_data().get_inx())));
    }
    if(inx1 < inx2) {
      val1 = aux1 ->get_data().get_val();
      lista.push_front(new sll_node_t<pair_double_t>(pair_double_t(val1,inx1)));
      aux1 = aux1 -> get_next();
    }
    else if (inx2 < inx1) {
      val2 = aux2 -> get_data().get_val();
      lista.push_front(new sll_node_t<pair_double_t>(pair_double_t(val2,inx2)));
      aux2 = aux2 -> get_next();
    }
  }
  sll_node_t<pair_double_t>* aux3 = lista.get_head();
  while (aux3 != NULL) {
    int inx3 = aux3->get_data().get_inx();
    double val3 = aux3->get_data().get_val();
    sllpolsum.push_front(new sll_node_t<pair_double_t>(pair_double_t(val3,inx3)));
    aux3 = aux3 ->get_next();
  }
}
double SllPolynomial::Sumpol(void) const{ // Modificacion de la practica
  sll_node_t<pair_double_t>* aux1 = get_head();
  double sum = 0.0;
  while (aux1 != NULL) {
    double val = aux1->get_data().get_val();
    int inx = aux1->get_data().get_inx();
    if(inx % 2 == 0) {
      sum += val;
    }
    aux1 = aux1->get_next();
    }
    return sum;
  }

#endif  // SLLPOLYNOMIAL_H_

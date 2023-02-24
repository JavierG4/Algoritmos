// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class Rational { //La creación de clase Rational
 
 public:
   Rational(const int = 0, const int = 1); //estruc
   // getters
   const int get_numerador();
   const int get_denominador();
   // setters
   void set_numerador(const int);
   void set_denominador(const int);

   const double value(); // Método

  // FASE II
   bool is_equal(Rational&, const double precision = EPSILON);
   bool is_greater(Rational&, const double precision = EPSILON);
   bool is_less(Rational&, const double precision = EPSILON);
  
  // FASE III
   Rational add(Rational&);
   Rational substract(Rational&);
   Rational multiply(Rational&);
   Rational divide(Rational&);
  
   void write();
   void read();
  
 private:
   int numerador_, denominador_;
};
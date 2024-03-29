// AUTOR:Javier González Brito  
// FECHA: 17/04/2023
// EMAIL: alu0101548197@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c << std::endl;

    if (isdigit(c)) {
      int i = c - '0';
      //stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
      stack_.push(i);
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r'|| c == 'c'|| c == 'l');
  if(c == 'r'|| c == 'c'|| c == 'l'){
    int aux = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << aux << std::endl;
    int aux2;
    switch (c) {
      case 'r':
        aux2 = sqrt(aux);
        stack_.push(aux2);
       break;
      case 'c':
        aux2 = pow(aux,2);
        stack_.push(aux2);
        break;
      case 'l':
        aux2 = log2(aux);
        stack_.push(aux2);
        break;
    }
    std::cout << "   Metemos en la pila el resultado: " << aux2 << std::endl;
  }
  else{
    int aux = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " <<  aux << std::endl;
    int aux2 = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << aux2 << std::endl;
    int aux3;
    switch (c) {
      case '+':
        aux3 = aux + aux2;
        stack_.push(aux3);
       break;
      case '-':
        aux3 = aux2 - aux;
        stack_.push(aux3);
        break;
      case '*':
        aux3 = aux2 * aux;
        stack_.push(aux3);
        break;
      case '/':
        aux3 = aux2 / aux;
        stack_.push(aux3);
        break;
      case '^':
        aux3 = pow(aux2, aux);
        stack_.push(aux3);
        break;
    
    }
    std::cout << "   Metemos en la pila el resultado: " << aux3 <<std::endl;
  }
}

 
#endif  // RPNT_H_

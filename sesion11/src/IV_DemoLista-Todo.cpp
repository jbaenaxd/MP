/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 9
//
/*
 */
/*********************************************************************/

#include <iostream>
#include "Lista.h"

using namespace std;
int main() {

  cout << "Creando una lista con 4 nodos inicializados a 1..." << endl;
  Lista lista(4,1);
  Lista copia = lista;
  lista += 4;
  lista += 2;
  lista += 4;
  lista.Muestra();
  lista -= 4;
  lista.Muestra();
  
  return (0);
}

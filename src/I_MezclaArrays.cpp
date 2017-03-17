/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACIóN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2016-2017
// (C) Antonio Jesús Heredia Castillo
// 1º - Grupo B - Subgrupo B2
//
// PRÁCTICA 5
//
/*
*/
/*********************************************************************/

#include <iostream>
#include "matriz_numeros.h"
using namespace std;

/*********************************************************************/


int main(int argc, char * argv[])
{
  const int TOPE = 100;
  int v1[TOPE];
  int v2[TOPE];
  int min, max;
  switch (argc) {
    case 1:
      min = 0;
      max = 100;
    break;
    case 2:
      min = 0;
      max = atoi(argv[1]);
    break;

    case 3:
      min = atoi(argv[1]);
      max = atoi(argv[2]);
    break;

    case 4:
      cout << "Numero de argumentos invalidos...." << endl;
      cout << "Saliendo del programa...." << endl;
      return 1;
    break;
  }
  RellenaVector(v1,TOPE,min,max);

  char mensaje[TOPE];
  cout << "Introduzca el mensaje a mostrar: ";
  cin.getline(mensaje,TOPE);

  MuestraVector(mensaje,v1,TOPE,10);

  
  RellenaVector(v2,TOPE,min,max);
  MuestraVector(mensaje,v2,TOPE,10);

  int v3[TOPE*2];
  MezclaVectores(v3,v1,TOPE,v2,TOPE);
  MuestraVector(mensaje,v3,TOPE*2,10);

  cout << endl << endl;
	return (0);
}

/*********************************************************************/

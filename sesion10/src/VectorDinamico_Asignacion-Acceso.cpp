#include <iostream>
#include "VectorDinamico_Asignacion-Acceso.h"

using namespace std;

/******************************************************************************/

/*
  Contructor indicando el numero de casillas.
  En caso de usar el constructor sin ningun argmumento se iniciara un vector
  con tamaño inicial = TAM_INICIAL
  Se crea un vector dinamico con un tamaño inicial indicado por el argumento,
*/
VectorDinamico_Asignacion::VectorDinamico_Asignacion(const int
  casillas):num_casillas(casillas),num_ocupadas(0),
  redimension(TipoRedimension::EnBloques){

  ReservaCasillas(casillas);
}

/*
  Contructor de copia
  Se crea un vector dinamico con un tamaño inicial indicado por el tamaño del
  VectorDinamico_Asignacion pasado en el argumentos
  Tambien se inicializa el vector con un valor inicial igual a los valores
  del VectorDinamico_Asignacion pasado por el argumento
*/
VectorDinamico_Asignacion::VectorDinamico_Asignacion(const
  VectorDinamico_Asignacion & otro){

  ReservaCasillas(otro.NumeroDeCasillas());
  CopiarDatos(otro);
}

/*
  Destructor
  Se encargara de liberar la memoria ocupada por el
  VectorDinamico_Asignacion en el heap
*/
VectorDinamico_Asignacion::~VectorDinamico_Asignacion(void){
  LiberarMemoria();
}

// Operador de asignacion
VectorDinamico_Asignacion & VectorDinamico_Asignacion :: operator =
(const VectorDinamico_Asignacion & otro){

  if(this != &otro){

    LiberarMemoria();

    ReservaCasillas(otro.NumeroDeCasillas());

    CopiarDatos(otro);
  }
  return (*this);
}

// Operador de asignacion
VectorDinamico_Asignacion & VectorDinamico_Asignacion :: operator =
(const TipoBase & valor){
  InicializarDato(valor);
}

TipoBase & VectorDinamico_Asignacion :: operator [] (const int indice){
  return (vector[indice]);
}


/*
  Metodo que nos devuelve si el VectorDinamico_Asignacion esta vacio.
  Devuelve un bool que sera TRUE si el VectorDinamico_Asignacion esta
  vacio o FALSE en caso contrario
  No recibe nada.
*/
bool VectorDinamico_Asignacion::EstaVacio(void) const{
  return (num_casillas == 0);
}

/*
  Metodo que devuelve el numero de casillas que tiene el
  VectorDinamico_Asignacion
  Devuelve un int que indica el numero de casillas que tiene ocupadas.
  No recibe nada.
*/
int VectorDinamico_Asignacion::NumeroDeCasillas(void) const{
  return num_casillas;
}

/*
  Metodo que devuelve el numero de casillas ocupadas que tiene el
  VectorDinamico_Asignacion
  Devuelve un int que indica el numero de casillas que tiene ocupadas.
  No recibe nada.
*/
int VectorDinamico_Asignacion::NumeroDeCasillasOcupadas(void) const{
  return num_ocupadas;
}

/*
  Metodo que añade un valor al VectorDinamico_Asignacion en la ultima
  posicion
  No devuelve nada.
  Recibe un TipoBase que sera el que se añada al final del
  VectorDinamico_Asignacion.
*/
void VectorDinamico_Asignacion::AniadirValor(const TipoBase valor){

  //Se comprueba si hay espacio  para mas valores y si no hay se redimensiona
  if(num_ocupadas == num_casillas)
    Redimensiona();

  //Se añade el valor
  vector[num_ocupadas] = valor;

  //Se aumenta el numero de casillas ocupadas
  num_ocupadas++;
}


/*
  Metodo que devuelve el valor que se encuentra en la casilla indicada
  Devuelve un TipoBase que es el que se encuentra en la posicion indicada
  Recibe un int que sera el que indique el numero de la casillas
  PREC:
    pos < num_ocupadas
*/
TipoBase VectorDinamico_Asignacion::Valor(int pos) const{
  return vector[pos];
}

/*
  Metodo que devuelve el tipo de redimenion que se hace cuando se aumenta el
  tamanio del VectorDinamico_Asignacion
  Devuelve un TipoRedimension que indica el tipo de redimension actual
  No recibe nada
*/
TipoRedimension VectorDinamico_Asignacion::Redimension(void) const{
  return redimension;
}

/*
  Metodo que establece un nuevo tipo de redimensionar para el
  VectorDinamico_Asignacion
  No devuelve nada
  Recibe el TipoRedimension nuevo que se va a establecer
*/
void VectorDinamico_Asignacion::Redimension(TipoRedimension
  nueva_redimension){
  redimension = nueva_redimension;
}

/*
  El metodo muestra por pantalla el contenido de un vector dinamico
  El metodo no recibe nada
  El metodo no devuelve nada
*/
void VectorDinamico_Asignacion::ImprimeVector(string mensaje) const{

  cout << mensaje << endl;
  cout << "(" << vector[0];

  for(int c = 1; c < num_ocupadas; c++){
      if(c%5 == 0)
        cout << endl << " ";
    cout << "," << vector[c];
  }

  cout << ")" << endl;
}

/*
  Metodo  que reserva un numero de casillas predeterminado
  No devuelve nada
  Recibe un int con el numero de casillas a reservar
  PREC: casillas > 0
*/
void VectorDinamico_Asignacion::ReservaCasillas(int casillas){
  vector = 0;
  if(casillas > 0)
    vector = new TipoBase [casillas];
}

/*
  Metodo que libera la memoria de un vector dinamico
  No recibe nada
  No devuelve nada
*/
void VectorDinamico_Asignacion::LiberarMemoria(void){
  if(vector)
    delete [] vector;
}


/*
  El metodo copia todos los valores de un vector dinamico a nuestro vector
  dinamico
  No devuelve nada
  Recibe un puntero a un VectorDinamico_Asignacion
*/
void VectorDinamico_Asignacion::CopiarDatos(const
  VectorDinamico_Asignacion & otro){

  num_casillas = otro.num_casillas;
  num_ocupadas = otro.num_ocupadas;
  redimension = otro.redimension;
  for(int c = 0; c < num_ocupadas; c++)
    vector[c] = otro.vector[c];

}

/*
  El metodo redimension el tamaño del vector dinamico para que tenga mas
  capacidad
  No devuelve nada
  No recibe nada
*/
void VectorDinamico_Asignacion::Redimensiona(void){
 switch (redimension) {
    case DeUnoEnUno:
      num_casillas++;
    break;
    case EnBloques:
      num_casillas += TAM_BLOQUE;
    break;
    case Duplicando:
      num_casillas *= 2;
    break;
  }
  TipoBase * tmp = vector;

  ReservaCasillas(num_casillas);

  for(int c = 0; c < num_ocupadas; c++)
    vector[c] = tmp[c];

  delete [] tmp;
}

void VectorDinamico_Asignacion::InicializarDato(TipoBase dato){
  num_ocupadas = num_casillas;
  for (int i = 0; i < num_casillas; i++) {
    vector[i] = dato;
  }
}

/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2015-2016
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 4
//
// Implementaci�n de la clase clase Lista (2).
//
// Incluye: 
//		* constructor de copia
//		* destructor
//		* operador de asignaci�n 
//		* sobrecarga de [].
//
// Fichero: Lista_Asignacion-Acceso.cpp
//
/***************************************************************************/

	#include <iostream>

	#include "Lista_Asignacion-Acceso.h"

	using namespace std; 

	/***********************************************************************/
	// Constructor sin argumentos: crea una lista vacia.
	Lista :: Lista (void)  : primero(0), tamanio(0)
	{ }

	/***********************************************************************/
	// Constructor con argumentos: crea una lista con "tam" nodos
	// PRE: tam > 0
	Lista :: Lista (int tam) : tamanio(tam) 
	{
		ReservarMemoria (tamanio);
	}
		
	/***********************************************************************/
	// Constructor de copia
	Lista :: Lista (const Lista & otro)
	{	
		// Reservar memoria para los nodos de la lista
		ReservarMemoria (otro.tamanio);

		// Copiar campos privados y los valores de la lista
		CopiarDatos (otro);
	}		
		
	/***********************************************************************/
    // Destructor
    Lista :: ~Lista (void)
    {
        LiberarMemoria ();
    }
	
	/***********************************************************************/
    // Consulta si la lista esta vacia
	bool Lista :: EstaVacia(void) const
	{
		return (tamanio == 0);
	}		

	/*******************************************************************/
	// Inicializa la lista al valor dado
	void  Lista :: Inicializar (TipoBase valor)
	{
		TipoNodo * p = primero; // Apuntar al primero.

		for(int i = 0; i < tamanio; i++) {
			p->info = valor; // Inicializar nodo.
			p = p->sig;		 // Adelantar "p".
		}						
	}
	
	/***********************************************************************/
	// Devuelve el n�mero de nodos de la lista
	int Lista :: Tamanio(void)	const
	{
		return tamanio;
	}

	/*******************************************************************/
	// Busca un alumno con el valor especificado. Devuelve la posici�n  
	// del primer nodo coincidente, o -1 si no se encuentra.
	//
	// NO MODIFICA EL N�MERO DE NODOS
    //	
	/*******************************************************************/
	int Lista :: Busca (const TipoBase valor) const
	{
        TipoNodo * p = primero;

        bool sigo = true;
        bool encontrado = false;
    
    	int pos = 0;
    	
        while ((p!=0) && sigo) {
        	
			pos++; // Actualizar posici�n

            if (p->info == valor) {
                sigo = false;
                encontrado = true;
            }
            else 
                p = p->sig;
		}
		
   		return (encontrado ? (pos) : -1); 
	}	
	

	/*********************************************************************/
	// Metodo de acceso individual a elementos
	// Metodo de lectura/escritura
	// PRE: 0 <= posicion <=tamanio
	TipoBase & Lista ::  operator [] (const int posicion)
	{
	    TipoNodo * p = primero;
	    for (int i = 1; i < posicion; i++)
	        p = p->sig;
	
	    // "p" apunta al nodo de la posici�n "pos"
	
	    return (p->info);
	}
	
	TipoBase & Lista ::  operator [] (const int posicion) const
	{
	    TipoNodo * p = primero;
	    for (int i = 1; i < posicion; i++)
	        p = p->sig;
	
	    // "p" apunta al nodo de la posici�n "pos"
	
	    return (p->info);
	}
	
	/*********************************************************************/
	// Metodo de acceso individual a elementos
	// Metodo de lectura/escritura
	// PRE: 0 <= posicion <=tamanio
	TipoBase & Lista ::  operator () (const int posicion)
	{
	    TipoNodo * p = primero;
	    for (int i = 1; i < posicion; i++)
	        p = p->sig;
	
	    // "p" apunta al nodo de la posici�n "pos"
	
	    return (p->info);
	}
	
	TipoBase & Lista ::  operator () (const int posicion) const
	{
	    TipoNodo * p = primero;
	    for (int i = 1; i < posicion; i++)
	        p = p->sig;
	
	    // "p" apunta al nodo de la posici�n "pos"
	
	    return (p->info);
	}
	
	/*********************************************************************/
	// Operador de asignaci�n 
	Lista & Lista :: operator = (const Lista & otro)
	{
	    if (this != &otro)  // Evitar autoasignaci�n
		{
	        // Libera la memoria ocupada
	        LiberarMemoria();
	
	        // Reserva de memoria para los valores de la matriz
			ReservarMemoria (otro.tamanio);
	
	        // Copia el contenido de la matriz y los campos privados
	        CopiarDatos(otro);
	    }
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignaci�n
	}
	
	/*********************************************************************/
	// Operador de asignaci�n 
	Lista & Lista :: operator = (const TipoBase valor)
	{
		// Escribir "valor" en todos los nodos
	    Inicializar (valor);
	 
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignaci�n
	}

	/*******************************************************************/
    // M�todos que modifican el n�mero de nodos 

	/*******************************************************************/
	// Aniade (al final) un nuevo elemento
	void  Lista :: Aniade (const TipoBase valor)
	{					
		// Crear un nuevo (�ltimo) nodo y rellenar sus campos
		TipoNodo * nuevo = new TipoNodo;
		nuevo->info = valor;
		nuevo->sig = 0;

		if (primero != 0) {  // La lista no est� vac�a

			// Buscar el �ltimo nodo
			TipoNodo * p = primero;
			
			for(int i=1; i<tamanio; i++)
				p = p->sig;
	
			// "p" apunta al �ltimo nodo	
						
			p->sig = nuevo;
		}
		else { // La lista estaba vac�a
			primero = nuevo; 
		}
		
		tamanio++;
	}

	/*******************************************************************/
    // Borra el primer nodo que contiene el valor "valor"
    void Lista :: Elimina (const TipoBase valor)
    {
		int pos = Busca (valor);
	
 		// Si pos > 0 se encontr� el alumno buscado: eliminarlo
		if (pos > 0) Borra (pos);
    }
 
	/*******************************************************************/
	// Inserta un nuevo elemento en la posici�n "pos_insertar"
	//
	// PRE: 1 <= pos_insertar <= tamanio+1
	// El criterio seguido para especificar una posicion ser� : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es id�ntico a la 
	// 		 ejecuci�n del m�todo Aniade()
	void  Lista :: Inserta (const TipoBase valor, int pos_insertar)
	{
		TipoNodo * ant = primero;
		TipoNodo * resto = primero;

		// Crear el nodo que se va a insertar e iniciarlo
		TipoNodo * nuevo = new TipoNodo; 
		nuevo->info = valor; 

		// Buscar el sitio que le corresponde 
		for (int i=1; i<pos_insertar; i++) { 
			ant = resto; 
			resto = resto->sig;
		}

		if (pos_insertar==1)   // El nuevo nodo sera el primero 
			primero = nuevo;
		else		  // Enlazar el nuevo con el anterior 
			ant->sig = nuevo;

		nuevo->sig = resto; // Enlazar el nuevo nodo con el resto

		tamanio++; // Actualizar tamanio
	}

	/*******************************************************************/
	// Borra el elemento de "pos_borrar" 
	//
	// PRE: 1 <= pos_borrar <= tamanio
	// El criterio seguido para especificar una posicion ser�: 
	// 1 -> primero, 2 -> segundo,...	
	void  Lista :: Borra (int pos_borrar) 
	{
		TipoNodo * ant = primero;
		TipoNodo * pos = primero;

		// Colocar "ant" y "act" 
		for (int i=1; i<pos_borrar; i++) { 
			ant = pos; 
			pos = pos->sig;
		}

		// "pos" apunta al nodo que se va a borrar
		// "ant" apunta al nodo anterior

		if (pos_borrar==1)   // Saltar el primero 
			primero = primero->sig;
		else 
			ant->sig = pos->sig;
			// Enlazar el anterior con el siguiente 

		delete pos; // Borrar nodo
		
		tamanio--;  // Actualizar tamanio
	}
	
	/*******************************************************************/
	// Pide memoria para "num_elementos" nodos
	// PRE: num_elementos > 0
	void  Lista :: ReservarMemoria (int num_elementos)
	{
		if (num_elementos > 0) {

			primero = new TipoNodo;		// Crear primer nodo.
	
			TipoNodo * ultimo = primero; // Apuntar al �ltimo.
			TipoNodo * p;
	
			for (int i = 1; i < num_elementos; i++) {
	
				p = new TipoNodo;	// Crear un nodo.
				ultimo->sig = p;	// Enlazar el nuevo nodo. 
				ultimo = p;			// Pasa a ser el �ltimo.
			}						
	
			ultimo->sig = 0; // Finalizar la lista
		}
		else primero = 0;
	}

	/*******************************************************************/
    // Liberar memoria
    void  Lista :: LiberarMemoria (void)
	{

		if (primero !=0) {
			
			TipoNodo *p = primero; // Colocar "p" al principio

			while (primero->sig != 0) {

				primero = primero->sig;  // Nuevo "primero"
				delete p;     // Borrar el antiguo primero
				p = primero;  // Actualizar "p"
			}

			delete primero; // Borrar el �nico que queda
			
			primero = 0; // MUY IMPORTANTE
		}
	}

	/*******************************************************************/
    // Copiar datos desde otro objeto de la clase
    // PRE: Se ha reservado memoria para los datos
	void Lista :: CopiarDatos (const Lista & otro)
	{
        // Copia los campos privados

        tamanio = otro.tamanio; // Copia el n�m. de nodos

        // Copia el contenido de los nodos

		TipoNodo * p_este = primero; 
		TipoNodo * p_otro = otro.primero; 

		for(int i = 0; i < tamanio; i++) {

			// Copiar valor
			p_este->info = p_otro->info; 

			// Adelantar punteros
			p_este = p_este->sig;		 
			p_otro = p_otro->sig;		 
		}	
	}

    /***********************************************************************/
    /***********************************************************************/
	// Otras funciones no pertenecientes a la clase
    /***********************************************************************/
    /***********************************************************************/
    
	/***********************************************************************/
	// Muestra el contenido de una lista, precedido del mensaje "msg"
	void PintaLista (const Lista l, const char * msg)
	{
		cout << endl; 
		cout << "--------------------------------------------------" << endl;
		cout << msg << endl;

		int tamanio = l.Tamanio();
	
		for(int pos=1; pos<=tamanio; pos++) 
			cout << l[pos] << ((pos != tamanio)?" - ":"");
		cout << endl;

		cout << "--------------------------------------------------" << endl;  
		cout << endl;
	}

	/*******************************************************************/
	/*******************************************************************/

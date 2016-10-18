/* Nombres: Gabriel Filtzer Gorbach
	    Daniel Ponce de León Súchil
   
   Descripción: En esta clase se encuentran lo métodos que determinan la creación 
   de un nodo y sus apuntadores correspondientes.
*/

#include <iostream>

class NodoA {

public:
    int Dato;
    NodoA* Hder;
    NodoA* Hizq;
    NodoA* Padre;
    NodoA(int Dato);
    NodoA(int Dato, NodoA* Padre);
};

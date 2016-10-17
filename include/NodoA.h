/* Nombres: Gabriel Filtzer Gorbach
	    Daniel Ponce de León Súchil
   
   Descripción: En esta clase se encuentran lo métodos que determinan la creación 
   de un nodo y sus apuntadores correspondientes.
*/

#include <iostream>
#include <vector>

class NodoA {

public:
    int dato;
    std::vector<NodoA*> Hijos;
    NodoA* Padre;
    NodoA(int dato);
    NodoA(int dato, NodoA* padre);
};

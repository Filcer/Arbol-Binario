/*  Nombres: Gabriel Filtzer Gorbach
	    Daniel Ponce de León Súchil
   
   Descripción: En esta clase se encuentran los métodos necesarios para buscar un elemento en el arbol, y para agregar y 
   eliminar un nodo deseado. Además también está definida la búsqueda recursiva (BusqRec), la cuál simplifica el proceso 
   de busqueda de un dato. 
*/

#include <stack>
#include "NodoA.h"

class Arbol {
private:
    NodoA* BusqRec(int ref, NodoA* aux);

public:
    NodoA* Raiz;
    Arbol(int orig);
    NodoA* Buscar(int ref);
    bool AddNodo(int ref, int aux);
    bool ElimNodo(int ref);
    std::stack<NodoA*> Camino(NodoA* aux);
    void Imprimir();
};

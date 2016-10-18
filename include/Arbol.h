/*  Nombres: Gabriel Filtzer Gorbach
	    Daniel Ponce de León Súchil
   
   Descripción: En esta clase se encuentran los métodos necesarios para buscar un elemento en el arbol, y para agregar y 
   eliminar un nodo deseado. Además también está definida la búsqueda recursiva (BusqRec), la cuál simplifica el proceso 
   de busqueda de un dato. 
*/

#include "NodoA.h"

class Arbol
{
public:
    NodoA* Raiz;

    Arbol(int orig);
    NodoA* Buscar(int ref);
    bool AddNodo(int dato);
    bool ElimNodo(int ref);
    void Intercambio(NodoA* a, NodoA* aux);
    void Imprimir();

private:
    NodoA* BusqRec(int ref, NodoA* aux);
    bool AddRec(int dato, NodoA* aux);
    void ImprimirRec(NodoA* nodo, int espacios);
};

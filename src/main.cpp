#include "Arbol.h"

int main()
{
    // Creando el arbol a pura manita :v
    Arbol arbol = Arbol(6);
    arbol.AddNodo(4);
    arbol.AddNodo(2);
    arbol.AddNodo(5);
    arbol.AddNodo(10);
    arbol.AddNodo(8);
    arbol.AddNodo(12);
    arbol.AddNodo(7);
    arbol.AddNodo(9);
    arbol.AddNodo(11);
    arbol.AddNodo(20);
    arbol.AddNodo(19);
    arbol.AddNodo(18);

    arbol.Imprimir();

    return 0;
}

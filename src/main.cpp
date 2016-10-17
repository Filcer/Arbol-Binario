#include "Arbol.h"

int main()
{
    // Creando el arbol a pura manita :v
    Arbol arbol = Arbol(1);
    arbol.Imprimir();
    arbol.AddNodo(1, 2);
    arbol.Imprimir();
    arbol.AddNodo(1, 3);
    arbol.Imprimir();
    arbol.AddNodo(2, 4);
    arbol.Imprimir();
    arbol.AddNodo(2, 5);
    arbol.Imprimir();
    arbol.AddNodo(3, 6);
    arbol.Imprimir();
    arbol.AddNodo(3, 7);
    arbol.Imprimir();
    arbol.AddNodo(3, 10);
    arbol.Imprimir();
    arbol.AddNodo(5, 9);
    arbol.Imprimir();
    arbol.AddNodo(5, 8);
    arbol.Imprimir();

    // Buscar 10 y decir si existe
    NodoA* busq;
    busq = arbol.BusqNodo(10);
    if (busq == NULL) {
        std::cout << "No existe" << std::endl;
    } else {
        std::cout << "Sí existe" << std::endl;
    }

    // Buscar 15 y decir si existe
    busq = arbol.BusqNodo(15);
    if (busq == NULL) {
        std::cout << "No existe" << std::endl;
    } else {
        std::cout << "Sí existe" << std::endl;
    }

    return 0;
}

#include "Arbol.h"

Arbol::Arbol(int orig)
{
    this->Raiz = new NodoA(orig);
}

// Búsqueda
NodoA* Arbol::Buscar(int ref)
{
    if (this->Raiz == NULL)
        return NULL;
    return BusqRec(ref, this->Raiz);
}

NodoA* Arbol::BusqRec(int ref, NodoA* aux)
{
    NodoA* res;
    if (aux->Dato == ref)
        return aux;
    if (ref < aux->Dato && aux->Hizq != NULL) {
        res = BusqRec(ref, aux->Hizq);
    } else if (ref > aux->Dato && aux->Hder != NULL) {
        res = BusqRec(ref, aux->Hder);
    } else {
        res = NULL;
    }
    return res;
}

// Agregar nodos al árbol
bool Arbol::AddNodo(int dato)
{
    if (Buscar(dato) != NULL)
        return true;
    return AddRec(dato, this->Raiz);
}

bool Arbol::AddRec(int dato, NodoA* aux)
{
    bool res;
    if (dato < aux->Dato) {
        if (aux->Hizq != NULL) {
            res = AddRec(dato, aux->Hizq);
            return res;
        } else {
            NodoA* nodo = new NodoA(dato, aux);
            aux->Hizq = nodo;
            return true;
        }
    } else if (dato > aux->Dato) {
        if (aux->Hder != NULL) {
            res = AddRec(dato, aux->Hder);
            return res;
        } else {
            NodoA* nodo = new NodoA(dato, aux);
            aux->Hder = nodo;
            return true;
        }
    }
    return false;
}

void Arbol::Intercambio(NodoA* a, NodoA* aux)
{
    if (a->Hizq == NULL) {
        a->Padre->Hder = NULL;
        a->Padre = aux->Padre;
        a->Hder = aux->Hder;
        a->Hizq = aux->Hizq;
        aux->Hizq->Padre = a;
        aux->Hder->Padre = a;
        aux->Padre = a;
        aux->Hizq = NULL;
        aux->Hder = NULL;
    }
}

bool Arbol::ElimNodo(int ref)
{
    NodoA* aux = Buscar(ref);
    if (aux == NULL) {
        std::cout << "No existe el valor en el arbol" << std::endl;
        return false;
    }

    if (aux->Hizq == NULL && aux->Hder == NULL) {
        if (aux->Padre->Hizq == aux)
            aux->Padre->Hizq = NULL;
        else
            aux->Padre->Hder = NULL;
        aux->Padre = NULL;
    }
    NodoA* a;
    if (aux->Hizq != NULL) {
        if (aux->Hizq->Hder == NULL) {
            aux->Padre->Hder = aux->Hizq;
            aux->Hizq->Padre = aux->Padre;
            aux->Padre = NULL;
            aux->Hizq->Hder = aux->Hder;
            aux->Hder->Padre = aux->Hizq;
            aux->Hder = NULL;
            aux->Hizq = NULL;
        } else {
            a = aux->Hizq->Hder;
            while (a->Hder != NULL) {
                a = a->Hder;
            }
        }
        if (a->Hizq != NULL) {
            a->Hizq->Padre = a->Padre;
            a->Padre->Hder = a->Hizq;
            a->Hizq = NULL;
            Intercambio(a, aux);
        } else {
            Intercambio(aux->Hder, aux);
            return true;
        }
    }
}

// Impresión del árbol
void Arbol::Imprimir()
{
    if (Raiz == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
    } else {
        ImprimirRec(this->Raiz, 0);
    }
}

void Arbol::ImprimirRec(NodoA* nodo, int espacios)
{
    if (nodo->Hder != NULL)
        ImprimirRec(nodo->Hder, espacios + 1);
    for (int i = 0; i < espacios; i++) {
        std::cout << "      ";
    }
    if (nodo != NULL) {
        std::cout << nodo->Dato;
        if (nodo->Hizq != NULL || nodo->Hder != NULL)
            std::cout << "  {";
        std::cout << "\n";
    }
    if (nodo->Hizq != NULL)
        ImprimirRec(nodo->Hizq, espacios + 1);
}
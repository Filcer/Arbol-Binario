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
    return BusqRec(ref, Raiz)
}

NodoA* Arbol::BusqRec(int ref, NodoA* aux)
{
    NodoA* busqueda = aux;
    NodoA* res;
    if (busqueda->Dato == ref)
        return busqueda;
    if (ref < busqueda->Dato && busqueda->Hizq != NULL)
        res = BusqRec(ref, busqueda->Hizq);
    else if (ref > busqueda->Dato && busqueda->Hder != NULL)
        res = BusqRec(ref, busqueda->Hder);
}

// Agregar nodos al árbol
bool Arbol::AddNodo(int Dato)
{
    if (Buscar(Dato) != NULL)
        return true;
    return AddRec(Dato, this->Raiz); //no se si la raiz esta bien escrita
}

bool Arbol::AddRec(int Dato, NodoA* aux)
{
    bool res;
    if (Dato < aux->Dato) {
        if (aux->Hizq != NULL)
            res = AddRec(Dato, aux->Hizq);
        else {
            NodoA* = NodoA(Dato, aux);
            aux->Hizq = NodoA;
            return true;
        }
    } else if (Dato > aux->Dato) {
        if (aux->Hder != NULL)
            res = AddRec(Dato, aux->Hder) else
            {
                NodoA* nodo = NodoA(Dato, aux);
                aux->Hder = nodo;
                return true;
            }
        return false;
    }
}

void Arbol::intercambio(NodoA* a, NodoA* aux) //escribir bien hijos derecho e izquierdo
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
    if (this->Raiz == NULL) {
        std::cout << "No existe el valor en el arbol" << std::endl;
        return false;
    }
    NodoA* aux = BusqNodo(ref);
    if (aux == NULL) {
        std::cout << "No existe el valor en el arbol" << std::endl;
        return false;
    }

    if (aux->Hizq == NULL && aux->Hder == NULL) //aquí no sé como escribir el hijo derecho
    {
        if (aux->Padre->Hizq == aux) //aquí no sé como escribir el hijo izquierdo
            aux->Padre->Hizq = NULL; //aquí tampoco
        else
            aux->Padre->Hder = NULL; //aquí tampoco
        aux->Padre = NULL;
    }

    if (aux->Hizq != NULL) { //escribir bien hijos derecho e izquierdo
        if (aux->Hizq->Hder == NULL) {
            aux->Padre->Hder = aux->Hizq;
            aux->Hizq->Padre = aux->Padre;
            aux->Padre = NULL;
            aux->Hizq->Hder = aux->Hder;
            aux->Hder->Padre = aux->Hizq;
            aux->Hder = NULL;
            aux->Hizq = NULL;
        } else {
            NodoA* a = aux->Hizq->Hder;
            while (a->Hder != NULL) {
                a = a->Hder;
            }
        }
        if (a->Hizq != NULL) {
            a->Hizq->Padre = a->Padre;
            a->Padre->Hder = a->Hizq;
            a->Hizq = NULL;
        }
        intercambio(a, aux);
        else
        {
            intercambio(aux->Hder, aux);
            return true;
        }

    /*
std::stack<NodoA*> Arbol::Camino(NodoA* aux)
{
	std::stack<NodoA*> Camino;
	while (aux != Raiz){
		Camino.push(aux);
		aux = aux->Padre;
	}
	return Camino;
}

NodoA* Arbol::BusqNodo(int ref)
{
	if(Raiz == NULL)
	{
		std::cout<<"No existen elementos en el arbol"<<std::endl;
		return NULL;
	}
	return BusqRec(ref,Raiz);
}

NodoA* Arbol::BusqRec(int ref, NodoA* aux)
{
	NodoA* Busque = aux;
	NodoA* Res;
	if (Busque->Dato ==ref)
		return Busque;
	if (Busque->Hijos.empty()) 
		return NULL;
	for (int i = 0 ; i < Busque->Hijos.size() ; ++i){
		Res  = BusqRec(ref, Busque->Hijos[i]);
		if (Res != NULL)
			return Res;			
	}
	return NULL;
}

void Arbol::Imprimir()
{
	if (Raiz == NULL)
	{
		cout << "El árbol está vacío" << endl;
	}
}

*/

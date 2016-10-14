#include "Arbol.h"

Arbol::Arbol(int orig)
{
	this->Raiz = new NodoA(orig);
}

Nodo* Arbol::Buscar(int ref){ 
	if(raiz==NULL) //no se sí raiz está bien escrita como nodo
		return NULL;
	return BusqRec(ref,Raiz)
}

Nodo* Arbol::BusqRec(int ref,Nodo* aux){
	Nodo* busqueda=aux;
	Nodo* Res;
	if(busqueda->getDato()==ref) //creo que getDato no está definida en nodo
		return busqueda;
	if(ref<busqueda->getDato() && Hizq != NULL) //checar sintaxis de Hizq
		res=BusqRec(ref,Hizq); // ¿se puede llamar a busqref dentro de busqref?
	else if(ref>busqueda->getDato() && Hder!= NULL) //sintaxis de Hder
		res=BusqRec(ref,Hder);
}


bool Arbol::AddRec(int dato, Nodo* aux)
{
	bool res;
	if(dato<aux.dato){
	    if(Hizq!=NULL) //aquí no sé como escribir el hijo izquierdo
		    res=AddRec(dato,Hizq); //aquí tampoco sé como
	    else{
	    	Nodo new= nodo(dato,aux); 
		aux.Hizq=nodo; //aquí tampoco
		return true;
	    }
	}
	else if(dato>aux.dato){
		if(HDer!=NULL) //aquí no sé como escribir el hijo derecho
			res=AddRec(dato,HDer) //aquí tampoco sé como
		else{
		   Nodo new=nodo(dato,aux);
		   aux.Hder=nodo; //aquí tampoco
		   return true;
		}
		return false;
	}	
}

bool Arbol::AddNodo(int dato)
{
	if(Buscar(dato)!=NULL)
		return true;
	return AddRec(dato,Raiz); //no se si la raiz esta bien escrita		
}

/*
bool Arbol::ElimNodo(int ref)
{
	if (this->Raiz == NULL)
	{
		std::cout << "No existe el valor en el arbol" << std::endl;
		return false;		
	}
	NodoA* aux = BusqNodo(ref);
	if (aux == NULL)
	{
		std::cout<<"No existe el valor en el arbol"<<std::endl;
		return false;
	}
	for (int i = 0 ; i < aux->Hijos.size() ; ++i)
	{
		aux->Padre->Hijos.push_back(aux->Hijos[i]);
		aux->Hijos[i] =aux->Padre;
	}
	aux->Hijos.clear();
	aux->Padre =NULL;
	for (int i  = 0; i < aux->Padre->Hijos.size(); ++i)
	{
		if (aux == aux->Padre->Hijos[i])
		{
			aux->Padre->Hijos.erase(aux->Padre->Hijos.begin()+i);
			return true;
		}
	}
	return false;
}

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
	if (Busque->dato ==ref)
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
	ImprimirRecursivo(Raiz);
}

int Arbol::ImprimirRecursivo(NodoA* nodo)
{
	if (!nodo->Hijos.empty())
	{
		
	}
}
*/

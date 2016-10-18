#include "NodoA.h"

NodoA::NodoA(int dato)
{
    this->Dato = dato;
    this->Padre = NULL;
    this->Hder = NULL;
    this->Hizq = NULL;
}

NodoA::NodoA(int dato, NodoA* Padre)
{
    this->Dato = dato;
    this->Padre = Padre;
    this->Hder = NULL;
    this->Hizq = NULL;
}
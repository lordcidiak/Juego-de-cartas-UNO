#include <iostream>
#include <string>
#include <string.h>
#include "lista.h"
#include <stack>



using namespace std;

template <class T>
sLista<T> *crearLista()
{
  sLista<T> *lista = new sLista<T>;
  lista->cab = NULL;
  lista->tam = 0;
  return lista;
}

template <class T>
bool listaVacia(sLista<T> *lista)
{
  if (lista->tam == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class T>
sNodo<T> *crearNodo(T dato)
{
  sNodo<T> *nodo = new sNodo<T>;
  nodo->dato = dato;
  nodo->sig = NULL;
  nodo->atrs = NULL;
  return nodo;
}

template <class T>
void insertarNodoCartas(sLista<T> *lista, T valor)
{
  sNodo<T> *nodo = crearNodo(valor);
  if (listaVacia(lista) == true)
  {
    lista->cab = nodo;
    lista->cola = nodo;
  }
  else
  {
    lista->cola->sig = nodo;
    lista->cola = nodo;
  }
  lista->tam++;
}

template <class H>
void insertarNodoCartasaJugador(sLista<H> *lista, H valor)
{
  sNodo<H> *nodo = crearNodo(valor);
  if (listaVacia(lista) == true)
  {
    lista->cab = nodo;
    lista->cola = nodo;
    lista->tam++;
    
  }
  else
  {

    lista->cola->sig = nodo;
    lista->cola = nodo;
    lista->tam++;
    
  }

}

template <class T>
void imprimirListaCartas(sLista<T> *lista)
{
  sNodo<T> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->valor << " " << aux->dato->color << aux->dato->numero << endl;
    aux = aux->sig;
  }
}

template <class I>
void imprimirListaJugadoresCabezas(sLista<I> *lista)
{
  sNodo<I> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    aux = aux->sig;
  }
}

template <class I, class J>
void imprimirListaJugadoresCarta(sLista<I> *lista)
{
  sNodo<I> *aux = lista->cab;
  while (aux != NULL)
  {
    cout << aux->dato->nombre << " " << aux->dato->apellido << "" << endl;
    sNodo<J> *auxcarta = aux->dato->cartas->cab;
    while (auxcarta != NULL)
    {
      cout << auxcarta->dato->numero << endl;
      auxcarta = auxcarta->sig;
    }
    aux = aux->sig;
  }
}
template <class T>
void imprimirListaJugadoresColas(sLista<T> *lista)
{
  int i = 0;
  sNodo<T> *node = lista->cola;
  while (node != NULL)
  {
    cout << "222  " << node->dato->nombre << node->dato->apellido << endl;
    node = node->atrs;
  }
}

template <typename V>
void insertarNodojugador(sLista<V> *lista, V valor)
{
  sNodo<V> *newNode = crearNodo(valor);

  if (lista->cab == NULL)
  {
    lista->cab = lista->cola = newNode;
    lista->cab->sig = NULL;
    lista->cola->sig = NULL;
  }
  else
  {
    lista->cola->sig = newNode;
    newNode->atrs = lista->cola;
    lista->cola = newNode;
    lista->cola->sig = NULL;
  }
}

template <typename T>
void imprimirCartasJugador(sLista<T> *auxi2)
{
  sNodo<T> *cartas;
  cartas = auxi2->cab;
  while (cartas != NULL)
  {
    cout << "                                                Carta: "<< setw(9) << cartas->dato->color << setw(10)<< "Valor:"<< setw(5) << cartas->dato->valor <<setw(10)<< "Numero: " << cartas->dato->numero << endl;
    cartas = cartas->sig;
    
  }
}

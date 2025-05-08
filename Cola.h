#pragma once
#include "Nodo.h"
#include <iostream>
#include <functional>
using namespace std;

template<class T>
class Cola {
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola(): inicio(nullptr), fin(nullptr){}

	bool esVacia();
	void enqueue(T elem);
	T dequeue();
	T front();
	void recorrer(function<void(T)> accion);
};


template<class T>
inline bool Cola<T>::esVacia()
{
	return (inicio == nullptr);
}

template<class T>
inline void Cola<T>::enqueue(T elem)
{
	Nodo<T>* nuevoNodo = new Nodo<T>(elem);
	if (esVacia())
	{
		inicio = nuevoNodo;
		fin = inicio;
	}
	else
	{
		fin->siguiente = nuevoNodo;
		fin = nuevoNodo;
	}
	nuevoNodo = NULL;
}

template<class T>
inline T Cola<T>::dequeue()
{
	T dato = inicio->elem;

	if (inicio == fin)
	{
		inicio = NULL;
		fin = NULL;
	}
	else
	{
		inicio = inicio->siguiente;
	}
	return dato;

	return T();
}

template<class T>
inline T Cola<T>::front()
{
	if (!esVacia())
	{
		return inicio->elem;
	}
	return T();
}

template<class T>
inline void Cola<T>::recorrer(function<void(T)> accion)
{
	Nodo<T>* aux = inicio;
	while (aux != nullptr)
	{
		accion(aux->elem);
		aux = aux->siguiente;
	}
}


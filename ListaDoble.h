#pragma once
#include <functional>

typedef unsigned int uint;
using namespace std;

template<class T>
class ListaDoble {
private:
	struct Nodo;
	Nodo* inicial;
	Nodo* final;
	uint lon;

public:
	ListaDoble() : inicial(nullptr), final(nullptr), lon(0) {}
	~ListaDoble();

	bool esVacia();
	int longitud();
	void agregar(T elem);
	void agregarFinal(T elem);
	T* buscar(function<bool(T)> criterio);
	void recorrer(function<void(T)> accion);
};

template<class T>
struct ListaDoble<T>::Nodo {
	T elem;
	Nodo* siguiente;
	Nodo* anterior;
	Nodo(T elem, Nodo* siguiente = nullptr, Nodo* anterior = nullptr) : elem(elem), siguiente(siguiente), anterior(anterior) { }
};

template<class T>
inline ListaDoble<T>::~ListaDoble()
{
	Nodo* aux = inicial;
	while (aux != nullptr)
	{
		inicial = inicial->siguiente;
		delete aux;
		aux = inicial;
		lon--;
	}
}

template<class T>
inline bool ListaDoble<T>::esVacia()
{
	return lon == 0;
}

template<class T>
inline int ListaDoble<T>::longitud()
{
	return lon;
}

template<class T>
inline void ListaDoble<T>::agregar(T elem)
{
	Nodo* nuevoNodo = new Nodo(elem);
	if (inicial == NULL)
	{
		inicial = final = nuevoNodo;
	}
	else
	{
		inicial->anterior = nuevoNodo;
		nuevoNodo->siguiente = inicial;
		inicial = nuevoNodo;
	}
	//inicio = nuevoNodo;
	lon++;
}

template<class T>
inline void ListaDoble<T>::agregarFinal(T elem)
{
	Nodo* nuevoNodo = new Nodo(elem);
	if (inicial == NULL)
	{
		//agregar(elem);
		inicial = final = nuevoNodo;
	}
	else
	{
		final->siguiente = nuevoNodo;
		nuevoNodo->anterior = final;
		final = nuevoNodo;
	}
	lon++;
}

template<class T>
inline T* ListaDoble<T>::buscar(function<bool(T)> criterio)
{
	Nodo* aux = inicial;
	while (aux != nullptr)
	{
		if (criterio(aux->elem))
		{
			return &(aux->elem);
		}
		aux = aux->siguiente;
	}
	return nullptr;
}

template<class T>
inline void ListaDoble<T>::recorrer(function<void(T)> accion)
{
	Nodo* aux = inicial;
	while (aux != nullptr)
	{
		accion(aux->elem);
		aux = aux->siguiente;
	}
}

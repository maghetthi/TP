#pragma once

template<class T>
class Nodo {

public:
	T elem;
	Nodo<T>* siguiente;
	Nodo(T elem, Nodo<T>* sig = nullptr) {
		this->elem = elem;
		this->siguiente = sig;
	}
};

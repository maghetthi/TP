#pragma once
#include <functional>
#include <iostream>
#include "Nodo.h"

using namespace std;
template <class T>
class Lista {
private:
    Nodo<T>* inicio;
    int lon;


public:
    Lista() : inicio(nullptr), lon(0) {}

    ~Lista() {
        Nodo<T>* actual = inicio;
        while (actual)
        {
            inicio = inicio->siguiente;
            delete actual;
            actual = inicio;
        }
    }

    int longitud() {
        return lon;
    }

    bool esVacio() {
        return lon == 0;
    }

    void agregar(T elem) {
        Nodo<T>* nuevoNodo = new Nodo<T>(elem);
        if (!inicio) {
            inicio = nuevoNodo;
        }
        else {
            Nodo<T>* aux = inicio;
            while (aux->siguiente) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevoNodo;
        }
        lon++;
    }

    bool eliminar(function<bool(T)> criterio) {
        Nodo<T>* aux = inicio;
        Nodo<T>* anterior = nullptr;
        while (aux)
        {
            if (criterio(aux->elem))
            {
                if (anterior == nullptr)
                {
                    inicio = inicio->siguiente;
                }
                else
                {
                    anterior->siguiente = aux->siguiente;
                }
                delete aux;
                lon--;
                return true;
            }
            anterior = aux;
            aux = aux->siguiente;
        }
        return false;
    }

    void recorrer(function<void(T&)> accion) {
        Nodo<T>* aux = inicio;
        while (aux)
        {
            accion(aux->elem);
            aux = aux->siguiente;
        }
    }
};

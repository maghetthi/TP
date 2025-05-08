#pragma once
#include <iostream>
#include <string>
#include "Lista.h"
#include "Cola.h"
using namespace std;

class Cancion {
private:
    static int contador;
    string id;
    string titulo;
    string duracion;
    string genero;
    string artista;
    string album;

public:
    Cancion() {
        id = "";
        titulo = "";
        duracion = "";
        genero = "";
        artista = "";
        album = "";
    }
    Cancion(string titulo, string duracion, string genero,
        string artista, string album)
        : titulo(titulo), duracion(duracion),
        genero(genero), artista(artista), album(album) {
        this->id = "C" + to_string(++contador);
    }

    Cancion(string id, string titulo, string duracion, string genero,
        string artista, string album)
        : id(id), titulo(titulo), duracion(duracion),
        genero(genero), artista(artista), album(album) {
    }

    ~Cancion() {}

    void mostrarInformacion() const {
        cout << "ID: " << id << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Duracion: " << duracion << " min" << endl;
        cout << "Genero: " << genero << endl;
        cout << "Artista: " << artista << endl;
        cout << "Album: " << album << endl;
    }

    string getId() { return id; }
    string getTitulo() { return titulo; }
    string getDuracion() { return duracion; }
    string getGenero() { return genero; }
    string getArtista() { return artista; }
    string getAlbum() { return album; }

};
int Cancion::contador = 0;

class SistemaCanciones {
private:
    Lista<Cancion> listaCancion;
    Cola<Cancion> colaCancion;

public:

    Lista<Cancion>& getListaCancion() {
        return listaCancion;
    }

    //lista
    void agregarCancion(Cancion cancion) {
        listaCancion.agregar(cancion);
    }

    void mostrarCanciones() {
        listaCancion.recorrer([](Cancion cancion) {
            cancion.mostrarInformacion();
            cout << "---------------------" << endl;
            });
    }

    void eliminarCancion(string titulo) {
        listaCancion.eliminar([&](Cancion cancion) {
            return cancion.getTitulo() == titulo;
            });
    }

    Cancion* buscarPorID(string id) {
        Cancion* encontrada = nullptr;
        listaCancion.recorrer([&](Cancion& cancion) {
            if (cancion.getId() == id)
            {
                encontrada = &cancion;
            }
            });
        return encontrada;
   }

    //cola
    void agregarACola(Cancion cancion) {
        colaCancion.enqueue(cancion);
    }

    void verCancionesEnCola() {
        colaCancion.recorrer([](Cancion cancion) {
            cancion.mostrarInformacion();
            cout << "---------------------" << endl;
            });
    }
    void reproducirSiguienteCancion() {
        if (!colaCancion.esVacia())
        {
            Cancion cancionActual = colaCancion.front();
            cout << "Reproduciendo ahora: " << endl;
            cancionActual.mostrarInformacion();
            colaCancion.dequeue();
        }
        else
        {
            cout << "No quedan canciones en cola" << endl;
        }
    }
};

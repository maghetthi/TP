#pragma once
#include <iostream>
#include "Lista.h"
#include "Cancion.h"

class Album {
private:
    static int contador;
    string id;
    string titulo;
    Lista<Cancion> canciones;

public:
    Album() {
        id = "";
        titulo = "";
    }
    Album(string titulo): titulo(titulo){
        this->id = "A" + to_string(++contador);
    }
    Album(string id, string titulo) : id(id), titulo(titulo) {}

    string getTitulo() {
        return titulo;
    }

    string getId() {
        return id;
    }

    Lista<Cancion>& getCanciones() {
        return canciones;
    }

    void agregarCancion(Cancion cancion) {
        canciones.agregar(cancion);
    }

    void mostrarCanciones() {
        canciones.recorrer([](Cancion cancion) {
            cancion.mostrarInformacion();
            cout << "------------------------" << endl;
            });
    }

    void eliminarCancion(string titulo) {
        canciones.eliminar([&](Cancion cancion) {
            return cancion.getTitulo() == titulo;
            });
    }
};
int Album::contador = 0;

class SistemaAlbum {
private:
    Lista<Album> listaAlbum;
public:

    void agregarAlbum(Album album) {
        listaAlbum.agregar(album);
    }

    void mostrarTodosAlbumes() {
        listaAlbum.recorrer([](Album album) {
            cout << "Album: " << album.getTitulo() << endl;
            album.mostrarCanciones();
            });
    }
    
    void mostrarAlbumOpciones() {
        int indice = 1;
        listaAlbum.recorrer([&](Album album) {
            cout << indice << album.getTitulo() << " (ID: " << album.getId() << ")" << endl;
            indice++;
            });

        cout << "Ingrese el numero del album que desea ver: ";
        int opcion;
        cin >> opcion;
        if (opcion < 1 || opcion >= indice)
        {
            cout << "Opcion invalida" << endl;
            return;
        }


        int contador = 1;
        listaAlbum.recorrer([&](Album& album) {
            if (contador == opcion)
            {
                cout << "Canciones del album " << album.getTitulo() << endl;
                album.mostrarCanciones();
            }
            contador++;
            });
    }
};
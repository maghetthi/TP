#pragma once
#include <iostream>
#include "Lista.h"
#include "Cancion.h"


using namespace std;

class Playlist {
private:
	static int contador;
	string id;
	string nombre;
	Lista<Cancion> canciones;

public:
	Playlist() {
		id = "";
		nombre = "";
		
	}
	Playlist(string titulo) : nombre(titulo) {
		this->id = "P" + to_string(++contador);
	}
	Playlist(string id, string titulo) : id(id), nombre(titulo) {}

	string getNombre() {
		return nombre;
	}

	string getID() {
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
int Playlist::contador = 0;

class SistemaPlaylist {
private:
	Lista<Playlist> listaPlaylist;
public:
	void agregarPlaylist(Playlist playlist) {
		listaPlaylist.agregar(playlist);
	}

	void eliminarPlaylist(string nombre) {
		listaPlaylist.eliminar([&](Playlist playlist) {
			return playlist.getNombre() == nombre;
			});
	}

	void mostrarPlaylistConOpciones() {
		int indice = 1;
		listaPlaylist.recorrer([&](Playlist playlist) {
			cout << indice << "." << playlist.getNombre() << " (ID: " << playlist.getID() << ")" << endl;
			indice++;
			});

		cout << "Ingrese el numero de la playlist que desea ver: ";
		int opcion;
		cin >> opcion;
		if (opcion < 1 || opcion >= indice)
		{
			cout << "Opcion invalida" << endl;
			return;
		}

		int contador = 1;
		listaPlaylist.recorrer([&](Playlist& playlist) {
			if (contador == opcion)
			{
				cout << "Canciones de la playlist " << playlist.getNombre() << endl;
				playlist.mostrarCanciones();
			}
			contador++;
			});
	}
};

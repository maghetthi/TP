#pragma once
#include <string>
#include <iostream>
#include "Lista.h"
#include "Playlist.h"
#include "ListaDoble.h"
using namespace std;

class Usuario {
private:
	static int contador;
	string id, username, correo, contrasena;
	ListaDoble<Playlist> playlists;

public:
	Usuario(string username, string correo, string contrasena) : username(username), correo(correo), contrasena(contrasena) {
		this->id = "U" + to_string(++contador);
	}

	Usuario(string ig, string username, string correo, string contrasena) : id(id), username(username), correo(correo), contrasena(contrasena) {}

	~Usuario() {}

	ListaDoble<Playlist>& getPlaylist() {
		return playlists;
	}

	void agregarPlaylist(Playlist playlist) {
		playlists.agregar(playlist);
	}
	string getNombre() {
		return username;
	}
	string getCorreo() {
		return correo;
	}
	string getContrasena() {
		return contrasena;
	}

	string getID() {
		return id;
	}
	void mostrar() {
		cout << "Username: " << username << endl;
		cout << "Correo: " << correo << endl;
		cout << "Contraseña: " << contrasena << endl;
	}

};
int Usuario::contador = 0;

class SistemaUsuario {
private:
	ListaDoble<Usuario> listaUsuarios;

public:

	ListaDoble<Usuario>& getListaUsuarios() {
		return listaUsuarios;
	}
	void ingresarUsuario(Usuario usuario) {
		listaUsuarios.agregar(usuario);
	}

	Usuario* buscarPorUsername(string username) {
		return listaUsuarios.buscar([&](Usuario usuario) {
			return usuario.getNombre() == username;
			});
	}

	void mostrarUsuarios() {
		listaUsuarios.recorrer([](Usuario usuario) {
			usuario.mostrar();
			cout << "---------------------------" << endl;
			});
	}

	void RegistrarUsuario()
	{

	}
};
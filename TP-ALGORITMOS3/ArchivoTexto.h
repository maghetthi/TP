#pragma once
#include <fstream>
#include <sstream>
#include "Lista.h"
#include "ListaDoble.h"
#include "Cancion.h"
#include "Usuario.h"
#include "Album.h"
#include "Playlist.h"

using namespace std;
class ArchivoTexto {
public:

	//cancion
		static void cargarCanciones(Lista<Cancion>& listaCancion, string& archivo) {
			ifstream file(archivo);
			if (!file.is_open())
			{
				cout << "Error al abrir el archivo de canciones" << endl;
				return;
			}
			
			string id, titulo, duracion, genero, artista, album;
			while (getline(file, id) &&
				getline(file, titulo) &&
				getline(file, duracion) &&
				getline(file, genero) &&
				getline(file, artista) &&
				getline(file, album))
			{
				Cancion c(id, titulo, duracion, genero, artista, album);
				listaCancion.agregar(c);
			}
			file.close();
		}

		static void guardarCancion(Lista<Cancion>& listaCancion, string archivo) {
			ofstream file(archivo);
			if (!file.is_open())
			{
				cout << "Error al abrir archivo para guardar cancion" << endl;
				return;
			}

			listaCancion.recorrer([&](Cancion& cancion) {
				file << cancion.getId() << endl;
				file << cancion.getTitulo() << endl;
				file << cancion.getDuracion() << endl;
				file << cancion.getGenero() << endl;
				file << cancion.getArtista() << endl;
				file << cancion.getAlbum() << endl;
				});
			file.close();
		}


		//usuarios
		 static void cargarUsuarios(ListaDoble<Usuario>& listaUsuario, Lista<Cancion>& canciones, string& archivo) {
			 ifstream file(archivo);
			 if (!file.is_open())
			 {
				 cout << "Error al abrir el archivo de usuarios" << endl;
				 return;
			 }

			 string id, username, correo, contraseña, linea;
			 while (getline(file, id) &&
				 getline(file, username) &&
				 getline(file, correo) &&
				 getline(file, contraseña))
			 {
				 Usuario u(id, username, correo, contraseña);
				 getline(file, linea);
				 int cantidadPlatlists = stoi(linea);

				 for (int i = 0; i < cantidadPlatlists; i++)
				 {
					 string id, nombre;
					 getline(file, id);
					 getline(file, nombre);
					 getline(file, linea);
					 int cantidadCanciones = stoi(linea);

					 Playlist p(id, nombre);

					 for (int i = 0; i < cantidadCanciones; i++)
					 {
						 string idCancion;
						 getline(file, idCancion);

						 Cancion* cancionEncontrada = nullptr;
						 canciones.recorrer([&](Cancion& cancion) {
							 if (cancion.getId() == idCancion)
							 {
								 cancionEncontrada = &cancion;
							 }
							 });

						 if (cancionEncontrada)
						 {
							 p.agregarCancion(*cancionEncontrada);
						 }
					 }
					 u.getPlaylist().agregar(p);
				 }
				 listaUsuario.agregar(u);
			 }
			 file.close();
		}

		static void guardarUsuario(ListaDoble<Usuario>& listaUsuario, string& archivo) {
			 ofstream file(archivo);
			 if (!file.is_open())
			 {
				 cout << "Error al abrir archivo para guardar usuario" << endl;
				 return;
			 }

			 listaUsuario.recorrer([&](Usuario& usuario) {
				 file << usuario.getID() << endl;
				 file << usuario.getNombre() << endl;
				 file << usuario.getCorreo() << endl;
				 file << usuario.getContrasena() << endl;

				 file << usuario.getPlaylist().longitud() << endl;
				 usuario.getPlaylist().recorrer([&](Playlist& playlist) {
					 file << playlist.getID() << endl;
					 file << playlist.getNombre() << endl;
					 file << playlist.getCanciones().longitud() << endl;

					 playlist.getCanciones().recorrer([&](Cancion& cancion) {
						 file << cancion.getId() << endl;
						 });
					 });
				 });;

			 file.close();
		 }


		 //Album
		 static void cargarAlbum(Lista<Album>& listaAlbum, Lista<Cancion>& canciones, string& archivo) {
			 ifstream file(archivo);
			 if (!file.is_open())
			 {
				 cout << "Error al abrir el archivo del album" << endl;
				 return;
			 }

			 string id, titulo, linea;
			 int cantidadCanciones;
			 while (getline(file, id) &&
				 getline(file, titulo) &&
				 getline(file, linea))
			 {
				 cantidadCanciones = stoi(linea);
				 Album album(id, titulo);

				 for (int i = 0; i < cantidadCanciones; i++)
				 {
					 string idCancion;
					 getline(file, idCancion);

					 Cancion* cancionEncontrada = nullptr;
					 canciones.recorrer([&](Cancion& cancion) {
						 if (cancion.getId() == idCancion && !cancionEncontrada)
						 {
							 cancionEncontrada = &cancion;
						 }
						 });

					 if (cancionEncontrada)
					 {
						 album.agregarCancion(*cancionEncontrada);
					 }
					 else
					 {
						 cout << "No se encontro la cancion con el ID: " << idCancion << endl;
					 }
				 }
				 listaAlbum.agregar(album);
			 }
			 file.close();
		 }
		 static void guardarAlbum(Lista<Album>& listaAlbum, string archivo) {
			 ofstream file(archivo);
			 if (!file.is_open())
			 {
				 cout << "Error al abrir archivo para guardar album" << endl;
				 return;
			 }

			 listaAlbum.recorrer([&](Album& album) {
				 file << album.getId() << endl;
				 file << album.getTitulo() << endl;
				 file << album.getCanciones().longitud() << endl;

				 album.getCanciones().recorrer([&](Cancion& cancion) {
					 file << cancion.getId() << endl;
					 });
				 });
			 file.close();
		 }
};
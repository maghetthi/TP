#pragma once
#include "ArchivoTexto.h"
#include "Usuario.h"
#include "Cancion.h"
#include "Funciones.h"
#include "Menu.h"

class Spotify {
private:
	ListaDoble<Usuario> ListaUsuarios;

	Index* index;
	SistemaUsuario* sistemaUsuario;
	SistemaCanciones* sistemaCanciones;
	
public:
	Spotify()
	{
		index = new Index();
		sistemaUsuario = new SistemaUsuario();
		sistemaCanciones = new SistemaCanciones();
	}

	void cargarDatosDesdeArchivo() {
		string archivoUsuario = "ArchivoUsuario.txt";
		string archivoCancion = "ArchivoCancion.txt";
		ArchivoTexto::cargarUsuarios(sistemaUsuario->getListaUsuarios(), sistemaCanciones->getListaCancion(), archivoUsuario);
		ArchivoTexto::cargarCanciones(sistemaCanciones->getListaCancion(), archivoCancion);
	}

	void guardarDatosDesdeArchivo() {
		string archivoUsuario = "ArchivoUsuario.txt";
		string archivoCancion = "ArchivoCancion.txt";
		ArchivoTexto::guardarUsuario(sistemaUsuario->getListaUsuarios(), archivoUsuario);
		ArchivoTexto::guardarCancion(sistemaCanciones->getListaCancion(), archivoCancion);
	}
	/*void RegistrarUsuario() {

		index->dibujar_MatrizRegistro();
		string username, correo, contrasena;

		cout << c12 << cc1;

		cursor(78, 15); getline(cin, username);
		cursor(77, 22); getline(cin, correo);
		cursor(81, 29); getline(cin, contrasena);

		Usuario nuevoUsuario = Usuario(username, correo, contrasena);
		sistemaUsuario->ingresarUsuario(nuevoUsuario);

		cout << RESET;
	}

	Usuario* IniciarSesion() {
		index->dibujar_MatrizIniciarSesion();

		string username, contrasena;

		cout << c12 << cc1;

		cursor(80, 17); getline(cin, username);
		cursor(83, 25); getline(cin, contrasena);

		Usuario* us = sistemaUsuario->buscarPorUsername(username);

		if (us != nullptr && us->getContrasena() == contrasena)
		{
			cursor(81, 29); cout << c12 << cc1 << "Iniciando sesion..." << RESET; system("pause>0");
			return us;
		}
		else {
			cursor(82, 29); cout << c12 << cc1 << "Usuario invalido" << RESET; system("pause>0");
			return nullptr;
		}

	}*/


	void RegistrarUsuario() {
		//index->dibujar_MatrizRegistro();
		system("cls");
		index->Texto_MatrizRegistro();

		cin.ignore();
		string username, correo, contrasena;
		
		cout << "Ingrese nombre de usuario: ";
		getline(cin, username);
		cout << "Ingrese correo: ";
		getline(cin, correo);
		cout << "Ingrese contraseña: ";
		getline(cin, contrasena);

		Usuario nuevoUsuario = Usuario(username, correo, contrasena);
		sistemaUsuario->ingresarUsuario(nuevoUsuario);
		cout << "Usuario registrado exitosamente!" << endl;
		system("pause");
	}

	Usuario* IniciarSesion() {
		//index->dibujar_MatrizIniciarSesion();
		system("cls");

		index->Texto_MatrizIniciarSesion();
		cin.ignore();
		string username, contrasena;
		cout << "Usuario: ";
		getline(cin, username);
		cout << "Contraseña: ";
		getline(cin, contrasena);

		Usuario* us = sistemaUsuario->buscarPorUsername(username);
		if (us != nullptr && us->getContrasena() == contrasena)
		{
			cout << "Iniciando sesion..." << endl;
			system("pause");
			return us;
		}
		else {
			cout << "Usuario o contraseña invalidos" << endl;
			system("pause");
			return nullptr;
		}
	}

	void agregarCancionesPlaylist(Usuario* usuario) {
		if (usuario->getPlaylist().esVacia())
		{
			cout << "No tienes playlists creadas. Crea una primero" << endl;
			system("pause");
			return;
		}

		cout << "Mostrar Playlists: " << endl;
		int indice = 1;
		ListaDoble<Playlist>& p = usuario->getPlaylist();
		p.recorrer([&](Playlist& playlist) {
			cout << indice++ << ". " << playlist.getNombre();
			});

		int opcion;
		cout << "Selecciona el numero de la playlist: ";
		cin >> opcion;

		cin.ignore();

		if (opcion < 1 || opcion >= indice)
		{
			cout << "Seleccione una opcion valida" << endl;
			system("pause");
			return;
		}

		indice = 1;
		Playlist* playlistElegida = nullptr;
		p.recorrer([&](Playlist& playlist) {
			if (indice == opcion)
			{
				playlistElegida = &playlist;
			}
			indice++;
			});
		
		if (!playlistElegida) return;

		cout << "Canciones disponibles: " << endl;
		sistemaCanciones->mostrarCanciones();

		cout << "Ingresa el ID de la cancion a agregar: ";
		string iDcancion;
		getline(cin, iDcancion);

		Cancion* c = sistemaCanciones->buscarPorID(iDcancion);

		if (c == nullptr)
		{
			cout << "No se encontro una cancion con ese id" << endl;
			system("pause");
			return;
		}

		playlistElegida->agregarCancion(*c);
		cout << "Cancion agregada a la playlist exitosamente" << endl;
		system("pause");
	}

	void mostrarPlaylists(Usuario* usuario) {
		cout << "Playlists creadas" << endl;

		int indice = 1;
		ListaDoble<Playlist>& p = usuario->getPlaylist();
		p.recorrer([&](Playlist& playlist) {
			cout << indice++ << ". " << playlist.getNombre() << endl;
			});
		system("pause");
	}

	void toString()
	{
		sistemaUsuario->mostrarUsuarios();
	}

	void provisional(Usuario* usuario)
	{
		int op;
		cin.ignore(); // Limpiar el buffer de entrada

		do {
			system("cls");
			cout << "===== MENU DE USUARIO =====" << endl;
			cout << "1. Crear Playlist" << endl;
			cout << "2. Agregar canciones a la playlist" << endl;
			cout << "3. Ver lista de playlists" << endl;
			cout << "4. buscar usuario" << endl;
			cout << "5. Cerrar sesion" << endl;
			cout << "Opcion: ";
			cin >> op;

			switch (op) {
			case 1: {
				cin.ignore();
				string nombre;
				cout << "Ingresa el nombre de la Playlist: ";
				getline(cin, nombre);
				Playlist nuevaPlaylist(nombre);
				usuario->agregarPlaylist(nuevaPlaylist);
			}
				break;
			case 2:
				agregarCancionesPlaylist(usuario);
				
				break;
			case 3:
				mostrarPlaylists(usuario);
				
				break;
			case 4:
				cout << "Implementar seleccionar playlist" << endl;
				
				break;
			case 5:
				guardarDatosDesdeArchivo();
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (op != 5);
	}
};

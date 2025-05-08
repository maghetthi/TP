#include "pch.h"
#include "iostream"
#include "SistemaSpotify.h"

using namespace System;
using namespace std;
//
//void ventana() {
//	Console::SetWindowSize(181, 46);
//	Console::CursorVisible = false;
//}

int main()
{
	//ventana();

	Index* index = new Index();
	Spotify* spotify = new Spotify();
	char tecla1, tecla2;

	spotify->cargarDatosDesdeArchivo();

	do {

		//index->dibujar_MatrizInicio();
		system("cls");
		cout << "===== BIENVENIDO A SPOTIFY CLON =====" << endl;
		cout << "1. Iniciar Sesion" << endl;
		cout << "2. Registrarse" << endl;
		cout << "3. Salir" << endl;
		cout << "Seleccione una opcion: ";

		if (_kbhit()) 
		{
			tecla1 = _getch();

			switch (tecla1)
			{
			case '1':
			{
				Usuario* u = spotify->IniciarSesion();
				if (u != nullptr)
				{
					spotify->provisional(u);
				}
				/*if (spotify->IniciarSesion() != nullptr)
				{
					


				}*/
				break;
			}
			case '2': 
			{
				spotify->RegistrarUsuario(); break;
			}
			case '3':
			{
				exit(0);
				break;
			}

			default:
				tecla2 = error();
				break;
			}
		} 


	} while (tecla1 != '3');


	system("pause>0");
    return 0;
}

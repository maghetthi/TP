#pragma once
#include "conio.h"

using namespace std;
using namespace System;

//FOREGROUND
#define c1 "\x1B[38;2;0;0;0m"
#define c2 "\x1B[38;2;10;10;10m"
#define c3 "\x1B[38;2;15;15;15m"
#define c4 "\x1B[38;2;20;20;20m"
#define c5 "\x1B[38;2;25;25;25m"
#define c6 "\x1B[38;2;30;30;30m"
#define c7 "\x1B[38;2;35;35;35m"
#define c8 "\x1B[38;2;40;40;40m"
#define c9 "\x1B[38;2;29;185;84m"
#define c10 "\x1B[38;2;255;255;255m"
#define c11 "\x1B[38;2;242;242;242m"
#define c12 "\x1B[38;2;128;128;128m"

#define RESET   "\x1b[0m"

//BACKGROUND
#define cc1 "\x1B[48;2;0;0;0m"
#define cc9 "\x1B[48;2;29;185;84m"

void colores(int op) {
	switch (op) {
	case 1:
		cout << c1 << char(219) << RESET;
		break;
	case 2:
		cout << c2 << char(219) << RESET;
		break;
	case 3:
		cout << c3 << char(219);
		break;
	case 4:
		cout << c4 << char(219);
		break;
	case 5:
		cout << c5 << char(219) << RESET;
		break;
	case 6:
		cout << c6 << char(219) << RESET;
		break;
	case 7:
		cout << c7 << char(219) << RESET;
		break;
	case 8:
		cout << c8 << char(219) << RESET;
		break;
	case 9:
		cout << c9 << char(219) << RESET;
		break;
	case 10:
		cout << c10 << char(219) << RESET;
		break;
	case 11:
		cout << c11 << char(219) << RESET;
		break;
	case 12:
		cout << c12 << char(219) << RESET;
		break;
	}
}

void cursor(int x, int y) {
	Console::SetCursorPosition(x, y);
}

int** Matriz(int y, int x) {
	int** aux = new int* [y];
	for (int i = 0; i < y; i++) {
		aux[i] = new int[x];
	}
	return aux;
}

void DibujarMatriz(int** Matriz, int x, int y, int width, int leght, int fondo) {
	for (int i = 0; i < leght; i++) {
		cursor(x, y + i);
		for (int j = 0; j < width; j++) {
			if (Matriz[i][j] == 0)
			{
				colores(fondo);
			}
			else
			{
				colores(Matriz[i][j]);
			}
		}
	}
}

char error()
{
	char tecla2;	
	do
	{
		system("cls");
		cout << cc1;
		cursor(75, 24); cout << c10 << "ERROR!";
		cursor(55, 25); cout << c10 << "Tecla incorrecta, presiona [Esc] para volver al menu";

		tecla2 = _getch();

	} while (tecla2 != char(27));

	return tecla2;
}
#include "tablero.h"

void inicializarTablero(char tablero[ALTO][ANCHO], char fichas[NUM_FICHAS])
{
	for (short j = 0; j < ANCHO; j++)
	{
		tablero[0][j] = VACIO;
	}

	for (short i = 1; i < ALTO; i++) {
		for (short j = 0; j < ANCHO; j++) {
			short indiceFicha = rand() % NUM_FICHAS;
			char ficharand = fichas[indiceFicha];
			tablero[i][j] = ficharand;
		}
	}

	short randPosArriba = rand() % ANCHO;
	tablero[0][randPosArriba] = fichas[rand() % NUM_FICHAS];
	short randPosArriba2;
	do
	{
		randPosArriba2 = rand() % ANCHO;
	} while (randPosArriba == randPosArriba2);
	tablero[0][randPosArriba2] = fichas[rand() % NUM_FICHAS];
}

void imprimirTablero(char  tablero[ALTO][ANCHO])
{
	std::cout << "\\ / \\ / \\ / \\ / \\ / \\ /" << std::endl;
	for (short i = 0; i < ALTO; i++) {
		for (short j = 0; j < ANCHO; j++) {
			std::cout << "|";
			std::cout << tablero[i][j];
			std::cout << "| ";
		}
		std::cout << std::endl;
	}
	std::cout << "''' ''' ''' ''' ''' '''" << std::endl;
	std::cout << " 1   2   3   4   5   6 " << std::endl;
}

bool columnaLlena(char tablero[ALTO][ANCHO], short indiceCol)
{
	return (tablero[0][indiceCol] != VACIO);
}

bool columnaTotalmenteVacia(char tablero[ALTO][ANCHO], short indiceCol)
{
	return tablero[ALTO-1][indiceCol] == VACIO;
}

bool comprobarVictoria(char tablero[ALTO][ANCHO])
{
	bool completado = true;
	for (short i = 0; i < ANCHO && completado; i++)
	{
		if (columnaTotalmenteVacia(tablero, i))
		{
			continue;
		}

		for (short j = 1; j < ALTO && completado; j++)
		{
			if (tablero[j][i] != tablero[j - 1][i])
			{
				completado = false;
			}
		}
	}

	return completado;
}

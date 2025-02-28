#include "jugada.h"
#include "tablero.h"

void pedirSource(short& indiceSource)
{
	bool error = false;
	do
	{
		if (error)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Introduce una posicion valida.";
		}
		std::cout << "\nPosicion que quieres mover (1 - 6): " << std::flush;
		std::cin >> indiceSource;
		error = indiceSource < 1 || indiceSource > 6 || std::cin.fail();
	} while (error);
	indiceSource -= 1;
}

void pedirDestino(short& indiceDestino, short indiceSource)
{
	bool error = false;
	do
	{
		if (error)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Introduce una posicion valida.";
		}
		std::cout << "\nPosicion donde quieres mover (1 - 6): " << std::flush;
		std::cin >> indiceDestino;
		error = indiceDestino < 1 || indiceDestino > 6 || std::cin.fail() || indiceSource == indiceDestino-1;
	} while (error);
	indiceDestino -= 1;
}

void moverContenido(short indiceSource, short indiceDestino, char tablero[ALTO][ANCHO])
{
	char elementoAMover = ' ';
	for (short i = 0; i < ALTO; i++)
	{
		if (tablero[i][indiceSource] != VACIO)
		{
			elementoAMover = tablero[i][indiceSource];
			tablero[i][indiceSource] = VACIO;
			break;
		}
	}

	for (short i = ALTO-1; i >= 0; i--)
	{
		if (tablero[i][indiceDestino] == VACIO)
		{
			tablero[i][indiceDestino] = elementoAMover;
			break;
		}
	}

}

short calcularPuntuacion(char tablero[ALTO][ANCHO], short intentos)
{
	short puntuacion = 0;

	for (short i = 0; i < ANCHO; i++)
	{
		if (columnaTotalmenteVacia(tablero, i))
		{
			puntuacion += 50;
			continue;
		}

		//columna llena de elemetos iguales (no vacía)
		else if ((tablero[ALTO - 1][i] == tablero[ALTO - 2][i] &&
			tablero[0][i] == tablero[ALTO - 1][i]) && (tablero[ALTO - 1][i] != VACIO))
		{
			puntuacion += 30;
		}

		//columna con elementos iguales, pero no llena del todo
		else if ((tablero[ALTO-1][i] == tablero[ALTO - 2][i]) 
			&& tablero[0][i] == VACIO)
		{
			puntuacion += 30;
		}
	}

	puntuacion += 3 * intentos;

	return puntuacion;
}


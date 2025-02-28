#include "tablero.h"
#include "jugada.h"

int main() {
	srand(time(NULL));

	short posicionMover = -1, posicionFinal = -1;
	char tablero[ALTO][ANCHO];
	char fichas[NUM_FICHAS] = { 'X', 'O', '#', 'S' };
	bool gameOver = false;
	short intentos = NUM_INTENTOS;

	inicializarTablero(tablero, fichas);
	short opcionMenu = 0;


	switch (opcionMenu)
	{
	case 0:
		
		std::cout << "------WATER COLOR SORT------\n" << std::endl;
		std::cout << "\t1 - Nueva partida" << std::endl;
		std::cout << "\t2 - Scores" << std::endl;
		std::cout << "\t3 - Salir\n" << std::endl;
		std::cout << "Escoje una opcion: " << std::flush;
		std::cin >> opcionMenu;

		while (std::cin.fail() || opcionMenu < 0 || opcionMenu > 3) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << std::endl;
			std::cout << "Introduce una opcion correcta: " << std::flush;
			std::cin >> opcionMenu;
		}

	case 1:
		gameOver = false;
		while (!gameOver)
		{
			system("cls");
			imprimirTablero(tablero);

			{
				bool error = false;
				short opcion = -1;
				do
				{
					if (error)
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Introduce una opcion valida.";
					}
					std::cout << "¿Que quieres hacer?" << std::endl;
					std::cout << "\t1 - Llenar botella" << std::endl;
					std::cout << "\t2 - Volver al menu" << std::endl;
					std::cin >> opcion;
					error = opcion < 1 || opcion > 2 || std::cin.fail();
				} while (error);

				if (opcion == 2)
				{
					opcionMenu = 0;
					gameOver = true;
				}
			}
		

			if (intentos <= 0)
			{
				std::cout << "\nTe quedaste sin intentos" << std::endl;
				std::cout << "Puntuacion final: " << calcularPuntuacion(tablero, intentos) << std::endl;
				gameOver = true;
				continue;
			}
			std::cout << "\nIntentos restantes: " << intentos << std::endl;
			intentos--;

			pedirSource(posicionMover);
			while (columnaTotalmenteVacia(tablero, posicionMover))
			{
				std::cout << "Elige una columna con contenido";
				pedirSource(posicionMover);
			}

		
			pedirDestino(posicionFinal, posicionMover);
			while (columnaLlena(tablero, posicionFinal))
			{
				std::cout << "Elige una columna vacia";
				pedirDestino(posicionFinal, posicionMover);
			}

			moverContenido(posicionMover, posicionFinal, tablero);


			if (comprobarVictoria(tablero))
			{
				std::cout << "\n¡Has ganado!" << std::endl;
				std::cout << "Puntuacion final: " << calcularPuntuacion(tablero, intentos) << std::endl;
				gameOver = true;
			}
		}
		break;

	case 2:

		break;

	case 3:

		break;

	default:
		break;
	}

	return 0;
}
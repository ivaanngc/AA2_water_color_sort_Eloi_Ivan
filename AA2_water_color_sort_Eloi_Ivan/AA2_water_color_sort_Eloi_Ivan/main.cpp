#include "defines.h"


int main() {

	int posicionmover, posicionfinal;
	char tablero[ALTO][ANCHO];
	char fichas[] = { 'X', 'O', '#', 'S' };

	for (int i = 0; i < ALTO; i++) {
		for (int j = 0; j < ANCHO; j++) {
			tablero[i][j] = ' ';
		}
	}


	std::cout << "\\ / \\ / \\ / \\ / \\ / \\ /" << std::endl;
	for (int i = 0; i < ALTO; i++) {
		for (int j = 0; j < ANCHO; j++) {
			std::cout << "|";
			std::cout << tablero[i][j];
			std::cout << "| ";
		}
		std::cout << std::endl;
	}
	std::cout << "''' ''' ''' ''' ''' '''" << std::endl;
	std::cout << " 1   2   3   4   5   6 " << std::endl;

	std::cout << "Posicion que quieres mover: \n";
	std::cin >> posicionmover;
	std::cout << "Posicion donde quieres mover: \n";
	std::cin >> posicionfinal;


	return 0;
}
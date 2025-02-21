#include <iostream>
#include <fstream>
#define ANCHO 6
#define ALTO 3


int main() {

	char tablero[ALTO][ANCHO];

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

	return 0;
}
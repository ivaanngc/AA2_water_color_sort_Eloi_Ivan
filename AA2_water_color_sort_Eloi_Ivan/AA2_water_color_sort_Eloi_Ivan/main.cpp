#include <iostream>
#include <fstream>
#define ANCHO 6
#define ALTO 3


int main() {

	char tablero[ALTO][ANCHO];

	for (int i = 0; i < ALTO; i++) {
		for (int j = 0; j < ANCHO; j++) {
			tablero[i][j] = '-';
		}
	}

	for (int i = 0; i < ALTO; i++) {
		for (int j = 0; j < ANCHO; j++) {
			std::cout << tablero[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}
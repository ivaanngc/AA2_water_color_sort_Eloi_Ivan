#include "scores.h"

void guardarScore(int puntuacion) {
	
	std::ofstream ficheroGuardado(NOMBRE_FICHERO, std::ios::app | std::ios::binary);
	if (!ficheroGuardado.is_open()) {
		std::cout << "Error al abrir el fichero" << std::endl;
		return;
	}

	std::string inputNombre;

	std::cout << "\nIntroduce tu nombre: " << std::flush;
	std::cin >> inputNombre;

	size_t tamNombre = inputNombre.size();
	ficheroGuardado.write(reinterpret_cast<char*>(&tamNombre), sizeof(size_t));
	ficheroGuardado.write(inputNombre.c_str(), sizeof(char)*inputNombre.size());
	ficheroGuardado.write(reinterpret_cast<char*>(&puntuacion), sizeof(int));
	ficheroGuardado.close();

	std::cout << "\nPuntuacion gradada como: " << inputNombre << " " << puntuacion << std::endl;
	system("pause");
	system("cls");
}

void leerScores() {
	
	std::ifstream ficheroLeer(NOMBRE_FICHERO, std::ios::binary);
	if (!ficheroLeer.is_open()) {
		std::cout << "Error al abrir el fichero" << std::endl;
		return;
	}

	while (!ficheroLeer.eof()) {

		size_t tamNombre;
		ficheroLeer.read(reinterpret_cast<char*>(&tamNombre), sizeof(size_t));
		char* temp = new char[tamNombre + 1];
		ficheroLeer.read(temp, tamNombre);
		if (temp[0] == 'Í') {
			delete[] temp;
			break;
		}
		temp[tamNombre] = '\0';
		std::string nombre = temp;
		delete[] temp;

		int puntuacion;
		ficheroLeer.read(reinterpret_cast<char*>(&puntuacion), sizeof(int));

		std::cout << nombre << ": " << puntuacion << std::endl;
	}
	
	ficheroLeer.close();
}
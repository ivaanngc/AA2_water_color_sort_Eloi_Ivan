#pragma once
#include "defines.h"

void inicializarTablero(char tablero[ALTO][ANCHO], char fichas[NUM_FICHAS]);
void imprimirTablero(char  tablero[ALTO][ANCHO]);
bool columnaLlena(char tablero[ALTO][ANCHO], short indiceCol);
bool columnaTotalmenteVacia(char tablero[ALTO][ANCHO], short indiceCol);
bool comprobarVictoria(char tablero[ALTO][ANCHO]);
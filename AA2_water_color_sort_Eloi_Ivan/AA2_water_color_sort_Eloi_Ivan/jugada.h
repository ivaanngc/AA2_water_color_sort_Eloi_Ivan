#pragma once
#include"defines.h"

void pedirSource(short& indiceSource);
void pedirDestino(short& indiceDestino, short indiceSource);
void moverContenido(short indiceSource, short indiceDestino, char tablero[ALTO][ANCHO]);
short calcularPuntuacion(char tablero[ALTO][ANCHO], short intentos);
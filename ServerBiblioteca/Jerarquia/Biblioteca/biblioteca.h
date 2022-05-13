#include "../../BD/sqlite3.h"

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

typedef struct {
	int idBiblioteca;
	char nombre[40];
	int aforo;
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];
} Biblioteca;

void anadirBiblioteca(sqlite3 *db, int result, Biblioteca biblioteca);
void imprimirBibliotecas(sqlite3 *db, Biblioteca biblioteca);
void eliminarBibliotecas(sqlite3 *db, int result, char cod[100]);
void eliminarTodasBibliotecas(sqlite3 *db, int result);

#endif /* BIBLIOTECA_H_ */

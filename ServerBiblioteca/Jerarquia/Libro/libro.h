#include "../../BD/sqlite3.h"

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct {
	int idLibro;
	char isbn[13];
	char titulo[20];
	char autor[20];
	char genero[20];
	int paginas;
} Libro;

void anadirLibro(sqlite3 *db, int result, Libro libro);
void imprimirLibro(sqlite3 *db, Libro libro);
void eliminarLibro(sqlite3 *db, int result, char cod[100]);
void eliminarTodosLibros(sqlite3 *db, int result);

#endif

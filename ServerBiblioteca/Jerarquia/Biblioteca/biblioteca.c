#include "biblioteca.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../BD/BD.h"
#include "../../BD/sqlite3.h"
#include "../../Log/logger.h"

void anadirBiblioteca(sqlite3 *db, int result, Biblioteca biblioteca) {
	result = insertBiblioteca(db, biblioteca.nombre, biblioteca.aforo,
			biblioteca.estado, biblioteca.genero, biblioteca.instalacion,
			biblioteca.barrio);
	if (result != SQLITE_OK) {
		LOG_PRINT("Error al insertar la biblioteca.\n");
		LOG_PRINT("%s%n", sqlite3_errmsg(db));
	}
}

void imprimirBibliotecas(sqlite3 *db, Biblioteca biblioteca) {
	printf("ID: %i\n", biblioteca.idBiblioteca);
	printf("NOMBRE: %s\n", biblioteca.nombre);
	printf("AFORO: %i\n", biblioteca.aforo);
	printf("ESTADO: %s\n", biblioteca.estado);
	printf("GENERO: %s\n", biblioteca.genero);
	printf("INSTALACIONES: %s\n", biblioteca.instalacion);
	printf("BARRIO: %s\n", biblioteca.barrio);

}

void eliminarBibliotecas(sqlite3 *db, int result, char cod[100]) {
	result = deleteBibliotecas(db, cod);
	if (result != SQLITE_OK) {
		LOG_PRINT("Error al eliminar la biblioteca.\n");
		LOG_PRINT("%s\n", sqlite3_errmsg(db));
	}
}

void eliminarTodasBibliotecas(sqlite3 *db, int result) {
	result = deleteAllBibliotecas(db);
	if (result != SQLITE_OK) {
		LOG_PRINT("Error al eliminar todas las bibliotecas.\n");
		LOG_PRINT("%s\n", sqlite3_errmsg(db));
	}
}

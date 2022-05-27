#include "socio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../BD/BD.h"
#include "../../BD/sqlite3.h"
#include "../../Log/logger.h"

void anadirSocio(sqlite3 *db, int result, Socio socio) {
	result = insertSocio(db, socio.nombre, socio.apellido, socio.DNI,
			socio.correo, socio.residencia, socio.codigoPostal);
	if (result != SQLITE_OK) {
		LOG_PRINT("Error al insertar el socio.\n");
		LOG_PRINT("%s%n", sqlite3_errmsg(db));
	}
}

void imprimirSocio(sqlite3 *db, Socio socio) {
	printf("NOMBRE: %s\n", socio.nombre);
	printf("APELLIDO: %s\n", socio.apellido);
	printf("DNI: %s\n", socio.DNI);
	printf("CORREO: %s\n", socio.correo);
	printf("RESIDENCIA: %s\n", socio.residencia);
	printf("CODIGO POSTAL: %i\n", socio.codigoPostal);
}

void eliminarSocio(sqlite3 *db, int result, char cod[100]) {
	result = deleteSocios(db, cod);
	if (result != SQLITE_OK) {
		LOG_PRINT("Error al eliminar el socio.\n");
		LOG_PRINT("%s\n", sqlite3_errmsg(db));
	}
}

void eliminarTodosSocios(sqlite3 *db, int result) {
	result = deleteAllSocios(db);
	if (result != SQLITE_OK) {
		LOG_PRINT("Error al eliminar todos los socios.\n");
		LOG_PRINT("%s\n", sqlite3_errmsg(db));
	}
}


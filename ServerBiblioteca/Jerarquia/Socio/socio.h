#include "../../BD/sqlite3.h"

#ifndef SOCIO_H_
#define SOCIO_H_

typedef struct {
	char nombre[20];
	char apellido[20];
	char DNI;
	char correo[20];
	char residencia[30];
	int codigoPostal;
// lista de reservas
} Socio;

void anadirSocio(sqlite3 *db, int result, Socio socio);
void imprimirSocio(sqlite3 *db, Socio socio);
void eliminarSocio(sqlite3 *db, int result, char cod[100]);
void eliminarTodosSocios(sqlite3 *db, int result);

#endif /* SOCIO_H_ */

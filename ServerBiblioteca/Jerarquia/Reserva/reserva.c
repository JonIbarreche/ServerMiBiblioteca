#include "reserva.h"
#include "../Usuario/usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../BD/BD.h"
#include "../../BD/sqlite3.h"

void anadirReserva(sqlite3 *db, int result, Reserva reserva) {
	result = insertReserva(db, reserva.usuario.nomUsuario, reserva.biblioteca.nombre);
	if (result != SQLITE_OK) {
		printf("Error al insertar la reserva.\n");
		printf("%s%n", sqlite3_errmsg(db));
	}
}

void imprimirReservas(sqlite3 *db, Reserva reserva) {
	printf("ID: %i\n", reserva.idReserva);
	printf("USUARIO: %s\n", reserva.usuario.nomUsuario);
	printf("BIBLIOTECA: %s\n", reserva.biblioteca.nombre);
}

void eliminarReserva(sqlite3 *db, int result, char cod[100]) {
	result = deleteReservas(db, cod);
	if (result != SQLITE_OK) {
		printf("Error al eliminar la reserva.\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}

void eliminarTodasReservas(sqlite3 *db, int result) {
	result = deleteAllReservas(db);
	if (result != SQLITE_OK) {
		printf("Error al eliminar todos las reservas.\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}


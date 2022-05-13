#include "../../BD/sqlite3.h"

#ifndef RESERVA_H_
#define RESERVA_H_

#include "../../Jerarquia/Usuario/usuario.h"
#include "../../Jerarquia/Biblioteca/biblioteca.h"

typedef struct {
	int idReserva;
	Usuario usuario;
	Biblioteca biblioteca;
} Reserva;

void anadirReserva(sqlite3 *db, int result, Reserva reserva);
void imprimirReservas(sqlite3 *db, Reserva reserva);
void eliminarReserva(sqlite3 *db, int result, char cod[100]);
void eliminarTodasReservas(sqlite3 *db, int result);

#endif

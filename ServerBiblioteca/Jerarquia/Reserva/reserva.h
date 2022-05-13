#include "../../BD/sqlite3.h"

#ifndef RESERVA_H_
#define RESERVA_H_

#include "../../Jerarquia/Usuario/usuario.h"
#include "../../Jerarquia/Libro/libro.h"
//typedef struct{
//	char fechaInicio[8];
//    char fechaFinal[8];
//}Fecha;

typedef struct {
	int idReserva;
	char concepto[100];
	//Fecha fecha;
	char fechaInicio[8];
	char fechaFinal[8];
	Usuario usuario;
	Libro libro;
} Reserva;

void anadirReserva(sqlite3 *db, int result, Reserva reserva);
void imprimirReservas(sqlite3 *db, Reserva reserva);
void eliminarReserva(sqlite3 *db, int result, char cod[100]);
void eliminarTodasReservas(sqlite3 *db, int result);

#endif

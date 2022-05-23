/*
 * BD.h
 *
 *  Created on: 2 abr. 2022
 *      Author: jonib
 */

#ifndef BD_BD_H_
#define BD_BD_H_
#include "../Jerarquia/Usuario/usuario.h"
#include "../Jerarquia/Socio/socio.h"
#include "../Jerarquia/Reserva/reserva.h"
#include "../Jerarquia/Biblioteca/biblioteca.h"
#include "sqlite3.h"

int insertUsuario(sqlite3 *db, char nombre[], char apellido[],
		char nomUsuario[], char contrasenya[]);
int insertSocio(sqlite3 *db, char nombre[], char apellido[], int DNI,
		char correo[], char residencia[], int codigoPostal);
int insertBiblioteca(sqlite3 *db, char nombre[], int aforo, char estado[],
		char genero[], char instalacion[], char barrio[]);
int insertReserva(sqlite3 *db, char nomUsuario[], char nombre[]);

int imprimirUsuarios(sqlite3 *db);
int imprimirSocios(sqlite3 *db);
int imprimirBiblioteca(sqlite3 *db);
int imprimirReserva(sqlite3 *db);

int deleteUsuario(sqlite3 *db, char cod[100]);
int deleteSocios(sqlite3 *db, char cod[100]);
int deleteBibliotecas(sqlite3 *db, char cod[100]);
int deleteReservas(sqlite3 *db, char cod[100]);

int deleteAllUsuarios(sqlite3 *db);
int deleteAllSocios(sqlite3 *db);
int deleteAllBibliotecas(sqlite3 *db);
int deleteAllReservas(sqlite3 *db);

Usuario getUsuario(sqlite3 *db, char cod[100]);
Socio getSocio(sqlite3 *db, char cod[100]);
Biblioteca getBiblioteca(sqlite3 *db, char cod[100]);
Reserva getReserva(sqlite3 *db, char cod[100]);

Usuario* getUsuarios(sqlite3 *db);
Biblioteca* getBibliotecas(sqlite3 *db);
Reserva* getReservas(sqlite3 *db);

#endif /* BD_BD_H_ */

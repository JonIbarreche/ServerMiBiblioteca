#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "BD.h"
#include "../Jerarquia/Usuario/usuario.h"
#include "../Jerarquia/Socio/socio.h"
#include "../Jerarquia/Reserva/reserva.h"
#include "../Jerarquia/Libro/libro.h"
#include "../Jerarquia/Biblioteca/biblioteca.h"

int insertUsuario(sqlite3 *db, char nombre[], char apellido[],
		char nomUsuario[], char contrasenya[]) {
	sqlite3_stmt *stmt;

	char sql[] =
			"insert into usuario (idUsuario, nombre, apellido, nomUsuario, contrasenya) values (NULL, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, apellido, strlen(apellido),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, nomUsuario, strlen(nomUsuario),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, contrasenya, strlen(contrasenya),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Usuario table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertSocio(sqlite3 *db, char nombre[], char apellido[], int DNI,
		char correo[], char residencia[], int codigoPostal) {
	sqlite3_stmt *stmt;

	char sql[] =
			"insert into socio (nombre, apellido, DNI, correo, residencia, codigoPostal) values (?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char charDNI[9];
	sprintf(charDNI, "%d", DNI);
	char charCP[9];
	sprintf(charCP, "%d", codigoPostal);

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, apellido, strlen(apellido),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, charDNI, strlen(charDNI),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, correo, strlen(correo), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, residencia, strlen(residencia),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, charCP, strlen(charCP), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Socio table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertLibro(sqlite3 *db, char isbn[], char titulo[], char autor[],
		char genero[], int paginas) {
	sqlite3_stmt *stmt;

	char sql[] =
			"insert into libro (idLibro, isbn, titulo, autor, genero, paginas) values (NULL, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char charPag[10];
	sprintf(charPag, "%d", paginas);

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, isbn, strlen(isbn), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, titulo, strlen(titulo), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, autor, strlen(autor), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, genero, strlen(genero), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, charPag, strlen(charPag),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Libro table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertBiblioteca(sqlite3 *db, char nombre[], int aforo, char estado[],
		char genero[], char instalacion[], char barrio[]) {
	sqlite3_stmt *stmt;

	char sql[] =
			"insert into biblioteca (idBiblioteca, nombre, aforo, estado, genero, instalacion, barrio) values (NULL, ?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char charAforo[20];
	sprintf(charAforo, "%d", aforo);

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, charAforo, strlen(charAforo),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, estado, strlen(estado), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, genero, strlen(genero), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, instalacion, strlen(instalacion),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, barrio, strlen(barrio), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Biblioteca table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertReserva(sqlite3 *db, int id, char concepto[], char fechaInicio[],
		char fechaFinal[], char nomUsuario[], char isbn[]) {
	sqlite3_stmt *stmt;




	char sql[] =
			"insert into reserva (concepto, fechaInicio, fechaFinal, nomUsuario, isbn, idReserva) values (?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, concepto, strlen(concepto),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, fechaInicio, strlen(fechaInicio),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, fechaFinal, strlen(fechaFinal),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, nomUsuario, strlen(nomUsuario),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, isbn, strlen(isbn), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 6, id);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Reserva table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

Usuario getUsuario(sqlite3 *db, char cod[100]) {
	sqlite3_stmt *stmt;
	Usuario u;

	char sql[] =
			"select idUsuario, nombre, apellido, nomUsuario, contrasenya from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	//Los atributos de Usuario que se recibirán
	char idUsuario[100];
	char nombre[100];
	char apellido[100];
	char nomUsuario[100];
	char contrasenya[100];

	printf("\n");
	printf("\n");
	printf("USUARIO:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			//idUsuario = sqlite3_column_int(stmt, 0);
			strcpy(idUsuario, (char*) sqlite3_column_text(stmt, 0));
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char*) sqlite3_column_text(stmt, 2));
			strcpy(nomUsuario, (char*) sqlite3_column_text(stmt, 3));
			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 4));
			if (!strcmp(cod, idUsuario)) {
				u.idUsuario = atoi(idUsuario);
				strcpy(u.nombre, nombre);
				strcpy(u.apellido, apellido);
				strcpy(u.nomUsuario, nomUsuario);
				strcpy(u.contrasenya, contrasenya);
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return u;
}

Socio getSocio(sqlite3 *db, char cod[100]) {

	sqlite3_stmt *stmt;
	Socio s;

	char sql[] =
			"select nombre, apellido, DNI, correo, residencia, codigoPostal from socio";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	char nombre[20];
	char apellido[20];
	char DNI[20];
	char correo[20];
	char residencia[30];
	char codigoPostal[20];

	printf("\n");
	printf("\n");
	printf("SOCIO:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 0));
			strcpy(apellido, (char*) sqlite3_column_text(stmt, 1));
			strcpy(DNI, (char*) sqlite3_column_text(stmt, 2));
			//DNI = sqlite3_column_int(stmt, 2);
			strcpy(correo, (char*) sqlite3_column_text(stmt, 3));
			strcpy(residencia, (char*) sqlite3_column_text(stmt, 4));
			strcpy(codigoPostal, (char*) sqlite3_column_text(stmt, 5));
			//codigoPostal = sqlite3_column_int(stmt, 5);
			if (!strcmp(cod, DNI)) {
				strcpy(s.nombre, nombre);
				strcpy(s.apellido, apellido);
				s.DNI = atoi(DNI);
				strcpy(s.correo, correo);
				strcpy(s.residencia, residencia);
				s.codigoPostal = codigoPostal;
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return s;
}

Libro getLibro(sqlite3 *db, char cod[100]) {

	sqlite3_stmt *stmt;
	Libro l;

	char sql[] =
			"select idLibro, isbn, titulo, autor, genero, paginas from libro";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	char idLibro[20];
	char isbn[13];
	char titulo[20];
	char autor[20];
	char genero[20];
	char paginas[20];

	printf("\n");
	printf("\n");
	printf("LIBRO:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			//idLibro = sqlite3_column_int(stmt, 0);
			strcpy(idLibro, (char*) sqlite3_column_text(stmt, 0));
			strcpy(isbn, (char*) sqlite3_column_text(stmt, 1));
			strcpy(titulo, (char*) sqlite3_column_text(stmt, 2));
			strcpy(autor, (char*) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char*) sqlite3_column_text(stmt, 4));
			//paginas = sqlite3_column_int(stmt, 5);
			strcpy(paginas, (char*) sqlite3_column_text(stmt, 5));

			if (!strcmp(cod, idLibro)) {
				l.idLibro = atoi(idLibro);
				strcpy(l.isbn, isbn);
				strcpy(l.titulo, titulo);
				strcpy(l.autor, autor);
				strcpy(l.genero, genero);
				l.paginas = paginas;
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return l;

}

Biblioteca getBiblioteca(sqlite3 *db, char cod[100]) {
	sqlite3_stmt *stmt;
	Biblioteca b;

	char sql[] =
			"select idBiblioteca, nombre, aforo, estado, genero, instalacion, barrio from biblioteca";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	char idBiblioteca[20];
	char nombre[40];
	char aforo[20];
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];

	printf("\n");
	printf("\n");
	printf("BIBLIOTECA:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			//idBiblioteca = sqlite3_column_int(stmt, 0);
			strcpy(idBiblioteca, (char*) sqlite3_column_text(stmt, 0));
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			strcpy(aforo, (char*) sqlite3_column_text(stmt, 2));
			//aforo = sqlite3_column_int(stmt, 2);
			strcpy(estado, (char*) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char*) sqlite3_column_text(stmt, 4));
			strcpy(instalacion, (char*) sqlite3_column_text(stmt, 5));
			strcpy(barrio, (char*) sqlite3_column_text(stmt, 6));
			if (!strcmp(cod, idBiblioteca)) {
				b.idBiblioteca = atoi(idBiblioteca);
				strcpy(b.nombre, nombre);
				b.aforo = aforo;
				strcpy(b.estado, estado);
				strcpy(b.genero, genero);
				strcpy(b.instalacion, instalacion);
				strcpy(b.barrio, barrio);
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return b;
}

Reserva getReserva(sqlite3 *db, char cod[100]) {

	sqlite3_stmt *stmt;
	Reserva r;

	char sql[] =
			"select idReserva, concepto, fechaInicio, fechaFinal, nomUsuario, isbn from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	char idReserva[20];
	char concepto[100];
	char fechaInicio[8];
	char fechaFinal[8];
	char nomUsuario[20];
	char isbn[13];

	printf("\n");
	printf("\n");
	printf("RESERVA:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			//idReserva = sqlite3_column_int(stmt, 0);
			strcpy(idReserva, (char*) sqlite3_column_text(stmt, 0));
			strcpy(concepto, (char*) sqlite3_column_text(stmt, 1));
			strcpy(fechaInicio, (char*) sqlite3_column_text(stmt, 2));
			strcpy(fechaFinal, (char*) sqlite3_column_text(stmt, 3));
			strcpy(nomUsuario, (char*) sqlite3_column_text(stmt, 4));
			strcpy(isbn, (char*) sqlite3_column_text(stmt, 5));
			if (!strcmp(cod, idReserva)) {
				r.idReserva = atoi(idReserva);
				strcpy(r.concepto, concepto);
				strcpy(r.fechaInicio, fechaInicio);
				strcpy(r.fechaFinal, fechaFinal);
				strcpy(r.usuario.nomUsuario, nomUsuario);
				strcpy(r.libro.isbn, isbn);
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return r;

}

int imprimirUsuarios(sqlite3 *db) {

	sqlite3_stmt *stmt;

	char sql[] = "select * from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idUsuario;
	char nombre[20];
	char apellido[20];
	char nomUsuario[20];
	char contrasenya[20];

	printf("\n");
	printf("==================================\n");
	printf("Usuarios:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idUsuario = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char*) sqlite3_column_text(stmt, 2));
			strcpy(nomUsuario, (char*) sqlite3_column_text(stmt, 3));
			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 4));
			printf("Id: %d Nombre: %s Apellido: %s Nick: %s Contrasena: %s\n",
					idUsuario, nombre, apellido, nomUsuario, contrasenya);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirSocios(sqlite3 *db) {

	sqlite3_stmt *stmt;

	char sql[] = "select * from socio";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char nombre[20];
	char apellido[20];
	int dni;
	char correo[20];
	char residencia[30];
	int codigoPostal;

	printf("\n");
	printf("==================================\n");
	printf("Socios:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 0));
			strcpy(apellido, (char*) sqlite3_column_text(stmt, 1));
			dni = sqlite3_column_int(stmt, 2);
			strcpy(correo, (char*) sqlite3_column_text(stmt, 3));
			strcpy(residencia, (char*) sqlite3_column_text(stmt, 4));
			codigoPostal = sqlite3_column_int(stmt, 5);
			printf(
					"Nombre: %s Apellido: %s DNI: %d Correo: %s Residencia: %s Codigo postal: %d\n",
					nombre, apellido, dni, correo, residencia, codigoPostal);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirLibros(sqlite3 *db) {

	sqlite3_stmt *stmt;

	char sql[] = "select * from libro";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idLibro;
	char isbn[20];
	char titulo[20];
	char autor[20];
	char genero[20];
	int paginas;

	printf("\n");
	printf("==================================\n");
	printf("Usuarios:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idLibro = sqlite3_column_int(stmt, 0);
			strcpy(isbn, (char*) sqlite3_column_text(stmt, 1));
			strcpy(titulo, (char*) sqlite3_column_text(stmt, 2));
			strcpy(autor, (char*) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char*) sqlite3_column_text(stmt, 4));
			paginas = sqlite3_column_int(stmt, 5);
			printf(
					"Id: %d Isbn: %s Titulo: %s Autor: %s Genero: %s Paginas: %d\n",
					idLibro, isbn, titulo, autor, genero, paginas);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirBiblioteca(sqlite3 *db) {

	sqlite3_stmt *stmt;

	char sql[] = "select * from biblioteca";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idBiblioteca;
	char nombre[10];
	int aforo;
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];

	printf("\n");
	printf("==================================\n");
	printf("Bibliotecas:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idBiblioteca = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			aforo = sqlite3_column_int(stmt, 2);
			strcpy(estado, (char*) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char*) sqlite3_column_text(stmt, 4));
			strcpy(instalacion, (char*) sqlite3_column_text(stmt, 5));
			strcpy(barrio, (char*) sqlite3_column_text(stmt, 6));
			printf(
					"Id: %d Nombre: %s Aforo: %d Estado: %s Genero: %s Instalacion: %s Barrio: %s\n",
					idBiblioteca, nombre, aforo, estado, genero, instalacion,
					barrio);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirReserva(sqlite3 *db) {

	sqlite3_stmt *stmt;

	char sql[] = "select * from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idReserva;
	char nombre[20];
	char concepto[100];
	char fechaInicio[8];
	char fechaFinal[8];
	char nomUsuario[20];
	char isbn[13];

	printf("\n");
	printf("==================================\n");
	printf("Reservas:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idReserva = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			strcpy(concepto, (char*) sqlite3_column_text(stmt, 2));
			strcpy(fechaInicio, (char*) sqlite3_column_text(stmt, 3));
			strcpy(fechaFinal, (char*) sqlite3_column_text(stmt, 4));
			strcpy(nomUsuario, (char*) sqlite3_column_text(stmt, 5));
			strcpy(isbn, (char*) sqlite3_column_text(stmt, 6));
			printf(
					"Id: %d Nombre: %s Concepto: %s Fecha inicio: %s Fecha final: %s NomUsuario: %s Isbn: %s\n",
					idReserva, nombre, concepto, fechaInicio, fechaFinal,
					nomUsuario, isbn);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int deleteUsuario(sqlite3 *db, char cod[100]) {
	sqlite3_stmt *stmt;

	char sql[100] = "delete from usuario where nomUsuario =";
	strcat(sql, cod);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteSocios(sqlite3 *db, char cod[100]) {
	sqlite3_stmt *stmt;

	char sql[100] = "delete from socio where DNI =";
	strcat(sql, cod);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteLibros(sqlite3 *db, char cod[100]) {
	sqlite3_stmt *stmt;

	char sql[100] = "delete from libro where isbn =";
	strcat(sql, cod);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteBibliotecas(sqlite3 *db, char cod[100]) {
	sqlite3_stmt *stmt;

	char sql[100] = "delete from biblioteca where idBiblioteca =";
	strcat(sql, cod);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteReservas(sqlite3 *db, char cod[100]) {
	sqlite3_stmt *stmt;

	char sql[100] = "delete from reserva where idReserva =";
	strcat(sql, cod);

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllUsuarios(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllSocios(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from socio";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllLibros(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from libro";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllBibliotecas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from biblioteca";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllReservas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

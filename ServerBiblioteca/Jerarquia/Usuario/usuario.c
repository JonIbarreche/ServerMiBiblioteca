#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../BD/BD.h"
#include "../../BD/sqlite3.h"

void anadirUsuario(sqlite3 *db, int result, Usuario usuario) {
	result = insertUsuario(db, usuario.nombre, usuario.apellido,
			usuario.nomUsuario, usuario.contrasenya);
	if (result != SQLITE_OK) {
		printf("Error al insertar el usuario.\n");
		printf("%s%n", sqlite3_errmsg(db));
	}
}

void imprimirUsuario(sqlite3 *db, Usuario usuario) {
	printf("ID: %i\n", usuario.idUsuario);
	printf("NOMBRE: %s\n", usuario.nombre);
	printf("APELLIDO: %s\n", usuario.apellido);
	printf("NICK DEL USUARIO: %s\n", usuario.nomUsuario);
	printf("CONTRASENA: %s\n", usuario.contrasenya);
}

void eliminarUsuario(sqlite3 *db, int result, char cod[100]) {
	result = deleteUsuario(db, cod);
	if (result != SQLITE_OK) {
		printf("Error al eliminar el usuario.\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}

void eliminarTodosUsuarios(sqlite3 *db, int result) {
	result = deleteAllUsuarios(db);
	if (result != SQLITE_OK) {
		printf("Error al eliminar todos los usuarios.\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}


#include "../../BD/sqlite3.h"

#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct {
	int idUsuario;
	char nombre[20];
	char apellido[20];
	char nomUsuario[20];
	char contrasenya[20];
// lista de reservas
} Usuario;

void anadirUsuario(sqlite3 *db, int result, Usuario usuario);
void imprimirUsuario(sqlite3 *db, Usuario usuario);
void eliminarUsuario(sqlite3 *db, int result, char cod[100]);
void eliminarTodosUsuarios(sqlite3 *db, int result);

#endif /* USUARIO_H_ */

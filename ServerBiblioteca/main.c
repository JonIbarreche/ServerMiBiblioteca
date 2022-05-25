/*
 * main.c
 *
 *  Created on: 6 may. 2022
 *      Author: jonib
 */

// IMPORTANT: Winsock Library ("ws2_32") should be linked
#include <stdio.h>
#include "BD/sqlite3.h"
#include "BD/BD.h"
#include "Jerarquia/Socio/socio.h"
#include "Jerarquia/Usuario/usuario.h"
#include "Jerarquia/Biblioteca/biblioteca.h"
#include "Jerarquia/Reserva/reserva.h"
#include <winsock2.h>
#include <math.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) {

	sqlite3 *db;

	int result = sqlite3_open("BD/DB.db", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
	}

	int idDefaultU = 0;
	int idDefaultL = 0;
	int idDefaultB = 0;
	int idDefaultR = 0;

//		proyectoLog("Ejecutando log...");
//		proyectoWarning("Warnig log...");
//		proyectoError("Error log");

	Usuario u;
	u.idUsuario = idDefaultU;
	strcpy(u.nombre, "Unai");
	strcpy(u.apellido, "Fernandez");
	strcpy(u.nomUsuario, "unaifj");
	strcpy(u.contrasenya, "1234");

	Usuario u2;
	u2.idUsuario = idDefaultU;
	strcpy(u2.nombre, "Jon");
	strcpy(u2.apellido, "Ibarretxe");
	strcpy(u2.nomUsuario, "jonibr");
	strcpy(u2.contrasenya, "123");

	Usuario u3;
	u3.idUsuario = idDefaultU;
	strcpy(u3.nombre, "Andrea");
	strcpy(u3.apellido, "Martinez");
	strcpy(u3.nomUsuario, "andream");
	strcpy(u3.contrasenya, "123");

	Usuario u4;
	u4.idUsuario = idDefaultU;
	strcpy(u4.nombre, "Samuel");
	strcpy(u4.apellido, "Martin");
	strcpy(u4.nomUsuario, "samuelunpiti");
	strcpy(u4.contrasenya, "123");

	Usuario u5;
	u5.idUsuario = idDefaultU;
	strcpy(u5.nombre, "ad");
	strcpy(u5.apellido, "ad");
	strcpy(u5.nomUsuario, "admin");
	strcpy(u5.contrasenya, "admin");

	Socio s;
	strcpy(s.nombre, "Iker");
	strcpy(s.apellido, "Jimenez");
	s.DNI = 79423450;
	strcpy(s.correo, "iker@gmail.com");
	strcpy(s.residencia, "Bilbao");
	s.codigoPostal = 48010;

	Socio s1;
	strcpy(s1.nombre, "Ander");
	strcpy(s1.apellido, "Cortes");
	s1.DNI = 78397293;
	strcpy(s1.correo, "ander@gmail.com");
	strcpy(s1.residencia, "Bilbao");
	s1.codigoPostal = 48011;

	Socio s2;
	strcpy(s2.nombre, "Ibai");
	strcpy(s2.apellido, "llanos");
	s2.DNI = 78777293;
	strcpy(s2.correo, "iker@gmail.com");
	strcpy(s2.residencia, "Bilbao");
	s2.codigoPostal = 48012;

	Biblioteca b;
	b.idBiblioteca = idDefaultB;
	strcpy(b.nombre, "Biblioteca Basurto");
	b.aforo = 30;
	strcpy(b.estado, "08:00 - 20:00");
	strcpy(b.genero, "Docencia");
	strcpy(b.instalacion, "Zona Fumadores");
	strcpy(b.barrio, "Basurto");

	Biblioteca b1;
	b1.idBiblioteca = idDefaultB;
	strcpy(b1.nombre, "Biblioteca Indautxu");
	b1.aforo = 40;
	strcpy(b1.estado, "08:30 - 19:00");
	strcpy(b1.genero, "Arte");
	strcpy(b1.instalacion, "Sala Ordenadores");
	strcpy(b1.barrio, "Indautxu");

	Biblioteca b2;
	b2.idBiblioteca = idDefaultB;
	strcpy(b2.nombre, "Biblioteca Erandio");
	b2.aforo = 10;
	strcpy(b2.estado, "10:00 - 17:00");
	strcpy(b2.genero, "Urbano");
	strcpy(b2.instalacion, "Sala Estudio");
	strcpy(b2.barrio, "Erandio");

	Reserva r;
	r.idReserva = 1;
	strcpy(r.usuario.nomUsuario, "jonibr");
	strcpy(r.biblioteca.nombre, "Bilbao Biblio");

	Reserva r1;
	r.idReserva = 2;
	strcpy(r.usuario.nomUsuario, "unaifj");
	strcpy(r.biblioteca.nombre, "Barakaldo Biblio");

	Reserva r2;
	r.idReserva = 3;
	strcpy(r.usuario.nomUsuario, "samu");
	strcpy(r.biblioteca.nombre, "Artxanda");

	//adminTxt(u5);

	eliminarTodosUsuarios(db, result);

	eliminarTodosSocios(db, result);
	eliminarTodasBibliotecas(db, result);
	eliminarTodasReservas(db, result);

	anadirUsuario(db, result, u);
	anadirUsuario(db, result, u2);
	anadirUsuario(db, result, u3);
	anadirUsuario(db, result, u4);
	anadirUsuario(db, result, u5);

	anadirSocio(db, result, s);
	anadirSocio(db, result, s1);
	anadirSocio(db, result, s2);

	anadirBiblioteca(db, result, b);
	anadirBiblioteca(db, result, b1);
	anadirBiblioteca(db, result, b2);

	anadirReserva(db, result, r);
	anadirReserva(db, result, r1);
	anadirReserva(db, result, r2);

//		imprimirUsuarios(db);
//		imprimirSocios(db);
//		imprimirLibros(db);
//		imprimirBiblioteca(db);
//		imprimirReserva(db);
//
//		inicioAdmin(db, result);

	WSADATA wsaData;
	SOCKET conn_socket;
	SOCKET comm_socket;
	struct sockaddr_in server;
	struct sockaddr_in client;
	char sendBuff[512], recvBuff[512];

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((conn_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//BIND (the IP/port with socket)
	if (bind(conn_socket, (struct sockaddr*) &server,
			sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	printf("Bind done.\n");

	//LISTEN to incoming connections (socket server moves to listening mode)
	if (listen(conn_socket, 1) == SOCKET_ERROR) {
		printf("Listen failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	//ACCEPT incoming connections (server keeps waiting for them)
	printf("Waiting for incoming connections...\n");
	int stsize = sizeof(struct sockaddr);
	comm_socket = accept(conn_socket, (struct sockaddr*) &client, &stsize);
	// Using comm_socket is able to send/receive data to/from connected client
	if (comm_socket == INVALID_SOCKET) {
		printf("accept failed with error code : %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}
	printf("Incomming connection from: %s (%d)\n", inet_ntoa(client.sin_addr),
			ntohs(client.sin_port));

	// Closing the listening sockets (is not going to be used anymore)
	closesocket(conn_socket);

	//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)
	printf("Waiting for incoming commands from client... \n");
	do {
		recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

		printf("Command receivede: %s \n", recvBuff);

		Usuario u;
		Reserva r;
		Socio o;

		if (strcmp(recvBuff, "ANYADIRUSUARIO") == 0) {
			int contador = 0;
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			while (strcmp(recvBuff, "ANYADIRUSUARIO-END") != 0) {
				contador++;
				if (contador == 1) {
					u.idUsuario = atoi(recvBuff);
				}
				if (contador == 2) {
					strcpy(u.nombre, recvBuff);
				}
				if (contador == 3) {
					strcpy(u.apellido, recvBuff);
				}
				if (contador == 4) {
					strcpy(u.nomUsuario, recvBuff);
				}
				if (contador == 5) {
					strcpy(u.contrasenya, recvBuff);
				}

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			}
			anadirUsuario(db, result, u);
			imprimirUsuarios(db);
		}

		if (strcmp(recvBuff, "GETUSUARIOS") == 0) {
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			if (strcmp(recvBuff, "GETUSUARIOS-END") == 0);
//			printf("hola");
			Usuario *usuarios = getUsuarios(db);

			int i;
			for (i = 0; i < 50; i++) {
//				printf("adios");
				if (usuarios[i].idUsuario != 0) {
//					printf("adios333");
					sprintf(sendBuff, "%s", "USERDATA");
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
//					printf("adios2");
					sprintf(sendBuff, "%d", usuarios[i].idUsuario);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", usuarios[i].nombre);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", usuarios[i].apellido);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", usuarios[i].nomUsuario);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", usuarios[i].contrasenya);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
				} else {
//					printf("adios4444");
					i = 50;
					sprintf(sendBuff, "%s", "ENDUSERDATA");
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				}
			}
		}

		if (strcmp(recvBuff, "ANYADIRSOCIO") == 0) {
			int contador = 0;
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			while (strcmp(recvBuff, "ANYADIRSOCIO-END") != 0) {
				contador++;
				if (contador == 1) {
					strcpy(o.nombre, recvBuff);
				}
				if (contador == 2) {
					strcpy(o.apellido, recvBuff);
				}
				if (contador == 3) {
					o.DNI = atoi(recvBuff);
				}
				if (contador == 4) {
					strcpy(o.correo, recvBuff);
				}
				if (contador == 5) {
					strcpy(o.residencia, recvBuff);
				}
				if (contador == 5) {
					o.codigoPostal = atoi(recvBuff);
				}

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			}
			anadirSocio(db, result, o);
			imprimirSocios(db);
		}

		if (strcmp(recvBuff, "GETBIBLIOTECAS") == 0) {
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			if (strcmp(recvBuff, "GETBIBLIOTECAS-END") == 0);

			Biblioteca *bibliotecas = (Biblioteca*) malloc(50 * sizeof(Biblioteca));
			bibliotecas = getBibliotecas(db);

			int i;
			for (i = 0; i < 50; i++) {
				if (bibliotecas[i].idBiblioteca != 0) {
					sprintf(sendBuff, "%s", "FINBUSCA");
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					sprintf(sendBuff, "%d", bibliotecas[i].idBiblioteca);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", bibliotecas[i].nombre);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %d \n", sendBuff);
					sprintf(sendBuff, "%d", bibliotecas[i].aforo);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", bibliotecas[i].estado);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", bibliotecas[i].genero);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", bibliotecas[i].instalacion);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%s", bibliotecas[i].barrio);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
				} else {
					i = 50;
					sprintf(sendBuff, "%s", "FINBUSCA-END");
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				}
			}
		}

		if (strcmp(recvBuff, "MENOSAFORO") == 0) {
			int contador = 0;
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			while (strcmp(recvBuff, "MENOSAFORO-END") != 0) {
				contador++;

				if (contador == 1) {
					printf("Codigo de reserva: %s\n", recvBuff);
					r.idReserva = atoi(recvBuff);
				}
				if (contador == 2) {
					printf("Nombre de usuario: %d\n", recvBuff);
					strcpy(r.biblioteca.nombre, recvBuff);
				}
				if (contador == 3) {
					printf("Nombre de biblioteca: %d\n", recvBuff);
					strcpy(r.biblioteca.nombre, recvBuff);
				}

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			}
			insertReserva(db, r.usuario.nomUsuario, r.biblioteca.nombre);
			imprimirReserva(db);
		}

		if (strcmp(recvBuff, "GETRESERVAS") == 0) {
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			if (strcmp(recvBuff, "GETRESERVAS-END") == 0);

			Reserva *reservas = getReservas(db);

			int i = 0;
			for (i = 0; i < 50; i++) {
				if (reservas[i].idReserva != 0) {
					sprintf(sendBuff, "%d", reservas[i].idReserva);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%d", reservas[i].usuario.nomUsuario);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
					sprintf(sendBuff, "%d", reservas[i].biblioteca.nombre);
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
					printf("Response sent: %s \n", sendBuff);
				} else {
					i = 50;
					sprintf(sendBuff, "%s", "FINRESERVAS");
					send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				}
			}
		}

		if (strcmp(recvBuff, "EXIT") == 0)
			break;

	} while (1);

	// CLOSING the sockets and cleaning Winsock...
	closesocket(comm_socket);
	WSACleanup();

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error closing database\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	return 0;
}

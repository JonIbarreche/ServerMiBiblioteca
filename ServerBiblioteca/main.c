/*
 * main.c
 *
 *  Created on: 6 may. 2022
 *      Author: jonib
 */

// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include "BD/sqlite3.h"
#include "Jerarquia/Socio/socio.h"
#include "Jerarquia/Usuario/usuario.h"
#include "Jerarquia/Biblioteca/biblioteca.h"
#include "Jerarquia/Reserva/reserva.h"
#include <winsock2.h>
#include <math.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) {

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
	do
	{
		recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

		printf("Command received: %s \n", recvBuff);

		if (strcmp(recvBuff, "SUMAR") == 0)
		{
			int suma = 0;
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			while (strcmp(recvBuff, "SUMAR-END") != 0)
			{
				int n = atoi(recvBuff);
				suma += n;
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			}
			sprintf(sendBuff, "%d", suma);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}

		if (strcmp(recvBuff, "RAIZ") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			int n = atoi(recvBuff);
			float raiz = sqrt(n);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			if (strcmp(recvBuff, "RAIZ-END") == 0); // Nada que hacer

			sprintf(sendBuff, "%f", raiz);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}

		if (strcmp(recvBuff, "IP") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			if (strcmp(recvBuff, "IP-END") == 0); // Nada que hacer

			strcpy(sendBuff, inet_ntoa(server.sin_addr));
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}

		if (strcmp(recvBuff, "EXIT") == 0)
			break;

	} while (1);

	// CLOSING the sockets and cleaning Winsock...
	closesocket(comm_socket);
	WSACleanup();

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

//		Libro l;
//		l.idLibro = idDefaultL;
//		strcpy(l.isbn, "9923");
//		strcpy(l.titulo, "Cien años");
//		strcpy(l.autor, "Latifi");
//		strcpy(l.genero, "Guerra");
//		l.paginas = 150;
//
//		Libro l1;
//		l1.idLibro = idDefaultL;
//		strcpy(l1.isbn, "8823");
//		strcpy(l1.titulo, "Romancero");
//		strcpy(l1.autor, "Alonso");
//		strcpy(l1.genero, "Romance");
//		l1.paginas = 260;
//
//		Libro l2;
//		l2.idLibro = idDefaultL;
//		strcpy(l2.isbn, "7723");
//		strcpy(l2.titulo, "Educacion");
//		strcpy(l2.autor, "Samuel");
//		strcpy(l2.genero, "Educativo");
//		l2.paginas = 300;

		Biblioteca b;
		b.idBiblioteca = idDefaultB;
		strcpy(b.nombre, "Biblioteca Basurto");
		b.aforo = 300;
		strcpy(b.estado, "08:00 - 20:00");
		strcpy(b.genero, "Militar");
		strcpy(b.instalacion, "Zona Fumadores");
		strcpy(b.barrio, "Basurto");

		Biblioteca b1;
		b1.idBiblioteca = idDefaultB;
		strcpy(b1.nombre, "Biblioteca Indautxu");
		b1.aforo = 400;
		strcpy(b1.estado, "08:30 - 19:00");
		strcpy(b1.genero, "Arte");
		strcpy(b1.instalacion, "Sala Ordenadores");
		strcpy(b1.barrio, "Indautxu");

		Biblioteca b2;
		b2.idBiblioteca = idDefaultB;
		strcpy(b2.nombre, "Biblioteca Erandio");
		b2.aforo = 100;
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

		sqlite3 *db;

		int result = sqlite3_open("BD/DB.db", &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
		}

		eliminarTodosUsuarios(db, result);


		eliminarTodosSocios(db, result);
//		eliminarTodosLibros(db, result);
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

//		anadirLibro(db, result, l);
//		anadirLibro(db, result, l1);
//		anadirLibro(db, result, l2);

		anadirBiblioteca(db, result, b);
		anadirBiblioteca(db, result, b1);
		anadirBiblioteca(db, result, b2);

		//anadirReserva(db, result, r);
		//anadirReserva(db, result, r1);
		//anadirReserva(db, result, r2);

//		imprimirUsuarios(db);
//		imprimirSocios(db);
//		imprimirLibros(db);
//		imprimirBiblioteca(db);
//		imprimirReserva(db);
//
//		inicioAdmin(db, result);


		result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			printf("Error closing database\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

	return 0;
}

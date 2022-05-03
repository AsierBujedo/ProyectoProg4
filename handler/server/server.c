/*
 * server.c
 *
 *  Created on: 29 abr 2022
 *      Author: asier
 */

#include "server.h"
#include <stdio.h>
#include <winsock2.h>
#include <math.h>
#include "../logger/logger.h"
#include "../properties/properties.h"

static WSADATA wsaData;
static SOCKET conn_socket;
static SOCKET comm_socket;
static struct sockaddr_in server;
static struct sockaddr_in client;

char sendBuff[512], recvBuff[512];

int initServer() {

	Properties prp;
	loadProperties(&prp, "config.prop");

	char *SERVER_IP = prp.propValue[0];
	int SERVER_PORT;

	sscanf(prp.propValue[1], "%i", &SERVER_PORT);

	printf("\nPreparando servidor...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Fallo con la apertura. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Inicializado correctamente\n");

	//SOCKET creation
	if ((conn_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("No se ha podido crear el socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket creado.\n");

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

	printf("servidor abierto en %s:%i.\n", SERVER_IP, SERVER_PORT);

	//LISTEN to incoming connections (socket server moves to listening mode)
	if (listen(conn_socket, 1) == SOCKET_ERROR) {
		printf("Fallo con la escucha de nuevas conexiones: %d",
				WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	//ACCEPT incoming connections (server keeps waiting for them)
	printf("Esperando nuevas conexiones...\n");
	int stsize = sizeof(struct sockaddr);
	comm_socket = accept(conn_socket, (struct sockaddr*) &client, &stsize);
	// Using comm_socket is able to send/receive data to/from connected client
	if (comm_socket == INVALID_SOCKET) {
		printf("Solicitud de conexion recibida pero no establecida : %d",
				WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}
	printf("Conexion establecida con %s (%d)\n", inet_ntoa(client.sin_addr),
			ntohs(client.sin_port));




	do {
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

			printf("Command received: %s \n", recvBuff);

			if (strcmp(recvBuff, "SUMAR") == 0) {
				int suma = 0;
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				while (strcmp(recvBuff, "SUMAR-END") != 0) {
					int n = atoi(recvBuff);
					suma += n;
					recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				}
				sprintf(sendBuff, "%d", suma);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Response sent: %s \n", sendBuff);
			}

			if (strcmp(recvBuff, "RAIZ") == 0) {
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				int n = atoi(recvBuff);
				float raiz = sqrt(n);

				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				if (strcmp(recvBuff, "RAIZ-END") == 0)
					; // Nada que hacer

				sprintf(sendBuff, "%f", raiz);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Response sent: %s \n", sendBuff);
			}

			if (strcmp(recvBuff, "IP") == 0) {
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
				if (strcmp(recvBuff, "IP-END") == 0)
					; // Nada que hacer

				strcpy(sendBuff, inet_ntoa(server.sin_addr));
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				printf("Response sent: %s \n", sendBuff);
			}

			if (strcmp(recvBuff, "EXIT") == 0)
				break;

		} while (1);
}

int closeServer() {
	closesocket(conn_socket);
	closesocket(comm_socket);
	return 1;
}




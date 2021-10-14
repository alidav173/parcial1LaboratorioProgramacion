#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct{
	char nombreCliente[50];
	unsigned long int cuit;
	char direccion[50];
	char localidad[50];
	int idCliente;
	int isEmpty;
}cliente;

cliente IngresarCliente();
int CargarCliente(cliente arrayCliente[], int tamanio);
int BuscarPrimerEspacioLibre(cliente arrayCliente[], int tamanio);
void InicializarArrayClientes (cliente arrayCliente[], int tamanio);
int ModificarClienteGuardado (cliente arrayCliente[], int tamanio);
int BajaCliente (cliente arrayCliente[], int tamanio);
void MostrarCliente (cliente unCliente);



#endif

#ifndef PEDIDO_H_
#define PEDIDO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tipoDesecho.h"
#include "informe.h"
#include "cliente.h"



typedef struct
{
	int idcliente;
	int cantKg;
	int idPedido;
	int estadoPedido;
	int tipoResiduo;
	int isEmpty;

}pedido;

pedido CrearPedidoRecoleccion(tipoDesecho arrayDesecho[], int tamanio);
int cargarPedido(pedido arrayPedido[], int tamanio,tipoDesecho arrayDesecho[], int tamanioDesecho);
int ProcesarResiduos(pedido arrayPedido[], int tamanio, tipoDesecho arrayDesecho[], int tamanioDesecho);
void InicializarArrayPedidos (pedido arrayPedido[], int tamanio);
void MostrarPedido (pedido unPedido);
int BuscarPrimerEspacioLibre (pedido arrayPedido[], int tamanio);


#endif

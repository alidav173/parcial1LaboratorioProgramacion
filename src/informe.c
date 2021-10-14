
#include "informe.h"

#define LLENO 1
#define PENDIENTE 2

void ImprimirClientes(cliente arrayCliente[], int tamanio){
	int i;
	printf("Id\tNombre\tCUIT\tDirección\tLocalidad\n");
	for(i = 0; i < tamanio; i++){
		if(arrayCliente[i].isEmpty == LLENO){
			MostrarCliente( arrayCliente[i]);
		}

	}

}


void ImprimirPedidos(pedido arrayPedido[], int tamanio){
	int i;
	printf("IdCliente\tIdPEdido\n");
	for(i = 0; i < tamanio; i++){
		if(arrayPedido[i].isEmpty == LLENO){
			MostrarPedido( arrayPedido[i]);
		}

	}

}


void ImprimirClientesConPedidosPendientes(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido){
	int i;
	int j;
	printf("Id\tNombre\tCUIT\tDirección\tLocalidad\n");
	for(i = 0; i < tamanio; i++){
		for(j = 0; j < tamanioPedido; j++){
		if((arrayCliente[i].idCliente == arrayPedidos[j].idcliente) && (arrayPedidos[j].estadoPedido = PENDIENTE) ){
			MostrarCliente( arrayCliente[i]);
		}

	}
	}

}

void ImprimirClientesConMasPedidosPendientes(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido){

}
void ImprimirClientesConMasPedidosCompletados(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido){

}
void ImprimirClientesConMasPedidos(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido){

}


#ifndef INFORME_H_
#define INFORME_H_


#include "cliente.h"
#include "pedido.h"
#include "tipoDesecho.h"

void ImprimirClientes(cliente arrayCliente[], int tamanio);
void ImprimirPedidos(pedido arrayPedido[], int tamanio);
void ImprimirClientesConPedidosPendientes(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido);
void ImprimirClientesConMasPedidosPendientes(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido);
void ImprimirClientesConMasPedidosCompletados(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido);
void ImprimirClientesConMasPedidos(cliente arrayCliente[], int tamanio, pedido arrayPedidos[], int tamanioPedido);


#endif

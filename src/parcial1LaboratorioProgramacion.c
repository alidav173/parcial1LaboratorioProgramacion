/*
 ============================================================================
 Name        : parcial1LaboratorioProgramacion.c
 Author      : Alí Ansidey
 Version     :1.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "informe.h"
#include "cliente.h"
#include "pedido.h"
#include "tipoDesecho.h"

#define SALIR 0
#define VACIO 0
#define TAM_PEDIDO 5
#define TAM_CLIENTE 5
#define TAM_DESECHO 4

int main(void) {
	setbuf (stdout, NULL);
	int opcion;
	int validacion1;
	int validacion2;
	int validacion3;
	int id;
	cliente arrayClientes[TAM_CLIENTE];
	pedido arrayPedidos[TAM_PEDIDO];



	 InicializarArrayClientes (arrayClientes, TAM_CLIENTE);
	 InicializarArrayPedidos (arrayPedidos, TAM_PEDIDO);

	 tipoDesecho arrayDesecho[TAM_DESECHO] = {{3, "LDPE", VACIO, VACIO}, {4, "PP", VACIO, VACIO}, {5, "HDPE", VACIO, VACIO}, {6, "BASURA", VACIO, VACIO} };



	do{
		printf("\n Seleccione una de las siguietes opciones: \n");
		printf("1. ALTA CLIENTE \n");
		printf("2. MODIFICAR DATOS CLIENTE \n");
		printf("3. BAJA DEL CLIENTE \n");
		printf("4. CREAR PEDIDO RECOLECCION \n");
		printf("5. PROCESAR RESIDUOS \n");
		printf("6. IMPRIMIR CLIENTES \n");
		printf("7. IMPRIMIR PEDIDOS PENDIENTES \n");
		printf("8. IMPRIMIR PEDIDOS PROCESADOS \n");
		printf("9. PEDIDO PENDIENTE POR LOCALIDAD \n");
		printf("8. CANTIDAD KG DE POLIPROPILENO (PP) POR LOCALIDAD \n");
		printf("0. SALIR DEL MENU \n");

		opcion = IngresarEntero("Ingrese una opción \n");

		switch(opcion){
		case 1:
			validacion1 = CargarCliente(arrayClientes, TAM_CLIENTE);
	        if(validacion1 != -1){
	        	id = arrayClientes[validacion1].idCliente;
	        	printf("El cliente se cargó correctamente con el id %d\n", id);

	        }else{
	        	puts("El cliente no pudo cargarse\n");
	        }
			break;

		case 2:
			validacion2 = ModificarClienteGuardado(arrayClientes,TAM_CLIENTE);
			 if(validacion2==1){
			    puts("Los datos del clientes se modificaron correctamente.\n");
			        }
			        else
			        {
			        	puts("No se pudo modificar los datos del cliente.\n");
			        }
			break;

		case 3:
			validacion3= BajaCliente(arrayClientes, TAM_CLIENTE);
	        if(validacion3 == 1)
	        {
	            puts("El cliente se borró exitosamente.\n");
	        }
	        else
	        {
	        	puts("no se pudo borrar al cliente.\n");
	        }

			break;

		case 4:
			CrearPedidoRecoleccion(arrayDesecho,TAM_DESECHO);

			break;

		case 5:
			validacion3= ProcesarResiduos(arrayPedidos, TAM_PEDIDO, arrayDesecho, TAM_DESECHO);
	        if(validacion3 == 1)
	        {
	            puts("Se pudo procesar el pedido\n");
	        }
	        else
	        {
	        	puts("No se pudo procesar el pedido.\n");
	        }
			break;

		case 6:
			ImprimirClientesConPedidosPendientes(arrayClientes, TAM_CLIENTE,  arrayPedidos, TAM_PEDIDO);
			break;

		case 7:
			break;

		case 8:
			break;

		case 9:
			break;

		case 10:
			break;
		}


	}while(opcion != SALIR);
	return 0;
}


#include "pedido.h"


#define ID_INICIAL 1000
#define VACIO 0
#define LLENO 1
#define PENDIENTE 2
#define COMPLETADO 3

int generarId(){
	static int id = ID_INICIAL;
	return ++id;

}

pedido CrearPedidoRecoleccion(tipoDesecho arrayDesecho[], int tamanio){
	pedido pedidoNuevo;
	pedidoNuevo.idcliente = IngresarEntero("Ingrese el id del cliente \n");
	pedidoNuevo.cantKg = IngresarEntero("Ingrese la cantidad de kg totales de desechos: \n");
	pedidoNuevo.idPedido = generarId();
	pedidoNuevo.estadoPedido = PENDIENTE;
	pedidoNuevo.tipoResiduo = VACIO;
	pedidoNuevo.isEmpty = LLENO;

	return pedidoNuevo;
}

int cargarPedido(pedido arrayPedido[], int tamanio,tipoDesecho arrayDesecho[], int tamanioDesecho){
	  int index = BuscarPrimerEspacioLibre (arrayPedido, tamanio);
	  if (index != -1)
	    {
		  arrayPedido[index] = CrearPedidoRecoleccion(arrayDesecho, tamanioDesecho);
	    }
	  return index;
}

int ProcesarResiduos(pedido arrayPedido[], int tamanio, tipoDesecho arrayDesecho[], int tamanioDesecho){
	int retorno = 0;
	int i;
	int j;
	int pedidoBuscado;
	ImprimirPedidos(arrayPedido,  tamanio);
	pedidoBuscado = IngresarEntero("Ingrese el número del pedido \n");
	for(i = 0; i < tamanio; i++){
		if(arrayPedido[i].idPedido == pedidoBuscado){
			listarDesechos(arrayDesecho, tamanioDesecho);
			arrayPedido[i].tipoResiduo = IngresarEntero("Ingrese el tipo de desecho");
			for(j = 0; j < tamanioDesecho; j++){
				if(arrayPedido[i].tipoResiduo == arrayDesecho[j].idTipoDesecho){
					arrayDesecho[j].cantKg = IngresarEntero("Ingrese la cantidad de kg \n");
					arrayPedido[i].estadoPedido = COMPLETADO;
					retorno = 1;
					break;
				}
			}
		}

	}
	return retorno;
}


int BuscarPrimerEspacioLibre (pedido arrayPedido[], int tamanio)
{
  int i;
  int index;

  index = -1;
  for (i = 0; i < tamanio; i++)
    {
      if (arrayPedido[i].isEmpty == VACIO)
	{
	  index = i;
	  break;
	}
    }
  return index;
}


void InicializarArrayPedidos (pedido arrayPedido[], int tamanio)
{
  for (int i = 0; i < tamanio; i++)
    {
	  arrayPedido[i].isEmpty = VACIO;
    }
}


void MostrarPedido (pedido unPedido)
{

	printf ("%4d %4d \n", unPedido.idcliente, unPedido.idPedido);
}

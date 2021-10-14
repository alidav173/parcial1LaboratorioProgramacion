#include "cliente.h"

#define ID_INICIAL 100
#define LLENO 1
#define VACIO 0

int generarId(){
	static int id = ID_INICIAL;
	return ++id;

}

cliente IngresarCliente(){
	cliente clienteNuevo;
	localidad localidadNueva;
	getString(clienteNuevo.nombreCliente, "Ingrese el nombre del cliente \n",50);
	clienteNuevo.cuit = IngresarEnteroGrande("Ingrese el cuit del cliente \n");
	clienteNuevo.idCliente = generarId();
	getString(clienteNuevo.direccion, "Ingrese la dirección del cliente: \n", 50);
	strcpy(clienteNuevo.localidad, localidadNueva.nombreLocalidad);
	clienteNuevo.isEmpty = LLENO;

	return clienteNuevo;
}

int CargarCliente(cliente arrayCliente[], int tamanio){
	  int index = BuscarPrimerEspacioLibre (arrayCliente, tamanio);
	  if (index != -1)
	    {
		  arrayCliente[index] = IngresarCliente();
	    }
	  return index;
}


int BuscarPrimerEspacioLibre (cliente arrayCliente[], int tamanio)
{
  int i;
  int index;

  index = -1;
  for (i = 0; i < tamanio; i++)
    {
      if (arrayCliente[i].isEmpty == VACIO)
	{
	  index = i;
	  break;
	}
    }
  return index;
}


void InicializarArrayClientes (cliente arrayCliente[], int tamanio)
{
  for (int i = 0; i < tamanio; i++)
    {
	  arrayCliente[i].isEmpty = VACIO;
    }
}


int ModificarClienteGuardado (cliente arrayCliente[], int tamanio)
{
  int i;
  int clienteSeleccionado;
  char direccionNueva[50];
  char localidadNueva[50];
  int retorno = 0;

  clienteSeleccionado = IngresarEntero("Ingrese el ID del cliente a modificar");

  for (i = 0; i < tamanio; i++)
    {
      if (arrayCliente[i].isEmpty == LLENO && arrayCliente[i].idCliente == clienteSeleccionado)
	{
    	  getString(direccionNueva, "Ingrese la  nueva dirección del cliente",50);
    	  strcpy(arrayCliente[i].direccion,direccionNueva);
    	  getString(localidadNueva, "Ingrese la  nueva localidad del cliente",50);
    	  strcpy(arrayCliente[i].localidad,localidadNueva);
	  retorno = 1;
	  break;
	}
    }

  return retorno;


}



int BajaCliente (cliente arrayCliente[], int tamanio)
{
  int i;
  int auxiliarCliente = 0;
  int clienteSeleccionado;
  char respuesta[2];

  clienteSeleccionado = IngresarEntero("Ingrese el id del cliente a borrar \n");
  getString(respuesta, "¿Esta seguro que desea eliminar a este cliente? [si /no]\n",2);

  while(stricmp(respuesta, "si")!= 0 && stricmp(respuesta, "no")!= 0 ){
	  getString(respuesta, "¿Esta seguro que desea eliminar a este cliente? [si /no]\n",2);
  }
	  for (i = 0; i < tamanio; i++)
	    {
	      if ((stricmp(respuesta, "si") == 0) && arrayCliente[i].isEmpty == LLENO && arrayCliente[i].idCliente == clienteSeleccionado)
		{
	      arrayCliente[i].isEmpty = VACIO;
	      auxiliarCliente = 1;
		  break;
		}
	    }

  return auxiliarCliente;
}



void MostrarCliente (cliente unCliente)
{

	printf ("%4d %20s %4lu %20s %20s\n", unCliente.idCliente,
		  unCliente.nombreCliente, unCliente.cuit, unCliente.direccion,  unCliente.localidad);
}

#include "localidad.h"
#include "input.h"

#define LLENO 1

localidad cargarLocalidad(){
	localidad nuevaLocalidad;

	getString(nuevaLocalidad.nombreLocalidad, "Ingrese el nombre de la localidad", 50);
	nuevaLocalidad.isEmpty = LLENO;

	return nuevaLocalidad;
}

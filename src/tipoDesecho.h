#ifndef TIPODESECHO_H_
#define TIPODESECHO_H_


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
	int idTipoDesecho;
	char nombreDesecho[10];
	int cantKg;
	int isEmpty;

}tipoDesecho;



void MostrarTipo(tipoDesecho desecho);
void listarDesechos(tipoDesecho arrayDesecho[], int tamanio);


#endif

#include "tipoDesecho.h"

void MostrarTipo(tipoDesecho desecho){

    printf("%d %s\n", desecho.idTipoDesecho, desecho.nombreDesecho);

}


void listarDesechos(tipoDesecho arrayDesecho[], int tamanio){

    int i;
    puts("Tipos de desechos");
    for(i = 0; i < tamanio; i++){
        MostrarTipo(arrayDesecho[i]);
    }

}

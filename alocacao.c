#include <stdio.h>
#include <stdlib.h>

#include "alocacao.h"

int *alocar_vet(int tam)
{
    int *vet = (int*) malloc(sizeof(int)*tam);

    return vet;
}

int *realocar_vet(int tam, int *vet)
{
    int *p = realloc(vet, sizeof(int)*tam);
    printf("\n\np:%d\n", p);
    printf("vet:%d\n", vet);
    return p;
}

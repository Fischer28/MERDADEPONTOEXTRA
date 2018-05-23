#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "alocacao.h"
#include "testando.h"

void read_file(char *file_name)
{
    int num=0, i=0, tam=2, prime=0, odd=0;
    int *vet = alocar_vet(tam);

    FILE *arquivo = fopen(file_name, "r");

   while(fscanf(arquivo, "%d", &num) != EOF)
    {
        vet[i] = num;
        printf("tam%d; %d: %d\n",tam, i, vet[i]);
        if(i>=tam)
        {
            tam*=2;
            vet = realocar_vet(tam, vet);
            printf("\n\nvet:%d: tam %d\n", vet, tam);
        }
        i++;
    }
    fclose(arquivo);
    for(i=0;i<tam;i++)
    {
        prime += is_prime(vet[i]);
        odd += is_odd(vet[i]);
    }
    printf("Primos: %d\nImpares: %d", prime, odd);
    write_file("quantos.txt", prime, odd);
}

void write_file(char *file_name, int prime, int odd)
{
    FILE *arquivo = fopen(file_name, "w");

    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
    }
    else
    {
        fprintf(arquivo, "Primos: %d\nImpares: %d", prime, odd);
    }

    fclose(arquivo);
}

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

int GeraPesos()
{
    int p[MAXSIZE];
    int i;
    struct timeval semente;
    gettimeofday(&semente, NULL);
    srand((int) (semente.tv_sec + 1000000 * semente.tv_usec));

    for (i = 0; i < MAXCHAVE; i++)
    {
        p[i] = 1 + (int) (10000.0 * rand() / (RAND_MAX + 1.0));
    
        
        return p;
}

void Inicializa(Hash H)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        H[i] = NULL;
    }
}

Reg* InicializaRegistro(char *chave)
{
    Reg* reg = (Reg*) malloc(sizeof (Reg));

    reg->chave = strdup(chave);
    reg->index = malloc(sizeof (int)*10);
    reg->indexPosition = 0;
    reg->indexSize = 10;

    return reg;
}

void Insere(Hash H, Reg *registro)
{
    if (Busca(H, registro->chave) != NULL)
    {
        printf("Registro ja existe na tabela\n");
        exit(0);
    }
    
    int h = HashFunction(registro->chave);
    H[h] = registro;

    return;
}

Reg* Busca(Hash H, char *chave)
{
    int h = HashFunction(chave);

    while (H[h] != NULL)
    {
        if (strcmp(H->chave, chave) == 0)
        {
            return H[h];
        }

        h = (h + 1) % MAXCHAVE;
    }

    return NULL;
}

int HashFunction(char *chave)
{
    int i;
    int soma = 0;
    int comp = strlen(chave);
    
    int pesos[] = GeraPesos();

    for (i = 0; i < comp; i++)
    {
        soma += (int) chave[i] * pesos[i];
    }

    return (soma % MAXSIZE);
}

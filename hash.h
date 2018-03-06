#ifndef HASH_H
#define HASH_H

#define MAXSIZE 257
#define MAXCHAVE 100

typedef struct reg Reg;
struct reg
{
    char chave[MAXCHAVE];
    int* index;
    int indexPosition;
    int indexSize;
    int peso;
};

typedef Reg* Hash[MAXSIZE];

void Inicializa(Hash H);
Reg* InicializaRegistro(char *chave);
void Insere(Hash H, Reg *registro);
Reg* Busca(Hash H, char *chave);
int HashFunction(char *chave);

#endif /* ARVOREBINARIA_H */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvorebinaria.h"

struct Node {
    Registro reg;
    NodePointer Esq;
    NodePointer Dir;
} Node;

struct registro {
    char* chave;
    int* index;
    int indexPosition;
    int indexSize;
} registro;

int vazia(NodePointer arvore) {
    return arvore == NULL;
}

NodePointer InicializaArvore() {
    NodePointer arvore = (struct Node*) malloc(sizeof (struct Node));
    arvore->reg = NULL;
    arvore->Esq = NULL;
    arvore->Dir = NULL;

    return arvore;
}

Registro InicializaRegistro(char* chave) {
    Registro reg = malloc(sizeof (struct registro));
    reg->chave = strdup(chave);
    reg->index = malloc(sizeof (int)*10);
    reg->indexPosition = 0;
    reg->indexSize = 10;
    return reg;
}

void Insere(NodePointer *arvore, Registro reg) {

    if (vazia((*arvore))) {
        *arvore = InicializaArvore();

        (*arvore)->reg = reg;
        //printf("%s inserida!\n", (*arvore)->reg->chave);

        return;
    }

    if (strcmp(reg->chave, (*arvore)->reg->chave) < 0) {
        Insere(&(*arvore)->Esq, reg);
        return;
    }
    if (strcmp(reg->chave, (*arvore)->reg->chave) > 0) {
        Insere(&(*arvore)->Dir, reg);
        return;
    } else {
        //printf("Erro : Registro ja existe na arvore\n");
    }
}

void Imprime(NodePointer arvore) {
    if (arvore != NULL) {
        Imprime(arvore->Esq);
        PrintReg(arvore->reg);
        Imprime(arvore->Dir);

    }
}

Registro Pesquisa(char* chave, NodePointer *p) {
    if (*p == NULL) {
        //printf("Erro: Registro nao esta presente na arvore\n");
        return NULL;
    }
    if (strcmp(chave, (*p)->reg->chave) < 0) {
        return Pesquisa(chave, &(*p)->Esq);
    }
    if (strcmp(chave, (*p)->reg->chave) > 0)
        return Pesquisa(chave, &(*p)->Dir);
    else return (*p)->reg;
}

void PrintReg(Registro reg) {
    int i;
    printf("%s ", reg->chave);
    for (i = 0; i < reg->indexPosition; i++) {
        printf("%i ", reg->index[i]);
    }
    printf("\n");
}

void RegistraIndice(Registro reg, int linha) {
    if (reg == NULL) {
        return;
    }
    if (reg->indexPosition >= reg->indexSize) {
        reg->index = realloc(reg->index, sizeof (int)*(reg->indexSize + 10));
        reg->indexSize += 10;
    }
    if (reg->index[reg->indexPosition - 1] == linha) return;
    reg->index[reg->indexPosition] = linha;
    reg->indexPosition++;
}

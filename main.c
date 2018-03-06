#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "arvorebinaria.h"

#define MAXALFABETO 255
#define TRUE 1
#define FALSE 0

typedef short TipoAlfabeto[MAXALFABETO + 1];
FILE *ArqTxt, *ArqAlf;
TipoAlfabeto Alfabeto;
char Palavra[256];
char Linha[256];
int i;
short aux;

void DefineAlfabeto(short *Alfabeto) {
    char Simbolos[MAXALFABETO + 1];
    int i;
    int CompSimbolos;
    char *TEMP;

    for (i = 0; i <= MAXALFABETO; i++) {
        Alfabeto[i] = FALSE;
    }

    fgets(Simbolos, MAXALFABETO + 1, ArqAlf);
    TEMP = strchr(Simbolos, '\n');

    if (TEMP != NULL) *TEMP = 0;
    {
        CompSimbolos = strlen(Simbolos);
    }

    for (i = 0; i < CompSimbolos; i++) {
        Alfabeto[Simbolos[i] + 127] = TRUE;
    }

    Alfabeto[0] = FALSE; /* caractere de codigo zero: separador */
}

int main(int argc, char *argv[]) {
    // Verificando se os arquivos foram passados como parametro
    if (argc != 4) {
        printf("Modelo: %s texto chaves alfabeto\n", argv[0]);
        return 1;
    }

    // Arquivos de texto e alfabeto prontos para leitura
    ArqTxt = fopen(argv[1], "r");
    FILE *ArqKey = fopen(argv[2], "r");
    ArqAlf = fopen(argv[3], "r");
    int linhaAtual = 0;

    DefineAlfabeto(Alfabeto); /* Le alfabeto definido em arquivo */
    aux = FALSE;

    NodePointer arvoreTexto = NULL;

    // Inicializa a arvore de palavras chave
    NodePointer arvorePalavrasChave = NULL;

    // Abre o arquivo de palavras chave

    while (fgets(Linha, 256, ArqTxt) != NULL) {
        for (i = 1; i <= strlen(Linha) + 1; i++) {
            if (Alfabeto[Linha[i - 1] + 127]) {
                sprintf(Palavra + strlen(Palavra), "%c", Linha[i - 1]);
                aux = TRUE;
            } else if (aux) {
                // Insere as palavras chave na arvore
                Insere(&arvoreTexto, InicializaRegistro(Palavra));
                *Palavra = '\0';
                aux = FALSE;
            }
        }
    }

    rewind(ArqTxt);
    linhaAtual = 0;
    while (fgets(Linha, 256, ArqTxt) != NULL) {
        linhaAtual++;
        for (i = 1; i <= strlen(Linha); i++) {
            if (Alfabeto[Linha[i - 1] + 127]) {
                sprintf(Palavra + strlen(Palavra), "%c", Linha[i - 1]);
                aux = TRUE;
            } else if (aux) {
                RegistraIndice(Pesquisa(Palavra, &arvoreTexto), linhaAtual);
                *Palavra = '\0';
                aux = FALSE;
            }
        }
    }

    Imprime(arvoreTexto);

    Registro reg;
    while (scanf("%s", Palavra)) {
        if (reg = Pesquisa(Palavra, &arvoreTexto)) {
            PrintReg(reg);
        } else {
            printf("Palavra nao presente no texto");
        }
    }
    
    
    
    
    
    //cria o indice das palavras chaves
    /*
    while (fgets(Linha, 256, ArqKey) != NULL)
    {
        for (i = 1; i <= strlen(Linha) + 1; i++)
        {
            if (Alfabeto[Linha[i - 1] + 127])
            {
                sprintf(Palavra + strlen(Palavra), "%c", Linha[i - 1]);
                aux = TRUE;
            }
            else if (aux)
            {
                // Insere as palavras chave na arvore
                Insere(&arvorePalavrasChave, InicializaRegistro(Palavra));
     *Palavra = '\0';
                aux = FALSE;
            }
        }
    }
    
     *Palavra = '\0';
    linhaAtual = 0;
    // Le o arquivo texto
    while (fgets(Linha, 256, ArqTxt) != NULL)
    {
        linhaAtual++;
        for (i = 1; i <= strlen(Linha); i++)
        {
            if (Alfabeto[Linha[i - 1] + 127])
            {
                sprintf(Palavra + strlen(Palavra), "%c", Linha[i - 1]);
                aux = TRUE;
            }
            else if (aux)
            {
                RegistraIndice(Pesquisa(Palavra, &arvorePalavrasChave), linhaAtual);
     *Palavra = '\0';
                aux = FALSE;
            }
        }
    }
    
    //Imprime arvore
    Imprime(arvorePalavrasChave);
     */

    fclose(ArqTxt);
    fclose(ArqAlf);
    fclose(ArqKey);
    return 0;
}

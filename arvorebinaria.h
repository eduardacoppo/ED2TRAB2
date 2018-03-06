/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvorebinaria.h
 * Author: Eduarda
 *
 * Created on 8 de Julho de 2017, 11:16
 */

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct Node* NodePointer;
typedef struct Node;
typedef struct registro* Registro;
typedef struct registro;


NodePointer InicializaArvore();
void Insere(NodePointer*, Registro);
void Imprime(NodePointer);

#endif /* ARVOREBINARIA_H */


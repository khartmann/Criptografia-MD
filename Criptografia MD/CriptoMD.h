//
//  CriptoMD.h
//  Criptografia MD
//
//  Created by Rafael Auyer on 11/16/15.
//  Copyright © 2015 Rafael Auyer. All rights reserved.
//

#ifndef CriptoMD_h
#define CriptoMD_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif /* CriptoMD_h */

typedef struct num{
    int x;
    struct num *prox;
}dVector;

//Vetor Dinamico

typedef struct ord
{
    int x;
    int y;
    int n;
    struct ord *prox;
}dTrioVet;

int menu();
//MENU
//Apresenta opçoes do programa


int imprChar(dVector *vet);
//Entrada de ASCII NO MAXIMO 10000
//Imprime a frase equivalente aos numeros recebidos pela funçao.

int imprInt(char *cripto);
//Imprime o codigo ASC II

int imprInvM(dTrioVet *vector);
//Entrada: Lista com dois valores e interio n do tamanho do conjunto
//Impprime dois pontos salvos no struct tipo listaInvM

dVector *entradaASCII(char *titulo);
// Entrada de Ints
//Recebe os nuemros digitados pelo usuario, parada com 0

char *entradaString(char *titulo);
//Recebe a string do usuario
//Recebe a string digitada pelo usuario

int entradaInt(char *titulo);
//retorna um int unico lido do usuario

char pausa(char *titulo);
//recebe titulo para sem impresso na tela
//Pausa o programa esperando pelo usuario

dTrioVet *invMod(int n);
//Imprime os inversos Modulares

dTrioVet *novoTrio(dTrioVet *vector ,int x, int y, int n);
//salva 3 valores em uma lista Struct

dVector *novoInt(dVector *vector, int x);
//Salva um int em um Vetor Dinamico
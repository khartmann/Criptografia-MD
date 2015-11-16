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

typedef struct invM
{
    int x;
    int y;
    int n;
    struct invM *prox;
}listaInvM;

int menu();
//MENU
//Apresenta opçoes do programa


int imprChar(int *vet);
//Entrada de ASCII NO MAXIMO 10000
//Imprime a frase equivalente aos numeros recebidos pela funçao.

int imprInt(char *cripto);
//Imprime o codigo ASC II

int imprInvM(listaInvM *vector);
//Entrada: Lista com dois valores e interio n do tamanho do conjunto
//Impprime dois pontos salvos no struct tipo listaInvM

int *entradaASCII(char *titulo);
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

listaInvM *invMod(int n);
//Imprime os inversos Modulares

listaInvM *novoStruct(listaInvM *vector ,int x, int y, int n);
//salva os valores que formam um inverso modular
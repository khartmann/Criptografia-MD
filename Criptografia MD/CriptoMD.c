//
//  CriptoMD.c
//  Criptografia MD
//
//  Created by Rafael Auyer on 11/16/15.
//  Copyright © 2015 Rafael Auyer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CriptoMD.h"



int menu(){
    int op;
    fflush(stdin);
    printf("\n-----------MENU-----------\n1-Frase para ASCII\n2-ASCII para Frase\n3-Verificaçao de Inversos Modulares\n0-Sair do programa\n--------------------------\n\n\nDigite sua opçao: ");
    scanf(" %d", &op);
    switch (op){
        case 1:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            return imprInt(entradaString("\n--------Frase para ASCII------\n\nDigite a String: "));
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            return imprChar(entradaASCII("\n--------ASCII para Frase------\n\nDigite a String ASCII separando por Espaços e digitando 0 no fim: "));
            break;
        case 3:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            return imprInvM( invMod(entradaInt("\n\n\n\nDigite o tamanho do conjunto ( Zn ) a ser analizado:")));
            break;
        case 0:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nObrigado por usar o programa.\n\n ");
            return 1;
            break;
        default:
            pausa("\n\n\nOpçao incorreta. Digite qualquer tecla para continuar");
            return 0;
    }
    return 0;
}

char *entradaString(char *titulo){
    fflush(stdin);
    char *frase= (char*) malloc ((sizeof(frase) * sizeof(char)));
    printf("%s",titulo);
    scanf(" %[^\n]",  frase);
    fflush(stdin);
    return frase;
}

int *entradaASCII(char *titulo){
    fflush(stdin);
    int *vector= (int*) malloc (10000*(sizeof(int))), x=0;
    printf("%s",titulo);
    do{
        scanf(" %d", (vector+x));
        x++;
    }while ( *(vector+x-1)!=0);
    
    fflush(stdin);
    return vector;
}

int entradaInt(char titulo[]){
    int valor;
    fflush(stdin);
    printf(" %s",  titulo);
    scanf(" %d", &  valor);
    return valor;
}

int imprChar(int *vet){
    int x=-1;
    printf("\n\n\nConversao do codigo ASCII: ");
    do{
        x++;
        printf("%c", *(vet+x));
    }while(*(vet+x)!=0);
    pausa("\n\nDigite qualquer tecla pra continuar: ");
    return 0;
}

int imprInt(char *cripto){
    printf("\n\n\nASC II: ");
    for(int x=0; x<(strlen(cripto)*sizeof(char)); x++){
        printf(" %d", *(cripto+x));
    }
    pausa("\n\nDigite qualquer tecla pra continuar: ");
    return 0;
}

int imprInvM(listaInvM *vector){
    int x=0;
    listaInvM *teste= (listaInvM*) malloc(sizeof(listaInvM));
    printf("\n\n\n\n\n\n\n\n\n\n\nInversos Modulares em Z%d:\n--\n|----------------------------------------------------------------------|", vector->n);
    for (teste = vector; teste!=NULL ; teste=teste->prox , x++){
        if((x%2)==0){
            printf("\n| Inverso modular de %5.d = %5.d", teste->x, teste->y );
        }else{
            printf("    Inverso modular de %5.d = %5.d |", teste->x, teste->y );
        }
    }
    printf("\n|----------------------------------------------------------------------|\n--\n");
    if(x==0){
        printf("\n\nImpressao nao execultada");
        return 1;
    }
    free(vector);
    pausa("\n\n Digire qualquer tecla para continuar: ");
    return 0;
}

char pausa(char *titulo){
    char letra;
    fflush(stdin);
    printf(" %s",titulo);
    scanf(" %c", & letra);
    fflush(stdin);
    return letra;
}

listaInvM *novoStruct(listaInvM *vector ,int x, int y, int n){
    listaInvM *novoElemento = (listaInvM*) malloc(sizeof(listaInvM));
    if (vector==NULL){
        novoElemento->x=x;
        novoElemento->y=y;
        novoElemento->n=n;
        novoElemento->prox=NULL;
        vector = novoElemento;
    }else{
        novoElemento->x=x;
        novoElemento->y=y;
        novoElemento->prox=NULL;
        
        listaInvM *teste;
        for(teste=vector; teste->prox!=NULL;teste=teste->prox);
        teste->prox= novoElemento;
    }
    return vector;
}



listaInvM *invMod(int n){
    listaInvM *vector = (listaInvM*) malloc(sizeof(listaInvM));
    vector=NULL;
    for(int x=1; x<n;x++){
        for(int y=1; y<n; y++){
            if(((x*y)%n)==1){
                vector= novoStruct(vector, x, y, n);
            }
            
        }
    }
    return vector;
}
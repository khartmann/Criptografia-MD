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
#include <math.h>
#include "CriptoMD.h"



int menu(){
    int op;
    fflush(stdin);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n-----------MENU-----------\n1-Frase para ASCII\n2-ASCII para Frase\n3-Verificaçao de Inversos Modulares\n0-Sair do programa\n--------------------------\n\n\nDigite sua opçao: ");
    scanf(" %d", &op);
    switch (op){
        case 1:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            return imprInt(entradaString("\n--------ASCII para Decimal------\n\nDigite a String: "));
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            return imprChar(entradaASCII("\n--------Decimal para ASCII------\n\nDigite a String ASCII separando por Espaços e digitando 0 no fim: "));
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

dVector *entradaASCII(char *titulo){
    fflush(stdin);
    dVector *vector= NULL;
    int tmp=0;
    printf("%s",titulo);
    do{
        tmp=entradaInt("");
        vector=novoInt(vector, tmp);
    }while ( tmp!=0);
    
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

int imprChar(dVector *vet){
    printf("\n\n\nConversao do codigo ASCII: ");
    dVector *teste;
    for (teste = vet; teste!=NULL ; teste=teste->prox){
        printf("%c", teste->x);
    }
    free(vet);
    pausa("\n\nDigite qualquer tecla pra continuar: ");
    return 0;
}

int imprInt(char *cripto){
    printf("\n\n\nASC II: ");
    for(int x=0; x<(strlen(cripto)*sizeof(char)); x++){
        printf(" %d", *(cripto+x));
    }
    free(cripto);
    pausa("\n\nDigite qualquer tecla pra continuar: ");
    return 0;
}

int imprInvM(dTrioVet *vector){
    int x=0;
    dTrioVet *teste;
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

dTrioVet *novoTrio(dTrioVet *vector ,int x, int y, int n){
    dTrioVet *novoElemento = (dTrioVet*) malloc(sizeof(dTrioVet));
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
        
        dTrioVet *teste;
        for(teste=vector; teste->prox!=NULL;teste=teste->prox);
        teste->prox= novoElemento;
    }
    return vector;
}

dVector *novoInt(dVector *vector, int x){
    dVector *novoElemento = (dVector*) malloc(sizeof(dVector));
    if (vector==NULL){
        novoElemento->x= x;
        novoElemento->prox= NULL;
        vector= novoElemento;
    }else{
        novoElemento->x= x;
        novoElemento->prox= NULL;
        
        dVector *teste;
        for(teste=vector; teste->prox != NULL; teste=teste->prox);
        teste->prox= novoElemento;
    }
    return vector;
}

dTrioVet *invMod(int n){
    dTrioVet *vector=NULL;
    if((n%2)==0){
        for(int x=1; x<n;x+=2){
            for(int y=1; y<n; y+=2){
                if(((x*y)%n)==1){
                    vector= novoTrio(vector, x, y, n);
                }
                
            }
        }
    }else{
        for(int x=1; x<n;x++){
            for(int y=1; y<n; y++){
                if(((x*y)%n)==1){
                    vector= novoTrio(vector, x, y, n);
                }
                
            }
        }
    }
    return vector;
}


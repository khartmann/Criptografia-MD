//
//  Created by Rafael Passos de Pedro Hartmann on 09/11/15.
//
//  Criptografia MD
//
//  Copyright © 2015 Rafael Auyer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
//MENU
void imprChar(int *vet);
//Entrada de ASCII NO MAXIMO 10000

int *entradaInt(char *titulo);
// Entrada de Ints
char *entradaString(char *titulo);
//Recebe a string do usuario

void imprInt(char *cripto);
//Imprime o codigo ASC II

int menu(){
    int op;
    fflush(stdin);
    printf("\n------MENU------\n1-Frase para ASCII\n2-ASCII para Frase\n\nDigite sua opçao: ");
    scanf(" %d", &op);
    switch (op){
        case 1:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            imprInt(entradaString("\n--------Frase para ASCII------\n\nDigite a String: "));
            break;
        case 2:
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            imprChar(entradaInt("\n--------ASCII para Frase------\n\nDigite a String ASCII separando por Espaços e digitando 0 no fim: "));
            break;
        default:
            printf("\n\nOpçao incorreta\n");
            return 0;
    }
    return 1;
}

char *entradaString(char *titulo){
    fflush(stdin);
    char *frase= (char*) malloc ((sizeof(frase) * sizeof(char)));
    printf("%s",titulo);
    scanf(" %[^\n]",  frase);
    fflush(stdin);
    return frase;
}

int *entradaInt(char *titulo){
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

void imprChar(int *vet){
    int x=-1;
    printf("\n\n\nConversao do codigo ASCII: ");
    do{
        x++;
        printf("%c", *(vet+x));
    }while(*(vet+x)!=0);
    
}

void imprInt(char *cripto){
    printf("\n\n\nASC II: ");
    for(int x=0; x<(strlen(cripto)*sizeof(char)); x++){
        printf(" %d", *(cripto+x));
    }
}

int main(int argc, const char * argv[]) {
    menu();
    printf("\n\n\n");
    return 0;
}

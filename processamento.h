#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PALAVRAS 2000
#define MAX_LETRAS 50
#define MAX_LINHAS 100
typedef struct {
    char palavra[MAX_LETRAS];
    int linhas[MAX_LINHAS];
    int qtd_linhas;
} EntradaIndice;
EntradaIndice indice[MAX_PALAVRAS];
int total_palavras=0;
long int particiona (Pessoa **ordem, long int baixo, long int alto);
void quick_sort(Pessoa **ordem, long int baixo, long int alto);


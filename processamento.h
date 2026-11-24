#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_PALAVRAS 2000
#define MAX_LETRAS 50
#define MAX_LINHAS 100
typedef struct {
    char palavra[MAX_LETRAS];
    int linhas[MAX_LINHAS];
    int qtd_linhas;
} EntradaIndice;
typedef struct {
    const char *com_acento;
    char sem_acento;
} MapaAcento;
void remover_acentos_utf8(char *str);
void extraiTokens (char* nome_arquivo,EntradaIndice *indice,int* total_palavras);


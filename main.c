#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "processamento.h"
int main()
{
    EntradaIndice *indice;
    indice=(EntradaIndice*) malloc(MAX_PALAVRAS*sizeof(EntradaIndice));
    int total_palavras=0;
    char nome_arquivo[MAX_LETRAS];
    scanf("%s",nome_arquivo);
    extraiTokens(nome_arquivo,indice,&total_palavras);
    for(int i=0;i<total_palavras-1;i++)
    {
        printf("%s\n",indice[i].palavra);
    }
    return 0;
}
/* TODO
 criar funcao para converter em minuscilas
 criar funcao para comparar palavras
 ajustar o quick sort para comparar palavras
 criar funcao para adicionar ou atualizar palavras no vetor
 ler o arquivo, tokenizar, ordenar e gravar no arquivo de saida
 */

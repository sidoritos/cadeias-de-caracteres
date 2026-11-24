#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "processamento.h"
void extraiTokens (char* nome_arquivo,EntradaIndice *indice,int *total_palavras)
{
    int i,pos=0,lidos=0;
    char palavra[MAX_LETRAS],linha[MAX_LETRAS*64];
    FILE* arquivo=fopen(nome_arquivo,"r");
    if(arquivo==NULL)
    {
        perror("erro ao abrir arquivo");
        return;
    }
    while(fgets(linha,sizeof(linha),arquivo)!=NULL)
    {
        remover_acentos_utf8(linha);
        for (i=0;linha[i]!='\0';i++)
        {
            unsigned char c=(unsigned char)linha[i];
            if(isalnum(c))
            {
                if(pos<MAX_LETRAS)
                    palavra[pos++]=tolower(c);
            }
            else
            {
                if (pos>0)
                {
                    palavra[pos]='\0';
                    strcpy(indice[i].palavra,palavra);
                    lidos++;
                    pos=0;
                }
            }
        }
    }
    if (pos>0)
    {
        palavra[pos]='\0';
        strcpy(indice[lidos].palavra,palavra);
        lidos++;
    }
    *total_palavras=lidos;
    fclose(arquivo);
}
void remover_acentos_utf8(char *str)
{
    static const MapaAcento mapa[] =
    {
        {"\xC3\xA1", 'a'}, {"\xC3\xA0", 'a'}, {"\xC3\xA2", 'a'}, {"\xC3\xA3", 'a'}, {"\xC3\xA4", 'a'},
        {"\xC3\xA9", 'e'}, {"\xC3\xA8", 'e'}, {"\xC3\xAA", 'e'}, {"\xC3\xAB", 'e'},
        {"\xC3\xAD", 'i'}, {"\xC3\xAC", 'i'}, {"\xC3\xAE", 'i'}, {"\xC3\xAF", 'i'},
        {"\xC3\xB3", 'o'}, {"\xC3\xB2", 'o'}, {"\xC3\xB4", 'o'}, {"\xC3\xB5", 'o'}, {"\xC3\xB6", 'o'},
        {"\xC3\xBA", 'u'}, {"\xC3\xB9", 'u'}, {"\xC3\xBB", 'u'}, {"\xC3\xBC", 'u'},
        {"\xC3\xA7", 'c'},
        {"\xC3\x81", 'A'}, {"\xC3\x80", 'A'}, {"\xC3\x82", 'A'}, {"\xC3\x83", 'A'}, {"\xC3\x84", 'A'},
        {"\xC3\x89", 'E'}, {"\xC3\x88", 'E'}, {"\xC3\x8A", 'E'}, {"\xC3\x8B", 'E'},
        {"\xC3\x8D", 'I'}, {"\xC3\x8C", 'I'}, {"\xC3\x8E", 'I'}, {"\xC3\x8F", 'I'},
        {"\xC3\x93", 'O'}, {"\xC3\x92", 'O'}, {"\xC3\x94", 'O'}, {"\xC3\x95", 'O'}, {"\xC3\x96", 'O'},
        {"\xC3\x9A", 'U'}, {"\xC3\x99", 'U'}, {"\xC3\x9B", 'U'}, {"\xC3\x9C", 'U'},
        {"\xC3\x87", 'C'}
    };
    const size_t n_mapa = sizeof(mapa) / sizeof(mapa[0]);

    size_t r = 0, w = 0;
    while (str[r] != '\0')
    {
        int substituido = 0;
        for (size_t i = 0; i < n_mapa && !substituido; i++)
        {
            size_t len = strlen(mapa[i].com_acento);
            if (strncmp(&str[r], mapa[i].com_acento, len) == 0)
            {
                str[w++] = mapa[i].sem_acento;
                r += len;
                substituido = 1;
            }
        }
        if (!substituido)
        {
            str[w++] = str[r++];
        }
    }
    str[w] = '\0';
}

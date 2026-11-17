#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void quick_sort(Pessoa **ordem, long int baixo, long int alto)
{
    long int p;
    if (baixo<alto)
    {
        p=particiona(ordem,baixo,alto);
        quick_sort(ordem,p+1,alto);
        quick_sort(ordem,baixo,p);
    }
}
long int particiona (Pessoa **ordem, long int baixo, long int alto)
{
    long int pivo= ordem[(baixo+alto)/2]->rg;
    long int i=baixo-1,j=alto+1;
    Pessoa *aux;
    while (1)
    {
        do
        {
            i++;
        }
        while (ordem[i]->rg<pivo);
        do
        {
            j--;
        }
        while (ordem[j]->rg>pivo);
        if (i>=j)
            return j;
        aux=ordem[i];
        ordem[i]=ordem[j];
        ordem[j]=aux;
    }
}

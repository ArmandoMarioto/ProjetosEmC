#include <conio.h>
#include <stdio.h>
#include<time.h>
#include <io.h>
#include<string.h>
#define TAM_MAX 50

struct arquivo
{
    char nome[30];
    int tamanho;
    char data[30];
    char tipo;

};
int carregaPasta(arquivo vet[])
{
    int tl=0;
    _finddata_t arq;
   int prox;
  prox=_findfirst("*.*",&arq);
  do
  {
    strcpy(vet[tl].nome,arq.name);
    vet[tl].tamanho = arq.size;


      strftime(vet[tl].data,30,"%d-%m-%Y  %H:%M:%S",localtime(&arq.time_create));
      vet[tl++].tipo = (arq.attrib == 32)? 'N'  : 'P';


  }while(!_findnext(prox,&arq));
  return tl;

}

int main()
{
    arquivo arquivos[TAM_MAX];
    int tl=0;

    tl=carregaPasta(arquivos);
    for(int i=0;i<tl;i++)
    {
        printf("\n%20s     %10d    %c                %s",arquivos[i].nome, arquivos[i].tamanho,arquivos[i].tipo,arquivos[i].data);

    }



   getch();

    return 0;
}


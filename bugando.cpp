#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
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
	int op,i=0;
    do
    {
    	system("cls");
        printf("\n------------------------------------------------------------------------------");
        printf("\n Escolha a Opção.");
        
        printf("\n\n<- \t\t->\t\tESC \t\t Ins\t\t  Delete\n");
		op = getch();
        switch(op)
        {
            case 75:
            	printf(".....................kkkkk....");
				getch();            	
            	break;
            case 77:
            	//          ->
            	printf("...................bbbb......");
            	getch();
            	break;
            case 82:
            	//         Insert
            	printf("..................vvvvv.......");
            	getch();
            	break;
            case 83:
            	//          Delete
            	printf("..................lllllll......");
            	getch();
            	break;
            	
	        default : 
	        printf("\n\n \t\t\tOpção invalida.");
	        _sleep(1000);
	        break;
            

        }

    /*tl=carregaPasta(arquivos);
    for(int i=0;i<tl;i++)
    {
        printf("\n\t\t%s     \t\t %d   \t\t %c  \t\t  %s",arquivos[i].nome, arquivos[i].tamanho,arquivos[i].tipo,arquivos[i].data);

    }
*/

    }while(op!=27);




   getch();

    return 0;
}


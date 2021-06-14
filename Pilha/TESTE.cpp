#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxpilha 10
#include "Pilha.h"

int main()
{
	TpPilha Pilha;
	char Elemento;
	int op,cheia,vazia;
	inicializa(&Pilha);
	do
	{
		printf("\t\t\t----- Escolha uma Opção ------");
	printf("\n 1 ° Inserir na pilha");
	printf("\n 2 ° Retirar ");
	printf("\n 3 ° Consultar");
	printf("\n");
	
	scanf("%d",&op);
	
	
	switch(op)
	{
		case 1:
		cheio = cheia(topo);
		if(cheio !=0)
		{
					printf("Elemento:");
					getch();
					Insere(&Pilha,Elemento);
		}
	
			break;
		case 2:
			vazia= Vazio(topo);
		if(vazio !=1)
			char Retira(&Pilha);
			break;
			
		case 3:
			Exibe(Pilha);
			break;
		case 4:
			Elemento=retornaelemtopo(Pilha);
			printf("\n\n \t\t\t Elemento: %c",Elemento);
			break;
			
		default :
			printf("\n Opção Invalida.");
			break;
			
	}
	}while(op!=27);
}

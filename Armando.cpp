#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<locale.h>
#define tf 100

struct rallye
{
	int cod,tempo[3];
	float total[tf];
};
int calculo(int valor,int vetor[10],float &total)
{
	
}

int main(void)
{
	rallye equipe[tf];
	int i,tp[3],tl=0,j;
	char op;
	setlocale(LC_ALL,"portuguese");
	do{
	
		system("cls");
		printf("\n [A] Tempo padrão.");
		printf("\n [B] Inserir o tempo de sua equipe.");
		printf("\n [C] Calcular o Tempo.");
		printf("\n [S] Sair.");
		printf("\n\n ESCOLHA UMA OPÇÃO:  ");
		op=toupper(getche());
		switch(op)
		{
			case 'A':
				system("cls");
				printf("\n ***Tempo padrão***");
				for(i=0;i<3;i++)
				{
					printf("\nInforme o Tempo padrão da %d°Etapa.",i+1);
					scanf("%d",&tp[i]);
				}
				getch();
				break;
			case 'B':
				system("cls");
				printf("\n ***Inserir o tempo de sua equipe***");
				printf("\nInforme o Número de inscrição de sua equipe.");
				scanf("%d",&equipe[tl].cod);
				for(j=0;j<3;j++)
				{
					printf("\nInforme o tempo que sua equipe fez na %dºEtapa.",j+1);
					scanf("%d",&equipe[tl].tempo[j]);	
				}
				tl++;
				getch();
				break;
			case 'C':
				system("cls");
				printf("*** Calcular o Tempo ***\n");
				if(tl==0)
				printf("\n Não há equipes registradas...");
				else
				{
					for(i=0;i<tl;i++)
					{
					calculo(tp[i],)	
					}
					
				}
		}
	}while(op!='S');
}



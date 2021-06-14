#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#define tf 20
int menu(void)
{
	int o;
	system("cls");
	printf("\n-----------------MENU-----------------\n\n");
	printf("[1]- Ler Vetor 1\n");
	printf("[2]- Ler Vetor 2\n");
	printf("[3]- Exibir Vetor 1\n");
	printf("[4]- Exibir Vetor 2\n");
	printf("[5]- Consultar Vetor 1\n");
	printf("[6]- Consultar Vetor 2\n");
	printf("[7]- Exclusão no Vetor 1\n");
	printf("[8]- Exclusão no Vetor 2\n");
	printf("[9]- Ordena Vetor 1\n");
	printf("[10]- Ordena Vetor 2\n");
	printf("[10]-Finalizar");
	printf("\n\n\nDigite a Opção: ");
	scanf("%d",&o);
	system("cls");
	return o;
}
void levetor(char v[tf][30], int &tl)
{
	char nome[30];
	printf("Nome: ");
	fflush(stdin);
	gets(nome);
	while(tl<tf && strcmp(nome, "\0")!=0)
	{
		strcpy(v[tl++], nome);
		printf("Nome: ");
		fflush(stdin);
		gets(nome);
	}
}
void exibe(char nomes[][30], int tl)
{
	int i;
	if(tl==0)
		printf("Não há Nomes!!!");
	else
		for(i=0; i<tl; i++)
			printf("\nNome[%d]: %s", i, nomes[i]);
	getch();
}
int busca(char n[][30], int tl, char nome[30])
{
	int i=0;
	while(i<tl && strcmp(nome, n[i])!=0)
		i++;
	if(i<tl)
		return i;
	else
		return -1;
}
void consulta(char v[tf][30], int tam)
{
	char n[30];
	int p;
	system("cls");
	printf("Nome a Consultar: ");
	fflush(stdin);
	gets(n);
	while(strcmp(n, "\0")>0)
	{
		p=busca(v, tam, n);
		if(p==-1)
			printf("Não Encontrou: ");
		else
			printf("Encontrado Na Posisão %d", p);
		getch();
		system("cls");
		printf("Nome a Consultar: ");
		fflush(stdin);
		gets(n);
	}
	system("cls");
}
void exvetor(char a[tf][30], int &b)
{
	char n[30];
	int p, i;
	system("cls");
	printf("Excluir Nome: ");
	fflush(stdin);
	gets(n);
	while(strcmp(n, "\0")>0)
	{
		p=busca(a, b, n);
		if(p==-1)
			printf("Não Encontrou: ");
		else
		{
			for(i=p; i<b ; i++)
				strcpy(a[i], a[i+1]);
			b--;
		}
		getch();
		system("cls");
		printf("Excluir Nome: ");
		fflush(stdin);
		gets(n);
	}
	system("cls");
}
void executa(void)
{
	int opcao, tl1=0, tl2=0;
	char v1[tf][30], v2[tf][30];
	do
	{
		opcao= menu();
		switch(opcao)
		{
			case 1:
				levetor(v1, tl1);
			break;
			case 2:
				levetor(v2, tl2);
			break;
			case 3:
				exibe(v1, tl1);
			break;
			case 4:
				exibe(v2, tl2);
			break;
			case 5:
				consulta(v1, tl1);
			break;
			case 6:
				consulta(v2, tl2);
			break;
			case 7:
				exvetor(v1, tl1);
			break;
			case 8:
				exvetor(v2, tl2);
			break;
			case 9:
				
			break;
			case 10:
				
			break;
			case 0:
				
			break;
		}
	}while(opcao!=0);
	getch();
}
int main(void)
{
	setlocale(LC_ALL,"portuguese");
	executa();
	return 0;
}

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>

#define Pi 3.14159

float area ( int r);
char exibemenu(void);
void lenumero(int &num);
void soma(int n1,int n2,int &re);
void exibe(int valor);
char exibemenu(void)
{
	system("cls");
	printf("###    Menu do Sistema   ###");
	printf("\n [A]  -  Digitar números.");
	printf("\n [B]  -  Somar dois números.");
	printf("\n [C]  -  Exibir resultado.");
	printf("\n [D]  -  Calcular área da esfera.");
	printf("\n [ESC]  -  Finalizar.");
	
	return(toupper(getche()));
	
}
void lenumero(int &num)
{
	printf("\n\n Informe um número:");
	scanf("%d",&num);
	
}
void soma(int n1,int n2,int &re)
{
	re=n1+n2;
}
void exibe(int valor)
{
	printf("\nO Resultado:%d",valor);
	getch();
}

float area ( int r)
{
	return(4*Pi*r*r);
}
int main (void)
{
	int raio,num1,num2,res;
	float area_esfera;
	char op;
	setlocale(LC_ALL, "Portuguese");
	do
	{
		op=exibemenu();
		switch(op)
		{
			case 'A':
				lenumero(num1);
				lenumero(num2);
				break;
			case 'B':
					soma(num1,num2,res);
				break;
			case 'C':
				
				exibe(res);
				break;
			case 'D':
				printf("\nDigite o raio da esfera:");
				scanf("%d",&raio);
				area_esfera=area(raio);
				printf("\nA área da esfera é %f",area_esfera);
				getch();
				break;
		}
	}while(op!=27);
	
}


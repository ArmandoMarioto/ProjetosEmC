#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAXFILA 10
struct tpfila
{
	int fim, inicio;
	char fila[MAXFILA];
	int qtde;
};

void inicializa(tpfila &f)
{
	f.fim = -1;
	f.qtde=0;
	f.inicio = 0;
}

int cheia(int qtde)
{
		return qtde==MAXFILA;
} 

void insere(tpfila &f, char elem)
{
	if(cheia(f) = 0)
	{
		if(f.fim==MAXFILA-1)
			f.fim = -1;
		f.fila[++f.fim] = elem;
		f.qtde++;
	}	
	else
	{
		printf("Fila Cheia!!!");
		getch();
		system("cls");
	}
	
}

bool vazia(int qtde)
{
		return qtde==0;
}

char retirar(tpfila &f)
{
	char aux;
	int i;
	
	/*if(!vazio(f.fim))
	{
		aux = f.fila[0];
		for(i = 0; i < MAXFILA - 1; i++)
			f.fila[i] = f.fila[i + 1];
		f.fim--;
		return aux;
	}
	else
		return '0';*/
	aux=f.fila[f.inicio++];
	if(f.inicio==MAXFILA-1)
		f.inicio=0;
	f.qtde--;
	return aux;
}

char RetornaElemInicio(tpfila f)
{
	return f.fila[f.inicio];
}
char retornaElemFim(tpfila f)
{
	return f.fila[f.fim];
}
void exibe(tpfila f)
{
	while(!vazia(f))
		printf("%c\n", retira(f));
}

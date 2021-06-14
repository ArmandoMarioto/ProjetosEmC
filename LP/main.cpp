#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "myconio.h"
#define FUNDO 15
#define TXT 8
#define GR 0
#define TF 50
bool grifSN(char pa[])
{
	FILE *arq=fopen("Grifar.txt", "r");
	char aux[20];
	fscanf(arq, "%s", aux);
	while(!feof(arq))
	{
		if(strcmp(pa, aux)==0)
		{
			fclose(arq);
			return true;
		}
		fscanf(arq, "%s", aux);
	}
	return false;
	fclose(arq);
}
void pbv(char a, int cor)
{
	TextColor(cor, FUNDO);
	printf("%c", a);
	TextColor(TXT, FUNDO);
}
int cor(char a)
{
	if(a == 34)
		return 9;
	if(a >= 33 && a <= 63 || a >= 91 && a <= 93 || a >= 123 && a <= 126)
		return 12;
	else
		return TXT;
}
void printvb(char p[])
{
	int i=0;
	while(i < strlen(p))
	{
		pbv(p[i], cor(p[i]));
		i++;
	}
}
bool buscapr(char li[], int &pos)
{
	int i=0, k;
	while(i<strlen(li) && li[i] != '"')
		i++;
	if(i==strlen(li))
		return false;
	else
	{
		k=i;
		for(i=0; i<strlen(li); i++)
		{
			if(i<k)
			{
				TextColor(TXT, FUNDO);
				printf("%c", li[i]);
			}
			else if(li[i+1]!='"')
			{
				TextColor(4, FUNDO);
				printf("%c", li[i]);
				TextColor(TXT, FUNDO);
			}
		}
		return true;
	}	
}
void grifar(char li[])
{
	char *p;
	int i=0;
	p=(char*)strtok(li, " ");
	while(p!=NULL)
	{
		if(grifSN(p)==true)
		{
			TextColor(GR, FUNDO);
			printf("%s ", p);
			TextColor(TXT, FUNDO);
			i+=strlen(p);
		}
		else if(buscapr(li, i)==false)
			printvb(p);
		printf(" ");
		p=(char*)strtok(NULL, " ");
	}
}
void executa(char nomearq[])
{
    char li[35];
    FILE*arq=fopen(nomearq, "r");
    TextColor(TXT, FUNDO);
    system("cls");
    if(arq!=NULL)
    {
    	fgets(li, 35, arq);
        while(!feof(arq))
        {
            if(li[0]=='#')
            {
                TextColor(2, FUNDO);
                printf("%s", li);
				TextColor(TXT, FUNDO);
            }
            else
            	grifar(li);
            fgets(li, 35, arq);
        }
    }
    else
        printf("Nao foi possivel abrir o arquivo");
    getch();
}
int main(void)
{
    char nomearq[TF];
    printf("Nome Do Arquivo: ");
    fflush(stdin);
    gets(nomearq);
    executa(nomearq);
    return 0;
}

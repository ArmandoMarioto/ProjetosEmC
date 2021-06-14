#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include <ctype.h>
#include <iostream>

void Conversao(void)
{	char texto[100],c;
	int i=0,tam;
	FILE *arq=fopen("texto.txt","r+");
	FILE *arq2=fopen("texto2.txt","w");
	fscanf(arq,"%[^;]",texto);
	tam=strlen(texto);
	
	for(i=0; i<tam; i++)
	{
		texto[i] = toupper(texto[i]);
	}
	
	fprintf(arq2," %s ;",texto);
	fclose(arq);
	fclose(arq2);
	remove("texto.txt");
	rename("texto2.txt","texto.txt");
	printf("\nArquivo transformado para maiusculo.");
}
int main ()
{
	Conversao();
}


#include <stdlib.h>
#include <string.h>
#include<locale.h>
#define null NULL
#include "Comandos.h"
#include "graph.h"
void exibeG(listaGAD *l, int x, int y)
{
	if(l != null)
	{
		gotoxy(x, y);printf("%d-%s", l->i_node, l->nome);
		gotoxy(x, y+1);
		exibeG(l->head, x, y + 2);
		exibeG(l->tails, x + strlen(l->nome) + 5, y);
	}
}
void executaComando(char c[], listaGAD **datual,descritor **d, char da[50])
{
	char auxc[250];
	strcpy(auxc, c);
	char *ss = strtok(c, " ");
	if(ss == null){}
	else if(!strcmp(ss, "chmod"))
	{

	}
	else if(!strcmp(ss, "cal"))
	{
		int mes = -1, ano = -1;
		ss = strtok(null, " ");
		if(ss != null)
		{
			mes = atoi(ss);
			ss = strtok(null, " ");
			if(ss != null)
				ano = atoi(ss);
		}
		call(mes, ano);
	}
	else if(!strcmp(ss, "ls"))
	{
		
		ss = strtok(null, " ");
		if(ss == null)
		{
			printf("Não Foi Possivel Executar o Comando!!!\n");
		}
		else if(!strcmp(ss, "-l"))
		{
			ls_l(*datual, *d);
		}
		else if(!strcmp(ss, "-m"))
		{
			ls_m(*datual, *d);
		}
	}
	else if(!strcmp(ss, "cd"))
	{
		cd(&*d, &*datual, auxc, da);
		//strcpy(da, pwd(*datual, *d));
	}
	else if(!strcmp(ss, "pwd"))
	{
		pwd(*datual, *d);
	}
	else if(!strcmp(ss, "mkdir"))
	{
		ss = strtok(null, " ");
		if(ss == null)
			printf("Nome de diretório inválido ou não especificado!!!\n");
		else
			mkdir(&*d, &*datual, ss);
	}
	else if(!strcmp(ss, "rmdir"))
	{

	}
	else if(!strcmp(ss, "cat"))
	{
		ss = strtok(null, " ");
		if(!strcmp(ss, ">"))
		{
			ss = strtok(null, " ");
			if(ss != null)
				catMaior(&*d, &*datual,  ss);
			else
				printf("Sintaxe do Comando cat errada ou inválida!!!\n");
		}
		else
		{
			catNormal(&*d, &*datual, ss);
		}
	}
	else if(!strcmp(ss, "rm"))
	{

	}
	else if(!strcmp(ss, "cp"))
	{

	}
	else if(!strcmp(ss, "mv"))
	{
		//ss = strtok(null, " ");
		mv(&*d, &*datual, auxc);
	}
	else if(!strcmp(ss, "clear"))
	{
		system("cls");
	}
	else if(!strcmp(ss, "find"))
	{

	}else if(!strcmp(ss, "exit"))
	{
		exit(0);
	}
	else if(!strcmp(ss, "p"))
	{
		printf("\n");
		exibeG((*d)->ListGen, 10, 10);
		printf("\n");
	}
	else if(!strcmp(ss, "pp"))
	{
		printf("numero do inode atual = %d\n", (*datual)->i_node);
	}
	else
	{
		printf("Comando inválido\n");
	}
}
void limpa_pontinode(ponti_node **i)
{
	int index;
	if((*i) != null)
	{
		limpa_pontinode(&(*i)->prox);
		for(index = 0; index < (*i)->TL; index++)
			free((*i)->vetPontBloco[index]);
		free(*i);
	}
}
void limpa_pontbloco(pont_bloco **b)
{
	if((*b) != null)
	{
		limpa_pontbloco(&(*b)->prox);
		free(*b);
	}
}
void limpa_listaGAD(listaGAD **l)
{
	if((*l) != null)
	{
		limpa_listaGAD(&((*l)->head));
		limpa_listaGAD(&((*l)->tails));
		free(*l);
	}
}
void limpaLixo(descritor **d)
{
	limpa_pontinode(&((*d)->ArqDir->i_nodes));
	limpa_pontbloco(&((*d)->ArqDir->diretorio_raiz));
	limpa_pontbloco(&((*d)->ArqDir->arquivos_diretorios));
	limpa_listaGAD(&((*d)->ListGen));
}
int main()
{
	setlocale(LC_ALL, "portuguese");
	char flag = 1;
	char comando[50], diratual[50];
	descritor *d;
	listaGAD *datual;
	startProgram(&d);
	datual = d->ListGen;
	strcpy(diratual, "~/armando/$");
	while(flag)
	{
		printf("%s", diratual);
		fflush(stdin);
		gets(comando);
		executaComando(comando, &datual,&d, diratual);
	}
	/*strcpy(comando, "mkdir lu");
	executaComando(comando, &datual,&d, diratual);
	strcpy(comando, "cd /lu");
	executaComando(comando, &datual,&d, diratual);
	strcpy(comando, "pwd");
	executaComando(comando, &datual,&d, diratual);*/
    limpaLixo(&d);
    return 0;
}

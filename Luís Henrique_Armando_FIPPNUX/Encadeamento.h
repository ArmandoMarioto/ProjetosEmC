#include "Estruturas.h"
#include "TADPilha.h"

listaGAD* Head(listaGAD *l)
{
	return l->head;
}
listaGAD* Tail(listaGAD *l)
{
	return l->tails;
}

char isNull(listaGAD *l)
{
	return l == null;
}
char isFile(listaGAD *l)
{
	return !isNull(l) /*&& ((l->pi_node)->tipo) == 'a'*/;//bugado
}
char Atomo(listaGAD *l)
{
	return (!isNull(l) && l->pi_node != null && l->pi_node->tipo != 'd');
}
void CriaINode(ponti_node **i,char tipo,int i_node, char atr[],int tam,char data[11],char hora[6])
{
	(*i) = (ponti_node*) malloc(sizeof(ponti_node));
	(*i)->prox = null;
	(*i)->tipo = tipo;
	(*i)->i_node = i_node;
	strcpy((*i)->atr,atr);
	(*i)->tam = tam;
	strcpy((*i)->data,data);
	strcpy((*i)->hora,hora);
	(*i)->TL = 0;
	int k;
	for(k = 0; k <5; k++)
	{
		(*i)->vetPontBloco[k] = null;
		(*i)->vetBloco[k]= 0;
	}

}

void InicializaInode(ponti_node **i)
{
	ponti_node *nc = (ponti_node*) malloc(sizeof(ponti_node));
	CriaINode(&nc, 'N', 1,"", -1, "", "");
}
pont_bloco* CriaBloco(int bloco)
{
	pont_bloco *nb = (pont_bloco*) malloc(sizeof(pont_bloco));
	nb->bloco = bloco;
	nb->prox =null;
	return nb;
}
pont_bloco* CriaBloco_Dir(int n)
{
	pont_bloco *nb = CriaBloco(n);
	nb->FileOrDir.dire.tl = 0;
	return nb;
}
pont_bloco* CriaBloco_Arq(int n, char dados[])
{
	pont_bloco *nb = CriaBloco(n);
	strcpy(nb->FileOrDir.parteArquivo, dados);
	return nb;
}
void startProgram(descritor **d)
{
	(*d) = (descritor*) malloc(sizeof(descritor));
	pontSA *arqD = (pontSA*)malloc(sizeof(pontSA));
	listaGAD *lg = (listaGAD*) malloc(sizeof(listaGAD));

	arqD->i_nodes = null;
	arqD->diretorio_raiz = CriaBloco_Dir(1);
	arqD->diretorio_raiz->FileOrDir.dire.vetl_node[0] = 1;
	arqD->diretorio_raiz->FileOrDir.dire.vetl_node[1] = 1;
	arqD->diretorio_raiz->FileOrDir.dire.tl = 2;
	strcpy(arqD->diretorio_raiz->FileOrDir.dire.vetArqDir[0], ".");
	strcpy(arqD->diretorio_raiz->FileOrDir.dire.vetArqDir[1], "..");
	arqD->arquivos_diretorios = null;
	strcpy(lg->nome, "/");

	lg->i_node = 1;
	lg->pi_node = null;
	lg->head = null;
	lg->tails = null;
	(*d)->ArqDir = arqD;
	(*d)->ListGen = lg;
}
void iniciaListaGAD(listaGAD **l, int n)
{
	(*l) = (listaGAD*) malloc(sizeof(listaGAD));
	(*l)->i_node = n;
	(*l)->head = null;
	(*l)->tails = null;
	(*l)->pi_node = null;
}
void Cons(descritor **d, listaGAD *h, listaGAD *t)
{
	listaGAD *lis;
	if(isFile(t))
	{
		printf("Erro O Segundo Argumento Não Pode Ser Arquivo");
		return;
	}
	else
	{
		lis = (listaGAD*) malloc(sizeof(listaGAD));
		lis->i_node = 10;
		CriaINode(&(lis->pi_node), 'd', lis->i_node, " ", 0, "02-30-2019", "00:00");
	}
}
void BuscaNo(listaGAD **lg, int n)
{
	listaGAD *aux = (*lg)->head;
	while(aux != null && aux->tails != null && aux->i_node != n)
	{
		aux = aux->tails;
	}
	if(aux != null && aux->i_node == n)
		*lg = aux;
}

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include "Encadeamento.h"

void getDataAndHora(char data[11], char hora[6])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(data, "%d-%d-%d", tm.tm_mday, tm.tm_mon, tm.tm_year);
	sprintf(hora, "%d:%d", tm.tm_hour, tm.tm_min);
}
char isRoot(listaGAD *l)
{
	return (l->i_node ==1);
}
void AddInodeListaGen(listaGAD **dAtual, listaGAD *ni)
{
	listaGAD *aux = *dAtual;
	aux = aux->head;
	if(aux == null)
	{
		(*dAtual)->head = ni;
	}
	else
	{
		while(aux->tails != null)
		{
			aux = aux->tails;
		}
		aux->tails = ni;
	}
}

void mkdir(descritor **d, listaGAD **l, char nome[])
{
	char data[11], hora[6], flag = 0;
	int nb = 0;
	pontSA *listaA = (*d)->ArqDir;
	pont_bloco *lblocos;
	ponti_node *lInode, *auxLinode, *ainode, *inodecout;
	if(isRoot(*l))
		lblocos = listaA->diretorio_raiz;
	else
	{
		if(listaA->arquivos_diretorios == null)
		{
			lblocos = (pont_bloco*) malloc(sizeof(pont_bloco));
			if((*l)->pi_node->TL == 0)
			{
				(*l)->pi_node->vetBloco[(*l)->pi_node->TL] = 100;
				lblocos = CriaBloco_Dir(100);
 				(*l)->pi_node->vetPontBloco[(*l)->pi_node->TL] = lblocos;
				(*l)->pi_node->TL++;
			}
			else
			{
				(*l)->pi_node->vetBloco[(*l)->pi_node->TL] = (*l)->pi_node->vetBloco[(*l)->pi_node->TL-1];
				lblocos = CriaBloco_Dir((*l)->pi_node->vetBloco[(*l)->pi_node->TL-1]);
				(*l)->pi_node->vetPontBloco[(*l)->pi_node->TL] = lblocos;
				(*l)->pi_node->TL++;
			}
			listaA->arquivos_diretorios = lblocos;
		}
		else
			lblocos = listaA->arquivos_diretorios;
		flag = 1;
	}
	listaGAD *novaCaixaListaGen;
	inodecout = listaA->i_nodes;
	if(inodecout == null)
		nb = 2;
	else
		while(inodecout != null)
		{
			if(inodecout->i_node > nb)
				nb = inodecout->i_node;
			inodecout = inodecout->prox;
		}
	if(lblocos->FileOrDir.dire.tl < 5)
	{
		nb++;
		lblocos->FileOrDir.dire.vetl_node[lblocos->FileOrDir.dire.tl] = nb;
		strcpy(lblocos->FileOrDir.dire.vetArqDir[lblocos->FileOrDir.dire.tl++], nome);
	}
	else
	{
		lblocos->prox = CriaBloco_Dir(lblocos->bloco+1);
		lblocos = lblocos->prox;
		nb++;
		lblocos->FileOrDir.dire.vetl_node[lblocos->FileOrDir.dire.tl] = nb;
		strcpy(lblocos->FileOrDir.dire.vetArqDir[lblocos->FileOrDir.dire.tl++], nome);
	}
	if(!flag)
	{
		getDataAndHora(data, hora);
		CriaINode(&lInode, 'd', nb, "rwxr–xr–x", 1 , data, hora);
		if(listaA->i_nodes == null)
		{
			listaA->i_nodes = lInode;
		}
		else
		{
			auxLinode = listaA->i_nodes;
			while(auxLinode->prox != null){auxLinode = auxLinode->prox;}
			auxLinode->prox = lInode;
		}
		iniciaListaGAD(&novaCaixaListaGen, nb);
		strcpy(novaCaixaListaGen->nome, nome);
		novaCaixaListaGen->pi_node = lInode;
		AddInodeListaGen(&*l, novaCaixaListaGen);
	}
	else
	{
		getDataAndHora(data, hora);
		CriaINode(&lInode, 'd', nb, "rwxr–xr–x", 1 , data, hora);
		auxLinode = listaA->i_nodes;
			while(auxLinode->prox != null){auxLinode = auxLinode->prox;}
			auxLinode->prox = lInode;
		auxLinode = listaA->i_nodes;
		while(auxLinode != null && auxLinode->i_node != (*l)->i_node)
		{
			auxLinode = auxLinode->prox;
		}
		if(auxLinode->i_node == (*l)->i_node)
		{
			auxLinode->vetBloco[auxLinode->TL] = lblocos->bloco;
			auxLinode->vetPontBloco[auxLinode->TL] = lblocos;
			auxLinode->TL++;
		}
		iniciaListaGAD(&novaCaixaListaGen, nb);
		strcpy(novaCaixaListaGen->nome, nome);
		novaCaixaListaGen->pi_node = lInode;
		AddInodeListaGen(&*l, novaCaixaListaGen);
	}
}
void getTLPilha(pilha *p)
{
	if(p != null)
	{
		printf("p ");
		getTLPilha(p->prox);
	}
}
void getPilhaCaminho(pilha **p, descritor *d, listaGAD *a)
{
	listaGAD *l = d->ListGen;
	initPilha(&*p);
	push(&(*p), l);
	while(!Pilha_Vazia(*p) && l != null && l->i_node != a->i_node)
	{
		if(!isNull(l))
		{
			pop(&*p, &l);
			while(!isNull(l) && !Atomo(l))
			{
				push(&*p, l);
				l = Head(l);
			}
		}
		pop(&*p, &l);
		l = Tail(l);
		if(!isNull(l))
			push(&*p, l);
	}
	if(l != null && l->i_node == a->i_node)
	{
		push(&*p, l);
	}
}
char taAqui(listaGAD *l, int n)
{
	if(l != null)
	{
		return (l->i_node == n)? 1 : taAqui(l->head, n) || taAqui(l->tails, n);
	}
	else
		return 0;
}
void LimpaPilha(pilha **p)
{
	listaGAD *lixo;
	while((*p) != null && !Pilha_Vazia(*p))
	{
		pop(&(*p), &lixo);
		free(lixo);
	}
	free(*p);
}
void getPilhaCaminho2(pilha **p, descritor *d, listaGAD *a)
{
	listaGAD *aux = d->ListGen;
	initPilha(&*p);
	while(aux != null && aux->i_node != a->i_node)
	{
		if(taAqui(aux->head, a->i_node))
		{
			push(&(*p), aux);
			aux = aux->head;
		}
		else
		{
			aux = aux->tails;
			//push(&(*p), aux);
		}
	}
	if(aux == null)
	{
		free(*p);
		(*p) = null;
	}
}
void pwd(listaGAD *atual, descritor *d)
{
	pilha *p, *p2;
	listaGAD *auxLixo;
	initPilha(&p2);
	getPilhaCaminho2(&p, d, atual);
	while(!Pilha_Vazia(p)){pop(&p, &auxLixo);push(&p2, auxLixo);}//dempilha e empilha para exibir na ordem certa
	while(!Pilha_Vazia(p2))
	{
		pop(&p2, &auxLixo);
		if(auxLixo != NULL)
		{
			if(auxLixo->i_node != 1)
			{
				printf("%s/", auxLixo->nome);
				//strcat(caminho, auxLixo->nome);
				//strcat(caminho, "/");
			}
			else
			{
				printf("%s", auxLixo->nome);
				//strcat(caminho, auxLixo->nome);
			}
		}
	}
	printf("%s\n", atual->nome);
	//return caminho;
	//printf("%s/%s\n", caminho, atual->nome);
}
void ls_m(listaGAD *a, descritor *d)
{
	a = a->head;
	while(a != null)
	{
		printf("%s", a->nome);
		if(a->tails != null)
			printf(",");
        a = a->tails;
	}
	printf("\n");
	/*pilha *p;
	listaGAD *GB;
	initPilha(&p);
	pont_bloco *pb ;
	int i = 0;
	if(a->i_node == 1)
	{
		a = a->head;
		pb = d->ArqDir->diretorio_raiz;
		while(!isNull(a))
		{
			push(&p, a);
			a = Tail(a);
		}
		while(pb != null && !Pilha_Vazia(p))
		{
			for(i = 0; i < pb->FileOrDir.dire.tl; i++)
			{
				if(!Pilha_Vazia(p) && pb->FileOrDir.dire.vetl_node[i] == p->info->i_node)
				{
					pop(&p, &GB);
					printf("%s",
					pb->FileOrDir.dire.vetArqDir[i]);
				}
				if(!Pilha_Vazia(p)&& i!=0)
					printf(",");
			}
		}
	}	
	else
	{
		a = a->head;
		pb = d->ArqDir->arquivos_diretorios;
		while(!isNull(a))
		{
			push(&p, a);
			a = Tail(a);
		}
			
		while(pb != null && !Pilha_Vazia(p))
		{
			for(i = 0; i < pb->FileOrDir.dire.tl; i++)
			{
				if(!Pilha_Vazia(p) && pb->FileOrDir.dire.vetl_node[i] == p->info->i_node)
				{
					pop(&p, &GB);
					printf("%s", pb->FileOrDir.dire.vetArqDir[i]);
				}
				if(!Pilha_Vazia(p) && i!=0)
					printf(",");
			}
		}
		printf("\n");
	}*/
}
void ls_l(listaGAD *a, descritor *d)
{
	a = a->head;
	while(a != null)
	{
		printf("%s   armando    users    %d    %s    %s    %s\n",
					a->pi_node->atr, 
					a->pi_node->tam, 
					a->pi_node->data, 
					a->pi_node->hora, 
					a->nome);
        a = a->tails;
	}
	/*pilha *p;
	listaGAD *GB;
	initPilha(&p);
	pont_bloco *pb ;
	int i = 0;
	if(a->i_node == 1)
	{
			a = a->head;
		pb = d->ArqDir->diretorio_raiz;
		while(!isNull(a))
		{
			push(&p, a);
			a = Tail(a);
		}
		while(pb != null && !Pilha_Vazia(p))
		{
			for(i = 0; i < pb->FileOrDir.dire.tl; i++)
			{
				if(!Pilha_Vazia(p) && pb->FileOrDir.dire.vetl_node[i] == p->info->i_node)
				{
					pop(&p, &GB);
					printf("%s   armando    users    %d    %s    %s    %s\n",
					GB->pi_node->atr, 
					GB->pi_node->tam, 
					GB->pi_node->data, 
					GB->pi_node->hora, 
					pb->FileOrDir.dire.vetArqDir[i]);
					//free(GB);
				}
			}
		}
	}	
	else
	{
		a = a->head;
		pb = d->ArqDir->arquivos_diretorios;
		while(!isNull(a))
		{
			push(&p, a);
			a = Tail(a);
		}
			
		while(pb != null && !Pilha_Vazia(p))
		{
			for(i = 0; i < pb->FileOrDir.dire.tl; i++)
			{
				if(!Pilha_Vazia(p) && pb->FileOrDir.dire.vetl_node[i] == p->info->i_node && pb->FileOrDir.)
				{
					pop(&p, &GB);
					printf("%s   armando    users    %d    %s    %s    %s\n",GB->pi_node->atr, GB->pi_node->tam, GB->pi_node->data, GB->pi_node->hora, pb->FileOrDir.dire.vetArqDir[i]);
					//free(GB);
					printf("\n");
				}
			}
		}
		printf("\n");
	}*/
}

/*void cd_Aux(descritor **d, listaGAD **a, char *dirFind, int nnode)
{
	int i, k, Nnode;
	pont_bloco *pb;
	char flag = 1;
	ponti_node *pn = (*d)->ArqDir->i_nodes;
	while(pn != null && pn->i_node != nnode){pn = pn->prox;}
    if(pn != null && flag)
	{
		for(i = 0; i < pn->TL && flag; i++)
		{
			pb = pn->vetPontBloco[i];
			for(k = 0; k < pb->FileOrDir.dire.tl && flag; k++)
			{
				if(!strcmp(pb->FileOrDir.dire.vetArqDir[k], dirFind))
				{
					flag = 0;
					Nnode = pb->FileOrDir.dire.vetl_node[k];
				}
			}
		}
		if(!flag)
		{
			dirFind = strtok(null, "/");
			if(dirFind != null)
			{
				BuscaNo(&*a, Nnode);
				cd_Aux(&*d, &*a, dirFind, Nnode);
			}
		}
	}
	else
	{
		*a = null;
	}
}*/
char cd(descritor **d, listaGAD **a, char caminho[250], char da[50])
{
	char *pd, flag = 1, flag2 = 1;
	listaGAD *auxdiratual, *aux;
	if(caminho[3] == '/')
	{
		pd = strtok(null, "/");	
		auxdiratual = (*d)->ListGen;
	}
	else
	{
		pd = strtok(null, " ");
		auxdiratual = *a;
	}
	while(auxdiratual != null && pd != null && flag)
	{
		aux = auxdiratual->head;
		while(aux!=null && flag2)
		{
			if(!strcmp(aux->nome, pd))
				flag2 = 0;
			else
				aux = aux->tails;
		}
		if(!flag2)
		{
			auxdiratual = aux;
		}
		pd = strtok(null, "/");
	}
	if(pd == null && auxdiratual != null && (*a) != auxdiratual)
	{
		*a = auxdiratual;
		return 1;
	}
	else
	{
		printf("Caminho incorreto!!!\n");
		return 0;
	}
		
}
char cd2(descritor **d, listaGAD **a, char caminho[250], char da[50])
{
	char *pd, flag = 1, flag2 = 1;
	listaGAD *auxdiratual, *aux;
	if(caminho[3] == '/')
	{
		pd = strtok(caminho, "/");	
		auxdiratual = (*d)->ListGen;
	}
	else
	{
		pd = strtok(null, " ");
		auxdiratual = *a;
	}
	while(auxdiratual != null && pd != null && flag)
	{
		aux = auxdiratual->head;
		while(aux!=null && flag2)
		{
			if(!strcmp(aux->nome, pd))
				flag2 = 0;
			else
				aux = aux->tails;
		}
		if(!flag2)
		{
			auxdiratual = aux;
		}
		pd = strtok(null, "/");
	}
	if(pd == null && auxdiratual != null && (*a) != auxdiratual)
	{
		*a = auxdiratual;
		return 1;
	}
	else
	{
		printf("Caminho incorreto!!!\n");
		return 0;
	}
		
}
int isLeapYear( int y ) /* True if leap year */
{
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int leapYears( int y ) /* The number of leap year */
{
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d) /* The number of days since the beginning of the year */
{
    static int DayOfMonth[] = 
        { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};

    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}

long days( int y, int m, int d) /* Total number of days */
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}

void call(int m, int y) /* display calendar at m y */
{
	if(m == -1)
		m = 4;
	if(y == -1)
		y = 2018;
    const char *NameOfMonth[] = 
	{ NULL/*dummp*/,
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    char Week[] = "Do Se Te Qu Qu Se Sá";
    int DayOfMonth[] =
        { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days(y, m, 1) % 7;
    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        printf("%2d ",day);
        if(i % 7 == 6)
            printf("\n");
    }   
    printf("\n");
}
void AdicionaBlocoDoTipoArquivo(ponti_node **i, pont_bloco **p, int n)//p é o ultimo bloco de arquivos de diretórios
{
	pont_bloco *ab;
	ab = CriaBloco_Arq(n, "");
	if((*p) == null)
		(*p) = ab;
	else
		(*p)->prox = ab;
	if((*i)->TL+1 < 5)
	{
		(*i)->vetPontBloco[(*i)->TL++] = ab;
		(*i)->vetBloco[(*i)->TL] = n;
	}
	else
		printf("Limite de conteúdo do I-node %d Atingido", (*i)->i_node);
	
}
int getMax(pont_bloco *p, int M)
{
	if(p != null)
		getMax(p->prox, (M < p->bloco)? p->bloco : M);
	else
		return M;
}
void ModoEdicao(ponti_node **inode, pont_bloco **bloco)
{
	char c, flag = 1;
	int i = 0;
	ponti_node *auxi = *inode;
	pont_bloco *auxb = *bloco;
	pont_bloco *newb;
	//system("cls");
	printf("\n[F2] - Sair\nModo Edição: ");
	while(flag)
	{
		fflush(stdin);
		c = getch();
		
		if(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c == 32 || c == 13)
		{
			printf("%c", c);
			auxb->FileOrDir.parteArquivo[i] = c;
			i=i+1;
			auxi->tam++;
		}
		if(c == 13)
			printf("\n");
		
		if(i == 74)
		{
			if(auxi->TL+1 < 5)
			{
				newb = CriaBloco_Arq(auxb->bloco+1, "");
				auxb->prox = newb;
				auxi->vetBloco[auxi->TL] = newb->bloco;
				auxi->vetPontBloco[auxi->TL++] = newb;
				auxb = auxb->prox;
				i = 0;//pra começar a escrever no inicio deste novo bloco
			}
			else
				flag = 0;
		}
		flag = (c == 60 || !flag)? 0 : 1;
	}
	printf("\n");
	//system("cls");
}
void catMaior(descritor **d, listaGAD **a, char nome[20])
{
	listaGAD *aux;
	char data[11], hora[6];
	ponti_node *inodecout = (*d)->ArqDir->i_nodes;
	ponti_node *auxnode;
	pont_bloco *auxbloco;
	int nb = 0, M1, M2;
	if((*a)->i_node != 1)
	{
		if(inodecout == null)
			nb = 2;
		else
			while(inodecout->prox != null)
			{
				if(inodecout->i_node > nb)
					nb = inodecout->i_node;
				inodecout = inodecout->prox;
			}
	    if(inodecout != null && inodecout->i_node > nb)
	    	nb = inodecout->i_node;
		if((*a)->head == null)
		{
			iniciaListaGAD(&aux, nb+1);
			strcpy(aux->nome, nome);
			(*a)->head = aux;
		}
		else
		{
			aux = (*a)->head;
			while(aux->tails != null)
			{
				aux = aux->tails;
			}
			iniciaListaGAD(&(aux->tails), nb+1);
			strcpy(aux->tails->nome, nome);
			aux = aux->tails;
		}
		getDataAndHora(data, hora);
		CriaINode(&auxnode, '-', nb+1, "rwxrwxrwx", 0, data, hora);
		inodecout->prox = auxnode;
		aux->pi_node = auxnode;
		if((*d)->ArqDir->arquivos_diretorios == null)
		{
			AdicionaBlocoDoTipoArquivo(&auxnode, &auxbloco, getMax((*d)->ArqDir->diretorio_raiz, 0) + 1);
		}
		else
		{
			auxbloco = (*d)->ArqDir->arquivos_diretorios;
			while(auxbloco->prox != null)
			{
				auxbloco = auxbloco->prox;
			}
			M1 = getMax((*d)->ArqDir->diretorio_raiz, 0);
			M2 = getMax((*d)->ArqDir->arquivos_diretorios, 0);
			AdicionaBlocoDoTipoArquivo(&auxnode, &auxbloco, (M1 > M2)? M1 + 1 : M2 + 1);
		}
		ModoEdicao(&auxnode, &auxbloco);
	}
	else
		printf("Não É Possível Criar Arquivos Na Raiz!!!\n");
}

void catNormal(descritor **d, listaGAD **a, char camin[250])
{
	int i, k, j;
	listaGAD *auxlistaGen = (*a)->head;
	ponti_node *pi;
	pont_bloco *pb;
	//system("cls");
	if((*a)->i_node != 1)
	{
		while(auxlistaGen != null && strcmp(auxlistaGen->nome, camin))
		{
			auxlistaGen = auxlistaGen->tails;
		}
		if(!strcmp(auxlistaGen->nome, camin))
		{
			if(auxlistaGen->pi_node !=null && auxlistaGen->pi_node->tipo == '-')
			{
				pi = auxlistaGen->pi_node;
				for(i = 0, k = pi->tam; i < pi->TL && k > 0; i++)
				{
					pb = pi->vetPontBloco[i];
					for(j = 0; j < 74 && k > 0; j++)
					{
						if(pb->FileOrDir.parteArquivo[j] == 13)
							printf("\n");
						else
						{
							printf("%c", pb->FileOrDir.parteArquivo[j]);
						}
						k--;
					}
				}
			}
			else
				printf("Caminho Especificado Não Existe ou Não Corresponde a um Arquivo!!!");
		}
	}
	else
		printf("Não Existem Arquivos na raiz");
	printf("\n");
}


void mv(descritor **d, listaGAD **a, char camin[250])
{
	char *pd,flag = 0,flag2 = 0;
	char *auxc, auxc2[250];
	listaGAD *aux = (*d)->ListGen;
	listaGAD *aux2,*antdestino,*antorigem;
	aux2 = (*a)->head;
	strcpy(auxc2, camin);
	auxc = strtok(camin, " ");

	auxc = strtok(null, " ");
	if(aux2->tails == NULL)
		flag2 = 1;
	while(aux2->tails != null && strcmp(auxc,aux2->nome))
	{
		antorigem = aux2;
		aux2 = aux2->tails;
	}
        

    if(aux2 != null && !strcmp(auxc,aux2->nome) && aux2->pi_node->tipo == '-')
    {
       	auxc = strtok(null, "/");
        aux = aux->head;
        while(auxc !=null && !flag)
		{
	        if(aux!=null)
			{
				while(aux!=null && strcmp(auxc,aux->nome))
	        		aux = aux->tails;
	        	
	        	if(aux!=null && !strcmp(auxc,aux->nome))
				{
					antdestino = aux;
					aux = aux->head;
					auxc = strtok(null, "/");
				}
	        		
	        	else
				{
					printf("Caminho não encontrado!!!\n");
					flag = 1;
				}
			}
			else
			{
				printf("Caminho não encontrado!!!\n");
				flag = 1;
			}
		}
		if(!flag)
		{
			if(flag2)
			{
				if(antdestino->head == null)
					antdestino->head = aux2;
				else
				{
					antdestino = antdestino->head;
					while(antdestino->tails != null)
						antdestino = antdestino->tails;
					
					antdestino->tails = aux2;
				}
				(*a)->head = null;
			}
			else
			{
				antorigem->tails = aux2->tails;
					
					if(antdestino->head == null)
						antdestino->head = aux2;
					else
					{
						antdestino = antdestino->head;
						while(antdestino->tails != null)
							antdestino = antdestino->tails;
						
						antdestino->tails = aux2;
					}
					if(aux2 != null)
						aux2->tails = null;
			}
				
		}
    }
    else
    printf("Arquivo não encontrado!!!\n");

}




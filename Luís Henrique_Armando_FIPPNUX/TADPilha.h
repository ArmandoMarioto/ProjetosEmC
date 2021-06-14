void initPilha(pilha **p)
{
	(*p) = null;
}
listaGAD* topPilha(pilha *p)
{
	return p->info;
}
void push(pilha **p, listaGAD *element)
{
	if(*p == null)
	{
		(*p) = (pilha*) malloc(sizeof(pilha));
		(*p)->info = element;
		(*p)->prox = null;
	}
	else
	{
		pilha *nc = (pilha*) malloc(sizeof(pilha));
		pilha *aux = (*p);
		nc->info = element;
		nc->prox = aux;
		(*p) = nc;
	}
}
void pop(pilha **p, listaGAD **elem)
{
	listaGAD *aux = (*p)->info;
	(*elem) = (*p)->info;
	if(aux != null)
		(*p) = (*p)->prox;
	//free(aux);
}
char Pilha_Vazia(pilha *p)
{
	return (p == null)? 1 : 0;
}

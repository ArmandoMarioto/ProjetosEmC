






int buscaExaustiva(int v[TF],int TL,int Elem)//busca exaustiva
{
	int i=0;
	while(i<tl && Elem !=v[i])
	i++;
	if(i<TL)//achou
	return i;
	else
	return -1;
}

int buscaExaustivaSentinela(int v[TF],int TL , int Elem)//Busca Exaustiva Sentinela
{
	int i=0;
	v[TL]=Elem;
	while(Elem!=v[i])
	i++;
	if(i<TL)//achou
	return i;
	else
	return -1;
	
}

int BuscaSequencialIndexada(int v[TF], int TL,int Elem)// Busca com Vetor ja Ordenado
{
	int i =0;
	while(i<tl && Elem >v[i])
	i++;
	if(i<tl && Elem == v[i])
	return i;
	else
	return -1;
}

int buscabinaria(int v[TF], int TL,int Elem)// Busca com Vetor ja Ordenado
{
	int incio=0,fim=tl-1,meio;
	meio=fim/2;
	while(inicio<fim && Elem!=v[meio])
	{
		if(v[meio<Elem])
	inicio=meio+1;
	else fim=meio;
	meio=((inicio+fim)/2);
	}
	if(Elem==v[meio])
	return meio;
	else
	return -1;	
}

/* estruturas de dados com disciplina de acesso pilha

conceito:   LIFO=> last in first out


A pilha disponibiliza acesso apenas 
*/
struct TpPilha
{
	int topo;
	char pilha[maxpilha];
};

/*void inicializa(TpPilha &P);
int Vazio(int topo);
int cheia(int topo);
void Insere(TpPilha &P,char Elemento);
char Retira(TpPilha &P);
char retornaelemtopo(TpPilha P);
void Exibe(TpPilha P);

*/

void inicializa(TpPilha &P)
{ 
			P.topo=-1;
	
}
int Vazio(int topo)
{
	if(topo==-1)
	  return 1;

}
int cheia(int topo)
{
	if(topo==maxpilha-1)
	return 0;
}
void Insere(TpPilha &P,char Elemento)
{
	P.pilha[++P.topo]=Elemento);
	
}
int Retira(TpPilha &P)
{
	return P.pilha[P.topo--];	
}
char retornaelemtopo(TpPilha P)
{
	return P[topo].pilha;
}
void Exibe(TpPilha P)
{
	while(!Vazia(P.topo))
	{
		printf("\n%c",Retira(P));
	}
}


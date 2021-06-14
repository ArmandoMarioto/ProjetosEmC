struct Dir
{
	int vetl_node[5];
	char vetArqDir[5][10];
	int tl;
};
union Info
{
	char parteArquivo[74];
	struct Dir dire;
};
struct pontbloco
{
	int bloco;
	struct pontbloco *prox;
	union Info FileOrDir;
};
struct listaGenArqDir
{
	int i_node;
	char nome[30];
	struct PontI_node *pi_node;
	struct listaGenArqDir *head;
	struct listaGenArqDir *tails;
};
struct PontI_node
{
	int i_node;
	char tipo;
	char atr[9];
	int tam;
	char data[11];
	char hora[6];
	int TL;//tamanho lógico do vetBloco
	int vetBloco[5];
	struct pontBloco *vetPontBloco[5];
	struct PontI_node *prox;
};
struct pontSistArq
{
	struct PontI_node *i_nodes;
	struct pontbloco *diretorio_raiz;
	struct pontbloco *arquivos_diretorios;
};
struct Descritor
{
	   struct pontSistArq *ArqDir;
	   struct listaGenArqDir *ListGen;	
};
struct TPpilha
{
	struct listaGenArqDir *info;
	struct TPpilha *prox;
};
typedef struct Descritor descritor;
typedef struct Dir dir;
typedef union Info info;
typedef struct pontbloco pont_bloco;
typedef struct listaGenArqDir listaGAD;
typedef struct PontI_node ponti_node;
typedef struct pontSistArq pontSA;
typedef struct TPpilha pilha;
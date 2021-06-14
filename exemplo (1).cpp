#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>

struct TpPessoa
{
	char Nome[30];
	int AnoNasc;
	float Salario;
};

//prototipos
void Executar(void);
char Menu(void);
void VerificaArq(FILE *Arq);
void cadastra(FILE *Arq);
void Exibe(FILE *Arq);

void Exibe_ERRO(FILE *Arq)//dando erro
{	TpPessoa RegPessoa;
	Arq=fopen("pessoa.dat","rb");    //Abre o arquivo para leitura
	clrscr();
	printf("### Dados das Pessoas ###\n");
	while(!feof(Arq))
	{
		fread(&RegPessoa,sizeof(TpPessoa),1,Arq);
		printf("\n%s \t%d \t %.2f",RegPessoa.Nome,RegPessoa.AnoNasc,RegPessoa.Salario);
	}
	printf("\n--------- Fim do Arquivo -------\n");
	getch();
	fclose(Arq);
}
void Exibe(FILE *Arq)
{	TpPessoa RegPessoa;
	Arq=fopen("pessoa.dat","rb");    //Abre o arquivo para leitura
	clrscr();
	printf("### Dados das Pessoas ###\n");
	fread(&RegPessoa,sizeof(TpPessoa),1,Arq);
	while(!feof(Arq))
	{
		
		printf("\n%s \t%d \t %.2f",RegPessoa.Nome,RegPessoa.AnoNasc,RegPessoa.Salario);
		fread(&RegPessoa,sizeof(TpPessoa),1,Arq);
	}
	printf("\n--------- Fim do Arquivo -------\n");
	getch();
	fclose(Arq);
}

void cadastra(FILE *Arq)
{
	TpPessoa RegPessoa;
	Arq = fopen("pessoa.dat","ab");// Abre arquivo para gravação , cria se o arquivo nao existir no HD
	
	clrscr();
	printf("\n## Cadastro de pessoas ###\n");
	printf("Nome: ");
	fflush(stdin);
	gets(RegPessoa.Nome);
	while(strcmp(RegPessoa.Nome,"\0")!=0)
	{
	printf("\n Ano de Nascimento: ");
	scanf("%d",&RegPessoa.AnoNasc);
	printf("\n Salario: ");
	scanf("%f",&RegPessoa.Salario);
	
	//Gravar os dados da struct no arquivo
	fwrite(&RegPessoa,sizeof(TpPessoa),1,Arq);
	printf("\nNome: ");
	fflush(stdin);
	gets(RegPessoa.Nome);
	}
	
	fclose(Arq);//Precisamos fechar o buffer para descarregar ele da memoria para  HD
}

void VerificaArq(FILE *Arq)
{
	Arq=fopen("pessoa.dat","rb"); //|Abre arquivo para leitura, nao cria.
	if(Arq == NULL)
		printf("\n Arquivo Não foi aberto!!!");
	else
	{
		printf("\n Arquivo foi aberto para uso!!!");
		fclose(Arq);
	}
	getch();	
}
char Menu(void)
{
	textcolor(15);
	clrscr();
	printf("[A] Verifica se Arquivo Existe\n");
	printf("[B] Cadastrar Pessoa\n");
	printf("[C] Exibir Dados\n");
	printf("[D] Consultar por Nome\n");
	printf("[E] Altera Dados\n");
	printf("[F] Ordenar Arquivo\n");
	printf("[G] Exclusão física em arquivo\n");
	printf("[ESC] Finalizar\n");
	printf("\n\n Digite a opção desejada:");
	return toupper(getch());	
}
void Executar(void){
	char opcao;
	FILE *ArqPessoa;//cria uma variavel do tipo buffer
	
	do{
		clrscr();
		opcao=Menu();
		switch(opcao)
		{
				case 'A':
					VerificaArq(ArqPessoa);

				break;
				case 'B':
					cadastra(ArqPessoa);
				break;
				case 'C':
					Exibe(ArqPessoa);
				break;
				case 'D':
				break;
				case 'E':
				break;
				case 'F':
				break;
				case 'G':
				break;
				
		}
	}while(opcao!=27);
};
int main()
{
	Executar();
	return 0;
	
}

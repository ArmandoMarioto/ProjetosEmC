#include<stdio.h>
#include<conio2.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<locale.h>
struct TpPessoa
{
	char Nome[30];
	int AnoNasc;
	float Salario;
};
//Prótotipos

void Executar(void);
char Menu(void);
void VerificaArq(FILE*Arq);
void Cadastra(FILE *Arq);
void Exibe(FILE *Arq);
void Consulta(FILE *Arq);
int Busca(FILE *Arq, char Chave[30]);
void Ordena(FILE *Arq);
void exclusao(FILE* Arq);
void Altera(FILE *Arq);

void Altera(FILE *Arq)
{
	TpPessoa Reg;
	int pos;
	Arq=fopen("Pessoas.dat","rb+"); //para leitura e gravação no arquivo
	clrscr();
	printf("###     Alteração de Dados    ###");
	printf("\nDigite o Nome a ser alterado:");
    fflush(stdin);
	gets(Reg.Nome);
	pos=Busca(Arq,Reg.Nome);
	if(pos ==-1)
	{
		printf("\n Nome não encontrado...");
		fclose(Arq);
		getch();
	}else
	{
		printf("\n\n Dados encontrados\n\n");
		fseek(Arq,pos,0);
		fread(&Reg,sizeof(TpPessoa),1,Arq);
		printf("\nNome;%s \t Ano Nasc:%d \t Salario:%.2f", Reg.Nome, Reg.AnoNasc, Reg.Salario);
		printf("\nCONFIRMA ALTERAÇÃO (S/N)?");
		if(toupper(getche())=='S')
		{
			printf("\n\nDigite os Novos dados \n ");
			printf("\n Nome:");
			fflush(stdin);
			gets(Reg.Nome);
			printf("\nAno Nascimento:");
			scanf("%d",&Reg.AnoNasc);
			printf("\nSalario:");
			scanf("%f",&Reg.Salario);
			//precisamos gravar os dados alterados....Precisa posicionar novamente para sobrepor os dados,pois como um fread já foi executado,o ponteiro deslocou para o inicio do proximo registro
			fseek(Arq,pos,0);
			fwrite(&Reg,sizeof(TpPessoa),1,Arq);
			fclose(Arq);
			printf("\n\n Dados Alterados...\n");
			getch();
		}else
		fclose(Arq);
		
	}
	
	
}

void exclusao(FILE* Arq)
{
	FILE *ArqTemp;
	TpPessoa Reg;
	char AuxNome[30];
	int pos;
	Arq = fopen("Pessoas.dat","rb");
	clrscr();
	printf("###     Exclusão de Dados    ###");
	printf("\nDigite o Nome a ser excluir:");
    fflush(stdin);
	gets(AuxNome);
	pos=Busca(Arq,AuxNome);
	if(pos ==-1)
	{
		printf("\n Nome não encontrado...");
		fclose(Arq);
		getch();
	}else
	{
		printf("\n\n Dados encontrados\n\n");
		fseek(Arq,pos,0);
		fread(&Reg,sizeof(TpPessoa),1,Arq);
		printf("\nNome;%s \t Ano Nasc:%d \t Salario:%.2f", Reg.Nome, Reg.AnoNasc, Reg.Salario);
		printf("\nCONFIRMA EXCLUSÃO (S/N)?");
		if(toupper(getche())=='S')
		{
			//gerar um arquivo temporario para copiar os registros que permanecerão
			ArqTemp = fopen("TempPessoas.dat","wb");
			fseek(Arq,0,0);
			fread(&Reg,sizeof(TpPessoa),1,Arq);
			while(!feof(Arq))
			{
				if(strcmp(Reg.Nome,AuxNome)!=0)
				fwrite(&Reg,sizeof(TpPessoa),1,ArqTemp);
				fread(&Reg,sizeof(TpPessoa),1,Arq);
			}
			//Vai a troca dos Nomes dos arquivos
			//1- excluir o arquivo pessoas.dat
			//2-renomear o arquivo TempPessoas.dat para pessoas.dat
			fclose(Arq);
			fclose(ArqTemp);
			remove("Pessoas.dat");
			rename("TempPessoas.dat","Pessoas.dat");
			printf("\n Dados  Excluidos...\n");
			getch();
		}else fclose(Arq);
			
	}
}

void Ordena(FILE *Arq)
{
	TpPessoa RegA, RegB;
	int posA, posB, QtdeRegistros;
	Arq = fopen("Pessoas.dat", "rb+");
	clrscr();
	printf("\n\n### Ordena o Arquivo ####\n");
	fseek(Arq, 0,2);//posicionar no final do arquivo
	QtdeRegistros = ftell(Arq)/sizeof(TpPessoa);
	for(posA=0;posA<QtdeRegistros-1;posA++)
	{
		for(posB=posA+1; posB<QtdeRegistros; posB++)
		{
			fseek(Arq,posA*sizeof(TpPessoa),0);
			fread(&RegA, sizeof(TpPessoa),1, Arq);
			
			fseek(Arq,posB*sizeof(TpPessoa),0);
			fread(&RegB, sizeof(TpPessoa),1, Arq);
			if(strcmp(RegA.Nome, RegB.Nome)>0)
			{
				fseek(Arq, posA*sizeof(TpPessoa),0);
				fwrite(&RegB, sizeof(TpPessoa),1,Arq);
				fseek(Arq, posB*sizeof(TpPessoa),0);
				fwrite(&RegA, sizeof(TpPessoa),1,Arq);
			}
			
		}
	}
	fclose(Arq);
	printf("\n ******** Arquivo Ordenado");
	getch();
	
}
void Consulta(FILE *Arq)
{
	TpPessoa RegPessoa;
	int pos;
	
	Arq = fopen("Pessoas.dat","rb");
	clrscr();
	printf("\n###    Consulta de Pessoas por Nome	###\n");
	printf("Informe o Nome:");
	fflush(stdin);
	gets(RegPessoa.Nome);
	pos = Busca(Arq, RegPessoa.Nome);
	if(pos== -1)
	{
		printf("\n Nome não encontrado no arquivo...");
	}
	else
	{
		printf("\n\n Dados da Pessoa: \n");
		fseek(Arq, pos,0);//0- a partir do inicio
						//1- a partir da posição atual
						//2- a partir do final do arquivo
		fread(&RegPessoa, sizeof(TpPessoa),1,Arq);
		printf("\n%s \t %d \t %.2f", RegPessoa.Nome, RegPessoa.AnoNasc, RegPessoa.Salario);
		
	}
	getch();
	fclose(Arq);
}
int Busca(FILE *Arq, char Chave[30])
{
	TpPessoa P;
	//Possicionar o ponteiro do buffer no inicio do arquivo
	fseek(Arq,0,0);//rewind(Arq);
	fread(&P, sizeof(TpPessoa),1,Arq);
	while(!feof(Arq) && strcmp(P.Nome,Chave)!=0)
	fread(&P, sizeof(TpPessoa),1,Arq);
	//Verifica se encontrou o nome no arquivo
	
	if(strcmp(P.Nome,Chave)==0)
		return ftell(Arq)-sizeof(TpPessoa);
	else
		return -1;
	
}
void Exibe(FILE *Arq)
{
	TpPessoa RegPessoa;
	Arq = fopen("Pessoas.dat", "rb");//Abre o arquivo para leitura
	clrscr();
	printf("### Dados das Pessoas ###\n");
	fread(&RegPessoa,sizeof(TpPessoa),1,Arq);	
	while(!feof(Arq))
	{
		printf("\n%s \t %d \t %.2f", RegPessoa.Nome, RegPessoa.AnoNasc, RegPessoa.Salario);
		fread(&RegPessoa,sizeof(TpPessoa),1,Arq);
	}
	printf("\n--------- Fim doo Arquivo ----------\n");
	getch();
	fclose(Arq);
}


void Cadastra(FILE *Arq)
{
	TpPessoa RegPessoa;
	Arq = fopen("Pessoas.dat", "ab");//Abre arquivo para gravação, cria se o arquivo não existir no HD
	
	clrscr();
	printf("### Cadastro de pessoas ###\n");
	printf("Nome: ");
	fflush(stdin);
	gets(RegPessoa.Nome);
	while(strcmp(RegPessoa.Nome, "\0")!=0)
	{
	
	printf("\n Ano de Nasciento: ");
	scanf("%d", &RegPessoa.AnoNasc);
	printf("\n Salario: ");
	scanf("%f", &RegPessoa.Salario);
	//Gravar os dados da STRUCT no arquivo
	fwrite(&RegPessoa, sizeof(TpPessoa),1,Arq);
	printf("\nNome:");
	fflush(stdin);
	gets(RegPessoa.Nome);
	}
	fclose(Arq);//,Prescisamos fechar o bufferpara descarregar ela da memória para o HD
}
void VerificaArq(FILE*Arq)
{
	Arq = fopen("Pessoas.dat", "rb");//Abre o arquivo para leitura, mais não cria o arquivo
	if (Arq == NULL)
	{
		printf("\n Arquivo nao foi aberto!!");
	}
	else
	{
		printf("\n Arquivo foi aberto para uso!!");
		fclose(Arq);
	}
	getch();
}

char Menu(void)
{
	textcolor(15);
	clrscr();
	printf("[A] Verific se o arquivo existe \n");
	printf("[B] Cadastrar pessoa\n");
	printf("[C] Exibir Dados \n");
	printf("[D] Consultar por Nome\n");
	printf("[E] Alterar dados\n");
	printf("[F] Ordenar Arquivo\n");
	printf("[G] Execlusão Física em um arquivo\n");
	printf("[ESC] Finalizar\n");
	printf("\n \n Digite a opção desejada:");
	return toupper(getch());
	
}
void Executar(void)
{
	char opcao;
	
	FILE *ArqPessoa;
	do
	{
		clrscr();
		opcao = Menu();
		switch (opcao)
		{
			case'A':VerificaArq(ArqPessoa);
				break;
			case'B':Cadastra(ArqPessoa);
				break;
			case'C':Exibe(ArqPessoa);
				break;
			case'D':Consulta(ArqPessoa);
				break;
			case'E':Altera(ArqPessoa);
				break;
			case'F':Ordena(ArqPessoa);
				break;
			case'G':exclusao(ArqPessoa);
				break;
		}
		
	}while(opcao!=27);
}
int main()
{
	setlocale(LC_ALL,"portuguese");
	Executar();
	return 0;
}

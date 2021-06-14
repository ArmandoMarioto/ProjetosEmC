#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<locale.h>
#define TFC 30
#define TFP 10
#define TFV 50 

struct TpProduto
{
	int CodProd, Estoque ;
	char Descricao[40];
	float Preco;
};

struct TpCliente
{
	int CodCli;
	char Nome[30];
	
};

struct TpVenda
{
	int CodCli, CopProd, Qtde;
	
};

int main(void)
{
	//Declaração das variáveis
	
	TpProduto vetProdutos[TFP];
	TpCliente vetClientes[TFC],auxCliente;
	TpVenda vetVendas[TFV];
	int tlc=0, tlp=0, tlV=0,auxCod,c,i,pos,tam,k=0;
	char op,auxCliente2[100],auxCliente3[100];
	setlocale(LC_ALL,"portuguese");
	
	//Vamos inicializar implementando a parte da Struct de Clientes
	do{
		//Menu de Opções do Sistema 
		system("cls");
		printf("*** Xing Ling Aula Peças *** ");
		printf("\n [A] Cadastro de Clientes");
		printf("\n [B] Relátorio de Clientes");
		printf("\n [C] Consulta de Clientes");
		printf("\n [D] Alteração de Clientes");
		printf("\n [E] Exclusão de Clientes");
		printf("\n [F] Ordenar pelo Código");
		printf("\n [G] Ordenar pelo Nome");
		printf("\n [H] Ordenar pelo Nome");
		printf("\n [S] Sair");
		printf("\n\n ESCOLHA UMA OPÇÃO:  ");
		op=toupper(getche());
		
		switch(op)
		{
			case 'A':
				//Inserção direta
				system("cls");
				printf("*** Cadastro de Clientes ***\n");
				printf("Informe o código do Cliente(0 p/ finalizar):\n");
				scanf("%d",&auxCod);
				while(tlc<TFC&&auxCod>0)
				{
					c=0;
					for(i=0;i<tlc;i++)
					{
						if(auxCod==vetClientes[i].CodCli)
						{
							c++;
							printf("Cód.existente.");
						}
					}
					if(c==0)
					{
					//validar códigos repetidos depois!!
					vetClientes[tlc].CodCli=auxCod;
					printf("\nNome do Cliente:");
					fflush(stdin);
					gets(vetClientes[tlc].Nome);
					tlc++;
				 	}
					printf("Informe o código do Cliente(0 p/ finalizar):\n");
					scanf("%d",&auxCod);		
				}
				break; 
				
			case 'B':
				system("cls");
				printf("*** Cadastro de Clientes ***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				for(i=0;i<tlc;i++)
				printf("\n%d ° Cod:%d %s",i+1,vetClientes[i].CodCli,vetClientes[i].Nome);

				printf(".");
				getch();
				
				break;
				
			case 'C':
				system("cls");
				printf("*** Consulta de Clientes ***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				{
					char auxNome[30];
					printf("\nNome do Cliente a ser pesquisado:");
					fflush(stdin);
					gets(auxNome);
					c=0;
				for(i=0;i<tlc;i++)
				if(stricmp(auxNome,vetClientes[i].Nome)==0)
				{c=1;
				printf("\n Cod:%d-%s",vetClientes[i].CodCli,vetClientes[i].Nome);
				printf(".");	
				}
				if(!c)
				printf("Não Achou este nome cadastrado...");	
				}
				
				getch();
				
				break;
				
			case 'D':
				system("cls");
				printf("*** Alteração de Clientes ***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				{for(i=0;i<tlc;i++)
				printf("\n%d ° Cod:%d %s",i+1,vetClientes[i].CodCli,vetClientes[i].Nome);
				printf(".\n");
				printf("Informe o código a ser alterado:");
				scanf("%d",&auxCod);
				c=0;
				i=0;
				while(i<tlc&&!c)
				{
					if(vetClientes[i].CodCli==auxCod)
					c=1;
					else
					i++;
				}	
				if(c)
				{
					printf("\nInforme o novo do Cliente :");
					fflush(stdin);
					gets(vetClientes[i].Nome);
					printf("\n%d ° Cod:%d %s",i+1,vetClientes[i].CodCli,vetClientes[i].Nome);		
				}
				else
				printf("Cód.Não existe");
				getch();
				}
				break;
				
			case 'E':
				system("cls");
				printf("*** Exclusão de Clientes ***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				{
					for(i=0;i<tlc;i++)
				{
				printf("\n%d-- Cod:%d-%s",i,vetClientes[i].CodCli,vetClientes[i].Nome);
				printf(".");
				}
				printf("Escolha qual posição deseja excluir\n");
				scanf("%d",&pos);
				for(i=pos;i<tlc;i++)
				vetClientes[i]=vetClientes[i+1];
				system("cls");
				printf("*** Novo Vetor de Clientes ***\n");
				for(i=0;i<tlc-1;i++)
				{
				printf("\nCod:%d-%s",vetClientes[i].CodCli,vetClientes[i].Nome);
				printf(".");
				}
				getch();
				}
				tlc--;
				break;
			case 'S':
				printf("\nSaindo...");
				return(0);
				break;
			case 'F':
				system("cls");
				printf("*** Ordenar pelo Código ***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				{
					for(i=0;i<tlc;i++)
					for(int j=i+1;j<tlc;j++)
				{
					if(vetClientes[i].CodCli>vetClientes[j].CodCli)
					{
					auxCliente=vetClientes[i];	
					vetClientes[i]=vetClientes[j];
					vetClientes[j]=auxCliente;
					}
					}
				printf("*** Vetor já Ordenado pelo Código ***\n");
				for(i=0;i<tlc;i++)
				{
				printf("\n Cod:%d-%s",vetClientes[i].CodCli,vetClientes[i].Nome);
				printf(".");
				}
				}
				getch();
				break;
				case 'G':
					system("cls");
				printf("*** Ordenar pelo Nome ***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				{
					for(i=0;i<tlc;i++)
					for(int j=i+1;j<tlc;j++)
				{
					if(stricmp(vetClientes[i].Nome,vetClientes[j].Nome)>0)
					{
					auxCliente=vetClientes[i];	
					vetClientes[i]=vetClientes[j];
					vetClientes[j]=auxCliente;
					}
					}
				printf("*** Vetor já Ordenado pelo Nome ***\n");
				for(i=0;i<tlc;i++)
				{
				printf("\n Cod:%d-%s",vetClientes[i].CodCli,vetClientes[i].Nome);
				printf(".");
				}
				}
				getch();
				break;
				case 'H' :
					system("cls");
				printf("*** Inverter os Nomes***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				{
										 	for(i=0;i<tlc;i++)
										 	{
											 	tam=strlen(vetClientes[i].Nome)-1;
											 	
										 		for(int j=0;j<strlen(vetClientes[i].Nome)/2;j++)
											 	 {
											  		auxCliente2[i] = vetClientes[i].Nome[j];
											  		vetClientes[i].Nome[j] = vetClientes[i].Nome[tam];
											  		vetClientes[i].Nome[tam]= auxCliente2[i];
											 	 	tam--;
											 	 }
											}
											printf("\n Nomes Invertidos. Retornando ao menu.");
											for(i=0;i<tlc;i++)
				{
				printf("\n Cod:%d-%s",vetClientes[i].CodCli,vetClientes[i].Nome);
				printf(".");
				}
											getch();
										}
					
					break;
					case 'I' :
					system("cls");
				printf("*** Inverter os Nomes***\n");
				if(tlc==0)
				printf("\n Não há Clientes cadastrados...");
				else
				{
										 	for(i=0;i<tlc;i++)
										 	{
											 	tam=strlen(vetClientes[i].Nome)-1;
											 	
										 		for(int j=0;j<strlen(vetClientes[i].Nome);j++)
											 	 {

											  		auxCliente2[i] = vetClientes[i].Nome[j];
											  		vetClientes[i].Nome[j] = vetClientes[i].Nome[tam];
											for(k=0;k<strlen(vetClientes[i].Nome)-1;k++)
											vetClientes[i].Nome[tam] = vetClientes[i].Nome[tam-1];
											  		printf("\n%s--",vetClientes[i].Nome);
											 	 }
											}
											printf("\n Nomes Invertidos. Retornando ao menu.");
											getch();
										}
					
					break;
					
			
		}	
	
	}while(op!='S');	
}

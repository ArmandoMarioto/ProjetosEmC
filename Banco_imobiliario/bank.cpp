#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define TF 15

struct TpJogador
{
	char nome[TF], login[TF], senha[TF];
	int cod, cor, x,y, potTab, status;
	float dinheiro;
	
};

int resetastatus(FILE *arq);// RESTA O STATUS DE LOGADO
int buscasenha(FILE *arq, char chave[], char nome[]);//AUTENTICADOR DE SENHA NA HORA DE LOGAR 
void logar(FILE *arq); //TELA DE LOGIN/ AUTENTICAÇÂO
int busca(FILE *arq, char chave[]);//BUSCA NO ARQUIVO
void cadastro(FILE *arq);//CADASTRO DE JOGADOR
void letras(void);//LETREIRO DO MENU PRINCIPAL
void menuquadro(void);//QUADRO DO MENU PRINCIPAL
void menuprincipal(void);//MENU PRINCIPAL
void gameover(void);//FIM DE JOGO

/*int resetastatus(FILE *arq)// RESTA O STATUS DE LOGADO
{
	fseek(arq, 0, 2);
	return (ftell(arq)/sizeof(TpJogador));
}*/

void logar(FILE *arq) //TELA DE LOGIN/ AUTENTICAÇÂO
{
	system("title LOGAR");
	menuquadro();//CHAMA QUADRO DO MENU PRINCIPAL
	TpJogador jog, log[4];
	if(!(arq = fopen("jogador.dat", "rb+")))
	{
		FILE *f = fopen("jogador.dat", "w");	
		fclose(f);
		arq = fopen("jogador.dat", "rb+");
	}
	
	int i, j, resp, p, flag=0, r, cad=0;
	char aux[TF],nome[30];
	
	//VE QUANTOS PODEM LOGAR
	cad = 0;
	fseek(arq, 0, 0);
	fread(&jog, sizeof(TpJogador), 1, arq);
	while(!feof(arq))
	{
		cad++;
		fread(&jog, sizeof(TpJogador), 1, arq);
	}

	if(arq == NULL)
	{
		textcolor(4);
		gotoxy(26, 5);printf("CADASTRE - SE !!!");
		gotoxy(25, 4);printf("%c", 201);
		gotoxy(25,6);printf("%c", 200);
		gotoxy(55, 4);printf("%c", 187);
		gotoxy(55, 6);printf("%c", 188);
		
		for(i=26; i<55; i++)
		{
			gotoxy(i, 4);printf("%c", 205);
			gotoxy(i, 6);printf("%c", 205);
		}
		
		for(i=5; i<6; i++)
		{
			gotoxy(25, i);printf("%c", 186);
			gotoxy(55, i);printf("%c", 186);
		}
		getch();
		textcolor(15);
	}
	else
	{
		gotoxy(43,5);printf("                        ");
		gotoxy(26, 5);printf("Jogadores[2 a 4]:  ");
		gotoxy(25, 4);printf("%c", 201);
		gotoxy(25,6);printf("%c", 200);
		gotoxy(55, 4);printf("%c", 187);
		gotoxy(55, 6);printf("%c", 188);
		
		for(i=26; i<55; i++)
		{
			gotoxy(i, 4);printf("%c", 205);
			gotoxy(i, 6);printf("%c", 205);
		}
		
		for(i=5; i<6; i++)
		{
			gotoxy(25, i);printf("%c", 186);
			gotoxy(55, i);printf("%c", 186);
		}
		gotoxy(43,5);scanf("%d", &resp);
		
		if(resp <= 1 || resp >= 4 || resp > cad) //VERIFICANDO NUMERO DE JOGADORES VALIDOS
		{
			textcolor(4);
			gotoxy(26, 5);printf("QUANTIDADE INVALIDA !!!");
			gotoxy(25, 4);printf("%c", 201);
			gotoxy(25,6);printf("%c", 200);
			gotoxy(55, 4);printf("%c", 187);
			gotoxy(55, 6);printf("%c", 188);
			
			for(i=26; i<55; i++)
			{
				gotoxy(i, 4);printf("%c", 205);
				gotoxy(i, 6);printf("%c", 205);
			}
			
			for(i=5; i<6; i++)
			{
				gotoxy(25, i);printf("%c", 186);
				gotoxy(55, i);printf("%c", 186);
			}
			getch();
			textcolor(15);
		}
		else //NUMERO DE JOGADORES VALIDOS
		{
			for(j=0; j<resp; j++) //LOGANDO OS JOGADORES
			{
			
				flag = 1;
				do
				{
					system("cls");
					menuquadro();
					gotoxy(36,9);printf("               ");
					gotoxy(26, 9);printf("Jogador %d: ", j+1);
					gotoxy(25, 8);printf("%c", 201);
					gotoxy(25,10);printf("%c", 200);
					gotoxy(55, 8);printf("%c", 187);
					gotoxy(55, 10);printf("%c", 188);
					
					for(i=26; i<55; i++)
					{
						gotoxy(i, 8);printf("%c", 205);
						gotoxy(i, 10);printf("%c", 205);
					}
					
					for(i=9; i<10; i++)
					{
						gotoxy(25, i);printf("%c", 186);
						gotoxy(55, i);printf("%c", 186);
					}
					fflush(stdin);
					gotoxy(36,9);gets(aux);
					//strcpy(nome,aux);
					
					p = busca(arq, aux); //BUSCA LOGIN JA CADASTRADO
					
					if(p == -1 || strcmp(aux,"\0") == 0 || strcmp(aux, " ") == 0)
					{
						textcolor(4);
						gotoxy(26, 9);printf("Jogador %d:INVALIDO !!!", j+1);
						gotoxy(25, 8);printf("%c", 201);
						gotoxy(25,10);printf("%c", 200);
						gotoxy(55, 8);printf("%c", 187);
						gotoxy(55, 10);printf("%c", 188);
						
						for(i=26; i<55; i++)
						{
							gotoxy(i, 8);printf("%c", 205);
							gotoxy(i, 10);printf("%c", 205);
						}
						
						for(i=9; i<10; i++)
						{
							gotoxy(25, i);printf("%c", 186);
							gotoxy(55, i);printf("%c", 186);
						}
						flag = 1;
						getch();
						textcolor(15);
					}
					else
					{
						flag = 1;
						//do
						//{
						if(strcmp(log.nome, aux) == 0 && log.status == 1)
						{
						
							gotoxy(32,13);printf("             ");
							gotoxy(26, 13);printf("Senha: ");
							gotoxy(25, 12);printf("%c", 201);
							gotoxy(25,14);printf("%c", 200);
							gotoxy(55, 12);printf("%c", 187);
							gotoxy(55, 14);printf("%c", 188);
							
							for(i=26; i<55; i++)
							{
								gotoxy(i, 12);printf("%c", 205);
								gotoxy(i, 14);printf("%c", 205);
							}
							
							for(i=13; i<14; i++)
							{
								gotoxy(25, i);printf("%c", 186);
								gotoxy(55, i);printf("%c", 186);
							}
							fflush(stdin);
							gotoxy(32,13);gets(aux);
							
							r = buscasenha(arq, aux,nome);
							
							if(r == 1)
							{
								/*log.status = 0;
								strpy(log.nome, jog.nome);*/
								textcolor(2);
								gotoxy(26, 16);printf("LOGADO !!!");
								flag = 0;
								getch();
								textcolor(15);
							}
							else
							{
								textcolor(4);
								gotoxy(26, 13);printf("Senha:INVALIDA !!!");
								gotoxy(25, 12);printf("%c", 201);
								gotoxy(25,14);printf("%c", 200);
								gotoxy(55, 12);printf("%c", 187);
								gotoxy(55, 14);printf("%c", 188);
								
								for(i=26; i<55; i++)
								{
									gotoxy(i, 12);printf("%c", 205);		
									gotoxy(i, 14);printf("%c", 205);
								}
									
								for(i=13; i<14; i++)
								{
									gotoxy(25, i);printf("%c", 186);
									gotoxy(55, i);printf("%c", 186);
								}
								flag = 1;
								textcolor(4);
								gotoxy(26, 16);printf("OU USUSARIO JA LOGADO !!!!");
								getch();
								textcolor(15);
							}
						}
					//}while(flag == 1);
						
						//flag = 0;	
					}
								
				}while(flag == 1);	
					
			}
			
		}	
	}
	fclose(arq);
}

int busca(FILE *arq, char chave[])//BUSCA NO ARQUIVO
{
	TpJogador aux;
	
	fseek(arq, 0, 0);
	fread(&aux, sizeof(TpJogador), 1, arq);
	
	while(!feof(arq) && strcmp(aux.login, chave)!=0)
		fread(&aux, sizeof(TpJogador), 1, arq);
	
	if(strcmp(aux.login, chave) == 0)
		return ftell(arq) - sizeof(TpJogador);
	else
		return -1;
}

int buscasenha(FILE *arq, char chave[],char nome[]) //AUTENTICADOR DE SENHA NA HORA DE LOGAR 
{
	TpJogador aux;
	
	int i;
	
	fseek(arq, 0, 0);
	fread(&aux, sizeof(TpJogador), 1, arq);
	
	while(!feof(arq) && strcmp(nome, aux.login) != 0)
		fread(&aux, sizeof(TpJogador), 1, arq);
		
	i = ftell(arq) - sizeof(TpJogador);
	
	if(strcmp(aux.senha, chave) == 0 && strcmp(nome, aux.nome) == 0 && aux.status == 1 )
	{
		fseek(arq, i, 0);
		aux.status = 0;
		fwrite(&aux, sizeof(TpJogador), 1, arq);
		return 1;
	}
		
	else
		return -1;		
}

void cadastro(FILE *arq)//CADASTRO DE JOGADOR
{
	menuquadro();//CHAMA QUADRO DO MENU PRINCIPAL
	TpJogador jog;
	arq = fopen("jogador.dat", "ab+");
	
	int p, flag=0, i;
	char aux[TF];
	
	system("title CADASTRO");
	gotoxy(8, 5);printf("Nome de usuario: ");
	gotoxy(7, 4);printf("%c", 201);
	gotoxy(7,6);printf("%c", 200);
	gotoxy(60, 4);printf("%c", 187);
	gotoxy(60, 6);printf("%c", 188);
	
	for(i=8; i<60; i++)
	{
		gotoxy(i, 4);printf("%c", 205);
		gotoxy(i, 6);printf("%c", 205);
	}
	
	for(i=5; i<6; i++)
	{
		gotoxy(7, i);printf("%c", 186);
		gotoxy(60, i);printf("%c", 186);
	}
	fflush(stdin);
	gotoxy(24, 5);gets(jog.nome);
	
	if(strcmp(jog.nome, "\0")!=0 && strcmp(jog.nome, " ")!=0)//NOME EM BRANCO
	{	
		do
		{
		
			flag = 0;
			
			do //ENQUANTO NÂO DIGITAR UM LOGIN VALIDO
			{
				gotoxy(22, 9);printf("             ");
				gotoxy(8, 9);printf("Nome de login: ");
				gotoxy(7, 8);printf("%c", 201);
				gotoxy(7,10);printf("%c", 200);
				gotoxy(60, 8);printf("%c", 187);
				gotoxy(60, 10);printf("%c", 188);
				
				for(i=8; i<60; i++)
				{
					gotoxy(i, 8);printf("%c", 205);
					gotoxy(i, 10);printf("%c", 205);
				}
				
				for(i=9; i<10; i++)
				{
					gotoxy(7, i);printf("%c", 186);
					gotoxy(60, i);printf("%c", 186);
				}
				fflush(stdin);
				gotoxy(22, 9);gets(jog.login);
				
				if(strcmp(jog.login, "\0")!=0 && strcmp(jog.login, " ")!=0)
					flag = 1;
				else
				{
					textcolor(4);
					gotoxy(8, 9);printf("Nome de login:INVALIDO !!!");
					gotoxy(7, 8);printf("%c", 201);
					gotoxy(7,10);printf("%c", 200);
					gotoxy(60, 8);printf("%c", 187);
					gotoxy(60, 10);printf("%c", 188);
					
					for(i=8; i<60; i++)
					{
						gotoxy(i, 8);printf("%c", 205);
						gotoxy(i, 10);printf("%c", 205);
					}
					
					for(i=9; i<10; i++)
					{
						gotoxy(7, i);printf("%c", 186);
						gotoxy(60, i);printf("%c", 186);
					}
					getch();
					textcolor(15);
					flag = 0;
				}
					
			}while(flag == 0);
			
			p = busca(arq, jog.login); //VALIDA NOME
			
			if(p != -1)//LOGIN JA EXISTENTE
			{
				textcolor(4);
				gotoxy(8, 9);printf("Nome de login:INVALIDO !!!");
				gotoxy(7, 8);printf("%c", 201);
				gotoxy(7,10);printf("%c", 200);
				gotoxy(60, 8);printf("%c", 187);
				gotoxy(60, 10);printf("%c", 188);
				
				for(i=8; i<60; i++)
				{
					gotoxy(i, 8);printf("%c", 205);
					gotoxy(i, 10);printf("%c", 205);
				}
				
				for(i=9; i<10; i++)
				{
					gotoxy(7, i);printf("%c", 186);
					gotoxy(60, i);printf("%c", 186);
				}
				getch();
				textcolor(15);
			}	
			else //LOGIN APROVADO
			{	
				flag=0;
				do //ENQUANTO NÂO DIGITAR UMA SENHA VALIDA
				{
					gotoxy(14, 13);printf("             ");
					gotoxy(8, 13);printf("Senha: ");
					gotoxy(7, 12);printf("%c", 201);
					gotoxy(7,14);printf("%c", 200);
					gotoxy(60, 12);printf("%c", 187);
					gotoxy(60, 14);printf("%c", 188);
					
					for(i=8; i<60; i++)
					{
						gotoxy(i, 12);printf("%c", 205);
						gotoxy(i, 14);printf("%c", 205);
					}
					
					for(i=13; i<14; i++)
					{
						gotoxy(7, i);printf("%c", 186);
						gotoxy(60, i);printf("%c", 186);
					}
					fflush(stdin);
					gotoxy(14, 13);gets(jog.senha);
					
					if(strcmp(jog.senha, "\0")!=0 && strcmp(jog.senha, " ")!=0)// VERIFICANDO SENHA 
					{
						gotoxy(8, 17);printf("                        ");
						gotoxy(8, 17);printf("Reedigite senha: ");
						gotoxy(7, 16);printf("%c", 201);
						gotoxy(7,18);printf("%c", 200);
						gotoxy(60, 16);printf("%c", 187);
						gotoxy(60, 18);printf("%c", 188);
						
						for(i=8; i<60; i++)
						{
							gotoxy(i, 16);printf("%c", 205);
							gotoxy(i, 18);printf("%c", 205);
						}
						
						for(i=17; i<18; i++)
						{
							gotoxy(7, i);printf("%c", 186);
							gotoxy(60, i);printf("%c", 186);
						}
						fflush(stdin);
						gotoxy(24, 17);gets(aux);
						
						if(strcmp(jog.senha, aux) == 0) // VERIFICANDO SE AS SENHAS SÂO IGUAIS
						{
							flag=1; 
							//jog.status = 1; //JOGADOR ATIVO
							fwrite(&jog, sizeof(TpJogador), 1, arq);
							
							textcolor(2);
							gotoxy(8, 20);printf("CADASTRO FEITO COM SUCESSO !!!");
							textcolor(15);
							getch();
						}
						else // CONFIMAÇÂO DE SENHA INVALIDA
						{
							flag = 0;
							textcolor(4);
							gotoxy(8, 17);printf("SENHAS DIFERENTES !!!!");
							gotoxy(7, 16);printf("%c", 201);
							gotoxy(7,18);printf("%c", 200);
							gotoxy(60, 16);printf("%c", 187);
							gotoxy(60, 18);printf("%c", 188);
							
							for(i=8; i<60; i++)
							{
								gotoxy(i, 16);printf("%c", 205);
								gotoxy(i, 18);printf("%c", 205);
							}
							
							for(i=17; i<18; i++)
							{
								gotoxy(7, i);printf("%c", 186);
								gotoxy(60, i);printf("%c", 186);
							}
							getch();
							textcolor(15);
						}
						
					}
					else //SENHA INVALIDA
					{
						textcolor(4);
						gotoxy(8, 13);printf("Senha:INVALIDA !!! ");
						gotoxy(7, 12);printf("%c", 201);
						gotoxy(7,14);printf("%c", 200);
						gotoxy(60, 12);printf("%c", 187);
						gotoxy(60, 14);printf("%c", 188);
						
						for(i=8; i<60; i++)
						{
							gotoxy(i, 12);printf("%c", 205);
							gotoxy(i, 14);printf("%c", 205);
						}
						
						for(i=13; i<14; i++)
						{
							gotoxy(7, i);printf("%c", 186);
							gotoxy(60, i);printf("%c", 186);
						}
						getch();
						textcolor(15);
					}
					
				}while(flag==0);
			}
		
		}while(p != -1);
	}
	else // USUARIO INVALIDO
	{
		textcolor(4);
		gotoxy(8, 5);printf("Nome de usuario: INVALIDO !!! ");
		gotoxy(7, 4);printf("%c", 201);
		gotoxy(7,6);printf("%c", 200);
		gotoxy(60, 4);printf("%c", 187);
		gotoxy(60, 6);printf("%c", 188);
		
		for(i=8; i<60; i++)
		{
			gotoxy(i, 4);printf("%c", 205);
			gotoxy(i, 6);printf("%c", 205);
		}
		
		for(i=5; i<6; i++)
		{
			gotoxy(7, i);printf("%c", 186);
			gotoxy(60, i);printf("%c", 186);
		}
		fflush(stdin);
		textcolor(15);
		getch();
	}
	fclose(arq);
	
}

void letras(void)//LETREIRO DO MENU PRINCIPAL
{
	int i, j;
	
	//B
	for(i=10; i<20; i++)
	{
		gotoxy(i, 3);printf("%c",178);
		gotoxy(i, 4);printf("%c",178);
		gotoxy(i, 15);printf("%c",178);
		gotoxy(i, 16);printf("%c",178);
		gotoxy(i, 9);printf("%c",178);
		gotoxy(i, 10);printf("%c",178);	
	}
	
	for(i=4; i<15; i++)
	{
			gotoxy(10, i);printf("%c",178);
			gotoxy(11, i);printf("%c",178);
	}
	
	gotoxy(20,4);printf("%c%c",178,178);
	gotoxy(20,5);printf("%c%c%c", 178, 178,178);
	gotoxy(20,6);printf("%c%c%c",178,178,178);
	gotoxy(20,7);printf("%c%c%c",178,178,178);
	gotoxy(20,8);printf("%c%c",178,178);
	gotoxy(20,9);printf("%c%c",178,178);
 	gotoxy(20,10);printf("%c%c",178,178);
	gotoxy(20,11);printf("%c%c%c",178,178,178);
	gotoxy(20,12);printf("%c%c%c",178,178,178);
	gotoxy(20,13);printf("%c%c%c",178,178,178);
	gotoxy(20,14);printf("%c%c",178,178);
	gotoxy(20,15);printf("%c%c",178,178);
	
	//A
	for(i=28; i<38; i++)
	{
		gotoxy(i, 3);printf("%c",178);
		gotoxy(i, 4);printf("%c",178);
		gotoxy(i, 9);printf("%c",178);
		gotoxy(i, 10);printf("%c",178);
	}
	
	for(i=3; i<17; i++)
	{
			gotoxy(27, i);printf("%c",178);
			gotoxy(28, i);printf("%c",178);
			gotoxy(38, i);printf("%c",178);
			gotoxy(39, i);printf("%c",178);
	}
	
	//N
	for(i=3; i<17; i++)
	{
			gotoxy(44, i);printf("%c",178);
			gotoxy(45, i);printf("%c",178);
			gotoxy(54, i);printf("%c",178);
			gotoxy(55, i);printf("%c",178);	
	}
	
	for(i=44, j=3; i<54, j<15; i++, j++)
	{
		gotoxy(i, j);printf("%c",178);
		gotoxy(i, j+1);printf("%c",178);
		gotoxy(i, j+2);printf("%c",178);
	}
	
	//K
	for(i=3; i<17; i++)
	{
		gotoxy(60, i);printf("%c",178);
		gotoxy(61, i);printf("%c",178);
	}
	for(i=60, j=6; i<70, j<16; i++, j++)
	{
		gotoxy(i, j);printf("%c",178);
		gotoxy(i, j+1);printf("%c",178);
		gotoxy(i, j+2);printf("%c",178);	
	}
	
	for(i=68, j=3; i>60, j<11; i--, j++)
	{
		gotoxy(i, j);printf("%c",178);
		gotoxy(i, j+1);printf("%c",178);
		gotoxy(i, j+2);printf("%c",178);	
	}	
}
void menuquadro(void) //QUADRO DO MENU PRINCIPAL
{
	int i;
	
	gotoxy(1, 1);printf("%c", 201); //CANTO SUPERIOR ESQUERDO
	gotoxy(2, 2);printf("%c", 201);
	
	gotoxy(1, 25);printf("%c", 200); //CANTO INFERIOR ESQUERDO
	gotoxy(2, 24);printf("%c", 200);
	
	gotoxy(79, 1);printf("%c", 187); //CANTO SUPERIO DIREITO
	gotoxy(78, 2);printf("%c", 187);
	
	gotoxy(78, 24);printf("%c", 188); //CANTO INFERIOR DIREITO
	gotoxy(79, 25);printf("%c", 188);
	
	//TRAÇO HORIZONTAL
	for(i=2; i<79; i++)
	{
		gotoxy(i, 1);printf("%c", 205);
		gotoxy(i, 25);printf("%c", 205);
	}
	
	//TRAÇO VERTICAL
	for(i=3; i<24; i++)
	{
		gotoxy(2, i);printf("%c", 186);
		gotoxy(78, i);printf("%c", 186);
	}
	
}

void gameover(void) // FIM DE JOGO
{
	    system("cls");
	    menuquadro();
    	gotoxy(25,4);printf("xxxxxx xxxxxx xxx  xxx xxxxxx");
    	gotoxy(25,5);printf("xx     xx  xx xxxxxxxx xx    ");
    	gotoxy(25,6);printf("xx xxx xxxxxx xx xx xx xxxxxx");
    	gotoxy(25,7);printf("xx  xx xx  xx xx xx xx xx    ");
    	gotoxy(25,8);printf("xxxxxx xx  xx xx xx xx xxxxxx");
    	
		gotoxy(25,10);printf("xxxxxx xx  xx xxxxxx xxxxxx ");
    	gotoxy(25,11);printf("xxxxxx xx  xx xx     xx  xx ");
    	gotoxy(25,12);printf("xx  xx xx  xx xxxxxx xxxxxx ");
    	gotoxy(25,13);printf("xxxxxx  x  x  xx     xx  xxx");
    	gotoxy(25,14);printf("xxxxxx   xx   xxxxxx xx   xxx");
		getch();
}

void menuprincipal(void)//MENU PRINCIPAL
{
	FILE *p;
	TpJogador jog;

	char resp, tecla;
	int a=20, r;
	
	/*DESLOGAR TODOS OS USUARIOS
	p = fopen("jogdor.dat", "rb+");
		
	r =  resetastatus(p);
	for(int i=0; i<r; i++)
	{
		fseek(p, 0, i*sizeof(TpJogador));
		fread(&jog, sizeof(TpJogador), 1, p);
		jog.status=1;
		fseek(p, 0, i*sizeof(TpJogador));
		fwrite(&jog, sizeof(TpJogador), 1, p);		
	}
	fclose(p);*/
	
	do
	{
		system("color 18");
		menuquadro();//QUADRO DO MENU PRINCIPAL
		letras();//LETREIRO
		
		gotoxy(35, 20); printf("LOGAR   [ ]");
		gotoxy(35, 21); printf("CADASTRO[ ]");
		gotoxy(35, 22); printf("SAIR    [ ]");
		gotoxy(44, a); printf("%c",36);
		fflush(stdin);
		tecla = toupper(getch());
		
		switch(tecla)
		{
			case 72:
				if(a != 20)
				{
					gotoxy(44,a); printf(" "); // APAGA $
					a--;
				}
				break;
				
			case 80:
				if(a != 22)
				{
					gotoxy(44,a); printf(" "); //APAGA $
					a++;
				}		
				break;		 
		}
		
		if(tecla == 13 && a == 20) //ENTRA NO JOGO
		{
			system("cls");
			system("color 0F");
			logar(p); //AUTENTICAÇÂO DOS JOGADORES
			system("cls");
		}

		if(tecla == 13 && a == 21) //ENTRA NO CADASTRO
		{
			system("cls");
			system("color 0F");
			cadastro(p);
			system("cls");
		}
			
		if(tecla == 13 && a == 22) // SAI DO MENU
		{
			system("cls");
			system("color 04");
			menuquadro();
			gameover();
			tecla = 27;
		}
				

	}while(tecla != 27);
  	//system("color 0F");
}

int main(void)
{
	system("title BANCO IMOBILIARIO");
	menuprincipal();//MENU PRINCIPAL
}

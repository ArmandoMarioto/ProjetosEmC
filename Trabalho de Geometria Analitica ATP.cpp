#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define TV 3
//#include<.h>
//#include<.h>
void func_executa(void);
char menu_main(void);
char menu_rp(void);
void func_posrelativa(char a);
int func_pontonareta(float pb[3], float a[3], float pa[3]);
void func_levetoreponto(float a[3], float pa[3], float b[3], float pb[3]);
void main_posrelativa_rr(float a[3], float pa[3], float b[3], float pb[3]);
int func_dl(float v[TV], float v1[TV]);
float func_lamb(float pb, float a, float pa, int &ver);
void func_vetab(float pa[3], float pb[3], float ab[3]);
float func_ProdMisto(float a[3], float b[3], float ab[3]);
float func_ProdEScalar(float a[3], float b[4]);
void func_levet(float v[3], float pv[3]);
void func_leplan(float N[4]);
int func_pontonaEqGeral(float a[3], float b[4]);
void main_posrelativa_rp(float v[3], float pv[3], float N[4]);
void main_posrelativa_pp(float N1[4], float N2[4]);
int func_LDouLIplan(float N1[4], float N2[4]);


void func_distancia()
{	int op;
	if(o2==1)
	{
	float v1[3], p1[3], v2[3], p2[3];
	func_levetoreponto(v1, p1, v2, p2);
	op=main_posrelativa_rr(v1, p1, v2, p2);
	switch(op)
	{
		case 1:
			break;
		case 2:
			printf("\nAs retas são concorrentes, portanto não há distancia entre elas.");
			break;
		case 3:
			break;
	}
	}
	if(o2==2)
	{
		
	}
	if(o2==3)
	{
		
	}else
	printf("Opção invalida.");00 ,   ,0                                 
	
}
void func_levetoreponto(float a[3], float pa[3], float b[3], float pb[3])
{
	int i;
	system("cls");
	printf("\tInsira as Coordenadas do 1ªVetor\n\n");
	for(i=0; i<3; i++)
	{
		printf("Insira a %dªCordenada do Vetor: ", i+1);
		scanf("%float", &a[i]);
	}
	system("cls");
	printf("\tInsira as Coordenadas do Ponto\n\n");
	for(i=0; i<3; i++)
	{
		printf("Insira a %dªCordenada do Ponto: ", i+1);
		scanf("%f", &pa[i]);
	}
	system("cls");
	printf("\tInsira as Coordenadas do 2ªVetor\n\n");
	for(i=0; i<3; i++)
	{
		printf("Insira a %dªCordenada do Vetor: ", i+1);
		scanf("%f", &b[i]);
	}
	system("cls");
	printf("\tInsira as Coordenadas do Ponto\n\n");
	for(i=0; i<3; i++)
	{
		printf("Insira a %dªCordenada do Ponto: ", i+1);
		scanf("%f", &pb[i]);
	}
}
float func_lamb(float pb, float a, float pa, int &ver)
{
	float lambida;
	if(a==0)
	{
		if(pa==pb)
			lambida=pa;
		else
			ver=1;
	}
	else
		lambida=(pb-pa)/a;
	return lambida;
}
int func_pontonareta(float pb[3], float a[3], float pa[3])
{
	float lambx, lamby, lambz;
	int ver=0;
	lambx=func_lamb(pb[0], a[0], pa[0], ver);
	lamby=func_lamb(pb[1], a[1], pa[1], ver);
	lambz=func_lamb(pb[2], a[2], pa[2], ver);
	if(lambx==lamby&&lambx==lambz&&ver==0)
		return 1;
	else
		return 0;
}
int func_dl(float v[3], float v1[3])
{
	float v3[3], aux;
	int veri=0;
	if(v1[0]!=0&&v[0]!=0)
	{
		aux=v[0]/v1[0];
		veri=1;
	}
	else if(v1[1]!=0&&v[1]!=0)
	{
		aux=v[1]/v1[1];
		veri=1;
	}
		
	else if(v1[2]!=0&&v[2]!=0)
	{
		aux=v[2]/v1[2];
		veri=1;
	}
	v3[0]=aux*v1[0];
	v3[1]=aux*v1[1];
	v3[2]=aux*v1[2];
	if( v3[0]==v[0] && v3[1]==v[1] && v3[2]==v[2] && veri==1)
	{
		printf("\n\nÉ LD\n\n");
		return 1;
	}
	else
	{
		printf("\n\nÉ LI\n\n");
		return 0;
	}
}
float func_ProdMisto(float a[3], float b[3], float ab[3])
{
	float mis=0;
	mis+=(a[0]*b[1]*ab[2]);
	mis+=(a[1]*b[2]*ab[0]);
	mis+=(a[2]*b[0]*ab[1]);
	mis+=((ab[0]*b[1]*a[2])*(-1));
	mis+=((ab[1]*b[2]*a[0])*(-1));
	mis+=((ab[2]*b[0]*a[1])*(-1));
	return mis;
}
void func_vetab(float pa[3], float pb[3], float ab[3])
{
	ab[0]=pb[0]-pa[0];
	ab[1]=pb[1]-pa[1];
	ab[2]=pb[2]-pa[2];
}
int main_posrelativa_rr(float a[3], float pa[3], float b[3], float pb[3])
{
	system("cls");
	float ab[3];
	if (func_dl(a, b) == 1)
	{
		if(func_pontonareta(pb, a, pa)==1)
			printf("As Retas R e S São Iguais!!!\n\n");
		else
			printf("As Retas R e S São Paralelas!!!\n\n");
			return 1;
	}
	else
	{
		func_vetab(pa,pb, ab);
		if(func_ProdMisto(a, b, ab)==0)
		{
			printf("As Retas R e S São Concorrentes!!!\n\n");
			return 2;
		}
		else{
			printf("As Retas R e S São Reversas!!!\n\n");
			return 3;
		}
			
			
	}
	system("pause");
}
void func_levet(float v[3], float pv[3])
{
	int i;
	system("cls");
	printf("\tInsira os Valores do Vetor Diretor da Reta: \n\n");
	for(i=0; i<3;i++)
	{
		printf("Insira %dªComponente do Vetor: ", i+1);
		scanf("%f",&v[i]);
	}
	system("cls");
	printf("\tInsira os Valores do Ponto da Reta: \n\n");
	for(i=0; i<3;i++)
	{
		printf("Insira %dªComponente do Ponto: ", i+1);
		scanf("%f",&pv[i]);
	}
	system("cls");
}
void func_leplan(float N[4])
{
	int i;
	printf("\tInsira o Vetor Normal: \n\n");
	for(i=0;i<3;i++)
	{
		printf("Insira a %dªCoordenada do Vetor: ", i+1);
		scanf("%f",&N[i]);
	}
	printf("\n\nInsira o Delta da Equação Geral Deste Plano: ");
	scanf("%f",&N[3]);
	system("cls");
}
float func_ProdEScalar(float a[3], float b[4])
{
	float pr;
	pr=(a[0]*b[0]+ a[1]*b[1]+ a[2]*b[2]);
	return pr;
}
int func_pontonaEqGeral(float a[3], float b[4])
{
	int ver;
	ver= a[0]*b[0]+a[1]*b[1]+a[2]*b[2]+b[4];
	if(ver==0)
		return 1;
	else
		return 0;
}
void main_posrelativa_rp(float v[3], float pv[3], float N[4])
{
	if(func_ProdEScalar(v, N)!=0)
		printf("A reta é Transversal ao Plano\n\n");
	else
		if(func_pontonaEqGeral(pv, N)==1)
			printf("A Reta Esta Contida no Plano\n\n");
		else
			printf("A reta é Paralela ao Plano\n\n");
	system("pause");
	system("cls");
}
float divisao(float a, float b)
{
	float r;
	r=a/b;
	return r;
}
int func_LDouLIplan(float N1[4], float N2[4])
{
	float v3[4];
	v3[0]=divisao(N1[0], N2[0]);
	v3[1]=divisao(N1[1], N2[1]);
	v3[2]=divisao(N1[2], N2[2]);
	v3[3]=divisao(N1[3], N2[3]);
	if(v3[0]==v3[1]&&v3[1]==v3[2]&&v3[2]==v3[3])
		return 1;
	else if(v3[0]==v3[1]&&v3[1]==v3[2]&&v3[2]!=v3[3])
		return 2;
	else if(v3[0]!=v3[1] || v3[1]!=v3[2] || v3[2]!=v3[1])
		return 0;
}
void main_posrelativa_pp(float N1[4], float N2[4])
{
	float v3[4];
	int d;
	d=func_LDouLIplan(N1, N2);
	if(d==1)
		printf("O 1ªPlano é Igual ao 2ªPlano\n\n");
	if(d==2)
		printf("O 1ªPlano é Paralelo ao 2ªPlano\n\n");
	if(d==0)
		printf("O 1ªPlano é Transversal ao 2ªPlano\n\n");
	system("pause");
	system("cls");
}
void func_posrelativa(char a)
{
	if(a=='1')
	{
		float v1[3], p1[3], v2[3], p2[3];
		func_levetoreponto(v1, p1, v2, p2);
		main_posrelativa_rr(v1, p1, v2, p2);//posição relativa entre retas
	}
	if(a=='2')
	{
		float v[3], pv[3], N[4];
		func_levet(v, pv);
		func_leplan(N);
		main_posrelativa_rp(v, pv, N);
	}
	if(a=='3')
	{
		float N1[4], N2[4];
		system("cls");
		printf("\t\t1ªPlano\n\n");
		func_leplan(N1);
		printf("\t\t2ªPlano\n\n");
		func_leplan(N2);
		main_posrelativa_pp(N1, N2);
	}
}
char menu_main(void)
{
	char o;
	system("cls");
	printf("\tPressione o número da Opção Escolhida\n\n");
	printf("[1] - Posição Relativa\n");
	printf("[2] - Ângulo\n");
	printf("[3] - Distância\n");
	printf("[ESC] - Sair\n");
	o=getch();
	return o;
}
char menu_rp(void)
{
	char o;
	system("cls");
	printf("\tPressione o número da Opção Escolhida\n\n");
	printf("[1] - Entre 2 Retas\n");
	printf("[2] - Entre 1 Reta e 1 Plano\n");
	printf("[3] - Entre 2 Planos");
	o=getch();
	return o;
}
void func_executa(void)
{
	char o, o2,o4;
	float v1[3], v2[3];
	do
	{
		o=menu_main();
		switch(o)
		{
			case'1':
				o2=menu_rp();
				func_posrelativa(o2);
			break;
			case'2':
				
			break;
			case'3':
				o2=menu_rp();
				func_distancia(o2);
			break;		
		}
	}while(o!=27);
	
}
int main()
{
	setlocale(LC_ALL,"portuguese");
	func_executa();
}

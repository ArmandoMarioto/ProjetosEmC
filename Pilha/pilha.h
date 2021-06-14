void cadpilha( int a[], int &pos);
void conc(int a[], int b[], int aux[], int &po1, int po2, int &po3);
int menu(void)
{
	int a;
	system("cls");
    printf("[1]- Cadastrar pilha 1\n");
    printf("[2]- Cadastrar pilha 2\n");
    printf("[3]- Concatenar pilhas\n");
    printf("[4]- Exibir\n");
    printf("[0]- SAIR\n");
    scanf("%d", &a);
    system("cls");
    return a;
}
void cadpilha( int a[], int &pos)
{
    pos++;
    printf("Digite o número: ");
    scanf("%d", &a[pos]);


}


void conc(int a[], int b[], int aux[], int &po1, int po2)
{
    int i, k;
    k=po2;
    printf("k=%d    pos2=%d    pos1=%d", k, po2, po1);
    getch();
    for(i=0; i<k; i++)
    {
        aux[i] =b[po2];

    }
    for(k=0; k>i; i--)
    {
        po1++;
        a[po1]=aux[i];
        printf("\n%d ", a[po1]);
        getch();
    }
}
void exibe(int a[], int po)
{
    for(int i=po; i>0; i--)
    {
        printf("\n| %d |", a[i]);
    }
}

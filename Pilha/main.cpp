#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include "pilha.h"


int main()
{
    setlocale(LC_ALL,"portuguese");
    int p1[9], p2[9], aux[9], pon1=-1, pon2=-1, pon3=-1;
    int op;
    do
    {
        op=menu();
        switch(op)
        {
            case 1:
                cadpilha( p1, pon1);
            break;
            case 2:
                cadpilha( p2, pon2);
            break;
            case 3:
                conc(p1, p2, aux, pon1, pon2, pon3);
            break;
            case 4:
                exibe(p1, pon1);
                getch();
            break;
            case 0:
                printf("Saindo...\n\n");
                system("pause");
                system("cls");
            break;
            default:
                printf("Opção Inválida...\n\n");
                system("pause");
                system("cls");
            break;
        }
    }while(op!=0);


}

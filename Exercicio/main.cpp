#include <iostream>
#include<stdio.h>

struct TpVendas
{
    int cod,mes;
    float valor;
    char nome[30];

};

void ExportaVendas(FILE *ArqBin,FILE *ArqTxt)
{
    TpVendas RegV;
    ArqBin=fopen("Vendas.dat","rb");
    ArqTxt=fopen("Vendas.txt","w");

    fread(&RegV,sizeof(TpVendas),1,ArqBin);
    while(!feof(ArqBin))
    {
        fprintf(ArqTxt,"%d\t%d\t%.2f\t%s\n",RegV.cod,RegV.mes,RegV.valor,RegV.nome);
        fread(&RegV,sizeof(TpVendas),1,ArqBin);
    }
    fclose(ArqBin);
    fclose(ArqTxt);
    printf("\n Arquivo texto gerado!!!\n");
}

void Exibe(FILE *ArqTxt)
{
    TpVendas RegV;
    float soma=0;
    ArqTxt=fopen("Vendas.txt","r");
    fscanf(ArqTxt,"%d %d %f %s",%RegV.cod,%RegV.mes,%RegV.valor,%RegV.nome);

    while(!feof(ArqTxt))
    {

        soma+=RegV.valor;
        fscanf(ArqTxt,"%d %d %f %s",%RegV.cod,%RegV.mes,%RegV.valor,%RegV.nome);
    }
    printf("\n Total em vendas R$ %.2f",soma);
    getch();
    fclose(ArqTxt);
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    FILE * fp;
    int i,p=0,z;
    char vet[60];
    char vet2[60];
    int TamMens;
    int largura;
    int altura;
    int escolha;
    char*pontMens;
    char cor;
    char letra='a';
    printf("Nesse momento, iremos procurar a imagem dentro da pasta para realizar a leitura da mensagem.\n\n");
    system("PAUSE");
    printf("%c fortemente recomendado que j%c tenha passado pelo programa anterior (Colocar na imagem) antes de come%car.\n\n",144,160,135);
    system("PAUSE");
    printf("\nDigite o nome da imagem: \n");
    scanf("%s",vet);
    for(i=0;vet[i]!='\0';i++)
    {}
     if(vet[i]=='\0'&&(vet[i-1]!='p'||vet[i-2]!='m'||vet[i-3]!='b'||vet[i-4]!='.'))
    {
        sprintf(vet2,"%s.bmp",vet);
    }
    else
    {
        sprintf(vet2,"%s",vet);
    }

    fp =fopen(vet2,"r+b");
    while(fp==NULL)
    {
        printf("\nMensagem n%co encontrada. \n",198);
        printf("\nDigite o nome da imagem novamente e verifique se ela est%c na pasta do programa:\n",160);
        scanf("%s",vet);
        for(i=0;vet[i]!='\0';i++)
        {}
        if(vet[i]=='\0'&&(vet[i-1]!='p'||vet[i-2]!='m'||vet[i-3]!='b'||vet[i-4]!='.'))
        {
            sprintf(vet2,"%s.bmp",vet);
        }
        else
        {
            sprintf(vet2,"%s",vet);
        }

            fp =fopen(vet2,"r");
    }
      fseek(fp,18,SEEK_SET);
    fread(&largura,1,4,fp);
    fread(&altura,1,4,fp);
    fseek(fp,largura*altura,SEEK_SET);
     fread(&TamMens,1,4,fp);
    pontMens= malloc(TamMens);
    printf("Escreva a escolha dada pelo programa anterior: (0;1;2): ");
    scanf("%i",&escolha);
    for(z=0;z<largura*altura;z++)
    {
        fseek(fp,54+(z*3)+escolha,SEEK_SET);
        fread(&cor,1,1,fp);
       if(cor>96&&cor<125&&p<TamMens+1)
       {
           fseek(fp,54+(z*3)+escolha,SEEK_SET);
            fread(&letra,1,1,fp);
            pontMens[p]=letra;
            p++;
       };
    }
    for(p=0;p<TamMens+1;p++)
    {
        if(pontMens[p]==123 )
        {
            pontMens[p] =32;
        }
          if(pontMens[p]==124 )
        {
            pontMens[p] ='\0';
        }
    }
    system("CLS");
    printf("Processando mensagem...\n ");
    Sleep(3000);
    system("CLS");
    printf("-");
    puts(pontMens);
    system("PAUSE");
    return 0;
}

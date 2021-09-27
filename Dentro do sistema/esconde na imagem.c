#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    int TamMens;
    char*pontMens;
    FILE * fp;
    int i;
    int p=0;
    char vet[60];
    char vet2[60];
    int max=0;
    int z;
    int largura;
    int altura;
    char cor;
    int escolha;
    char letra;
    printf("Nesse momento, iremos procurar a imagem dentro da pasta.\n");
    printf("\nObs.: - Imagem obrigatoriamente '.bpm'\n\n");
    system("PAUSE");
    printf("\nDigite o nome da imagem:\n");
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
        printf("\nImagem n%co encontrada\n\n",198);
        printf("\nDigite novamente o nome da imagem ou verifique se ela esta na pasta do programa:\n");
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
    system("CLS");
    printf("Digite 0 para esconder a mensagem na cor - Azul \nDigite 1 para esconder a mensagem na cor - Verde\nDigite 2 para esconder a mensagem na cor - Vermelha\n");
    scanf("%i",&escolha);
    system("CLS");
    fseek(fp,18,SEEK_SET);
    fread(&largura,1,4,fp);
    fread(&altura,1,4,fp);
    for(z=0;z<largura*altura;z++)
    {
        fseek(fp,54+(z*3)+escolha,SEEK_SET);
        fread(&cor,1,1,fp);
       if(cor>96&&cor<124)
       {
            max++;
       };
    }

    printf("\nObs.1: - Espa%co conta como caractere;\nObs.2: - M%cximo de espa%cos para caracteres na imagem:%i\nObs.3: - Acentos('%c' '%c') ou s%cmbolos('%c' '%c') n%co podem ser usados;\n\nEscreva quantos caracateres sua mensagem tem: \n",135,160,135,max,94,160,161,63,36,198);
    scanf("%d",&TamMens);
    getchar();
    pontMens=malloc(TamMens+1);
    printf("\nEscreva sua mensagem:\n");
    gets(pontMens);
    printf("\nMensagem lida com sucesso.\n");
    for(i=0;pontMens[i]!='\0';i++)
    {
        if(pontMens[i]<90&&pontMens[i]>65)
        {
            pontMens[i]=pontMens[i]+32;
        }
        if(pontMens[i]==32)
        {
            pontMens[i]=123;
        }

    }
    if(pontMens[i]=='\0')
        {
            pontMens[i]=124;
        }
    system("PAUSE");
    system("CLS");
    	printf("\nEscondendo mensagem - Aguarde...\n");
				Sleep(2000);
    p=0;
    for(z=0;z<largura*altura;z++)
    {
        fseek(fp,54+(z*3)+escolha,SEEK_SET);
        fread(&cor,1,1,fp);
       if(cor>96&&cor<125&&p<i+1)
       {
           fseek(fp,54+(z*3)+escolha,SEEK_SET);
            letra=pontMens[p];
            fwrite(&letra,1,1,fp);
            p++;
       };
    }

     fseek(fp,largura*altura,SEEK_SET);
     fwrite(&i,1,4,fp);
    printf("\nMensagem escondida com sucesso;\nPor favor anote sua escolha: %i\n",escolha);
    system("PAUSE");
    return 0;
}

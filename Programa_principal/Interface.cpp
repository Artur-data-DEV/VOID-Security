#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define RESX 1024
#define RESY 768


int main() 
{
 FILE* colocar;
			
	int x=0,y=0; //variaveis para guardar as coordenadas do ponteiro do mouse
	initwindow(RESX, RESY, "Void Security - Steganography");
	setcolor (0); // cor da linha: 0 igual a preto
	setfillstyle (1, 15);//(forma de preenchimento, cor do preenchimento)  
    bar(0, 0, RESX, RESY); // fundo branco
   
	
	//abrindo a imagem Void Security
	readimagefile("Void Security.jpeg",0,0,RESX,RESY);
	
	
	while(true)
	{
	while (ismouseclick(WM_LBUTTONDOWN))
	{
		
		getmouseclick(WM_LBUTTONDOWN, x, y);//pegando o clique do mouse		
		
		if((x>=96&&x<=361) && (y>=526)&&(y<=560))
		{
						//dando a impressão gráfica do clique---------
		
			readimagefile("colocar na imagem.jpg",96,526,361,560);	
			delay(30);
			readimagefile("Void Security.jpeg",0,0,RESX,RESY);
			PlaySound("Efeito Sonoro do mouse.wav", NULL, SND_FILENAME);
			colocar = fopen ("escondeimagem.exe", "r");	
			system("C:\\VoidSecurity\\Opcoes\\Esconde.exe");
				
		
			
		}
			else if((x>=95&&x<=362) && (y>=603)&&(y<=638))
			
		{	
			
			readimagefile("retirar da imagem.jpeg",95,603,362,638);
			delay(30);
			readimagefile("Void Security.jpeg",0,0,RESX,RESY);
			PlaySound("Efeito Sonoro do mouse.wav", NULL, SND_FILENAME);
			system("C:\\VoidSecurity\\Opcoes\\Leitura.exe");
		    
		}		
		else if((x>=74&&x<=180) && (y>=675)&&(y<=721))
		{	
			readimagefile("sair.jpeg",74,675,180,721);
			delay(30);
			readimagefile("Void Security.jpeg",0,0,RESX,RESY);
			PlaySound("Efeito Sonoro do mouse.wav", NULL, SND_FILENAME);
			
		
						
			return(0);
		}		
		else if((x>=66&&x<=123) && (y>=23)&&(y<=101))
		
		{	
			
			readimagefile("duvida.jpeg",66,23,123,101);	
			delay(30);
			readimagefile("Void Security.jpeg",0,0,RESX,RESY);
			PlaySound("Efeito Sonoro do mouse.wav", NULL, SND_FILENAME);
			system("C:\\VoidSecurity\\leia.pdf");
			
		}		
		else if((x>=685&&x<=893) && (y>=509)&&(y<=681))
		
		{	
			
			readimagefile("equipe void.jpg",685,509,893,681);	
			delay(30);
			readimagefile("Void Security.jpeg",0,0,RESX,RESY);
			PlaySound("Efeito Sonoro do mouse.wav", NULL, SND_FILENAME);
			
			
			readimagefile("melhores.jpg",0,0,RESX,RESY);
			delay(4000);
			readimagefile("Void Security.jpeg",0,0,RESX,RESY);
		  
			
		}		
	
	}
}
	
	system("PAUSE");
	return 0;
}

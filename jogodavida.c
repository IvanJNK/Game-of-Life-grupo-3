// 1.1 - Inclus�o das bibliotecas
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <errno.h>
	
	#include "jogodavida.h"

// 1.2 -Defini��o da dimen��o so mundo para o modelo

	#define LARGURA_MUNDO 39
	#define ALTURA_MUNDO 20

// Representa��o de caracteres de estado da celula

	#define  CHAR_VIVA '*' 
	#define  CHAR_MORTA ' '

//Armazenamento dos estados actuais da celula e a proxima gera��o de estado no mundo

	static int mundo[LARGURA_MUNDO][ALTURA_MUNDO];
	static int proximos_estados[LARGURA_MUNDO][ALTURA_MUNDO];
	
// 1.5-  Implementa��o da fun��o iniciar_Mundo

	void iniciar_mundo(void){
		int i, j;
		
		for(i=0;i<LARGURA_MUNDO; i++)
			for(j=0; j<ALTURA_MUNDO; j++)
				mundo[i][j]=proximos_estados[i][j]=MORTA;
				
	//Padr�o contante
	mundo[1][2]=VIVA;
	mundo[3][1]=VIVA;
	mundo[3][2]=VIVA;
	mundo[3][3]=VIVA;
	mundo[2][3]=VIVA;
	}

// 1.6 Implementa��o da fun��o que retornam a dimen��o do mundo

int get_mundo_largura(void){
		return LARGURA_MUNDO;
}
int get_mundo_altura(void){
		return ALTURA_MUNDO;
}

// 1.7 Implementa��o da fun��o get_estado_celula

int get_estado_celula(int x, int y){
	if(y<0||y>=ALTURA_MUNDO||x<0||x>=LARGURA_MUNDO){
		return MORTA;
	}
	
	return mundo[x][y];
}

// 1.8 Implementa��o da fun��o set estado de celula
	
	void set_estado_celula(int x, int y, int estado){
		if(y<0||y>=ALTURA_MUNDO||x<0||x>=LARGURA_MUNDO){
			fprintf(stderr,"erro: cordenadas (%d,%d) s�o invaludas. \n",x,y);
			abort();
		}
		mundo[x][y]=estado;
	}
	
// 1.9 Implementa��o da fun��o finalizar _evolu��o
	void finalizar_evolucao(void){
		int i,j;
		for(i=0;i<LARGURA_MUNDO; i++)
			for(j=0;j<ALTURA_MUNDO; j++){
				mundo[i][j]=proximos_estados[i][j];
				proximos_estados[i][j]=MORTA;
			}
		
		
		
	}
// 1.10 Implementa��o da fun��o imprimir Mundo

	void imprimir_mundo(void){
		char mundostr[2*LARGURA_MUNDO+2];
		int i, j;
		
		 mundostr[2*LARGURA_MUNDO+1] = '\0';
		  mundostr[0]='+';
		  for(i=1;i<2*LARGURA_MUNDO; i++)
		  	mundostr[i]='-';
		mundostr[2*LARGURA_MUNDO]= '+';
		puts(mundostr);
		 for(i=0;i<=2*LARGURA_MUNDO; i+=2)
		  	mundostr[i]='|';
		 for(i=0;i<ALTURA_MUNDO; i++){
		 	 for(j=0;j<LARGURA_MUNDO; j++)
		  		mundostr[2*j+1]=mundo[j][i]==VIVA?
		  	CHAR_VIVA : CHAR_MORTA;
		  	puts(mundostr);
		 }
		mundostr[0]='+';
		 for(i=1;i<2*LARGURA_MUNDO; i++)
		  	mundostr[i]='-'; 
		mundostr[2*LARGURA_MUNDO]= '+';
		puts(mundostr);
	}

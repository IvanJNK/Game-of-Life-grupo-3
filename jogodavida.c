// 1.1 - Inclusão das bibliotecas
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <errno.h>
	
	#include "jogodavida.h"

// 1.2 -Definição da dimenção so mundo para o modelo

	#define LARGURA_MUNDO 39
	#define ALTURA_MUNDO 20

// Representação de caracteres de estado da celula

	#define  CHAR_VIVA '*' 
	#define  CHAR_MORTA ' '

//Armazenamento dos estados actuais da celula e a proxima geração de estado no mundo

	static int mundo[LARGURA_MUNDO][ALTURA_MUNDO];
	static int proximos_estados[LARGURA_MUNDO][ALTURA_MUNDO];
	
// 1.5-  Implementação da função iniciar_Mundo

	void iniciar_mundo(void){
		int i, j;
		
		for(i=0;i<LARGURA_MUNDO; i++)
			for(j=0; j<ALTURA_MUNDO; j++)
				mundo[i][j]=proximos_estados[i][j]=MORTA;
				
	//Padrão contante
	mundo[1][2]=VIVA;
	mundo[3][1]=VIVA;
	mundo[3][2]=VIVA;
	mundo[3][3]=VIVA;
	mundo[2][3]=VIVA;
	}

// 1.6 Implementação da função que retornam a dimenção do mundo

int get_mundo_largura(void){
		return LARGURA_MUNDO;
}
int get_mundo_altura(void){
		return ALTURA_MUNDO;
}

// 1.7 Implementação da função get_estado_celula

int get_estado_celula(int x, int y){
	if(y<0||y>=ALTURA_MUNDO||x<0||x>=LARGURA_MUNDO){
		return MORTA;
	}
	
	return mundo[x][y];
}

// 1.8 Implementação da função set estado de celula
	
	void set_estado_celula(int x, int y, int estado){
		if(y<0||y>=ALTURA_MUNDO||x<0||x>=LARGURA_MUNDO){
			fprintf(stderr,"erro: coordenadas (%d,%d) são invalidas. \n",x,y);
			abort();
		}
		proximos_estados[x][y]=estado;
	}
	
// 1.9 Implementação da função finalizar _evolução
	void finalizar_evolucao(void){
		int i,j;
		for(i=0;i<LARGURA_MUNDO; i++)
			for(j=0;j<ALTURA_MUNDO; j++){
				mundo[i][j]=proximos_estados[i][j];
				proximos_estados[i][j]=MORTA;
			}
		
		
		
	}
// 1.10 Implementação da função imprimir Mundo

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

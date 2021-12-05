#include <stdio.h>
#include <stdlib.h>
/* Funções auxiliares - biblioteca do jogo*/
#include "jogodavida.h"
/* Adiciona outras bibliotecas aqui, se necessário*/
#include <dos.h>

/* número de gerações para evoluir o mundo */
#define NUM_GERACOES 50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void prox_geracao(void);
int get_prox_estado(int x, int y);
int num_vizinhos(int x, int y);
int main(int argc, char *argv[]) {
	iniciar_mundo();
	imprimir_mundo();
	return 0;
}

void prox_geracao(void){

}

void get_prox_estado(void){
	
}

int num_vizinhos(int x, int y){
	int i,j,v;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			if((x+i>=0&&x+i<=get_mundo_largura)&&(y+j>=0&&y+j<=get_mundo_altura)&&i!=0&&j!=0)
				if(get_estado_celula(x+i,y+j)==VIVA)
					v++;
	return v;
}
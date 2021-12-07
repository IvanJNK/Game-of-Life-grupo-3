#include <stdio.h>
#include <stdlib.h>
/* FunÃ§Ãµes auxiliares - biblioteca do jogo*/
#include "jogodavida.h"
/* Adiciona outras bibliotecas aqui, se necessÃ¡rio*/
#include <dos.h>

/* nÃºmero de geraÃ§Ãµes para evoluir o mundo */
#define NUM_GERACOES 50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void prox_geracao(void);
int get_prox_estado(int x, int y);
int num_vizinhos(int x, int y);
int main(int argc, char *argv[]) {
	int i;
	iniciar_mundo();
	for(i = 0; i < NUM_GERACOES; i++) {
		prox_geracao();
		system("cls");
		imprimir_mundo();
		sleep(2);
	}

	return 0;
}

void prox_geracao(void){
	int largura=get_mundo_largura(),altura=get_mundo_altura();
	int i,j;
	for(j=0;j<altura;j++)
		for(i=0;i<largura;i++)
			set_estado_celula(i,j,get_prox_estado(i,j));
	finalizar_evolucao();
}

int get_prox_estado(int x,int y){
	int v=num_vizinhos(x,y);
	if(get_estado_celula(x,y)==VIVA&&(v<2||v>3))
		return MORTA;
	else if(get_estado_celula(x,y)==VIVA&&(v==2||v==3)||get_estado_celula(x,y)==MORTA&&v==3)
		return VIVA;
}

int num_vizinhos(int x, int y){
	int i,j,v=0;
	for(j=-1;j<=1;j++)
		for(i=-1;i<=1;i++)
			if((i==0&&j==0)&&get_estado_celula(x+i,y+j)==VIVA)
				v++;
	return v;
}

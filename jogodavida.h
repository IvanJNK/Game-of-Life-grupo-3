/*
	Name: 
	Copyright: 
	Author: 
	Date: 02/12/21 08:24
	Description: 
*/

#ifndef JOGO_H_
	#define JOGO_H_
	
	#define MORTA 0
	#define VIVA 1

	void iniciar_mundo(void);
	int get_mundo_largura(void);
	int get_mundo_altura(void);
	int get_estado_celula(int x ,int y);
	void set_estado_celula(int x, int y, int estado);
	void finalizar_evolucao(void);
	void imprimir_mundo(void);
	
#endif


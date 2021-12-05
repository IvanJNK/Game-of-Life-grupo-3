Introdução
O trabalho prático de Programação para Engenharia é um projecto que está
organizado em vários exercícios a serem resolvidos em aulas de laboratório.
Este documento fornece uma visão global do projecto. Nas próximas versões
deste documento, teremos mais detalhes e guia para implementação da
aplicação com base nas boas práticas de programação.
A secção seguinte apresenta, de modo superficial, o programa a ser
desenvolvido pelos alunos.
Visão geral
O Jogo da Vida , inventado por John Conway em 1970, é um exemplo de 1
“jogo” sem jogador. É conhecido como autómato celular.
O jogo consiste em um mundo bi-dimensional que se estende infinitamente em
todas as direcções, dividido em "células".
Cada célula está "morta" ou "viva" em uma determinada "geração". O jogo
consiste em um conjunto de regras que descrevem como as células evoluem
de geração em geração.
Essas regras calculam o estado de uma célula na próxima geração como uma
função dos estados de suas células vizinhas na geração actual. 
Em um mundo 2-D, os vizinhos de uma célula são aquelas 8 células vertical,
horizontal ou diagonalmente adjacentes a essa célula.
O conjunto de regras de Conway é resumido como:
1. Uma célula viva com menos de dois vizinhos vivos morre.
2. Uma célula viva com mais de três vizinhos vivos também morre.
3. Uma célula viva com exactamente dois ou três vizinhos vivos vive.
4. Uma célula morta com exactamente três vizinhos vivos torna-se viva.
Neste trabalho, implementaremos o Jogo da Vida de Conway, com a pequena
restricção de que nosso mundo 2-D é finito.
Os vizinhos de uma célula na borda do mundo que estaria além da borda são
considerados mortos.
A essa restricção, denominamos por jclife.
As próximas versões deste documento descreverão os exercícios de cada fase
do projecto a implementar na aula de laboratório.
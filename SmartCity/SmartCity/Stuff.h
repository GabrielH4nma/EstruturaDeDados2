/*****************************************************************//**
 * \file   Stuff.h
 * \brief  Client/Transport/Gestor info
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
 // Este � um arquivo de cabe�alho que impede v�rias inclus�es do mesmo cabe�alho.
 // Se n�o estiver definido, ent�o est� definido e tudo no cabe�alho � inclu�do.
#pragma once
#include "consts.h"

typedef struct {
    double x;
    double y;
} Coordenadas;

typedef struct {
    int origem;       // identificador do v�rtice de origem
    int destino;      // identificador do v�rtice de destino
    double distancia; // dist�ncia entre os v�rtices
} Aresta;

typedef struct Grafo {
	int numVertices; // n�mero total de v�rtices no grafo
	int numArestas; // n�mero total de arestas no grafo
    Aresta* arestas;    // vetor de arestas
    Coordenadas* vertices; // vetor de localiza��es dos v�rtices
} Grafo;


typedef struct {
    int* vertices;  // Array para armazenar os v�rtices do trajeto
    int tamanho;    // Tamanho atual do trajeto
    int capacidade; // Capacidade m�xima do trajeto
} TrajetoCamiao;


// Fun��o para criar um grafo vazio
Grafo* criarGrafo(int numVertices);
// Fun��o para obter a dist�ncia entre dois v�rtices no grafo
double obterDistancia(Grafo* grafo, int origem, int destino);
//Funcao para adicionar uma aresta
void adicionarAresta(Grafo* grafo, int origem, int destino, double distancia);
//Salvar dados
int salvarDadosTexto(Grafo* grafo, const char* nomeArquivo);
int salvarDadosBinario(Grafo* grafo, const char* nomeArquivo);

//double calcularDistancia(Coordenadas coord1, Coordenadas coord2);
//double calcularDistanciaTotal(TrajetoCaminhao trajeto, Coordenadas* coordenadas);
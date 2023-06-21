/*****************************************************************//**
 * \file   Stuff.h
 * \brief  Client/Transport/Gestor info
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
 // Este é um arquivo de cabeçalho que impede várias inclusões do mesmo cabeçalho.
 // Se não estiver definido, então está definido e tudo no cabeçalho é incluído.
#pragma once
#include "consts.h"

typedef struct {
    double x;
    double y;
} Coordenadas;

typedef struct {
    int origem;       // identificador do vértice de origem
    int destino;      // identificador do vértice de destino
    double distancia; // distância entre os vértices
} Aresta;

typedef struct Grafo {
	int numVertices; // número total de vértices no grafo
	int numArestas; // número total de arestas no grafo
    Aresta* arestas;    // vetor de arestas
    Coordenadas* vertices; // vetor de localizações dos vértices
} Grafo;


typedef struct {
    int* vertices;  // Array para armazenar os vértices do trajeto
    int tamanho;    // Tamanho atual do trajeto
    int capacidade; // Capacidade máxima do trajeto
} TrajetoCamiao;


// Função para criar um grafo vazio
Grafo* criarGrafo(int numVertices);
// Função para obter a distância entre dois vértices no grafo
double obterDistancia(Grafo* grafo, int origem, int destino);
//Funcao para adicionar uma aresta
void adicionarAresta(Grafo* grafo, int origem, int destino, double distancia);
//Salvar dados
int salvarDadosTexto(Grafo* grafo, const char* nomeArquivo);
int salvarDadosBinario(Grafo* grafo, const char* nomeArquivo);

//double calcularDistancia(Coordenadas coord1, Coordenadas coord2);
//double calcularDistanciaTotal(TrajetoCaminhao trajeto, Coordenadas* coordenadas);
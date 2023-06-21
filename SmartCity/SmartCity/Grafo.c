/*****************************************************************//**
 * \file   Grafo.c
 * \brief  
 * 
 * \author guilh
 * \date   May 2023
 *********************************************************************/
#include "Stuff.h"
#include "Clientes.h"
#include "Transportes.h"

/**
 * .
 * 
 * \param numVertices
 * \return 
 */
Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->numArestas = 0;
    grafo->arestas = (Aresta*)malloc(sizeof(Aresta));
    grafo->vertices = (Coordenadas*)malloc(numVertices * sizeof(Coordenadas));
    return grafo;
}

/**
 * .
 * 
 * \param grafo
 * \param origem
 * \param destino
 * \param distancia
 */
void adicionarAresta(Grafo* grafo, int origem, int destino, double distancia) {
    grafo->numArestas++;
    grafo->arestas = (Aresta*)realloc(grafo->arestas, grafo->numArestas * sizeof(Aresta));
    grafo->arestas[grafo->numArestas - 1].origem = origem;
    grafo->arestas[grafo->numArestas - 1].destino = destino;
    grafo->arestas[grafo->numArestas - 1].distancia = distancia;
}

/**
 * .
 * 
 * \param grafo
 * \param origem
 * \param destino
 * \return 
 */
double obterDistancia(Grafo* grafo, int origem, int destino) {
    for (int i = 0; i < grafo->numArestas; i++) {
        if (grafo->arestas[i].origem == origem && grafo->arestas[i].destino == destino) {
            return grafo->arestas[i].distancia;
        }
    }
    return -1;  // aresta não encontrada
}

/**
 * . Função para calcular a distância euclidiana entre duas coordenadas
 * 
 * \param coord1
 * \param coord2
 * \return 
 */
double calcularDistancia(Coordenadas coord1, Coordenadas coord2) {
    double difX = coord2.x - coord1.x;
    double difY = coord2.y - coord1.y;
    return sqrt(difX * difX + difY * difY);
}

/**
 * . Função para calcular a distância total percorrida no trajeto
 * 
 * \param trajeto
 * \param coordenadas
 * \return 
 */
double calcularDistanciaTotal(TrajetoCamiao trajeto, Coordenadas* coordenadas) {
    double distanciaTotal = 0.0;
    for (int i = 0; i < trajeto.tamanho; i++) {
        int verticeAtual = trajeto.vertices[i];
        int proximoVertice = trajeto.vertices[i + 1];
        Coordenadas coordAtual = coordenadas[verticeAtual];
        Coordenadas coordProximo = coordenadas[proximoVertice];
        distanciaTotal += calcularDistancia(coordAtual, coordProximo);
    }
    return distanciaTotal;
}
/*
void listarTransportRaio(Cliente localizacaoCliente, Transporte* meiosMobilidade, int numMeiosMobilidade, double raio, int tipo) {
    printf("Meios de Mobilidade Elétrica do tipo %d dentro do raio de %.2f a partir da localização do cliente (%d, %d):\n", tipo, raio, localizacaoCliente.x, localizacaoCliente.y);
    for (int i = 0; i < numMeiosMobilidade; i++) {
        double distancia = sqrt(pow(localizacaoCliente.x - meiosMobilidade[i].local.x, 2) + pow(localizacaoCliente.y - meiosMobilidade[i].local.y, 2));
        if (distancia <= raio && meiosMobilidade[i].tipo == tipo) {
            printf("ID: %d\n", meiosMobilidade[i].id);
            printf("Localização: (%d, %d)\n", meiosMobilidade[i].local.x, meiosMobilidade[i].local.y);
            printf("\n");
        }
    }
}*/

int salvarDadosTexto(Grafo* grafo, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        //printf("Erro ao abrir o arquivo de destino.\n");
        return -1;
    }

    // Escrever os dados do grafo no arquivo de texto
    fprintf(arquivo, "%d\n", grafo->numVertices);
    fprintf(arquivo, "%d\n", grafo->numArestas);

    fclose(arquivo);
    return 1;
}

int salvarDadosBinario(Grafo* grafo, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        //printf("Erro ao abrir o arquivo de destino.\n");
        return -1;
    }

    // Escrever os dados do grafo no arquivo binário
    fwrite(&grafo->numVertices, sizeof(int), 1, arquivo);
    fwrite(&grafo->numArestas, sizeof(int), 1, arquivo);

    fclose(arquivo);
    return 1;
}

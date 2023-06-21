/*****************************************************************//**
 * \file   Transportes.h
 * \brief  
 * 
 * \author guilh
 * \date   May 2023
 *********************************************************************/
#pragma once

#ifndef DATA_T
#define DATA_T

#include "consts.h"

 // Define constants for the maximum size of a string and the maximum number of clients and vehicles.
#define MAX_VEHICLES 100

typedef enum {
	trotinete,
	mota,
	carro
} TransportType;

typedef struct {
	int id;
	TransportType tipo;
	float carga;
	float custo;
	char geocodigo[MAX_VEHICLES];
	int alugado;
} Transport;

typedef struct TransporteList TransporteList;
struct TransporteList {
	Transport transport;
	TransporteList* anterior;
	TransporteList* proximo;
};



//Transporte Ativação de métodos
TransporteList* CreatTransporte(int id, TransportType tipo, float carga, float custo, char* geocodigo, int alugado);
int AddTransporte(TransporteList** head, TransporteList* novoTransporte);
int RemoverTransporte(TransporteList** head, TransporteList* transporteRemovido);
void AlterarTransporte(TransporteList* head, int id, TransportType novoTipo, float novaCarga, float novoCusto, char* novoGeocodigo, int novoAlugado);
int RegistrarReserva(TransporteList* head, int id, int novaReserva);
int CompareAutonomia(Transport v1, Transport v2);
void ListarVeiculosPorAutonomia(Transport* transportes, int numTransportes);


#endif

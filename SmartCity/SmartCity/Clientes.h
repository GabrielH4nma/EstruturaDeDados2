/*****************************************************************//**
 * \file   Clientes.h
 * \brief  
 * 
 * \author guilh
 * \date   May 2023
 *********************************************************************/
#pragma once

#ifndef DATA_C
#define DATA_C

#include "consts.h"

 // Define constants for the maximum size of a string and the maximum number of clients and vehicles.
#define MAX_CLIENTS 100

// Forward declarations of struct types
typedef struct Cliente Cliente;

// Define a structure for a client, which contains their tax identification number, name, address and balance.
typedef struct {
	char nif[MAX_CLIENTS];
	char nome[MAX_CLIENTS];
	char morada[MAX_CLIENTS];
	float saldo;
} Cliente;

//Cliente Ativação de métodos
void addCliente(Cliente* clientes, int* numclientes, char* nif, char* nome, char* morada, float saldo);
void removerCliente(Cliente* clientes, int* numClientes, char* nif);
void alterarCliente(Cliente* clientes, int numClientes, int index, char* novoNome, char* novaMorada, float novoSaldo);

#endif
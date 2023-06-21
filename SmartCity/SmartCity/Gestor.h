/*****************************************************************//**
 * \file   Gestor.h
 * \brief  
 * 
 * \author guilh
 * \date   May 2023
 *********************************************************************/
#pragma once

#ifndef DATA_G
#define DATA_G

#include "consts.h"

// Forward declarations of struct types
typedef struct Gestor Gestor;

// Define a structure for a manager, which contains their username, password, name and email.
typedef struct {
	char username[MAX_GESTOR];
	char password[MAX_GESTOR];
	char nome[MAX_GESTOR];
	char email[MAX_GESTOR];
} Gestor;

//Gestor Ativação de métodos
void addGestor(Gestor* gestores, int* numgestores, char* username, char* password, char* nome, char* email);
void removerGestor(Gestor* gestores, int* numGestores, char* username);
void alterarGestor(Gestor* gestores, int numGestores, int index, char* novoNome, char* novoEmail);

#endif
/*****************************************************************//**
 * \file   Gestor.c
 * \brief  Gestor functions
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
#include "Stuff.h"
#include "Clientes.h"
#include "Gestor.h"
#include "Transportes.h"

/**
 * Adiciona um novo gestor ao array de gestores.
 *
 * Esta fun��o adiciona um novo gestor ao array de gestores fornecido. O gestor � criado com as informa��es fornecidas
 * de username, password, nome e email. Se o n�mero de gestores j� atingiu o limite m�ximo (MAX_GESTOR), a fun��o n�o
 * adicionar� o gestor e exibir� uma mensagem de erro.
 *
 * \param gestores O array de gestores.
 * \param numgestores O n�mero atual de gestores no array.
 * \param username O nome de usu�rio do gestor a ser adicionado.
 * \param password A senha do gestor a ser adicionado.
 * \param nome O nome do gestor a ser adicionado.
 * \param email O email do gestor a ser adicionado.
 */
void addGestor(Gestor* gestores, int* numgestores, char* username, char* password, char* nome, char* email) {
    if (*numgestores < MAX_GESTOR) {
        Gestor novoGestor;
        strncpy(novoGestor.username, username, MAX_GESTOR);
        strncpy(novoGestor.password, password, MAX_GESTOR);
        strncpy(novoGestor.nome, nome, MAX_GESTOR);
        strncpy(novoGestor.email, email, MAX_GESTOR);
        gestores[*numgestores] = novoGestor;
        (*numgestores)++;
    }
    else {
        //printf("N�o � poss�vel adicionar mais gestores.\n");
    }
}

/**
 * Remove um gestor do array de gestores.
 *
 * Esta fun��o remove um gestor do array de gestores com base no username fornecido. O gestor correspondente � encontrado
 * pelo username e � movido para o final do array. Em seguida, o n�mero de gestores � decrementado e o espa�o ocupado pelo
 * �ltimo gestor � liberado. Se o gestor n�o for encontrado, a fun��o n�o far� nada.
 *
 * \param gestores O array de gestores.
 * \param numGestores O n�mero atual de gestores no array.
 * \param username O nome de usu�rio do gestor a ser removido.
 */
void removerGestor(Gestor* gestores, int* numGestores, char* username) {
    // Encontra o �ndice do gestor com o nome de usu�rio correspondente
    int indice = -1;
    for (int i = 0; i < *numGestores; i++) {
        if (strcmp(gestores[i].username, username) == 0) {
            indice = i;
            break;
        }
    }

    // Se o gestor foi encontrado, mova-o para o final do array
    if (indice >= 0) {
        gestores[indice] = gestores[*numGestores - 1];
        (*numGestores)--;

        // Libera o espa�o ocupado pelo �ltimo gestor
        gestores = (Gestor**)realloc(&gestores, (*numGestores) * sizeof(Gestor));
    }
}

/**
 * Altera os dados de um gestor no array de gestores.
 *
 * Esta fun��o altera o nome e o email de um gestor no array de gestores com base no �ndice fornecido. Os novos valores de
 * nome e email s�o atribu�dos ao gestor correspondente. Se o �ndice fornecido estiver fora do intervalo v�lido, a fun��o
 * exibir� uma mensagem de erro.
 *
 * \param gestores O array de gestores.
 * \param numGestores O n�mero atual de gestores no array.
 * \param index O �ndice do gestor a ser alterado.
 * \param novoNome O novo nome a ser atribu�do ao gestor.
 * \param novoEmail O novo email a ser atribu�do ao gestor.
 */
void alterarGestor(Gestor* gestores, int numGestores, int index, char* novoNome, char* novoEmail) {
    // Verifica se o �ndice fornecido est� dentro do intervalo v�lido
    if (index < 0 || index >= numGestores) {
        //printf("Indice de gestor invalido!\n");
        return;
    }

    // Altera os dados do gestor
    strcpy(gestores[index].nome, novoNome);
    strcpy(gestores[index].email, novoEmail);
}
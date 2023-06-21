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
 * Esta função adiciona um novo gestor ao array de gestores fornecido. O gestor é criado com as informações fornecidas
 * de username, password, nome e email. Se o número de gestores já atingiu o limite máximo (MAX_GESTOR), a função não
 * adicionará o gestor e exibirá uma mensagem de erro.
 *
 * \param gestores O array de gestores.
 * \param numgestores O número atual de gestores no array.
 * \param username O nome de usuário do gestor a ser adicionado.
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
        //printf("Não é possível adicionar mais gestores.\n");
    }
}

/**
 * Remove um gestor do array de gestores.
 *
 * Esta função remove um gestor do array de gestores com base no username fornecido. O gestor correspondente é encontrado
 * pelo username e é movido para o final do array. Em seguida, o número de gestores é decrementado e o espaço ocupado pelo
 * último gestor é liberado. Se o gestor não for encontrado, a função não fará nada.
 *
 * \param gestores O array de gestores.
 * \param numGestores O número atual de gestores no array.
 * \param username O nome de usuário do gestor a ser removido.
 */
void removerGestor(Gestor* gestores, int* numGestores, char* username) {
    // Encontra o índice do gestor com o nome de usuário correspondente
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

        // Libera o espaço ocupado pelo último gestor
        gestores = (Gestor**)realloc(&gestores, (*numGestores) * sizeof(Gestor));
    }
}

/**
 * Altera os dados de um gestor no array de gestores.
 *
 * Esta função altera o nome e o email de um gestor no array de gestores com base no índice fornecido. Os novos valores de
 * nome e email são atribuídos ao gestor correspondente. Se o índice fornecido estiver fora do intervalo válido, a função
 * exibirá uma mensagem de erro.
 *
 * \param gestores O array de gestores.
 * \param numGestores O número atual de gestores no array.
 * \param index O índice do gestor a ser alterado.
 * \param novoNome O novo nome a ser atribuído ao gestor.
 * \param novoEmail O novo email a ser atribuído ao gestor.
 */
void alterarGestor(Gestor* gestores, int numGestores, int index, char* novoNome, char* novoEmail) {
    // Verifica se o índice fornecido está dentro do intervalo válido
    if (index < 0 || index >= numGestores) {
        //printf("Indice de gestor invalido!\n");
        return;
    }

    // Altera os dados do gestor
    strcpy(gestores[index].nome, novoNome);
    strcpy(gestores[index].email, novoEmail);
}
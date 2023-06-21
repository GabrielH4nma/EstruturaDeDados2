/*****************************************************************//**
 * \file   Client.c
 * \brief  Client functions
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
#include "Stuff.h"
#include "Clientes.h"
#include "Gestor.h"
#include "Transportes.h"

 /**
  * Adiciona um novo cliente ao array de clientes.
  *
  * Esta função adiciona um novo cliente ao array de clientes fornecido. O cliente é criado com as informações fornecidas
  * de nome, idade, endereço e telefone. Se o número de clientes já atingiu o limite máximo (MAX_CLIENTES), a função não
  * adicionará o cliente e exibirá uma mensagem de erro.
  *
  * @param clientes O array de clientes.
  * @param numClientes O número atual de clientes no array.
  * @param nome O nome do cliente a ser adicionado.
  * @param idade A idade do cliente a ser adicionado.
  * @param endereco O endereço do cliente a ser adicionado.
  * @param telefone O telefone do cliente a ser adicionado.
  */
void addCliente(Cliente* clientes, int *numclientes, char* nif, char* nome, char* morada, float saldo) {
    if (*numclientes < MAX_CLIENTS) {
        Cliente novoCliente;
        strncpy(novoCliente.nif, nif, MAX_CLIENTS);
        strncpy(novoCliente.nome, nome, MAX_CLIENTS);
        strncpy(novoCliente.morada, morada, MAX_CLIENTS);
        novoCliente.saldo = saldo;
        clientes[*numclientes] = novoCliente;
        (*numclientes)++;
    }
    else {
        //printf("Não é possível adicionar mais clientes.\n");
    }
}

/**
 * Remove um cliente do array de clientes.
 *
 * Esta função remove um cliente do array de clientes com base no nome fornecido. O cliente correspondente é encontrado
 * pelo nome e é movido para o final do array. Em seguida, o número de clientes é decrementado e o espaço ocupado pelo
 * último cliente é liberado. Se o cliente não for encontrado, a função não fará nada.
 *
 * @param clientes O array de clientes.
 * @param numClientes O número atual de clientes no array.
 * @param nome O nome do cliente a ser removido.
 */
void removerCliente(Cliente* clientes, int* numClientes, char* nif) {
    // Encontra o índice do cliente com o NIF correspondente
    int indice = -1;
    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(clientes[i].nif, nif) == 0) {
            indice = i;
            break;
        }
    }

    // Se o cliente foi encontrado, mova-o para o final do array
    if (indice >= 0) {
        clientes[indice] = clientes[*numClientes - 1];
        (*numClientes)--;

        // Libera o espaço ocupado pelo último cliente

        clientes = (Cliente*)realloc(clientes, (*numClientes) * sizeof(Cliente));
    }
}

/**
 * Altera os dados de um cliente no array de clientes.
 *
 * Esta função altera a idade, o endereço e o telefone de um cliente no array de clientes com base no índice fornecido.
 * Os novos valores de idade, endereço e telefone são atribuídos ao cliente correspondente. Se o índice fornecido estiver
 * fora do intervalo válido, a função exibirá uma mensagem de erro.
 *
 * @param clientes O array de clientes.
 * @param numClientes O número atual de clientes no array.
 * @param index O índice do cliente a ser alterado.
 * @param novaIdade A nova idade a ser atribuída ao cliente.
 * @param novoEndereco O novo endereço a ser atribuído ao cliente.
 * @param novoTelefone O novo telefone a ser atribuído ao cliente.
 */
void alterarCliente(Cliente* clientes, int numClientes, int index, char* novoNome, char* novaMorada, float novoSaldo) {
    // Verifica se o índice fornecido está dentro do intervalo válido
    if (index < 0 || index >= numClientes) {
        ///printf("Indice de cliente invalido!\n");
        return;
    }

    // Altera os dados do cliente
    strcpy(clientes[index].nome, novoNome);
    strcpy(clientes[index].morada, novaMorada);
    clientes[index].saldo = novoSaldo;
}
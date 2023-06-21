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
  * Esta fun��o adiciona um novo cliente ao array de clientes fornecido. O cliente � criado com as informa��es fornecidas
  * de nome, idade, endere�o e telefone. Se o n�mero de clientes j� atingiu o limite m�ximo (MAX_CLIENTES), a fun��o n�o
  * adicionar� o cliente e exibir� uma mensagem de erro.
  *
  * @param clientes O array de clientes.
  * @param numClientes O n�mero atual de clientes no array.
  * @param nome O nome do cliente a ser adicionado.
  * @param idade A idade do cliente a ser adicionado.
  * @param endereco O endere�o do cliente a ser adicionado.
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
        //printf("N�o � poss�vel adicionar mais clientes.\n");
    }
}

/**
 * Remove um cliente do array de clientes.
 *
 * Esta fun��o remove um cliente do array de clientes com base no nome fornecido. O cliente correspondente � encontrado
 * pelo nome e � movido para o final do array. Em seguida, o n�mero de clientes � decrementado e o espa�o ocupado pelo
 * �ltimo cliente � liberado. Se o cliente n�o for encontrado, a fun��o n�o far� nada.
 *
 * @param clientes O array de clientes.
 * @param numClientes O n�mero atual de clientes no array.
 * @param nome O nome do cliente a ser removido.
 */
void removerCliente(Cliente* clientes, int* numClientes, char* nif) {
    // Encontra o �ndice do cliente com o NIF correspondente
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

        // Libera o espa�o ocupado pelo �ltimo cliente

        clientes = (Cliente*)realloc(clientes, (*numClientes) * sizeof(Cliente));
    }
}

/**
 * Altera os dados de um cliente no array de clientes.
 *
 * Esta fun��o altera a idade, o endere�o e o telefone de um cliente no array de clientes com base no �ndice fornecido.
 * Os novos valores de idade, endere�o e telefone s�o atribu�dos ao cliente correspondente. Se o �ndice fornecido estiver
 * fora do intervalo v�lido, a fun��o exibir� uma mensagem de erro.
 *
 * @param clientes O array de clientes.
 * @param numClientes O n�mero atual de clientes no array.
 * @param index O �ndice do cliente a ser alterado.
 * @param novaIdade A nova idade a ser atribu�da ao cliente.
 * @param novoEndereco O novo endere�o a ser atribu�do ao cliente.
 * @param novoTelefone O novo telefone a ser atribu�do ao cliente.
 */
void alterarCliente(Cliente* clientes, int numClientes, int index, char* novoNome, char* novaMorada, float novoSaldo) {
    // Verifica se o �ndice fornecido est� dentro do intervalo v�lido
    if (index < 0 || index >= numClientes) {
        ///printf("Indice de cliente invalido!\n");
        return;
    }

    // Altera os dados do cliente
    strcpy(clientes[index].nome, novoNome);
    strcpy(clientes[index].morada, novaMorada);
    clientes[index].saldo = novoSaldo;
}
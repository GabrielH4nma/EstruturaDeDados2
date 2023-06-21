/*****************************************************************//**
 * \file   Transport.c
 * \brief  Transport functions
 * 
 * \author Gabriel
 * \date   March 2023
 *********************************************************************/
#include "Stuff.h"
#include "Clientes.h"
#include "Gestor.h"
#include "Transportes.h"

TransporteList* CreatTransporte(int id, TransportType tipo, float carga, float custo, char* geocodigo, int alugado) {


        TransporteList* novoTransporte = (TransporteList*)malloc(sizeof(TransporteList));
        //TransporteList* novoTransporte;
        novoTransporte->transport.id = id;
        novoTransporte->transport.tipo = tipo;
        novoTransporte->transport.carga = carga;
        novoTransporte->transport.custo = custo;
        strcpy(novoTransporte->transport.geocodigo, geocodigo);
        novoTransporte->anterior = NULL;
        novoTransporte->proximo = NULL;

        return novoTransporte;

}

int AddTransporte(TransporteList** head, TransporteList* novoTransporte) {
    if (*head == NULL) {
        *head = novoTransporte;
        return 1;
    }
    else {
        TransporteList* last = *head;
        while (last->proximo != NULL) {
            last = last->proximo;
        }
        last->proximo = novoTransporte;
        novoTransporte->anterior = last;
        return 1;
    }
}
/**
 * Adiciona um novo transporte ao array de transportes.
 *
 * @brief Esta função adiciona um novo transporte ao array de transportes fornecido. O transporte é criado com as informações
 * fornecidas de ID, tipo, carga, custo e geocódigo. Se o número de transportes já atingiu o limite máximo (MAX_VEHICLES),
 * a função não adicionará o transporte e exibirá uma mensagem de erro.
 *
 * @param transportes O array de transportes.
 * @param numTransportes O número atual de transportes no array.
 * @param id O ID do transporte a ser adicionado.
 * @param tipo O tipo do transporte a ser adicionado.
 * @param carga A carga do transporte a ser adicionado.
 * @param custo O custo do transporte a ser adicionado.
 * @param geocodigo O geocódigo do transporte a ser adicionado.
 *
 * @pre O parâmetro transportes deve apontar para um array válido de transportes.
 * @pre O parâmetro numTransportes deve apontar para uma variável válida representando o número atual de transportes.
 *
 * @post O transporte é adicionado ao array de transportes se houver espaço disponível.
 * @post O parâmetro numTransportes é incrementado se o transporte for adicionado com sucesso.
 */
/*
void AddTransporte(Transport* transportes, int* numtransportes, char* id, char* tipo, float carga, float custo, char* geocodigo) {

    if (*numtransportes < MAX_VEHICLES) {
        Transport novoTransporte;
        strncpy(novoTransporte.id, id, MAX_VEHICLES);
        strncpy(novoTransporte.tipo, tipo, MAX_VEHICLES);
        novoTransporte.carga = carga;
        novoTransporte.custo = custo;
        strncpy(novoTransporte.geocodigo, geocodigo, MAX_VEHICLES);
        transportes[*numtransportes] = novoTransporte;
        (*numtransportes)++;
    }
    else {
        //printf("Não é possível adicionar mais transportes.\n");
    }
}
*/
int RemoverTransporte(TransporteList** head, TransporteList* transporteRemovido) {
    if (*head == NULL || transporteRemovido == NULL) {
        return 0; // Se a lista estiver vazia ou o transporte a ser removido for nulo, retorna sem fazer nada
    }

    if (*head == transporteRemovido) {
        *head = (*head)->proximo; // Se o transporte a ser removido for a cabeça da lista, atualiza o ponteiro head
    }

    if (transporteRemovido->anterior != NULL) {
        transporteRemovido->anterior->proximo = transporteRemovido->proximo;
    }

    if (transporteRemovido->proximo != NULL) {
        transporteRemovido->proximo->anterior = transporteRemovido->anterior;
    }

    free(transporteRemovido); // Libera a memória ocupada pelo transporte removido
}

/**
 * Remove um transporte do array de transportes.
 *
 * @brief Esta função remove um transporte do array de transportes com base no ID fornecido. O transporte correspondente é
 * encontrado pelo ID e é movido para o final do array. Em seguida, o número de transportes é decrementado e o espaço
 * ocupado pelo último transporte é liberado. Se o transporte não for encontrado, a função não fará nada.
 *
 * @param transportes O array de transportes.
 * @param numTransportes O número atual de transportes no array.
 * @param id O ID do transporte a ser removido.
 *
 * @pre O parâmetro transportes deve apontar para um array válido de transportes.
 * @pre O parâmetro numTransportes deve apontar para uma variável válida representando o número atual de transportes.
 *
 * @post O transporte é removido do array de transportes se for encontrado.
 * @post O parâmetro numTransportes é decrementado se o transporte for removido com sucesso.
 */
/*
void RemoverTransporte(Transport* transportes, int* numTransportes, char* id) {
    // Encontra o índice do transporte com o ID correspondente
    int indice = -1;
    for (int i = 0; i < *numTransportes; i++) {
        if ((transportes[i].id, id) == 0) {
            indice = i;
            break;
        }
    }

    // Se o transporte foi encontrado, mova-o para o final do array
    if (indice >= 0) {
        transportes[indice] = transportes[*numTransportes - 1];
        (*numTransportes)--;

        // Libera o espaço ocupado pelo último transporte
        transportes = (Transport**)realloc(&transportes, (*numTransportes) * sizeof(Transport));
    }
}*/

int AlterarTransporte(TransporteList* head, int id, TransportType novoTipo, float novaCarga, float novoCusto, char* novoGeocodigo, int novoAlugado) {
    TransporteList* transporte = head;

    while (transporte != NULL) {
        if (transporte->transport.id == id) {
            // Atualizar os dados do transporte encontrado
            transporte->transport.tipo = novoTipo;
            transporte->transport.carga = novaCarga;
            transporte->transport.custo = novoCusto;
            strcpy(transporte->transport.geocodigo, novoGeocodigo);
            transporte->transport.alugado = novoAlugado;
            return 1; // Retorna 1 para indicar que o transporte foi alterado com sucesso
        }
        transporte = transporte->proximo;
    }

    return 0; // Retorna 0 para indicar que o transporte não foi encontrado
}

/**
 * Altera os dados de um transporte no array de transportes.
 *
 * @brief Esta função altera o ID e o custo de um transporte no array de transportes com base no índice fornecido. Os novos valores
 * de ID e custo são atribuídos ao transporte correspondente. Se o índice fornecido estiver fora do intervalo válido, a
 * função exibirá uma mensagem de erro.
 *
 * @param transportes O array de transportes.
 * @param numTransportes O número atual de transportes no array.
 * @param index O índice do transporte a ser alterado.
 * @param novoID O novo ID a ser atribuído ao transporte.
 * @param novoCusto O novo custo a ser atribuído ao transporte.
 *
 * @pre O parâmetro transportes deve apontar para um array válido de transportes.
 * @pre O parâmetro numTransportes deve apontar para uma variável válida representando o número atual de transportes.
 * @pre O índice fornecido deve estar dentro do intervalo válido de transportes.
 *
 * @post Os dados do transporte são alterados se o índice for válido.
 */
/*
void AlterarTransporte(Transport* transportes, int numTransportes, int index, char* NovoID, float NovoCusto) {
    // Verifica se o índice fornecido está dentro do intervalo válido
    if (index < 0 || index >= numTransportes) {
        //printf("Indice de transporte invalido!\n");
        return;
    }

    // Altera os dados do transporte
    strcpy(transportes[index].id, NovoID);
    transportes[index].custo = NovoCusto;
}
*/

int RegistrarReserva(TransporteList* head, int id, int novaReserva) {
    TransporteList* transporte = head;

    while (transporte != NULL) {
        if (transporte->transport.id == id) {
            // Atualizar o valor da reserva do transporte encontrado
            transporte->transport.alugado = novaReserva;
            return 1; // Retorna 1 para indicar que a reserva foi registrada com sucesso
        }
        transporte = transporte->proximo;
    }

    return 0; // Retorna 0 para indicar que o transporte não foi encontrado
}

/**
 * Registra um aluguel para um transporte.
 *
 * @brief Esta função registra um aluguel para um transporte específico. Se o transporte já estiver alugado, exibirá uma mensagem
 * de erro. Caso contrário, o aluguel é registrado, atualizando o status de aluguel para "alugado" e armazenando a data
 * e hora do registro.
 *
 * @param transporte O transporte a ser registrado o aluguel.
 *
 * @post O status de aluguel do transporte é atualizado se o transporte não estiver alugado.
 */
/*
int RegistrarReserva(Transport* transporte) {
    if (transporte->alugado) {
        //printf("Este transporte já está alugado.\n");
        return -1;
    }
    else {
        // Registra a reserva
        transporte->alugado = 1;
        time_t now;
        time(&now);
        printf("Aluguer registrado para o transporte com ID %s às %s\n", transporte->id, ctime(&now));
    }
}*/

/**
 * Função de comparação para ordenar os transportes por autonomia.
 *
 * @brief Esta função de comparação é usada para ordenar os transportes por autonomia em ordem decrescente. É usada pela função
 * `qsort()` da biblioteca padrão do C.
 *
 * @param v1 O primeiro transporte a ser comparado.
 * @param v2 O segundo transporte a ser comparado.
 *
 * @return Um valor negativo se o primeiro transporte tiver maior autonomia, um valor positivo se o segundo transporte
 *         tiver maior autonomia, ou zero se ambos tiverem a mesma autonomia.
 */
int CompareAutonomia(Transport v1, Transport v2) {
    if (v1.carga > v2.carga) {
        return -1;
    }
    else if (v1.carga < v2.carga) {
        return 1;
    }
    else {
        return 0;
    }
}

// Função para imprimir informações sobre um veículo
void PrintMobility(Transport* t) {
    printf("ID: %s\n", t->id);
    printf("Tipo: %s\n", t->tipo);
    printf("Carga: %.2f\n", t->carga);
    printf("Custo: %.2f\n", t->custo);
    printf("Geocódigo: %s\n", t->geocodigo);
    printf("Alugado: %s\n", t->alugado ? "Sim" : "Não");
    printf("\n");
}

/**
 * Lista os veículos por ordem decrescente de autonomia.
 *
 * @brief Esta função lista os veículos por ordem decrescente de autonomia. Primeiro, os transportes são ordenados usando a função
 * `compareAutonomia()`. Em seguida, são impressas informações sobre cada transporte na ordem classificada.
 *
 * @param transportes O array de transportes.
 * @param numTransportes O número atual de transportes no array.
 *
 * @pre O parâmetro transportes deve apontar para um array válido de transportes.
 * @pre O parâmetro numTransportes deve representar o número atual de transportes no array.
 *
 * @post Os transportes são listados em ordem decrescente de autonomia.
 */
void ListarVeiculosPorAutonomia(Transport* transportes, int numTransportes) {
    // Classifica os veículos por ordem decrescente de autonomia
    qsort(transportes, numTransportes, sizeof(Transport), CompareAutonomia);

    // Imprime informações sobre cada veículo classificado
    for (int i = 0; i < numTransportes; i++) {
        printf("Veículo %d:\n", i + 1);
        printMobility(&transportes[i]);
    }
}


/*
-------------------------------------------------------------return
int addTransporte(Transporte* transportes, int* numtransportes, char* id, char* tipo, float carga, float custo, char* geocodigo) {

    if (*numtransportes < MAX_VEHICLES) {
        Transporte novoTransporte;
        strncpy(novoTransporte.id, id, MAX_VEHICLES);
        strncpy(novoTransporte.tipo, tipo, MAX_VEHICLES);
        novoTransporte.carga = carga;
        novoTransporte.custo = custo;
        strncpy(novoTransporte.geocodigo, geocodigo, MAX_VEHICLES);
        transportes[*numtransportes] = novoTransporte;
        (*numtransportes)++;
        return 1;
    }
    else {
        printf("Não é possível adicionar mais transportes.\n");
        return 0;
    }
}

int removerTransporte(Transporte* transportes, int* numTransportes, char* id) {
    // Encontra o índice do transporte com o ID correspondente
    int indice = -1;
    for (int i = 0; i < *numTransportes; i++) {
        if (strcmp(transportes[i].id, id) == 0) {
            indice = i;
            break;
        }
    }

    // Se o transporte foi encontrado, mova-o para o final do array
    if (indice >= 0) {
        transportes[indice] = transportes[*numTransportes - 1];
        (*numTransportes)--;

        // Libera o espaço ocupado pelo último transporte
        transportes = (Transporte*)realloc(transportes, (*numTransportes) * sizeof(Transporte));

        return 1; // retorna 1 em caso de sucesso
    }
    else {
        printf("Transporte com ID %s não encontrado.\n", id);
        return -1; // retorna -1 em caso de erro
    }
}

int alterarTransporte(Transporte* transportes, int numTransportes, int index, char* NovoID, float NovoCusto) {
    // Verifica se o índice fornecido está dentro do intervalo válido
    if (index < 0 || index >= numTransportes) {
        printf("Indice de transporte invalido!\n");
        return 0;
    }

    // Altera os dados do transporte
    strcpy(transportes[index].id, NovoID);
    transportes[index].custo = NovoCusto;

    return 1;

    
}*/
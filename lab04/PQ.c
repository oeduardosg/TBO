#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"
#include "item.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

void sink(Event ** e, int k, int max){
    while (k * 2 <= max) {
        int j = k * 2;
        if (j < max && compare(e[j + 1], e[j]) < 0){
            j++;
        }
        if (compare(e[k], e[j]) < 0) {
            break;
        }
        exch(e[k], e[j]);
        k = j;
    }
}

void rise(Event ** e, int k) {
    while (k > 1 && compare(e[k/2], e[k]) > 0) {
        exch(e[k], e[k/2]);
        k = k/2;
    }
}

// TODO: Crie a struct pq.
struct pq {
    int max_N;
    int last;
    Event ** array;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.
    PQ * pq = (PQ *) calloc(1, sizeof(PQ));
    pq -> array = (Event **) calloc(max_N, sizeof(Event *));
    pq -> max_N = max_N;
    pq -> last = 0;

return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.
    for(int i = 1; i < pq -> last; i++) {
        destroy_event(pq -> array[i]);
    }
    free(pq -> array);
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.
    if(pq -> last == pq -> max_N) {
        printf("\nMax number of events reached.\n");
        return;
    }

    pq -> last++;
    pq -> array[pq -> last] = e;
    rise(pq -> array, pq -> last);

}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.
    if(pq -> last < 1) return NULL;

    exch(pq -> array[1], pq -> array[pq -> last]);
    Event * min = pq -> array[pq -> last];
    pq -> last--;
    sink(pq -> array, 1, pq -> last);

return min;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.]
    if(pq -> last <= 0) return true;
    else return false;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    // TODO: Implemente essa função.
    return pq -> last;
}

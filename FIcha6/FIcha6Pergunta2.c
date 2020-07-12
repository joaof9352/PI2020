#include <stdlib.h>

typedef struct queue {
    int size; 
    // guarda o tamanho do array valores
    int inicio, tamanho;
    int *valores;
} QUEUE;

void initQueue (QUEUE *q){
    q->valores = malloc(sizeof(int) * 10);
    q->size = 10;
    q->inicio = 0;
    q->tamanho = 0;
}

int isEmptyQ (QUEUE *q){
    return q->tamanho == 0;
}

int enqueue (QUEUE *q, int x){
    if(q->tamanho == q->size){
        realloc(q->valores,2 * q->size * sizeof(int));
        q->size *= 2;
    }

    q->valores[(q->tamanho + q->inicio) % q->size] = x; 
    q->tamanho++;
    return 0;
}

int dequeue (QUEUE *q, int *x){
    if(isEmptyQ(q))
        return 1;
    (*x) = q->valores[q->inicio];
    q->inicio++;
    q->tamanho--;

    if(q->size >= 2*q->tamanho){
        realloc(q->valores,q->size * sizeof(int) / 2);
        q->size /= 2;
    }

    return 0;
}

int front (QUEUE *q, int *x){
    if(isEmptyQ(q))
        return 1;
    
    (*x) = q->valores[q->inicio];
    return 0;
}

int main(){

}
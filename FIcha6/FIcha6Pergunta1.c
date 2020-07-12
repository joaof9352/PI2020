#define MAX 100
typedef struct queue {
    int inicio, tamanho;
    int valores [MAX];
} QUEUE;

void initQueue (QUEUE *q){
    q->inicio = 0;
    q->tamanho = 0;
}

int isEmptyQ (QUEUE *q){
    if(q->tamanho == 0)
        return 1;
    else return 0;
}

int enqueue (QUEUE *q, int x){
    if(q->tamanho == MAX)
        return 1;

    q->valores[(q->tamanho + q->inicio) % MAX] = x; 
    q->tamanho++;
    return 0;
}

int dequeue (QUEUE *q, int *x){
    if(isEmptyQ(q))
        return 1;
    
    (*x) = q->valores[q->inicio];
    q->inicio++;
    q->tamanho--;
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
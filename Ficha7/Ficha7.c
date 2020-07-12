#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} Nodo, *LInt;

// PERGUNTA 1

LInt cons (LInt l, int x){
    LInt init = malloc(sizeof(Nodo));
    init->valor = x;
    init->prox = l;
    return init;
}

LInt tail(LInt l){
    if(!l || !l->prox) return NULL;
    LInt temp = l->prox;
    free(l);
    return temp;
}

LInt init(LInt l){
    if(!l || !l->prox) return NULL;
    LInt ant,temp = l;
    while(temp->prox){
        ant = temp;
        temp = temp->prox;
    }
    ant->prox = NULL;
    free(temp);
    return l;
}

LInt snoc(LInt l, int x){
    LInt temp = l;
    LInt add = malloc(sizeof(Nodo));
    add->valor = x;
    add->prox = NULL;
    while(l && l->prox){
        l = l->prox;
    }
    if(!l) return add;
    else l->prox = add;
    
    return temp; 
}

LInt concat(LInt a, LInt b){
    LInt temp = a;

    while(a && a->prox)
        a = a->prox;
    
    if(!a) return b;
    else a->prox = b;

    return temp;
}

//PERGUNTA 2 -> Para confirmar: https://codeboard.io/projects/155925
typedef struct sAluno{
    char nome[61];
    int numero;
    int nota;
} Aluno;

typedef struct sTurma{
    Aluno aluno;
    struct sTurma* prox;
} *Turma;

Aluno newAluno (char *nome, int numero, int nota){
	Aluno novo;
    strcpy(novo.nome,nome);
    novo.numero = numero;
    novo.nota = nota;
    return novo;
}

Turma vazia () {
	Turma r = NULL;
	return r;
}

int acrescentaAluno (Turma *t, Aluno a){
    Turma add = malloc(sizeof(struct sTurma));
    add->aluno = a;
    add->prox = NULL;
    
    while(*t && (*t)->prox)
        t = &((*t)->prox);

    if(!(*t)) (*t) = add;
    else (*t)->prox = add;

    return 0;
}

Aluno *procura (Turma t, int numero){
    while(t && t->aluno.numero != numero)
        t = t->prox;

    if(!t) return NULL;
    return &(t->aluno);
}

int aprovados (Turma t){
    int count = 0;
    while(t){
        if(t->aluno.nota >= 10)
            count++;
        t = t->prox;
    }
    return count;
}

//Pergunta 3 -> Para confirmar: https://codeboard.io/projects/158904
typedef LInt Stack;

void initStack (Stack *s){
    *s = NULL;
}

int isEmptyS (Stack *s){
    return (*s) == NULL;
}

int push (Stack *s, int x){
    Stack add = malloc(sizeof(Nodo));
    add->valor = x;
    add->prox = (*s);
    (*s) = add;
    return 0;
}

int pop (Stack *s, int *x){
    if(!(*s)) return 1;
    (*x) = (*s)->valor;
    Stack *temp = s;
    (*s) = (*s)->prox;
    return 0;
}

int top (Stack *s, int *x){
    if(!(*s)) return 1;
    (*x) = (*s)->valor;
    return 0;
}

//Pergunta 4


int main(){
    LInt a = malloc(sizeof(Nodo));
    LInt b = malloc(sizeof(Nodo));
    LInt c = malloc(sizeof(Nodo));
    a->valor = 10;
    a->prox = b; b->valor = 5;
    b->prox = c; c->valor = 15;
    c->prox = NULL;
}
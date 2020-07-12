int minusculas (char s[]){
    int i = 0, counter = 0;;
    int dif = 32;
    while(s[i]){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            counter++;
            s[i] -= 32;
        }
        i++;
    }
    return counter;
}

int contalinhas(char s[]){
    int count = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == '\n')
            count++;
    }
    return count;
}

int procura (char *p, char *ps[], int N){
    for(int i = 0; i < N; i++){
        if(strcmp(ps[i],p) == 0)
            return i;
    }
    return -1;
}

#define MAX 100
typedef struct stack {
    int sp;
    int valores [MAX];
} STACK;

void initStack (STACK *s){
    s->sp = 0;
}

int isEmptyS (STACK *s){
    return s->sp == 0;
}

int push (STACK *s, int x){
    if(s->sp > MAX)
        return 1;

    s->valores[s->sp++] = x;
    return 0;
}

int pop (STACK *s, int *x){
    if(isEmptyS(s))
        return 1;

    (*x) = s->valores[--s->sp];
    return 0;
}

int top (STACK *s, int *x){
    if(isEmptyS(s))
        return 1;

    (*x) = s->valores[s->sp - 1];
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int *que;
} Deck;

int InitialIize(Deck *d, int max) {
    
    d->num = d->front = d->rear = 0;
    
    if((d->que = calloc(max, sizeof(int))) == NULL) {
        d->max = 0;
        return -1;
    }
    
    d->max = max;
    return 0;
}

int EnqueFront(Deck *d, int v) {
    
    if(d->num >= d->max)
        return -1;
    
    d->num++;
    if(--d->front < 0)
        d->front = d->max - 1;
    
    d->que[d->front] = v;
    return 0;
}

int EnqueRear(Deck *d, int v) {
    
    if(d->num >= d->max)
        return -1;
    
    d->num++;
    d->que[d->rear++] = v;
    
    d->rear = d->rear % d->max;
    return 0;
}

int DequeFront(Deck *d, int *v) {
    
    if(d->num <= 0)
        return -1;
    
    d->num--;
    *v = d->que[d->front++];
    
    d->front = d->front % d->max;
    return 0;
}

int DequeRear(Deck *d, int *v) {
    
    if(d->num <= 0)
        return -1;
    
    d->num--;
    
    if(--d->rear < 0)
        d->rear = d->max - 1;
    
    *v = d->que[d->rear];
    return 0;
    
}
void Clear(Deck *d) {
    d->num = d->front = d->rear = 0;
}

int Size(Deck *d) {
    return d->num;
}

int IsEmpty(Deck *d) {
    return (d->num <= 0);
}

int PeekFront(Deck *d, int *v) {
    
    if(d->num <= 0)
        return -1;
    
    *v = d->que[d->front];
    return 0;
}

int PeekRear(Deck *d, int *v) {
    int temp;
    
    if(d->num <= 0)
        return -1;
    
    if((temp = d->rear - 1) < 0)
        temp = d->max - 1;
    
    *v = d->que[temp];
    return 0;
}

int Find_Sequence(Deck *d, int v) {
    int index = -1;
    for(int i = 0; i < d->num; i++) {
        
        // 항상 잊지말길. 재조정 과정이 중요하다!!
        if(d->que[index = (i + d->front) % d->max] == v)
            return i;
        
    }
    
    return -1; // 실패
    
}


int N, K;
char com[12];
int temp;
int COUNT;

int main() {
    Deck deck;
    
    scanf("%d %d", &N, &K);
    InitialIize(&deck, N);
    
    for(int i = 1; i <=N; i++) {
        EnqueRear(&deck, i);
    }
    
    
    for(int i = 0; i < K; i++) {
        
        scanf("%d", &temp);
        
        int seq = Find_Sequence(&deck, temp);
        
        if(seq < deck.num - seq) {
            
            while(seq--) {
                DequeFront(&deck, &temp);
                EnqueRear(&deck, temp);
                COUNT++;
            }
            
        } else {
            seq = deck.num - seq;
            while(seq--) {
                DequeRear(&deck, &temp);
                EnqueFront(&deck, temp);
                COUNT++;
            }
        }
        DequeFront(&deck, &temp);
    }
    
    printf("%d\n", COUNT);
}

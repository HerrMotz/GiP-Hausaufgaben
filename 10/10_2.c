/*
 * Datei: 10_2.c
 * Daniel Motz
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int PRIME_LIMIT = 100;

struct dnode{
    int data; struct dnode *next, *prev;
};

struct dnode *mkNode(int val){
    struct dnode *node = NULL;
    if ((node = malloc(sizeof (struct dnode))) != NULL) {
        node->data = val; node->next = node->prev = NULL;
        return node;
    }
    else { perror("Error"); return NULL; }
}


struct dnode *head, *tail;

void insertFirst (int val) {
    struct dnode *new = mkNode(val);
    if (head != NULL) {
        new->next = head;
        head->prev = new;
    }
    if (tail == NULL) {
        tail = new;
    }
    head = new;
}

void delete (int val) {
    struct dnode *p = head, *prev = NULL;
    while (p != NULL && p->data != val) {
        prev = p;
        p = p->next;
    } // p == NULL || p->data == val
    if (p != NULL) { // p->data == val
        if (p == head){
            head = p->next;
        } else if (p == tail) {
            tail = p->prev;
            tail->next = NULL;
        } else {
            prev->next = p->next;
            p->next->prev = prev;
        }
        free(p);
    }
}

void printList(void){
    struct dnode *tmp = head;
    printf("(");
    while(tmp != NULL){
        printf(" %d", tmp->data);
        tmp = tmp->next;
    }
    printf(" )\n");
}

void printListReverse(void){
    struct dnode *tmp = tail;
    printf("(");
    while(tmp != NULL){
        printf(" %d", tmp->data);
        tmp = tmp->prev;
    }
    printf(" )\n");
}

int main(void) {
    /* Sieve of Eratosthenes */
    int n = PRIME_LIMIT;
    int primes[PRIME_LIMIT];

    int * end = &primes[0]+PRIME_LIMIT;
    for (int * i = primes; i != end; ++i) *i = 1;

    for (int p = 2; p * p <= n; p++)
    {
        if (primes[p] == 1)
        {
            for (int i = p * p; i <= n; i += p){
                primes[i] = 0;
            }
        }
    }

    for (int i = PRIME_LIMIT; i >= 0; --i) {
        if (primes[i] == 1 && i >= 2) {
            insertFirst(i);
        }
    }

    printList();

    int value;
    printf("Geben Sie eine zu löschende Zahl aus den oben gegebenen Liste an\n");
    scanf("%d", &value);
    delete(value);

    printList();

    printf("Geben Sie eine am Anfang einzufügende Zahl ein\n");
    scanf("%d", &value);
    insertFirst(value);

    printListReverse();
    printList();

    return EXIT_SUCCESS;
}
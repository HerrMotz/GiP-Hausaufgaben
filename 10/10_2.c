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

void insertLast (int val) {
    struct dnode *new = mkNode(val);
    if (head == NULL) {
        head = new;
    } else {
        tail->next = new;
        new->prev = tail;
    }
    tail = new;
}

void insertFirst (int val) {
    struct dnode *new = mkNode(val);
    new->next = head;
    head->prev = new;
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

    for (int i = 0; i <= PRIME_LIMIT; i++) {
        if (primes[i] == 1 && i >= 2) {
            insertLast(i);
        }
    }

    printList();

    delete(17);

    printListReverse();

    insertFirst(0);

    printListReverse();

    return EXIT_SUCCESS;
}
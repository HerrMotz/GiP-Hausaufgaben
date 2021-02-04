#include <stdio.h>
#include <stdlib.h>

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

void delete (int val) {
    struct dnode *p = head, *prev = NULL;
    while (p != NULL && p->data != val) {
        prev = p;
        p = p->next;
    } // p == NULL || p->data == val
    if (p != NULL) { // p->data == val
        if (p == head) {
            head = p->next;

        } else {
            prev->next = p->next;
        }
        free(p);
    }
}

void insertFirst (int val) {
    struct dnode *p = mkNode(val);
    if (head != NULL) {
        p->next = head;
        head->prev = p;
    }
    head = p;
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

int main(void) {
    //Berechnung der Primzahlen bis 100
    //Array mit Zahlen von 2 bis 100:
    int eratosthenes[99];
    for (int i = 2; i <= 100; i++) {
        eratosthenes[i - 2] = i;
    }
    //Alle nicht-primen Zahlen werden auf 0 gesetzt (Sieb des Eratosthenes):
    for (int i = 0; i < 99; i++) {
        if (eratosthenes[i] != 0) {
            //Vielfache der aktuellen Zahl eratosthenes[i] auf 0 setzen
            for (int j = i + 1; j < 99; j++) {
                if (eratosthenes[j] % eratosthenes[i] == 0) eratosthenes[j] = 0;
            }
        }
    }
    for (int i = 99; i > 0; i--) {
        if (eratosthenes[i] != 0) {
            insertFirst(eratosthenes[i]);
        }
    }
    //Aus irgendeinem Grund ist die 2 nicht in meiner Liste (obwohl ich prinzipiell den selben Code wie in HA 8 verwende und sie da natürlich drin ist).
    //Deswegen füge ich die 2 so ein.
    //insertFirst(2);
    printList();
    printf("Welche Zahl soll geloescht werden?");
    int zahl;
    scanf("%d", &zahl);
    delete(zahl);
    printList();
    return 0;
}
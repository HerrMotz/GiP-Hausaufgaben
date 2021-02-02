#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool self_assert(char name[], int b1, int b2) {
    printf("[self assert] Test ");
    if (b1 == b2) {
        printf("successful! %s\n", name);
        return true;
    } else {
        printf("failed. %s\n", name);
        return false;
    }
}

const char brackets[] = {
        '(', ')',
        '[', ']',
        '{', '}'
};

const int amount_brackets = sizeof(brackets)/sizeof(char);

struct node {
    int data;
    struct node *next;
};

struct node *mkNode(int val){
    struct node *node = NULL;
    if((node = malloc(sizeof (struct node))) != NULL){
        node->data = val;
        node->next = NULL;
        return node;
    } else {
        perror("mkNode Null");
        return NULL;
    }
}

struct node *top = NULL;

void push(int x){
    struct node *p = mkNode(x);
    p->next = top;
    top = p;
}

int pop(void){
    if(top == NULL) perror("Pop Null");
    int result = top->data;
    struct node *p = top;
    top = top->next;
    free(p);
    return result;
}

int peek(void){
    if(top == NULL) {
        return 0;
    }
    return top->data;
}

bool empty(void) {return top == NULL;}

void clear() {
    while (!empty()) {
        pop();
    }
}

int findBracket(char value) {
    for (int i = 0; i < amount_brackets; ++i) {
        if (value == brackets[i]) {
            return i;
        }
    }

    return -1;
}

int isOpenBracket(char value) {
    int position = findBracket(value);
    if (position != -1 && position % 2 == 0) {
        return 1;
    }
    return 0;
}

int isClosingBracket(char value) {
    int position = findBracket(value);
    if (position != -1 && position % 2 == 1) {
        return 1;
    }
    return 0;
}

char getOpenBracket(char value) {
    int position = findBracket(value);
    return brackets[position-1];
}

void printWarn(char*expression, int position, bool verbose) {
    if (!verbose) return;

    printf("fehlerhafte Klammerung:\n%s\n", expression);
    for (int k = 0; k < position; ++k) {
        printf(" ");
    }
    printf("^\n");
}

int validateExpression(char *expression, bool verbose) {
    int i;
    for (i = 0; expression[i] != '\0'; ++i) {
        if (isOpenBracket(expression[i])) {
            push(expression[i]);

        } else if (isClosingBracket(expression[i])) {
            if (empty() || peek() != getOpenBracket(expression[i])){
                printWarn(expression, i, verbose);
                clear();
                return 0;
            } else if (peek() == getOpenBracket(expression[i]))
                pop();

        }
    }
    if (!empty()) {
        // Fehlende Klammer am Ende
        printWarn(expression, i, verbose);
        clear();
        return 0;
    }
    clear();
    return 1;
}

int main(void){
    // Sonst steht in *top noch ein Wert
    push(0);
    pop();

    self_assert("(n) No braces", validateExpression("", false), true);
    self_assert("(n) No braces but value", validateExpression("12", false), true);
    self_assert("(n) Wrong order", validateExpression("(([[)]", false), false);
    self_assert("(n) Open end", validateExpression("(([", false), false);
    self_assert("(n) No open", validateExpression("))", false), false);
    self_assert("(n) Only one closing bracket", validateExpression("]", false), false);
    self_assert("(n) One pair with trailing closing", validateExpression("{}}", false), false);
    self_assert("(p) Valid with all brackets", validateExpression("([{}])", false), true);
    self_assert("(p) Only one pair", validateExpression("{}", false), true);

    char expression[41];
    printf("\nEnter an expression you would like to validate:\n");
    fgets(expression, 41, stdin);
    strtok(expression, "\n");

    validateExpression(expression, true);

    return EXIT_SUCCESS;
}
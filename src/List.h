#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Record.h"


typedef struct Node {
    Record value;
    struct Node *next;
} Node;


void push(Node **head, Record data) { /
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}


void pop(Node **head) { 
    Node* prev = NULL;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}


Node* getNth(Node* head, int n) { 
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}



Node* getLast(Node *head) { 
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}


void pushBack(Node *head, Record value) { 
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}


Node* getLastButOne(Node* head) { 
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}		




void popBack(Node **head) { 
    Node *lastbn = NULL;
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    //Если в списке один элемент
    if (lastbn == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(lastbn->next);
        lastbn->next = NULL;
    }
}


void insert(Node *head, unsigned n, Record val) { 
    unsigned i = 0;
    Node *tmp = NULL;
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value = val;
 
    if (head->next) {
        tmp->next = head->next;
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}


void deleteNth(Node **head, int n) { 
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
 
        prev->next = elm->next;
        free(elm);
    }
}



int Count(const Node *head){
	int counter = 0;
    while (head) {
    	counter++;
        head = head->next;
    }
    return counter;
}

void printList(const Node *head) {
	int counter = 0;
    while (head) {
    	counter++;
        printf("%i: %s | %s | %s | %s | %s | %s\n", counter, head->value.work, head->value.student, head->value.variant, head->value.level, head->value.date, head->value.mark); 
        head = head->next;
    }
    printf("\n");
}
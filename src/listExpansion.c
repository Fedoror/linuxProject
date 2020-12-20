#include "List.h"


void push(Node **head, Expense data);

void pop(Node **head);

Node* getNth(Node* head, int n);

Node* getLast(Node *head);

void pushBack(Node *head, Expense value);

Node* getLastButOne(Node* head);

void popBack(Node **head);

void insert(Node *head, unsigned n, Expense val);

void deleteNth(Node **head, int n);

int count(const Node *head);

void printList(const Node *head);


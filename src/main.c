#include "mainFunctions.h"






int main() {
    Node* head = NULL;
    Expense expense;
    strcpy(expense.product, "Product");
    strcpy(expense.price, "13");
    strcpy(expense.quantity, "10");
    strcpy(expense.date, "22-22-2222");
    push(&head, expense);
    run(head);
}
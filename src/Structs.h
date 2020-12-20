

typedef struct Expense {
    char product[40];
    char price[10];
    char quantity[10];
    char date[20];
} Expense;


typedef struct Node {
    Expense value;
    struct Node *next;
} Node;
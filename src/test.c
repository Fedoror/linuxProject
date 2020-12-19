
#include "../Unity/src/unity.c"
#include <string.h>
#include "List.h"



void pushTest()
{
    Node* head = NULL;
    Expense expense;
    strcpy(expense.product, "Product");
    strcpy(expense.price, "13");
    strcpy(expense.quantity, "10");
    strcpy(expense.date, "22-22-2222");

    push(&head, expense);

    TEST_ASSERT_EQUAL_STRING("Product", head->value.product);
    TEST_ASSERT_EQUAL_STRING("13", head->value.price);
    TEST_ASSERT_EQUAL_STRING("22-22-2222", head->value.date);
}


void countTest(){
    Node* head = NULL;
    Expense expense;
    strcpy(expense.product, "Product");
    strcpy(expense.price, "13");
    strcpy(expense.quantity, "10");
    strcpy(expense.date, "22-22-2222");

    push(&head, expense);
    TEST_ASSERT_EQUAL_INT(1, count(head));
    push(&head, expense);
    push(&head, expense);
    TEST_ASSERT_EQUAL_INT(3, count(head));
    push(&head, expense);
    push(&head, expense);
    TEST_ASSERT_EQUAL_INT(5, count(head));
}


void deleteTest(){
    Node* head = NULL;
    Expense expense;
    strcpy(expense.product, "Product");
    strcpy(expense.price, "13");
    strcpy(expense.quantity, "10");
    strcpy(expense.date, "22-22-2222");

    push(&head, expense);
    push(&head, expense);
    push(&head, expense);
    push(&head, expense);
    TEST_ASSERT_EQUAL_INT(4, count(head));
    push(&head, expense);
    TEST_ASSERT_EQUAL_INT(5, count(head));

    TEST_ASSERT_EQUAL_STRING("Product", getNth(head, 2)->value.product);

    pop(&head);
    pop(&head);
    popBack(&head);
    TEST_ASSERT_EQUAL_INT(2, count(head));
}


void getNthTest(){
    Node* head = NULL;
    Expense expense;
    strcpy(expense.product, "Product");
    strcpy(expense.price, "13");
    strcpy(expense.quantity, "10");
    strcpy(expense.date, "22-22-2222");

    push(&head, expense);
    strcpy(expense.product, "potato");
    push(&head, expense);
    TEST_ASSERT_EQUAL_STRING("potato", getNth(head, 0)->value.product);
    push(&head, expense);
    push(&head, expense);
    strcpy(expense.product, "banana");
    push(&head, expense);
    TEST_ASSERT_EQUAL_STRING("potato", getNth(head, 2)->value.product);

}


void insertTest(){
    Node* head = NULL;
    Expense expense;
    strcpy(expense.product, "Product");
    strcpy(expense.price, "13");
    strcpy(expense.quantity, "10");
    strcpy(expense.date, "22-22-2222");

    push(&head, expense);
    strcpy(expense.product, "product2");
    push(&head, expense);
    strcpy(expense.product, "product3");
    push(&head, expense);
    strcpy(expense.product, "product4");
    insert(head, 2, expense);

    TEST_ASSERT_EQUAL_STRING("product2", getNth(head, 1)->value.product);
}




void setUp(){}
void tearDown() {}


int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(pushTest);
    RUN_TEST(countTest);
    RUN_TEST(deleteTest);
    RUN_TEST(getNthTest);
    RUN_TEST(insertTest);

    return UNITY_END();
}

#include "Unity/src/unity.c"
#include <string.h>
#include "list.h"



void pushTest()
{
    Node* head = NULL;
    Record record;
    strcpy(record.student, "student_name");
    strcpy(record.work, "work");
    strcpy(record.mark, "52");
    strcpy(record.date, "28-04-2002");
    strcpy(record.variant, "4");
    strcpy(record.level, "10");

    push(&head, record);

    TEST_ASSERT_EQUAL_STRING("student_name", head->value.student);
    TEST_ASSERT_EQUAL_STRING("work", head->value.work);
    TEST_ASSERT_EQUAL_STRING("28-04-2002", head->value.date);
}


void countTest(){
    Node* head = NULL;
    Record record;
    strcpy(record.student, "student_name");
    strcpy(record.work, "work");
    strcpy(record.mark, "52");
    strcpy(record.date, "28-04-2002");
    strcpy(record.variant, "4");
    strcpy(record.level, "10");

    push(&head, record);
    TEST_ASSERT_EQUAL_INT(1, getLength(head));
    push(&head, record);
    push(&head, record);
    TEST_ASSERT_EQUAL_INT(3, getLength(head));
    push(&head, record);
    push(&head, record);
    TEST_ASSERT_EQUAL_INT(5, getLength(head));
}


void deleteTest(){
    Node* head = NULL;
    Record record;
    strcpy(record.student, "student_name");
    strcpy(record.work, "work");
    strcpy(record.mark, "52");
    strcpy(record.date, "28-04-2002");
    strcpy(record.variant, "4");
    strcpy(record.level, "10");

    push(&head, record);
    push(&head, record);
    push(&head, record);
    push(&head, record);
    TEST_ASSERT_EQUAL_INT(4, getLength(head));
    push(&head, record);
    TEST_ASSERT_EQUAL_INT(5, getLength(head));

    TEST_ASSERT_EQUAL_STRING("student_name", getNth(head, 2)->value.student);


    pop(&head);
    pop(&head);
    popBack(&head);
    TEST_ASSERT_EQUAL_INT(2, getLength(head));
}


void getNthTest(){
    Node* head = NULL;
    Record record;
    strcpy(record.student, "student1");
    strcpy(record.work, "work");
    strcpy(record.mark, "52");
    strcpy(record.date, "28-04-2002");
    strcpy(record.variant, "4");
    strcpy(record.level, "10");

    push(&head, record);
    strcpy(record.student, "student2");
    push(&head, record);
    TEST_ASSERT_EQUAL_STRING("student2", getNth(head, 0)->value.student);
    strcpy(record.student, "student3");
    push(&head, record);
    strcpy(record.student, "student4");
    push(&head, record);

    TEST_ASSERT_EQUAL_STRING("student2", getNth(head, 2)->value.student);

}


void insertTest(){
    Node* head = NULL;
    Record record;
    strcpy(record.student, "student1");
    strcpy(record.work, "work");
    strcpy(record.mark, "52");
    strcpy(record.date, "28-04-2002");
    strcpy(record.variant, "4");
    strcpy(record.level, "10");

    push(&head, record);
    strcpy(record.student, "student2");
    push(&head, record);
    strcpy(record.student, "student3");
    push(&head, record);
    strcpy(record.student, "student4");
    insert(head, 2, record);

    TEST_ASSERT_EQUAL_STRING("student2", getNth(head, 1)->value.student);
}





void setUp(){}

void tearDown(){}

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
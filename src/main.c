#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "logic.h"






int main() {
    Node* head = NULL;

    Record record;
    strcpy(record.student, "cdc");
    strcpy(record.work, "cdc");
    strcpy(record.mark, "cdc");
    strcpy(record.date, "cdc");
    strcpy(record.variant, "cdc");
    strcpy(record.level, "cdc");
    push(&head, record);
    

    mainloop(head);
}
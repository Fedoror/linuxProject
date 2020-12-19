#include "List.h"


void clearScanf(){
	while (getchar() != '\n');
}


void saveDB(const Node* head){
	printf("Enter path: ");
	char path[300];
	scanf("%299s", path);
	clearScanf();
	FILE *file;

	if((file = fopen(path, "w"))==NULL)
    {
        printf("Error open file\n");
    }
    else{
    	char recordingData[110] = "";

    	while (head) {
    		strcpy(recordingData, "");
    		strcat(recordingData, head->value.product);
	    	strcat(recordingData, ";");
	    	strcat(recordingData, head->value.price);
	    	strcat(recordingData, ";");
	    	strcat(recordingData, head->value.quantity);
	    	strcat(recordingData, ";");
	    	strcat(recordingData, head->value.date);
	    	strcat(recordingData, "\n");
	    	fputs(recordingData, file);
		    head = head->next;
    	}
    	
    	
    	printf("Data base was saved\n");
    	fclose(file);
    }
}


void openDB(Node* head){
	printf("Enter file path: ");
	char path[300];
	scanf("%299s", path);
	clearScanf();
	FILE *file;

	if((file = fopen(path, "r"))==NULL)
    {
        printf("Error open file\n");
    }
    else{
    	char text[256];

    	Node* newList = NULL;


    	

    	char product[40];
    	char price[10];
    	char quantity[10];
    	char date[20];
	   	strcpy(product, "");
		strcpy(price, "");
		strcpy(quantity, "");
		strcpy(date, "");

    	int nowField = 1;
    	int counter = 0;
	    while((fgets(text, 256, file))!=NULL)
	    {

	    	for (int i = 0; i < strlen(text); i++){

		    	if (text[i] == ';'){
		    		nowField++;
		    		counter = 0;
		    	}
		    	else if (text[i] == '\n'){
		    		Expense expense;
		    		strcpy(expense.product, product);
		    		strcpy(expense.price, price);
		    		strcpy(expense.quantity, quantity);
		    		strcpy(expense.date, date);

		    		strcpy(product, "");
		    		strcpy(price, "");
		    		strcpy(quantity, "");
		    		strcpy(date, "");

		    		push(&newList, expense);
		    		counter = 0;
		    		nowField = 1;
		    	}
		    	else{
		   
		    		if (nowField == 1)
		    			product[counter] = text[i];
		    		else if (nowField == 2)
		    			price[counter] = text[i];
		    		else if (nowField == 3)
		    			quantity[counter] = text[i];
		    		else if (nowField == 4)
		    			date[counter] = text[i];
		    		counter++;
		    	}

	    	}

	    }

	  
	    *head = *newList;
	    fclose(file);
    }
}

void delete(Node* head){
	printf("Input record id: ");
	int elId;
	scanf("%i", &elId);
	clearScanf();
	if (elId <= 0 || count(head) <= elId)
		printf("Element was not found\n");
	else{
		printf("Element was deleted\n");
		deleteNth(&head, elId);
	}
}



void refactor(Node* head){
	printf("Input record id: ");
	int index;
	scanf("%i", &index);
	clearScanf();
	if (index < 1 || count(head) <= index){
		printf("Record was not found\n");
	}
	else{
		printf("Input column number(1-4): ");
		scanf("%i", &index);
		clearScanf();
		if (index < 1 || index > 4)
			printf("Column was now found\n");
		else{
			printf("Input new value: ");
			Node *node = getNth(head, index - 1);
			Expense expense;
			strcpy(expense.product, node->value.product);
		    strcpy(expense.price, node->value.price);
		    strcpy(expense.quantity, node->value.quantity);
		    strcpy(expense.date, node->value.date);

			switch (index){
				case 1:
					scanf("%39s", expense.product);
					break;
				case 2:
					scanf("%9s", expense.price);
					break;
				case 3:
					scanf("%9s", expense.quantity);
					break;
				case 4:
					scanf("%19s", expense.date);
					break;
			}
			deleteNth(&head, index);
			insert(head, index, expense);
			printf("Greate!\n");
		}
	}
}


void add(Node* head){

	Expense expense;
	printf("Product name: ");
	scanf("%39s", expense.product);
	clearScanf();

	printf("Price: ");
	scanf("%9s", expense.price);
	clearScanf();

	printf("Quantity: ");
	scanf("%9s", expense.quantity);
	clearScanf();

	printf("date: ");
	scanf("%19s", expense.date);
	clearScanf();

	printf("Record was add!\n");

	pushBack(head, expense);
}




void run(Node* head){

	while (1) {
	    printf("\n");
	    printf("\n");
	    printf("\n");
	    printf("\n");
	    printf("\n");
	    printf("\n");
	    printf("\n");
	    printf("Comands: \n" );
	    printf("add - add record\n");
	    printf("refactor - edir record\n");
	    printf("delete - delete record; \n");
	    printf("save - save to file; \n");
	    printf("open - импорт базы данных \n");
	    printf("exit - выход из программы \n");
	    printf("\n");
	    printList(head);
		printf("Команда: ");
		char comand[30];
		scanf("%29s", comand);
		clearScanf();
		
		

		if (strcmp(comand, "add") == 0)
			add(head);
		else if (strcmp(comand, "refactor") == 0)
			refactor(head);
		else if (strcmp(comand, "delete") == 0)
			delete(head);
		else if (strcmp(comand, "save") == 0)
			saveDB(head);
		else if (strcmp(comand, "open") == 0)
			openDB(head);
		else if (strcmp(comand, "exit") == 0)
			exit(1);
		else
			printf("Comand was not found\n");
	}
}
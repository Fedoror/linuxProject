#include "list.h"



void clearBuffer(){
	while (getchar() != '\n');
}

void printDB(Node* head){
	printf("Практические работы | Студенты | Варианты | Уровни | Даты | Оценки\n");
	printList(head);
}

void update(){
	printf("\n");
	system("clear");
    printf("Режимы работы: " );
    printf("a - Добавить запись; ");
    printf("r - изменить запись; ");
    printf("d - удалить запись; ");
    printf("s - сохранить в файл; ");
    printf("o - импорт базы данных ");
    printf("e - выход из программы\n");
}




void saveDB(Node* head){
	printf("Введите путь к файлу для сохранения: ");
	char path[300];
	scanf("%299s", path);
	clearBuffer();
	FILE *file;

	if((file = fopen(path, "w"))==NULL)
    {
        printf("Файл не удалось открыть\n");
    }
    else{
    	char separator[1];
    	separator[0] = ';';
    	while (head) {
    		fputs(head->value.work, file);
    		fputs(separator, file);
    		fputs(head->value.student, file);
    		fputs(separator, file);
    		fputs(head->value.variant, file);
    		fputs(separator, file);
    		fputs(head->value.level, file);
    		fputs(separator, file);
    		fputs(head->value.date, file);
    		fputs(separator, file);
    		fputs(head->value.mark, file);
    		fputs(separator, file);
    		fputs(head->value.variant, file);
    		fputs("\n", file);
		    head = head->next;
    	}
    	
    	printf("База данных сохранена\n");
    	fclose(file);
    }
}


void openDB(Node* head){
	printf("Введите путь к файлу: ");
	char path[300];
	scanf("%299s", path);
	clearBuffer();
	FILE *file;

	if((file = fopen(path, "r"))==NULL)
    {
        printf("Файл не удалось открыть\n");
    }
    else{
    	char text[256];

    	Node* newList = NULL;
    	char separator = ';';

    	char work[35] = "";
    	char student[35] = "";
    	char variant[5] = "";
    	char modificator[5] = "";
    	char level[5] = "";
    	char date[10] = "";
    	char mark[5] = "";

    	int nowField = 1;
   
	    while((fgets(text, 256, file))!=NULL)
	    {

	    	for (int i = 0; i < strlen(text); i++){

		    	if (text[i] == separator)
		    		nowField++;
		    	else if (text[i] == '\n'){

		    		Record record;
		    		strcpy(record.work, work);
		    		strcpy(record.student, student);
		    		strcpy(record.variant, modificator);
		    		strcpy(record.level, level);
		    		strcpy(record.date, date);
		    		strcpy(record.mark, mark);

		    		strcpy(work, "");
		    		strcpy(student, "");
		    		strcpy(variant, "");
		    		strcpy(level, "");
		    		strcpy(date, "");
		    		strcpy(mark, "");
		    		strcpy(modificator, "");

		    		push(&newList, record);
		    		nowField = 1;
		    	}
		    	else{
		    		char crutch[1];
		    		crutch[0] = text[i];
		    		if (nowField == 1)
		    			strcat(work, crutch);
		    		else if (nowField == 2)
		    			strcat(student, crutch);
		    		else if (nowField == 4)
		    			strcat(level, crutch);
		    		else if (nowField == 5)
		    			strcat(date, crutch);
		    		else if (nowField == 6)
		    			strcat(mark, crutch);
		    		else if (nowField == 7)
		    			strcat(modificator, crutch);
		    		printf("%i", nowField);
		    	}

	    	}

	    }

	    deleteNth(&newList, 0);
	    *head = *newList;

	    fclose(file);
    }
}

void delete(Node* head){
	// printf("Введите номер записи: ");
	// int elId;
	// scanf("%i", &elId);
	// if (getLength(head) < elId)
	// 	printf("Элемент не найден \n");
	// else{
	// 	printf("Элемент удален\n");
	// 	deleteNth(&head, elId);
	// }
}

void refactor(Node* head){
	printf("Введите номер записи: ");
	int index;
	scanf("%i", &index);
	clearBuffer();
	if (getLength(head) < index){
		printf("Элемент не найден\n");

	}
	else{
		Record record = getNth(head, index - 1)->value;
		printf("Введите номер столбца: ");
		scanf("%i", &index);
		clearBuffer();
		if (index < 1 || index > 6)
			printf("Столбец не найден\n");
		else{
			printf("Введите новое значение: ");
			switch (index){
				case 1:
					scanf("%35s", record.work);
					break;
				case 2:
					scanf("%35s", record.student);
					break;
				case 3:
					scanf("%5s", record.variant);
					break;
				case 4:
					scanf("%5s", record.level);
					break;
				case 5:
					scanf("%10s", record.date);
					break;
				case 6:
					scanf("%5s", record.mark);
					break;
			}
			printf("Элемент отредактирован\n");
		}
	}
}


void add(Node* head){

	Record record;
	printf("Введите название работы(35 символов): ");
	scanf("%34s", record.work);
	clearBuffer();

	printf("Введите имя студента(35 символов): ");
	scanf("%34s", record.student);
	clearBuffer();

	printf("Введите номер варианта(5 символов): ");
	scanf("%4s", record.variant);
	clearBuffer();

	printf("Введите номер уровня(5 символов): ");
	scanf("%4s", record.level);
	clearBuffer();

	printf("Введите дату(10 символов): ");
	scanf("%9s", record.date);
	clearBuffer();


	printf("Введите оценку(10 символов): ");
	scanf("%4s", record.mark);
	clearBuffer();

	update();
	printDB(head);
	printf("Запись добавлена!\n");

	pushBack(head, record);
}


void mainloop(Node* head){

	char comand = '~'; 
	while (1) {
		update();
		printDB(head);
		
		switch (comand) {
			case 'a':
				add(head);
				break;
			case 'r':
				refactor(head);
				break;
			case 'd':
				delete(head);
				break;
			case 's':
				saveDB(head);
				break;
			case 'o':
				openDB(head);
				break;
			case 'e':
				exit(1);
				break;
			case '~':
				break;
			default:
				printf("Команда не найдена\n");
				break;
		}
		printf("Команда: ");
		scanf("%c", &comand);
		clearBuffer();
	}
}
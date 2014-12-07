#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MainMenu.h"
//#include "StudentMenu.h"
#include "LibrarianMenu.h"


int LibMenu()
{
	int menu;
	INFO data[MAX];

	while (1){

		printf("Librarian Function\n");
		printf("1. Add book\n2. Update book\n3. Delete book\n0. Exit\n\nINPUT: ");
		scanf("%d", &menu);
		switch (menu)
		{
		
		case 1:
			AddBook(data);
			Save_File(data);
			break;
		case 2:
			UpdateBook(data);  
			break;

		case 3:
			DeleteBook(data);
			break;

		case 0:
			printf("Exit\n\n");
			return;
		
		default:
			printf("Wrong Number.\n\n");
			system("pause");
			system("cls");
			LibMenu();
		}
	}
}

int LibLogin()//�缭 �α���
{
   int psw;
   printf("Insert password\n");
   printf("pw:");
   scanf("%d",&psw);

   if(psw==1234){
      system("cls");
      return 0;}
   else
      return 1;

}


void AddBook(INFO book[])//�߰�
{
		printf("Title: ");
		scanf("%s",&book[num].Title);
		printf("Author: ");
		scanf("%s",&book[num].Author);
		printf("Publisher:");
		scanf("%s",&book[num].Publisher);
		printf("ISBN: ");
		scanf("%s",&book[num].ISBN);
		printf("Availability: ");
		scanf("%d",&book[num].Avail);         
		num++; 
}

void Save_File(INFO book[]) //���� ���� �Լ�
{
	FILE * fp = fopen("bookinfo.txt","at");
	int i;
	fprintf(fp, "%d\t", num);

	fprintf(fp, "%s %s %s %s %d \n", book[num-1].Title,book[num-1].Author, book[num-1].Publisher, book[num-1].ISBN, book[num-1].Avail);
	
	printf("Success!\n");
	fclose(fp);
}





void Delete_File(INFO book[]) //���� ���� �Լ�
{
	int i;
	
	FILE * fp = fopen("bookinfo.txt","at");
	for (i = 0; i<num; i--)
	{
		fprintf(fp, "%s %s %s %s %d \n", book[i].Title,book[i].Author, book[i].Publisher, book[i].ISBN, book[i].Avail);
	}
	printf("Success!\n");
	fclose(fp);

/*
	int i;
	
	FILE * fp = fopen("bookinfo.txt","at");
	for (i = 0; i<num; i--)
	{
		fprintf(fp, "%s %s %s %s %d \n", book[i].Title,book[i].Author, book[i].Publisher, book[i].ISBN, book[i].Avail);
	}
	band=num;
	printf("Success!\n");
	fclose(fp);
*/

}

/*
void find_book_name(void)
{	char *p=NULL;
	char buff[100] = {0};
	char answer;
	char possible;
	INFO *book = NULL;
	printf("�������� �Է��ϼ��� : ");
	gets(buff);
	if(strlen(buff) == 0)
	{
		printf("\n�������� �Է��ϼ���!\n");
		return;
	}
	set_book_head();
	book = book_head;
	book_find = NULL;
		while(book)
	{
		p=strstr(book->name, buff);
		if(p)
		{
			book_find = book;
			printf("\n������ : ");
			puts(book_find->name);
			printf("���ǻ� : ");
			puts(book_find->publisher);
			printf("���ڸ� : ");
			puts(book_find->author);
			printf("ISBN : ");
			puts(book_find->ISBN);
			
			printf("�˻��� ��� �Ͻðڽ��ϱ�? (y/n)\n");
			scanf("%c", &answer);
			getchar();
		
		}
			
		if(answer == 'n' || answer == 'N')
			break;
		
		book = book->next;
	}
	if(book_find == NULL)
	{
		printf("\n\n%s �� å ��Ͽ��� ã�� �� �����ϴ�.\n\n", buff);
	}
}
*/







void Search_title_lib(INFO book[])//�����Ҷ� å ���� �˻�
{
	int i;int ret;
	char find[30];
	//FILE * fp = fopen("bookinfo.txt","rt");
	printf("Search book\n\n");
	printf("Insert Title: ");
	scanf("%s", &find);
	/*
	for(i=0;i<num;i++)
	{
		ret=fscanf(fp, "%c",book[i].Title);
		printf("%s",book[i].Title);
		if(ret==EOF)
			break;
		if(ret==find)
		{
			printf("Search book Result\n");
			printf("Title: %d\nAuthor: %s\nPublisher: %s\nISBN: %s \nAvailability: %d\nRenting Student: %d\n"
				, book[i].Title, book[i].Author, book[i].Publisher, book[i].ISBN,book[i].Avail,book[i].RentStu);
			printf("undate found");
		}
	}
	*/
	////////////////////////////////////////////////////
	/*
	for (i = 0; i<num; i++)
	{
		if(strcmp(book[i].Title,find)==0)
		{
			printf("Search book Result\n");
			printf("Title: %d\nAuthor: %s\nPublisher: %s\nISBN: %s \nAvailability: %d\nRenting Student: %d\n"
				, book[i].Title, book[i].Author, book[i].Publisher, book[i].ISBN,book[i].Avail,book[i].RentStu);

			return;
		}
		printf("Not Found!\n");
	}
	*/
	
}



void DeleteBook(INFO book[])//����
{   
	int num, i=0, j,dnum = 0;
	INFO data[MAX];
	char find[30];
	int ibnnum;
	
	printf("Delete book\n\n");
	//Search_title_lib(data);
	printf("Insert ISBN");
	scanf("%s",&find);
	for (j = 0; j<i; j++){
		if (book[i].Avail == 1 && book[i].ISBN==ibnnum){
			strcpy(book[i].Title,"0");
			strcpy(book[i].Author,"0");
			strcpy(book[i].Publisher,"0");
			strcpy(book[i].ISBN,"0");
			
			num--;
			printf("Success!\n");
			return;
		}
	}
}


void UpdateBook(INFO book[])
{
	INFO data[MAX];
	char find[30];
	
	printf("Update book\n\n");
	Search_title_lib(data);
	printf("Insert ISBN");
	scanf("%s",&find);
	//////////////�̿ϼ�//////////
}



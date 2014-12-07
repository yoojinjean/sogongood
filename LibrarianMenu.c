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
			return 0;
		
		default:
			printf("Wrong Number.\n\n");
			system("pause");
			system("cls");
			LibMenu();
		}
	}
}

int LibLogin()//사서 로그인
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


void AddBook(INFO book[])//추가
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

void Save_File(INFO book[]) //파일 저장 함수
{
	int i;
	
	FILE * fp = fopen("bookinfo.txt","a");
	fprintf(fp, "%d\n", num);
	for (i = 0; i<num; i++)
	{
		fprintf(fp, "%s %s %s %s %d \n",book[i].Title,book[i].Author, book[i].Publisher, book[i].ISBN, book[i].Avail);
	}
	printf("Success!\n");
	system("cls");
	fclose(fp);
}


void Search_title_lib(INFO book[])//삭제할때 책 제목 검색
{
	int i;
	char find[30];
	//int ret;
	//num=fscanf(fp, "%d\n",num);

	FILE * fp = fopen("bookinfo.txt","rt");
	printf("Search book\n\n");

	
	for(i=0; i < num; i++)
		fscanf(fp, "%s\n",book[i].Title);

	printf("Insert Title: ");
	scanf("%s", find);
	
	////////////////////////////////////////////////////
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
	
}



void DeleteBook(INFO book[])//삭제
{
	int num, i, j,dnum = 0;
	INFO data[MAX];
	char find[30];
	
	printf("Delete book\n\n");
	Search_title_lib(data);
	printf("Insert ISBN:");
	scanf("%s",find);
	for (j = 0; j<i; j++){
		if (book[i].Avail == 1 && strcmp(book[i].ISBN,find)==0){
			strcpy(book[i].Title,"0");
			strcpy(book[i].Author,"0");
			strcpy(book[i].Publisher,"0");
			strcpy(book[i].ISBN,"0");
			
			num--;
			printf("Success!\n");
			system("cls");
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
	printf("Insert ISBN:");
	scanf("%s",&find);
	//////////////미완성//////////
}



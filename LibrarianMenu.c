#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MainMenu.h"
//#include "StudentMenu.h"
#include "LibrarianMenu.h"

<<<<<<< HEAD
 
=======

>>>>>>> origin
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
<<<<<<< HEAD
			return;
		
		default:
			printf("Wrong Number.\n\n");
=======
			return 0;
		
		default:
			printf("Wrong Number.\n\n");
			system("pause");
			system("cls");
			LibMenu();
>>>>>>> origin
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
<<<<<<< HEAD
		scanf("%d",&book[num].Avail);         
		printf("삽입되었습니다.\n\n");
		num++; 
		//Save_File(book[num]);
=======
		scanf("%d",&book[num].Avail);
		num++; 
>>>>>>> origin
}

void Save_File(INFO book[]) //파일 저장 함수
{
	int i;
<<<<<<< HEAD
	FILE * fp = fopen("bookinfo.txt","at");
//	fprintf(fp,"책제목 작가 출판사 ISBN 대출현황\n");
	for (i = 0; i<num; i++)
	{	
		fprintf(fp, "%s %s %s %s %d \n", book[i].Title,book[i].Author, book[i].Publisher, book[i].ISBN, book[i].Avail);
	}
	printf("Success!\n");
	fclose(fp);
}


void Delete_File(INFO book[]) //파일 삭제 함수
{
	int i;
	FILE * fp = fopen("bookinfo.txt","at");
	for (i = 0; i<num; i--)
	{
		fprintf(fp, "%s %s %s %s %d \n", book[i].Title,book[i].Author, book[i].Publisher, book[i].ISBN, book[i].Avail);
	}
	printf("Success!\n");
=======
	
	FILE * fp = fopen("bookinfo.txt","a");
	fprintf(fp, "%d\n", num);
	for (i = 0; i<num; i++)
	{
		fprintf(fp, "%s %s %s %s %d \n",book[i].Title,book[i].Author, book[i].Publisher, book[i].ISBN, book[i].Avail);
	}
	printf("Success!\n");
	system("cls");
>>>>>>> origin
	fclose(fp);
}


void Search_title_lib(INFO book[])//삭제할때 책 제목 검색
{
<<<<<<< HEAD
	int i;int ret;
	char find[30];
	//FILE * fp = fopen("bookinfo.txt","rt");
	printf("Search book\n\n");
	printf("Insert Title: ");
	scanf("%s", &find);
=======
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
>>>>>>> origin
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
<<<<<<< HEAD
	/*
=======
>>>>>>> origin
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
<<<<<<< HEAD
	*/
=======
>>>>>>> origin
	
}



void DeleteBook(INFO book[])//삭제
<<<<<<< HEAD
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
=======
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
>>>>>>> origin
			strcpy(book[i].Title,"0");
			strcpy(book[i].Author,"0");
			strcpy(book[i].Publisher,"0");
			strcpy(book[i].ISBN,"0");
			
			num--;
			printf("Success!\n");
<<<<<<< HEAD
=======
			system("cls");
>>>>>>> origin
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
<<<<<<< HEAD
	printf("Insert ISBN");
=======
	printf("Insert ISBN:");
>>>>>>> origin
	scanf("%s",&find);
	//////////////미완성//////////
}



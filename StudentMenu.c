#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MainMenu.h"
#include "StudentMenu.h"
#include "LibrarianMenu.h"
#define STUMAX 100
//seungeun jjang
//eunji jjang
stuNum=1;
STU student[STUMAX];



void CreateID (){
	printf("Create ID \n");
	//Count_Student();
	Read_Student_File();
	if (Create(student) == 1)
		return;
	else
		Student_Save_File(student);
}

void Read_Student_File(){
	char buf[100];
	char* temp;
	int i=1, j=1;
	FILE* fp = fopen("studentinfo.txt", "r");
	Count_Student();
	for(i=1;  i<stuNum; i++){
		fgets(buf, sizeof(buf), fp);
		temp = strtok(buf," ");
		strcpy(student[j].id, temp);
		temp = strtok(NULL," ");
		strcpy(student[j].pw, temp);
		temp = strtok(NULL," ");
		strcpy(student[j].name, temp);
		temp = strtok(NULL," ");
		strcpy(student[j].department, temp);
		j++;

	}

	fclose(fp);
}

void Count_Student(){
	char buf[100];
	char* temp;
	int i=1, j=1;
	FILE* fp = fopen("studentinfo.txt", "r");

	for(i=1; i<=STUMAX; i++)
		if(fgets(buf, sizeof(buf), fp))
			stuNum++;
	//printf("%d", stuNum);
	fclose(fp);

}


int Create(){

	printf("id: ");
	scanf("%s", &student[0].id);
	if( Check_ID(student[0].id,1) == 1)
		return 1;
	printf("pw: ");
	scanf("%s", &student[0].pw);
	if( Check_PW(student[0].pw) == 1)
		return 1;
	printf("name: ");
	scanf("%s", &student[0].name);
	printf("department: ");
	scanf("%s", &student[0].department);

	return 0;

}

void Student_Save_File(STU student[]){
	
	FILE * fp = fopen("studentinfo.txt","a");
	fprintf(fp, "%s %s %s %s \n", student[0].id, student[0].pw, student[0].name, student[0].department);
	printf("Success! \n");
	fclose(fp);

}

int Check_ID(char id[], int flag){
	int i=1;
	switch (flag) {
		case 1:
			for(i=1; i<stuNum; i++){
				if( strcmp(id, student[i].id) == 0){
					printf("Check your ID\n"); 
					return 1;
				}
			}
			break;

		case 2:
			for(i=1; i<stuNum; i++){
				if( strcmp(id, student[i].id) == 0)
					return i;
			}
			break;
	}
	return 0;
}

int Check_PW(char pw[]){

	  
		if( strlen(pw) < 4 ){
			printf("Check your PW\n");
			return 1;
		}
		else
			return 0;

}


void StuLogin(){
	stuNum=1;
	if (StuLogin_Menu() == 1)
		return;
	else 
		StudentMenu();
	
}

int StuLogin_Menu(){

	int stu;
	char id[8];
	char pw[5];

	Read_Student_File();

	printf(" Insert ID, PW\n");
	printf(" ID : ");
	scanf("%s", &id);

	if ((stu = Check_ID(id,2)) > 0){
		printf(" PW : ");
		scanf("%s", &pw);
		if( strcmp(pw, student[stu].pw) != 0 ){
			printf(" Not Correct Number\n" );
			return 1;
		}
	}
	else{
		printf("Not Exist ID");
		return 1;
	}
	return 0;

}

void StudentMenu(){
	printf("login success!\n");
	
}
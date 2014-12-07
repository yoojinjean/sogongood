#include <stdio.h>
#include <string.h>
#include "MainMenu.h"
//#include "StudentMenu.h"
#include "LibrarianMenu.h"


int main()
{
	int menu;

	while (1){

		printf("Main Menu\n");
		printf("1. Librarian mode\n2. Student mode\n3.Create ID\n\nINPUT: ");
		scanf("%d", &menu);
		switch (menu)
		{
		
		case 1:
			Login_Check();
			break;
		case 2:
			//StuLogin();  
			break;
		case 3:
			//CreateID();
			break;
		default:
			printf("Wrong Number.\n\n");
		}
	}
}

int Login_Check(){
int ok;

   ok=LibLogin();

   if(ok==0)
   {
      LibMenu();
   }
   else
      printf("Wrong password");

   return 0;
}
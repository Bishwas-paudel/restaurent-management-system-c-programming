#include<stdio.h>
#include<string.h>
#include"border.h"
#include"admin.h"
#include"manager.h"
#include"employee.h"
#include"menu.h"


int choice;
	char pass;

int main(){
	 int n;

	   
mainmenu:
border();


	
	printf("\n\t\t\t\t\t\t\t\t RESTAURANT MANAGEMENT SYSTEM \n");
border();	
	
	printf("\n\n");
	
	                                                             //login section//
	printf("\n\t\t\t\t\t\t\tMAIN MENU\n");
	printf("\n\t\t\t\t\t\t\t1.ADMIN\n");
	printf("\n\t\t\t\t\t\t\t2.MANAGER\n");
	printf("\n\t\t\t\t\t\t\t3.EMPLOYEE\n");
	printf("\n\t\t\t\t\t\t\t4.EXIT\n");
   
    printf("\n\t\t\t\t\t\t\tEnter your choice: ");
	scanf("%d",&choice);
	 system("cls");
	switch(choice){
	                                                             //admin section//
		case 1:
			border();
	printf("\n\t\t\t\t\t\t\t\t ADMIN \n");
		  border(); 
		  
		n=admin();
		if(n==1)
		goto mainmenu;
				 
			break;
	
	                                                             //manager section//
	case 2:
	  border();
	printf("\n\t\t\t\t\t\t\t\t MANAGER \n");
		  border(); 
	 n=manager();
	 if(n==1)
	 goto mainmenu;
			break;
		
	
	                                                            //employee section//
	case 3:
			border();
	 printf("\n\t\t\t\t\t\t\t\t\tEMPLOYEE \n");
	border();
	n=employee();
	if(n==1)
	goto mainmenu;
			break;
			                                                  //exit section//
	case 4:
		printf("\n\t\t\t\t\t\t\tAre you sure\?\?(y/n):");
		getchar();
			scanf("%c",&pass);
		if(pass=='y'){
			return 0;
		}
		else if(pass == 'n'){
			system("cls");
			goto mainmenu;
		}
		else{
			printf("\n\t\t\t\t\t\t\tInvalid Input.........");
			system("pause");
			system("cls");
		}
		break;
	default:
		printf("\n\t\t\t\t\t\t\tInvalid Input.........\n");
	   goto mainmenu;
		break;
		
	}
		
		
		


return 0;}
	

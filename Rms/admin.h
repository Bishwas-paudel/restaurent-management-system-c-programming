#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"border.h"
#include"menu.h"

int admin(){
	int length,choice,i;
	char passkey[20],pass[20],ch;
	int getch();

    FILE *fptr,*fp=fopen("admin.txt","a+");
      
   
    	if(fp==NULL){
		system("cls");
		printf("\n\t\t\t\t\t\t\tERROR!");
		system("pause");
	}
	fscanf(fp,"%s",&pass);
	length=strlen(pass);
  printf("\n\t\t\t\t\t\t\tenter your passkey to continue: ");
    for(i=0;i<length;i++){
    	ch=getch();
    	passkey[i]=ch;
    	printf("*");
		}
		
passkey[i]='\0';
		
	i=strcmp(pass,passkey);
	fclose(fp);		
	if(i==0){
	  while(1){
        system("cls");
          border();
	printf("\n\t\t\t\t\t\t\t\t ADMIN \n");
		  border(); 
		    
	printf("\n\t\t\t\t\t\t\t1.MANAGE MENU ITEMS\n");
	printf("\n\t\t\t\t\t\t\t2.CHANGE PASSWORD\n");
	printf("\n\t\t\t\t\t\t\t3.GO BACK TO MAINMENU\n");
    printf("\n\t\t\t\t\t\t\tEnter your choice: ");
	
	scanf("%d",&choice);
	system("cls");
			switch(choice){
	                                                                  //current Sales//
		case 1:
	            menu();
		       break;
		    
	
		  	
	
		case 2:
		border();  
		printf("\n\t\t\t\t\t\t\t\t\tCHANGE PASSWORD\n");
		border();
		fptr=fopen("ad.txt","w+");
	printf("\n\t\t\t\t\t\t\tEnter New Password:");
	scanf("%s",pass);
	fprintf(fptr,"%s",pass);
	fclose(fptr);
	remove("admin.txt");
	rename("ad.txt","admin.txt");
	fflush(stdin);
		
    	printf("\n\t\t\t\t\t\t\t");
		system("pause");
			  break;
		    	
				
		case 3: return 1;	  		
			           	}   
			}	}
			else{printf("\n\t\t\t\t\t\t\tINCORRECT PASSWORD!!");
	             system("pause");
	             system("cls");
				 return 1;   		  
			}
		
	}

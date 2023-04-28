#ifndef menu_file
#define menu_file
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include"border.h"

struct menu{
	char food_name[50];
	float price;
	int id;
};
struct menu m;

long int siz= sizeof(m); 

FILE *mp,*ftr;

void add_item(){
	system("cls");
	fseek(mp,0,SEEK_END);
	char another='y';
	while(another=='y'){
	
		printf("\n\t\t\t\t\t\t\tEnter Food Id:");
	scanf("%d",&m.id);
	
	
	printf("\n\t\t\t\t\t\t\tEnter Food Name: ");
		getchar();
    	gets(m.food_name);
   
   printf("\n\t\t\t\t\t\t\tEnter Food Price: ");
   scanf("%f",&m.price);
   
   fwrite(&m,siz,1,mp);
   printf("\n\t\t\t\t\t\t\tDo you want to add another?(y/n): ");
		 fflush(stdin);
		 
		 scanf("%c",&another);
		  if(another!='y'&& another!='n'){
		 	
		 		system("cls");
		 		printf("\n\t\t\t\t\t\t\tInvalid Choice....Going back to menu.....");
		system("pause");
		system("cls"); 	
}}}

void view_item(){
/*	struct menu{
	char food_name[50];
	float price;
	int id;
};
struct menu m;

long int siz= sizeof(m); */
	rewind(mp);
	printf("\n\t\t\t\t\t\t\t\t\tFOOD MENU:\n\t\t\t\t\t\t\t\t\t---------\n");

	while(fread(&m,siz,1,mp)==1)
	printf("\n\t\t\t\t\t\t\t%d.%s \t\t\t%.2f/=",m.id,m.food_name,m.price);
	printf("\n\t\t\t\t\t\t\t");
}

void delete_item(){
	system("cls");
	view_item();
	int foodid;
	char another='y';
	 while (another == 'y') {
        printf("\n\t\t\t\t\t\t\tEnter food id to delete : ");
       scanf("%d",&foodid);
           
        ftr = fopen("delete.txt", "w");
        rewind(mp);
  
      while (fread(&m, siz,
                     1, mp)
               == 1) {
               if (foodid!=m.id)
				fwrite(&m, siz, 1, ftr);	
				 }
  
        fclose(mp);
        fclose(ftr);
        remove("menu.txt");
        rename("delete.txt", "menu.txt");
        mp= fopen("menu.txt", "r+");
  
        printf("\n\t\t\t\t\t\t\tWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        
         another= getchar();
          if (another=='n'){
          	system("cls");
		  	printf("\n\n\t\t\t\t\t\t\tMENU AFTER DELETING.........\n");
			view_item();
			printf("\n\t\t\t\t\t\t\t");
			system("pause");
				}
	  else if(another!='y'){
		 		system("cls");
		 		printf("\n\t\t\t\t\t\t\tInvalid Choice....");
	        	system("pause");
                          	
							   }
		
        
        
    } 
}
void modify_item(){
	
	system("cls");
	view_item();
	int id,choice;
	char another='y';
	
		while(another=='y'){
		
			printf("\n\t\t\t\t\t\t\tEnter Food id to modify:");
		scanf("%d",&id);
		rewind(mp);
		while(fread(&m,siz,1,mp)==1){
			if(id==m.id){
				 printf("\n\t\t\t\t\t\t\t1.Change Food Name\n");
			    printf("\n\t\t\t\t\t\t\t2.Change Food Price\n");
			printf("\n\t\t\t\t\t\t\tEnter your choice: ");
	scanf("%d",&choice);
		switch(choice){
		case 1:
	   printf("\n\t\t\t\t\t\t\tEnter new item:");
			getchar();
			gets(m.food_name);
			break;
		case 2:	
	   printf("\n\t\t\t\t\t\t\tEnter new Food Price: ");
         scanf("%f",&m.price);
         break;
         default:
		printf("\n\t\t\t\t\t\t\tInvalid Input.........");
	   system("pause");
		break;
		
	}
          fseek(mp,-siz,SEEK_CUR);
          fwrite(&m,siz,1,mp);
          break;
      }
	}
		 printf("\n\t\t\t\t\t\t\tDo you want to add another?(y/n): ");
		 fflush(stdin);
		 
		  another= getchar();
          if (another=='n'){
          	system("cls");
		  	printf("\n\n\t\t\t\t\t\t\tMENU AFTER MODIFYING.........\n");
			view_item();
			printf("\n\t\t\t\t\t\t\t");
			system("pause");
				}
	  else if(another!='y'){
		 		system("cls");
		 		printf("\n\t\t\t\t\t\t\tInvalid Choice....");
	        	system("pause");
                          	
							   }
		
		
	}
}


int menu(){
	int choice;
	mp=fopen("menu.txt","r+");
	 if (mp == NULL) {
        mp = fopen("menu.txt", "w+");
        if (mp == NULL) {
            printf("\n\t\t\t\t\t\t\t\nCanot open file...");
            exit(1);
        }
    }
    
    while(1){
    	system("cls");
    	border();
	printf("\n\t\t\t\t\t\t\t\t MANAGE MENU ITEMS \n");
		  border(); 
    	printf("\n\t\t\t\t\t\t\t1. ADD ITEMS\n");
    	printf("\n\t\t\t\t\t\t\t2. VIEW ITEMS\n");
    	printf("\n\t\t\t\t\t\t\t3. DELETE ITEMS\n");
    	printf("\n\t\t\t\t\t\t\t4. MODIFY ITEMS\n");
        printf("\n\t\t\t\t\t\t\t5. GO BACK TO MAINMENU \n");
    	printf("\n\t\t\t\t\t\t\tEnter your choice: ");
     	fflush(stdin);
	  scanf("%d", &choice);	
	 switch (choice) {
        case 1:
  
            // Add the records
            add_item();
            break;
        
		 case 2:
		 	system("cls");
            view_item();
            printf("\n\t\t\t\t\t\t\t");
            system("pause");
        	break;
        	
        case 3:
		delete_item();
		break;
		
		case 4:
		
            modify_item();
           
        	break;
			
		
		case 5:
			return 1;
		break;
		
	default:
		system("cls");
		printf("\n\t\t\t\t\t\t\tInvalid Choice....");
		system("pause");
}
     }
return 0;}
#endif
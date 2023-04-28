#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"border.h"


struct emp{
	char name[50];
	float salary;
	int age;
	int id;
};

struct emp e;

// size of structure
long int size= sizeof(e);
FILE *femp,*feptr;

                                                  //function to add records
int add_record(){
	
	system("cls");
	fseek(femp,0,SEEK_END);
	char another = 'y';
	printf("\n\t\t\t\t\t\t\t\t\tEMPLOYEE RECORD\n");
	while(another == 'y'){	
	printf("\n\t\t\t\t\t\t\tEnter Name: ");
		getchar();
    	gets(e.name);
    	
		printf("\n\t\t\t\t\t\t\tEnter Age: ");
		scanf("%d",&e.age);
	   
		
		printf("\n\t\t\t\t\t\t\tEnter Salary: ");
		scanf("%f",&e.salary);
		
		
		printf("\n\t\t\t\t\t\t\tEnter employee Id:");
    	scanf("%d",&e.id);
    
		 
		
		fwrite(&e,size,1,femp);
		 printf("\n\t\t\t\t\t\t\tDo you want to add another?(y/n): ");
		 fflush(stdin);
		 
		 scanf("%c",&another);
		  if(another!='y'&& another!='n'){
		 	
		 		system("cls");
		 		printf("\n\t\t\t\t\t\t\tInvalid Choice....Going back to menu.....");
		system("pause");
		system("cls");
	   
	
                           	
							   }	
	 }         
	 }
                                                         //function to view records	 
void view_record()
{
    
  
    // sets pointer to start of the file
    rewind(femp);
  
    border();
    printf("\n\t\t\t\t\t\tNAME\t\tAGE\t\tSALARY\t\tID\n", e.name, e.age, e.salary, e.id);
    border();
  
    while (fread(&e, size, 1, femp) == 1)
	printf("\n\t\t\t\t\t%s\t\t%d\t\t%.2f\t\t%d",e.name,e.age, e.salary,e.id);
    printf("\n\t\t\t\t\t\t\t");
    //system("pause");
    
}
                                                                  //function to delete record
void delete_record()
{

    system("cls");
    view_record();
   int id;
    char another = 'y';
  
    while (another == 'y') {
        printf("\n\t\t\t\t\t\t\tEnter employee id to delete(Press 0 to go back) : ");
       scanf("%d",&id);
	if(id==0){
			break;
		}

	    
        feptr = fopen("temp.txt", "wb");
        rewind(femp);
  
      while (fread(&e, size,
                     1, femp)
               == 1) {
            if (e.id!=id){
			fwrite(&e, size, 1, feptr);
			 }}
             
        fclose(femp);
        fclose(feptr);
        remove("emp.txt");
        rename("temp.txt", "emp.txt");
        femp = fopen("emp.txt", "rb+");
    
        printf("\n\t\t\t\t\t\t\tWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        
         another= getchar();
          if (another=='n'){
          	system("cls");
		  	printf("\n\n\t\t\t\t\t\t\tRECORD AFTER DELETING.........\n");
			view_record();
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

void modify_record(){
		system("cls");
	view_record();
	int id,choice;
	char another='y';
	
		while(another=='y'){
		
			printf("\n\t\t\t\t\t\t\tEnter Employee id to modify(Press 0 to go back):");
		scanf("%d",&id);
		if(id==0){
			break;
		}
		rewind(femp);
		while(fread(&e,size,1,femp)==1){
			if(id==e.id){
			  printf("\n\t\t\t\t\t\t\t1.Change Name\n");
			  printf("\n\t\t\t\t\t\t\t2.Change Age\n");
			  printf("\n\t\t\t\t\t\t\t3.Change Salary\n");
		
			printf("\n\t\t\t\t\t\t\tEnter your choice: ");
	scanf("%d",&choice);
	
	 switch(choice){
	     case 1:
	   printf("\n\t\t\t\t\t\t\tEnter new Name:");
			getchar();
			gets(e.name);
			break;
		case 2:	
	   printf("\n\t\t\t\t\t\t\tEnter new Age: ");
         scanf("%d",&e.age);
         break;
        case 3:
		  printf("\n\t\t\t\t\t\t\tEnter new Salary: ");
         scanf("%f",&e.salary);
         break;
       
        default:
		printf("\n\t\t\t\t\t\t\tInvalid Input.........");
	   system("pause");
		break;
		
	}
          fseek(femp,-size,SEEK_CUR);
          fwrite(&e,size,1,femp);
          break;
      }
	}
		 printf("\n\t\t\t\t\t\t\tDo you want to add another?(y/n): ");
		 fflush(stdin);
		 
		 another= getchar();
          if (another=='n'){
          	system("cls");
		  	printf("\n\n\t\t\t\t\t\t\tRECORD AFTER MODIFYING.........\n");
			view_record();
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


int manager(){

		int length,choice,i;
	char passkey[20],pass[20],ch;
	int getch();

    FILE *fptr,*fp=fopen("manager.txt","a+");
      
   
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

		 	
		    	

    
  
    // opening the file
    femp = fopen("emp.txt", "rb+");
  
    // showing error if file is
    // unable to open.
    if (femp == NULL) {
        femp = fopen("emp.txt", "wb+");
        if (femp == NULL) {
            printf("\n\t\t\t\t\t\t\t\nCannot open file...");
            exit(1);
        }
    }
    
   while(1){
        system("cls");
          border();
	printf("\n\t\t\t\t\t\t\t\t MANAGER \n");
		  border(); 
     	printf("\n\t\t\t\t\t\t\t1. ADD RECORD\n");
     	printf("\n\t\t\t\t\t\t\t2. DELETE RECORD\n");
     	printf("\n\t\t\t\t\t\t\t3. VIEW RECORD\n");
     	printf("\n\t\t\t\t\t\t\t4. MODIFY RECORD\n");
     	printf("\n\t\t\t\t\t\t\t5. CHANGE PASSWORD\n");
        printf("\n\t\t\t\t\t\t\t6.GO BACK TO MAINMENU\n");
     	printf("\n\t\t\t\t\t\t\tEnter your choice: ");
     	fflush(stdin);
	    scanf("%d", &choice);
  system("cls");
        // Switch Case
        switch (choice) {
        case 1:
  
            // Add the records
            add_record();
            break;
  
        case 2: 
            // delete the records
            delete_record();
            break;
        
		    
        case 3:
              // view the records
              system("cls");
            view_record();
             printf("\n\t\t\t\t\t\t\t");
            system("pause");
			break;
			
		case 4:
	
            modify_record();
            
        	break;
			
	    case 5:	
	   
		border();  
		printf("\n\t\t\t\t\t\t\t\t\tCHANGE PASSWORD\n");
		border();
		fptr=fopen("manage.txt","w+");
	printf("\n\t\t\t\t\t\t\tEnter New Password:");
	scanf("%s",pass);
	fprintf(fptr,"%s",pass);
	fclose(fptr);
	remove("manager.txt");
	rename("manage.txt","manager.txt");
	fflush(stdin);
		
    	printf("\n\t\t\t\t\t\t\t");
		system("pause");
			  break;
            
    case 6:
	fclose(femp);
	system("cls");
	return(1);
	break;
	
	
	default:
		system("cls");
		printf("\n\t\t\t\t\t\t\tInvalid Choice....");
		system("pause");
}
     }
 }
 else{printf("\n\t\t\t\t\t\t\tINCORRECT PASSWORD!!");
	system("pause");
	system("cls");	 
return 1;}
		return 0; }
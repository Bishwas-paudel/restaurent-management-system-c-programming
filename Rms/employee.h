#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"border.h"
#include"menu.h"
struct customer {
	char name[50];
	int table_no;
	int id[20],quantity[20];
};

struct customer c;
int i=0;

long int s= sizeof(c);

FILE *cp;


void add_order() {
	system("cls");
	fseek(cp,0,SEEK_END);
	char another= 'y';



	printf("\n\t\t\t\t\t\t\tEnter Customer Name: ");
	getchar();
	gets(c.name);

	printf("\n\t\t\t\t\t\t\tEnter table no: ");
	scanf("%d",&c.table_no);

	view_item();


	printf("\n\t\t\t\t\t\t\tEnter Food Id: ");
	scanf("%d",&c.id[i]);


	printf("\n\t\t\t\t\t\t\tEnter Food Quantity: ");
	scanf("%d",&c.quantity[i]);

	fwrite(&c,s,1,cp);
	//fclose(cp);
	system("pause");
	system("cls");


}




void bill_shown() {
	int t_no,n;
	rewind(cp);
	rewind(mp);

	printf("\n\t\t\t\t\t\t\tEnter Table no: ");
	scanf("%d",&t_no);

	while(fread(&c,s,1,cp)==1) {
		if(c.table_no==t_no) {
			printf("Customer Name: %s ",c.name);
			for(n=0; n<i; n++) {
				printf("id: %d",c.id[n]);
				printf("quantity: %d",c.quantity[n]);
			}
		}
	}

}



int employee() {

	cp = fopen("customer.txt", "rw+");
	if (cp == NULL) {
		printf("\n\t\t\t\t\t\t\t\nCanot open file...");
		exit(1);
	}

	mp=fopen("menu.txt","rb+");
	if (mp == NULL) {
		printf("\n\t\t\t\t\t\t\t\nCanot open file...");
		exit(1);
	}

	int length,choice,i;
	char passkey[20],pass[20],ch;
	int getch();

	FILE *fptr,*fp=fopen("emppass.txt","a+");


	if(fp==NULL) {
		system("cls");
		printf("\n\t\t\t\t\t\t\tERROR!");
		system("pause");
	}
	fscanf(fp,"%s",&pass);
	length=strlen(pass);
	printf("\n\t\t\t\t\t\t\tenter your passkey to continue: ");
	for(i=0; i<length; i++) {
		ch=getch();
		passkey[i]=ch;
		printf("*");
	}

	passkey[i]='\0';

	i=strcmp(pass,passkey);
	fclose(fp);
	if(i==0) {
		printf("\n\t\t\t\t\t\t\tChoose the options below:\n");
		while(1) {
			rewind(mp);
			system("cls");
			border();
			printf("\n\t\t\t\t\t\t\t\t\tEMPLOYEE \n");
			border();
			printf("\n\t\t\t\t\t\t\t1.ADD ORDER\n");
			printf("\n\t\t\t\t\t\t\t2.SHOW BILL\n");
			printf("\n\t\t\t\t\t\t\t3.CHANGE PASSWORD\n");
			printf("\n\t\t\t\t\t\t\t4.GO BACK TO MAIN MENU\n");

			printf("\n\t\t\t\t\t\t\tEnter your choice: ");
			scanf("%d",&choice);
			system("cls");
			switch(choice) {
					//current Sales//
				case 1:
					border();
					printf("\n\t\t\t\t\t\t\t\t\tADD ORDER\n");
					border();
					add_order();
					printf("\n\t\t\t\t\t\t\t");
					system("pause");
					break;

				case 2:
					border();
					bill_shown() ;
					printf("\n\t\t\t\t\t\t\t");
					system("pause");
					break;

				case 3:
					border();
					printf("\n\t\t\t\t\t\t\t\t\tCHANGE PASSWORD\n");
					border();
					fptr=fopen("em.txt","w+");
					printf("\n\t\t\t\t\t\t\tEnter New Password:");
					scanf("%s",pass);
					fprintf(fptr,"%s",pass);
					fclose(fptr);
					remove("emppass.txt");
					rename("em.txt","emppass.txt");
					fflush(stdin);
					printf("\n\t\t\t\t\t\t\t");
					system("pause");
					break;

				case 4:

					fclose(cp);
					return 1;
			}
return 1;
		}
	} else {
		printf("\n\t\t\t\t\t\t\tINCORRECT PASSWORD!!");
		system("pause");
		system("cls");
		return 1;
	}
	return 0;
}

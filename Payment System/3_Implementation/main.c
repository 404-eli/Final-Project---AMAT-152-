#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include"struct.h"

void addrecords();
void deleterecords();
void searchrecords();
void listrecords();
void payment();
void modifyrecords();
char get;

int main()
{	int password;
	int smartcardnumber;
	char choice;

    system("cls");

	printf("\n\n\n\n\n\n\n\n\n**************************************************************");
	printf("\n\t\t------WELCOME TO THE DTH BILLING MANAGEMENT SYSTEM---");
	printf("\n\t\t****************************************************************");
	Sleep(2000);
	getch();
    system("cls");
	while (1)
	{
		system("cls");
		printf("\n Enter\n A : for adding new records.\n L : for list of records");
		printf("\n M : for modifying records.\n P : for payment");
		printf("\n S : for searching records.");
		printf("\n D : for deleting records.\n E : for exit\n");
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case 'P':
				payment();break;
			case 'A':
				addrecords();break;
			case 'L':
				listrecords();break;
			case 'M':
				modifyrecords();break;
			case 'S':
				searchrecords();break;
			case 'D':
				deleterecords();break;
			case 'E':
				system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\n\n\n:\n\tFOR USING OUR SERVICE");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
		}
	}
}

void deleterecords()
{
	FILE *f,*t;
	int i=1;
	char smartcardnumber[20];
	if((t=fopen("records.txt","w+"))==NULL)
	exit(0);
	if((f=fopen("file.txt","rb"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Smartcard Number to be deleted from the Database");
	fflush(stdin);
	scanf("%[^\n]",smartcardnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.smartcardnumber,smartcardnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       system("cls");
		printf("Smartcard Number \"%s\" not found",smartcardnumber);
		remove("file.txt");
		rename("records.txt","file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("file.txt");
	rename("records.txt","file.txt");
	system("cls");
	printf("The Smartcard Number %s Successfully Deleted!!!!",smartcardnumber);
	fclose(f);
	fclose(t);
	getch();
}

void searchrecords()
{
	FILE *f;
	char smartcardnumber[20];
	int flag=1;
	f=fopen("file.txt","rb+");
	if(f==0)
		exit(0);
	fflush(stdin);
	system("cls");
	printf("Enter Smartcard Number to search user in our database");
	scanf("%s", smartcardnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.smartcardnumber,smartcardnumber)==0)
		{	system("cls");
			printf(" Record Found ");
			printf("\n\nSmartcard Number: %s\nName: %s\nAmount: Rs.%0.2f\n",s.smartcardnumber,s.name,s.amount);
			flag=0;
			break;
		}
		else if(flag==1)
		{	system("cls");
			printf("Requested Smartcard Number Not found in our database");
		}
	}
	getch();
	fclose(f);
}

void addrecords()
{
	FILE *f;
	char test;
	f=fopen("file.txt","ab+");
	if(f==0)
	{   f=fopen("file.txt","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Smartcard Number:");
		scanf("%s",&s.smartcardnumber);
		printf("\n Enter name of the user:");
		fflush(stdin);
		scanf("%[^\n]",&s.name);
		printf("\n Enter amount:");
		scanf("%f",&s.amount);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("1 record successfully added");
		printf("\n Press esc key to exit, any other key to add other record:");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}

void listrecords()
{
	FILE *f;
	int i;
	if((f=fopen("file.txt","rb"))==NULL)
		exit(0);
	system("cls");
	printf("Smartcard Number\t\tUser Name\t\t\tAmount\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%-10s\t\t%-20s\t\tRs. %.2f /-",s.smartcardnumber,s.name,s.amount);
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}

void payment()
{
	FILE *f;
	char smartcardnumber[20];
	long int size=sizeof(s);
	float amt;
	int i;
	if((f=fopen("file.txt","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Smartcard Number of the subscriber for payment");
	scanf("%[^\n]",smartcardnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.smartcardnumber,smartcardnumber)==0)
		{
			system("cls");
			printf("\n Smartcard No.: %s",s.smartcardnumber);
			printf("\n Name: %s",s.name);
			printf("\n Current amount: %f",s.amount);
			printf("\n");
			for(i=0;i<79;i++)
				printf("-");
			printf("\n\nEnter amount of payment :");
			fflush(stdin);
			scanf(" %f",&amt);
			s.amount=s.amount-amt;
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	system("cls");
	printf("THANK YOU %s FOR YOUR TIMELY PAYMENTS",s.name);
	getch();
	fclose(f);
}

void modifyrecords()
{
	FILE *f;
	char smartcardnumber[20];
	long int size=sizeof(s);
	if((f=fopen("file.txt","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Smartcard Number of the subscriber to modify:");
	scanf("%[^\n]",smartcardnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.smartcardnumber,smartcardnumber)==0)
		{
			system("cls");
			printf("\n Enter Smartcard Number:");
			scanf("%s",&s.smartcardnumber);
			printf("\n Enter name: ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf("\n Enter amount: ");
			scanf("%f",&s.amount);
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
}

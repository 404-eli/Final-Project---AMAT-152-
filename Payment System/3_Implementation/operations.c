#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "fun.h"
#include "struct.h"

void deleterecords()
{
	FILE *f,*t;
	int i=1;
	char smartcardnumber[20];
	if((t=fopen("c:/temp.ojs","w+"))==NULL)
	exit(0);
	if((f=fopen("c:/file.ojs","rb"))==NULL)
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
		remove("c:/file.ojs");
		rename("c:/temp.ojs","c:/file.ojs");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("c:/file.ojs");
	rename("c:/temp.ojs","c:/file.ojs");
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
	f=fopen("c:/file.ojs","rb+");
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
	f=fopen("c:/file.ojs","ab+");
	if(f==0)
	{   f=fopen("c:/file.ojs","wb+");
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
	if((f=fopen("c:/file.ojs","rb"))==NULL)
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
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
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
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
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

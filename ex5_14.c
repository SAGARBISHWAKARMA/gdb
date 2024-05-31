/*
Modify the sort program to handle a -r flag, which indicates sorting in reverse 
(decreasing) order. Be sure that -r works with -n. 
Author:Sagar
Create:17 April 2024
*/

/*Required Header files*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Funcation Prototypes*/
void getdata(int *,int);
void ascending(int *,int );
void descending(int *,int);

/*Main Function*/
void main(int argc,char **argv)
{

	if(argc!=2)
	{
		printf("enter the correct argunment\n");
		return;
	}

	int a;
	printf("enter number you want\n");
	scanf("%d",&a);

	int arr[a];
	getdata(arr,a);

	switch(argv[1][1])
	{
		case 'n': ascending(arr,a);
			  break;
		case 'r':descending(arr,a);
			 break;
		default:printf("please enter the correct formet");
			return;
	}
	for(int i=0;i<a;i++)
		printf("%d ",arr[i]);
}/*Main Function End*/


/*getdata function is to store data from user and print*/
void getdata(int arr[],int a)
{
	for(int i=0;i<a;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<a;i++)
		printf("%d ",arr[i]);
}/*getdata function end*/

/*ascending function is sort data in ascending order*/
void ascending(int *arr,int a)
{

	for(int i=0;i<a-1;i++)
	{
		for(int j=i+1;j<a;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}/*ascending function end*/

/*descending function is to sort the data from descending*/
void descending(int *arr,int a)
{
	for(int i=0;i<a-1;i++)
	{
		for(int j=i+1;j<a;j++)
		{
			if(arr[i]<arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;

			}
		}
	}
}/*descending function end*/

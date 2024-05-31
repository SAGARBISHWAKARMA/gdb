/*Add the option -f to fold upper and lower case together, so that case 
*distinctions are not made during sorting; for example, a and A compare equal
*Author:Sagar
*Create: 18 April 2024
*/

/*Required Header File*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Function Prototype*/
void getdata(int *,int);
void ascending(int *,int );
void descending(int *,int);

/*Main Function*/
void main(int argc,char **argv)
{

	int a;
	if(argc!=3)
	{
		printf("enter the correct argunment\n");
		return;
	}

	printf("enter number you want\n");
	scanf("%d",&a);

	int arr[a];
	getdata(arr,a);
	
	/*checking the condition*/
	if(argv[1][1]=='f')
	{
		switch(argv[2][1])
		{
			case 'n': ascending(arr,a);
				  break;
			case 'N': ascending(arr,a);
				  break;
			case 'r':descending(arr,a);
				 break;
			case 'R':descending(arr,a);
				 break;
			default:printf("please enter the correct formet");
				return;
		}
	}
	else
	{
		printf("enter the correct argunment\n");
		return;
	}

	for(int i=0;i<a;i++)
		printf("%d ",arr[i]);
}/*Main Function End*/

void getdata(int arr[],int a)
{
	for(int i=0;i<a;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<a;i++)
		printf("%d ",arr[i]);
}

/*ascending function is to sort data in ascending order*/
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

/*descending function is to sort data in descending order*/
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

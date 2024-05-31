/*
 *Write the function strend(s,t), which returns 1 if the string t occurs at the 
 *end of the string s, and zero otherwise.
Author: Sagar 
Create: 16 april 2024
 */

/*Required Header */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Function Prototype*/
int  myStrend(char *,char *);

/*Main Function*/
void main()
{
	char *s1;
	char *s2;
	int i;

	s1=(char *)malloc(sizeof(char)*100);
	s2=(char *)malloc(sizeof(char)*100);


	printf("enter the string you want\n");
	scanf("%s",s1);

	printf("enter the string to find\n");
	scanf("%s",s2);

	i=myStrend(s1,s2);

	if(i)
	{
		printf("value of i is %d so sring is present\n",i);
	}
	else
	{
		printf("value of i is %d so value is not present\n",i);
	}

}

/*myStrend functio search if substring present or not*/
int myStrend(char *s1,char *s2)
{
	int i;
	int j;
	int k;

	i=strlen(s1);

	for(k=i-strlen(s2),j=0;s2[j];j++,k++)
	{

		if(s1[k]!=s2[j])
		{
			return 0;
		}
	}
	return 1;

}

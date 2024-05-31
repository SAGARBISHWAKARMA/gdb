/*Write versions of the library functions strncpy, strncat, and strncmp, which 
  operate on at most the first n characters of their argument strings. For example, 
  strncpy(s,t,n) copies at most n characters of t to s
Author: Sagar Bike
 */

/*Required Headerfiles */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*Function prototype*/
void myStrncpy(char *,char *,int);
int myStrncmp(char *,char *,int);
void myStrncat(char *,char *,int);

/*Main Function*/
/*Main function call multiple userdefine function in place of predefine function*/
void main()
{
	char *s1;
	char *s2;
	int x;
	int y;
	int z;

	s1=(char *)malloc(sizeof(char)*100);
	s2=(char *)malloc(sizeof(char)*100);

	printf("enter the string 1\n");
	scanf("%s",s1);

	printf("enter the string 2\n");
	scanf("%s",s2);

	printf("enter the number you want\n");
	scanf("%d",&x);

	printf("1)my_strcat 2)my_strncpy 3)my_strncmp\n");
	scanf("%d",&y);

	switch(y)
	{
		case 1:myStrncat(s1,s2,x);
		       break;

		case 2:myStrncpy(s1,s2,x);
		       break;

		case 3:myStrncmp(s1,s2,x);
		       break;

		default:printf("enter the correct option\n");
	}
}

/*myStrncat is userdefine function in place of predefine function*/
void myStrncat(char *s1,char*s2,int x)
{
	int i;
	int j;
	int k=0;

	for(i=strlen(s1),j=0;j<x;i++,j++)
	{
		s1[i]=s2[j];
	}
	s1[i]='\0';

	printf("%s\n",s1);
}

/*myStrncpy is userdefine function in place of predefine function*/
void myStrncpy(char *s1,char *s2,int x)
{
	int i;
	int j;
	int k=0;

	for(i=0,j=0;j<x;i++,j++)
	{
		s1[i]=s2[j];
	}
	s1[i]='\0';

	printf("%s\n",s1);
}

/*myStrncmp is userdefine function in place of predefine function*/
int myStrncmp(char *s1,char *s2,int x)
{
	int i;
	int j;
	int k=0;

	for(i=0,j=0;j<x && s2[j] &&s1[i];i++,j++)
	{
		if(s1[i]!=s2[j])
		{
			k=s1[i]-s2[j];
			break;
		}
	}
	if(k==0)
	{
		printf("string s1 and string s2 are same\n");
	}
	else if(k<1)
	{
		printf("string s2 is smaller than s1\n");
	}
	else if(k>=1)
	{
		printf("string s1 is greater tha s2\n");
	}
}

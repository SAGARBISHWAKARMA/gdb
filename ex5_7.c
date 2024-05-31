/*Rewrite readlines to store lines in an array supplied by main, rather than 
 *calling alloc to maintain storage. How much faster is the program?
 *Author: Sagar
 *Create: 17 April
 */

/*Required Heder Files*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*Function Prototypes*/
void getlin(char *,int );

/*Main Function*/
void main()
{
	char s1[100];

	getlin(s1,100);

	for(int i=0;s1[i]!='\0';i++)
		printf("%c",s1[i]);

}
/*getline function store a data directly store in array providede by main*/
void getlin(char *s1,int i)
{ 
	int j=0;
	char c;
	while((c=getchar())!=EOF && c!='\n')
	{
		s1[j++]=c;

		if(j>i)
			break;
	}
	s1[j]='\0';
}

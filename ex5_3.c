/*. Write a pointer version of the function strcat that we showed in Chapter 2: 
*strcat(s,t) copies the string t to the end of s
Author:Sagar 
Create: 16 april 2024
*/
/*REQUIRED HEADER FILES*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*FUNCTION PROTOTYPE*/
void myStrcat(char *,char *);

/*MAIN FUCTION*/
/**/
void main()
{
char *s1;
char *s2;

s1=(char *)malloc(sizeof(char)*100);
s2=(char *)malloc(sizeof(char)*100);


printf("enter the string s1\n");
scanf("%s",s1);

printf("enter the string s2\n");
scanf("%s",s2);


myStrcat(s1,s2);
printf("%s\n",s1);
}

/*myStrcat is user define funcion for strccat*/
void myStrcat(char *s1,char *s2)
{
int i;
int j;
i=strlen(s1);

for(i,j=0;s2[j];i++,j++)
{
s1[i]=s2[j];
}
s1[i]=s2[j];
}

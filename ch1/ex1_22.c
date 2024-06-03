/*
This program is use to remove single and multi line commnets
Author :Sagar
Date: 18 april 2023
*/


/*Requied Header files*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* function prototypes*/
void removeComment(char *,char *);
int  singleComment(char *,int);
int  multiComment(char *,int);

/* Main Program*/
void main()
{
char *s1,*s2,c;
int i=0;

s1=(char *)malloc(sizeof(char)*100); //allocate the memory in heap section
s2=(char *)malloc(sizeof(char )*100);

printf("enter the string you want\n");

while((c=getchar())!=EOF) // store the data from the user ,char by char
{
s1[i++]=c;
}
s1[i]='\0'; //adding the \0 at end of string

//printf("%s\n",s1);

removeComment(s1,s2);   //calling function of remove commnet
}/*End main*/


/*function is used to remove the single and multi line comment*/
void removeComment(char *s1,char *s2)
{
int i=0,j=0; //dummy variable

for(i=0,j=0;s1[i];i++,j++)  //loop
{
if(s1[i]=='/' && s1[i+1]== '/') // find the pattern to calling the function
{
i=singleComment(s1,i);/* calling the function of single line commnet*/
}
else if(s1[i]=='/' && s1[i+1]== '*' ) /*matching pattern for multi line comment*/
{
i=multiComment(s1,i+2);/*calling multi_comment*/
if(i==-1)
return;
}

s2[j]=s1[i];
}
printf("after remove the commnet\n");
printf("%s\n",s2);
}

/*function is to remove single line commnet*/
int singleComment(char *s1,int i)
{
while(s1[i]!='\n')
i++;

if(s1[i]=='\n')
return i;
else
return ++i;
}/*single_commnet end*/


/*Function to remove multiline comment*/
int multiComment(char *s1,int i)
{
while(s1[i]!='*' || s1[i+1]!='/')
{i++;
if(i>100)
{
printf("please correct the commnet\n");
return -1;
}
}
return i+2;
}/*multi_commnet end*/

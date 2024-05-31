/* Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument
Author:Sagar
Create:17 april 2024
*/

/*Required Header Files*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Function Prototypes*/
int my_atoi(char *);
void my_tail(char *,int,int);

/*Main function*/
void main(int argc,char **argv)
{
	char *s1;
	char c;
	int i=0;
	int line=1;
	int sum;

	printf("%d\n",argc);
	s1=(char *)malloc(sizeof(char)*100);

	printf("enter the string you want\n");
	while((c=getchar())!=EOF)
	{
		s1[i++]=c;

		if(c=='\n')
			line++;
	}
	s1[i]='\0';
	printf("\n");

	printf("number of line are:%d\n",line);
	
	if(argc!=1)
	{
	sum=my_atoi(argv[1]);
	printf("number of line to be printed are:%d\n",sum);
	}
	else
	{
	sum=10;
	printf("%d\n",sum);
	}
	my_tail(s1,sum,line);
}/*main function end*/

/*my_atoi functionis to conver string into integer*/
int  my_atoi(char *arg)
{
	int sum=0;
	for(int i=0;arg[i];i++)
	{
		sum=sum*10 + arg[i] - '0';
	}
	return sum;
}/*atoi function end*/

/*myTail function is to print data from bottom to top */
void my_tail(char *s1,int sum,int line)
{
	int num;
	int count=1;
			

	if(sum>=line)
	{
		printf("whole line will be printed\n");
		printf("%s\n",s1);
	}
	else 
	{
		num=line-sum;
		printf("%d",num);

		for(int i=0;s1[i];i++)
		{
			if(s1[i]=='\n')
				count++;

			if(count>num)
			{
				for(int j=i;s1[j];j++)
					printf("%c",s1[j]);

						printf("\n");
						return;
			}

		}
	}
}/*myTail function end*/

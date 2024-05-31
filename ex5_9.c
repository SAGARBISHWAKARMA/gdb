/* Rewrite the routines day_of_year and month_day with pointers instead of 
*indexing
*Author:Sagar
*Create: 17 April 2024
*/

/*Required Headerfiles*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Static char 2d array*/
static char daytab[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/*Function Prototype*/
int day_of_year(int ,int ,int);
void month_day(int ,int,int *,int * );

/*Main Function*/
/*Main function call a functions and use pointer instead of indexing method*/
void main()
{
	int year;
	int month;
	int day;
	int k=0;
	int yearday;
	int pmonth;
	int pday;

	printf("enter the value year ,month ,day\n");
	scanf("%d %d %d",&year,&month,&day);

	printf("enter the number of yearday want\n");
	scanf("%d",&yearday);

	if(month<=12 && day<=31)
	{	k=day_of_year(year,month,day);
		if(k)
		{
			printf("%d\n",k);
		}
		else
			printf("enter the correct day or month\n");

	}
	else
		printf("please enter the correct day or month\n");

	if(yearday<=366)
	{
		month_day(year,yearday,&pmonth,&pday);
		printf("%d %d\n",pmonth,pday);
	}
	else
		printf("please enter the correct number of days days\n");
}


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i=1;
	int leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;


	if((leap==0 && month==2 && day>28) || (leap==1 && month==2 && day>29))
	{
		return 0;

	}
	else{	
	for (i = 1; i < month; i++)
			day += daytab[leap][i];
		return day;
	}
}

/*month_day function is to get the month and day from data*/
void month_day(int year, int yearday,int *pmonth,int *pday)
{
	int i=1;
	int leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;


	if(((leap==0)&&yearday<=365) ||(leap==1) &&yearday<=366)
	{
		for (i = 1; yearday > daytab[leap][i]; i++)
			yearday -= daytab[leap][i];

		*pmonth = i;
		*pday = yearday; }
	else
		printf("enter the correct number of day");
}

/*
*There is no error checking in day_of_year or month_day. Remedy this defect.
*Author: Sagar
Create:17 April 2024
*/

/*Required Header Files*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Globle char datatype*/
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*Funcion Prototypes*/
int day_of_year(int ,int ,int);
void month_day(int ,int,int *,int * );

/*Main Function*/
/*Solving error from given question*/
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

	if((month>=1 && month<=12) && (day>=1 && day<=31))
	{
		k = day_of_year(year,month,day);
		if(k)
		{
			printf("%d\n",k);
		}
		else
			printf("enter the correct day or month\n");
	}

	if((yearday>=1 &&yearday<=366))
	{
		month_day(year,yearday,&pmonth,&pday);
		printf("%d %d\n",pmonth,pday);
	}
	else
		printf("please enter the correct number of days days\n");
}


/* day_of_year: set day of year from month & day */

int day_of_year(int year, int month, int day)
{	char *p;
	int i;
	int leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;


	if((leap==0 && month==2 && day>28) || (leap==1 && month==2 && day>29))
	{
	return 0;
	}
	else
        {
	for(p=daytab[leap];month>1;month--)
		day+=*++p;
		return day;
	}
}

/*month_day give a monthe and number of days from a data*/
void month_day(int year, int yearday,int *pmonth,int *pday)
{
	int i;
	int leap;
	char *p;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;


	if(((leap==0)&&yearday<=365) ||(leap==1) &&yearday<=366)
	{
		for(p=daytab[leap];yearday>*p;p++)
			yearday-=*p;			

		*pmonth = p - *(daytab + leap);
		*pday = yearday; }
	else
		printf("enter the correct number of day");
}

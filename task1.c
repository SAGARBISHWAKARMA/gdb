/*At the EIC Cafeteria, n employees are standing in the queue. Today, on the menu, we have 
*either a plain dosa or a masala dosa. Each employee has a preference. He/She either want to
*eat a sada dosa or a masala dosa. At the front end of the queue, there is a stack of dosas, a 
*mix of sada and masala dosas. A employee at the front of the queue performs the following 
*operation
*1. If the employee likes a sada dosa and the top of the stack is a sada dosa, then the 
*employee takes the sada dosa and leaves the queue.
*2. If the employee likes a masala dosa and the top of the stack is a masala dosa, then the
*employee takes the masala dosa and leaves the queue.
*3. Else the employee leaves the front of the queue and goes to end of the queue.
*This process goes on till no one in the queue is able to leave it. All these employees will not 
*be able to have the breakfast today. Your job is to find the number of such employees.

*Author: Sagar
*Create:14/05/1024
*/


/*Required HeaderFiles*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*struct datatypes*/
typedef struct node
{
	int inum;
	struct node *next;
}slist;

/*Function Prototypes for stack*/
void stackPush(slist **);
slist * nodePop(slist **);

/*function prototypes for queue*/
void queuePush(slist **);
void endQueue(slist **);

/*function prototypes for print and countnode*/
void printData(slist*);
int countNode(slist*);

/*Main Function */
/*main is to call function to store nodes , print the node , delete node and rotate end node */
int main()
{
	int ilimit;
	int ipeople;
	int icount;
	int flag=0;

	slist *stackptr=NULL;
	slist *queueptr=NULL;
	slist *dummy;

	printf("enter the number of doas in stack you want\n");
	scanf("%d",&ilimit);
	
	printf("enter the number of peoples are in the queue\n");
	scanf("%d",&ipeople);

	for(int i=0;i<ilimit;i++)
		stackPush(&stackptr);

	for(int i=0;i<ipeople;i++)
		queuePush(&queueptr);

	/*logic to serve the dosa according to requiredment */
	while(queueptr && stackptr )
	{	printData(stackptr);
		printf("\n");
		printData(queueptr);
		printf("\n");
		if(stackptr->inum==queueptr->inum)
		{
			nodePop(&stackptr)&&nodePop(&queueptr);
		}
		else
			endQueue(&queueptr);

		if(flag>250)
			break;
		flag++;
	}

	icount=countNode(queueptr);
	
	printf("%d number of person didn't get dosa\n",icount);



}
/*****************************************/
/*
*stackPush Add number of dosa in a stack method
*/void stackPush(slist **ptr)
{
	slist *new=(slist *)malloc(sizeof(slist)*1);

	printf("enter the data you stack \n");
	scanf("%d",&new->inum);

	if(*ptr==NULL)
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		new->next=*ptr;
		*ptr=new;
	}
}/*stackPush function end*/
/*****************************************************/
/*printfData is to print employ or dosa in a stack or queue*/
void printData(slist *ptr)
{
	if(ptr==NULL)
	{
		printf("empty\n");
		return;
	}

	while(ptr)
	{
		printf("%d",ptr->inum);
		ptr=ptr->next;
	}
}/*printData function end*/
/************************************************/
/*queuwPush function is to add no of employ in a queue*/
void queuePush(slist **ptr)
{
	slist *new=(slist *)malloc(sizeof(slist)*1);
	slist *dum=*ptr;

	printf("enter the data for queue\n");
	scanf("%d",&new->inum);

	if(*ptr==NULL)
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		while(dum->next)
			dum=dum->next;

		dum->next=new;
		new->next=NULL;
	}
}/*queueFunction End*/
/**************************************************************/
/*Nodepop function is to remove a dosa from a stack*/
slist * nodePop(slist **ptr)
{
	slist *pop=(slist *)malloc(sizeof(slist)*1);

	if(*ptr==NULL)
	{
		printf("stack is empty better luck next time\n");
		return 0;
	}

	pop=*ptr;
	*ptr=(*ptr)->next;

	return pop;
}/*nodepop function end*/
/***************************************************************/
/*endQueue function is to call when employ did get the dosa of requiedment and he has stand last in a line*/
void endQueue(slist **ptr)
{
	slist *new=*ptr;
	slist *dummy=*ptr;

	if(*ptr==NULL || (*ptr)->next==NULL)
	{
		printf("node is not enough to perform the peration please try again\n");
		return;
	}

	//*ptr=dummy->next;

	while(dummy->next)
		dummy=dummy->next;

	*ptr=new->next;
	dummy->next=new;
	new->next=NULL;
}/*endQueue Function End*/
/*************************************/
/*countNode is to check no of node*/
int countNode(slist *ptr)
{
int icount=0;

if(ptr==NULL)
{
//printf("node is not present\n");
return 0;
}

while(ptr!=NULL)
{icount++;
ptr=ptr->next;
}
return icount;
}/*count the no of data present*/





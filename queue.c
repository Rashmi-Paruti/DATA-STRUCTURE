#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 5

void fnInsertRear(char [], int*, int*, char);
char fnDeleteFront(char[], int*, int*);
void fnDisplay(char [], int, int);
bool fnQueueFull(int, int);
bool fnQueueEmpty(int, int);

int main()
{
    char myQueue[QUEUE_SIZE];
    int iFront = -1, iRear = -1;
    int iChoice;
    char cElem;
    
    for(;;)
    {
	    printf("\nQueue Operations\n");
	    printf("=====================");
	    printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exitn");
	    printf("Enter your choice\n");
	    scanf("%d",&iChoice);
	    getchar();	//read trialing enter character
	    switch(iChoice)
	    {
		    case 1: if(!fnQueueFull(iFront, iRear))
		            {
		                printf("nEnter an element : ");
		                scanf("%c", &cElem);
		                fnInsertRear(myQueue, &iFront, &iRear, cElem);
		            }
		            else
		            {
		                printf("nQueue is Fulln");
		            }

			    break;
		    case 2: if(!fnQueueEmpty(iFront, iRear))
		            {
		                cElem = fnDeleteFront(myQueue, &iFront, &iRear);
		                printf("nDeleted element is %cn", cElem);
		            }
		            else
		            {
		                printf("nQueue is Emptyn");
		            }

			    break;
		    case 3: if(!fnQueueEmpty(iFront, iRear))
		            {
		                printf("nContents of the Queue is n");
		                fnDisplay(myQueue, iFront, iRear);
		            }
		            else
		            {
		                printf("nQueue is Emptyn");
		            }

			    break;
			
		    case 4: exit(0);
		
		    default: printf("nInvalid choicen");

			    break;
	    }
    }
    return 0;
}

bool fnQueueFull(int f, int r)
{
    if((r+1) % QUEUE_SIZE == f)
        return true;
    else
        return false;
}

bool fnQueueEmpty(int f, int r)
{
    if(f == -1)
        return true;
    else
        return false;
}

void fnInsertRear(char queue[], int *f, int *r, char cVal)
{
    if(*r == -1)
    {
        *f = *f + 1;
        *r = *r + 1;
    }
    else
        *r = (*r + 1)%QUEUE_SIZE;
        
    queue[*r] = cVal;
}

char fnDeleteFront(char queue[], int *f, int *r)
{
    char cElem;
    cElem = queue[*f];
    
    if(*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
    {
        *f = (*f + 1)%QUEUE_SIZE;
    }
    return cElem;
}

void fnDisplay(char queue[], int f, int r)
{
    int i;
    if(f<=r)
    {
        for(i=f; i<=r; i++)
        {
            printf("%ct", queue[i]);
        }
        printf("n");    
    }
    else
    {
        for(i=f; i<=QUEUE_SIZE-1; i++)
        {
            printf("%ct", queue[i]);
        }
        for(i=0; i<=r; i++)
        {
            printf("%ct", queue[i]);
        }
        printf("n");    
    }
}
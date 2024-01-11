#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_DAYS_IN_WEEK 7

// Structure to represent a day
typedef struct
{
    char *acDayName;    // Dynamically allocated string for the day name
    int iDate;         // Date of the day
    char *acActivity;   // Dynamically allocated string for the activity description
}DAYTYPE;

void fnFreeCal(DAYTYPE *); 
void fnDispCal(DAYTYPE *);
void fnReadCal(DAYTYPE *); 
DAYTYPE *fnCreateCal();

int main() 
{
    // Create the calendar
    DAYTYPE *weeklyCalendar = fnCreateCal();

    // Read data from the keyboard
    fnReadCal(weeklyCalendar);

    // Display the week's activity details
    fnDispCal(weeklyCalendar);

    // Free allocated memory
    fnFreeCal(weeklyCalendar);

    return 0;
}

DAYTYPE *fnCreateCal() 
{
    DAYTYPE *calendar = (DAYTYPE *)malloc(NUM_DAYS_IN_WEEK * sizeof(DAYTYPE));

    
    for(int i = 0; i < NUM_DAYS_IN_WEEK; i++) 
	{
        calendar[i].acDayName = NULL;
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }

    return calendar;
}

void fnReadCal(DAYTYPE *calendar) 
{
	char cChoice;
    for(int i = 0; i < NUM_DAYS_IN_WEEK; i++) 
	{
        printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
        scanf("%c", &cChoice); getchar();
        
        if(tolower(cChoice) == 'n')
        	continue;
        
        printf("Day Name: ");
        char nameBuffer[50];
        scanf("%s", nameBuffer);
        calendar[i].acDayName = strdup(nameBuffer);  // Dynamically allocate and copy the string


        printf("Date: ");
        scanf("%d", &calendar[i].iDate);

        
        printf("Activity: ");
        char activityBuffer[100];
        scanf(" %[^n]", activityBuffer);  // Read the entire line, including spaces
        calendar[i].acActivity = strdup(activityBuffer); 

        printf("n");
        getchar();		//remove trailing enter character in input buffer
    }
}


void fnDispCal(DAYTYPE *calendar) 
{
    printf("nWeek's Activity Details:n");
    for(int i = 0; i < NUM_DAYS_IN_WEEK; i++) 
	{
        printf("Day %d:n", i + 1);
		if(calendar[i].iDate == 0)
		{
			printf("No Activitynn");
			continue;
		}
		
        printf("  Day Name: %sn", calendar[i].acDayName);
        printf("  Date: %dn", calendar[i].iDate);
        printf("  Activity: %snn", calendar[i].acActivity);
    }
}

void fnFreeCal(DAYTYPE *calendar) 
{
    for(int i = 0; i < NUM_DAYS_IN_WEEK; i++) 
	{
        free(calendar[i].acDayName);
        free(calendar[i].acActivity);
    }
    free(calendar);
}
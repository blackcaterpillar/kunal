#include <stdio.h>
#include<time.h>

#define LEAP_YEAR ((Year%4==0 && Year%100 != 0)||Year%400==0)
#define TRUE 1


int inp;
int k=1;
int MonthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *MonthName[]={"January","February","March","April","May","June","July",
		"August","September","October","November","Decembeer"};
char *MonthName1[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP",
			"OCT","NOV","DEC"};


int getZeller(int Month,int Year)
{
	int Day = 1, ZMonth, ZYear, Zeller;
	if(Month < 3)
		ZMonth = Month+10;
	else
		ZMonth = Month-2;
	if(ZMonth > 10)
		ZYear = Year-1;
	else
		ZYear = Year;
	Zeller = ((int)((13*ZMonth-1)/5)+Day+ZYear%100+
			(int)((ZYear%100)/4)-2*(int)(ZYear/100)+ 
			(int)(ZYear/400)+77)%7;
	return Zeller;
}

		
int main()
{
	
	int i, j,inp;
	
	int day, Month, Year,Zeller;

    time_t now;
 
    time(&now);
 
    struct tm *local = localtime(&now);
 
   
 
    day = local->tm_mday;            
    Month = local->tm_mon + 1;      
    Year = local->tm_year + 1900;  
    printf("Date is: %2d/%2d/%d\n", day, Month, Year); 
 
   
come: 
      

      Zeller = getZeller(Month,Year);

		
		
		printf("%s %d\n",MonthName[Month-1],Year);
		

		
		MonthDay[1] = LEAP_YEAR ? 29 : 28;

		
		

		
		printf("\t");
    	printf("SUN     MON     TUE     WED     THU     FRI    SAT");
    
    	
        printf("\n");
    	
    	for(i = 1; i <= Zeller; i++)
    		printf("\t  ");
    	j = Zeller;
		for(i = 1; i <= MonthDay[Month-1]; i++)
		{
			if(j++ % 7 == 0)
			{
				printf("\n\t");
				if(i==day)
    			{
    			    printf("\033[0;34m"); 
    			    printf("|%2d|",i);
    			    printf("\033[0m");    
    			    
    			}else{
				
				printf("%2d",i);}
				
			}
			else{if(i==day)
    			{
    			    printf("\033[0;34m");  
    			    printf("|%2d|",i);
    			    printf("\033[0m");     
    			    
    			}else{
				printf("      %2d",i);} }
		}

               printf("\n");
		printf("ENTER 1 FOR NEXT MONTH \n");
		printf("ENTER 2 FOR PREVIOUS MONTH \n");
		printf("ENTER 3 FOR SELECTION \n");
		
		scanf("%d",&inp);
		
		if(inp!=3&& inp!=1 &&inp != 2){
		    printf("Please enter a valid number\n");
		    goto come;
		    
		    }
		if(inp == 1)           
		{
			Month++;
			if(Month > 12)
			{
				Month = 1;
				Year++;
			}
			goto come;
		}
		if(inp == 2)            
		{
			Month--;
			if(Month < 1)

			{
				Month = 12;
				Year--;
			}
			goto come;
		}
		
		
		
		if(inp == 3)  { 
		while(TRUE)
	{
		fflush(stdin);
		printf("\n\n\tEnter mm:yyyy: ");
		scanf("%d:%d", &Month, &Year);
		if(Year < 0)
		{
			printf("\nInvalid year value...");
			continue;
		}
		if(Year < 100)
			Year += 1900;
		if(Year < 2017 || Year > 2025)
		{
			printf("\nInvalid year value...");
			continue;
		}
		if(Month < 1 || Month > 12)
		{
			printf("\nInvalid month value...");

			continue;

		}

		break;

	        }
	        	
		goto come;
		
		}
}

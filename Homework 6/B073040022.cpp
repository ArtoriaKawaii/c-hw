#include<stdio.h>
#include<stdlib.h>

int main(void){

	int year, month, startDay, dayOfMonth, leapYear;

	while(1){
		leapYear = 0, year = 0, month = 0, startDay = 0;
		fflush(stdin);	//²M°£¿ù»~¿é¤J 
		printf("Input: ");
		scanf("%4d %2d %1d", &year, &month, &startDay);
		if(month >= 1 && month <= 12 && startDay >= 0 && startDay <= 6){
			if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				leapYear = 1;
			break;
		}
		printf("error!Please input YYYYMMD within year, month(01 ~ 12), and start day(0 ~ 6)\n");
	}
	switch(month){
		case 1:
			dayOfMonth = 31;
			for(int i = 0; i < 22; i++)
				printf(" ");
			printf("January, ");
			break;
		case 2:
			if(leapYear == 1)
				dayOfMonth = 29;
			else
				dayOfMonth = 28;
			for(int i = 0; i < 21; i++)
				printf(" ");
			printf("February, ");			
			break;
		case 3:
			dayOfMonth = 31;
			for(int i = 0; i < 24; i++)
				printf(" ");
			printf("March, ");			
			break;
		case 4:
			dayOfMonth = 30;
			for(int i = 0; i < 24; i++)
				printf(" ");
			printf("April, ");			
			break;
		case 5:
			dayOfMonth = 31;
			for(int i = 0; i < 26; i++)
				printf(" ");
			printf("May, ");			
			break;
		case 6:
			dayOfMonth = 30;
			for(int i = 0; i < 25; i++)
				printf(" ");
			printf("June, ");			
			break;
		case 7:
			dayOfMonth = 31;
			for(int i = 0; i < 25; i++)
				printf(" ");
			printf("July, ");			
			break;
		case 8:
			dayOfMonth = 31;
			for(int i = 0; i < 23; i++)
				printf(" ");
			printf("August, ");			
			break;
		case 9:
			dayOfMonth = 30;
			for(int i = 0; i < 20; i++)
				printf(" ");
			printf("September, ");			
			break;
		case 10:
			dayOfMonth = 31;
			for(int i = 0; i < 22; i++)
				printf(" ");
			printf("October, ");			
			break;
		case 11:
			dayOfMonth = 30;
			for(int i = 0; i < 21; i++)
				printf(" ");
			printf("November, ");			
			break;
		case 12:
			dayOfMonth = 31;
			for(int i = 0; i < 21; i++)
				printf(" ");
			printf("December, ");			
			break;
	}
	printf("%4d\n", year);
	printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");
	
	for(int i = 0; i < startDay; i++)
		printf("     ");
	for(int i = 1; i <= dayOfMonth; i++){
		printf("  %3d", i);
		if((i + startDay) % 7 == 0)
			printf("\n");
	}
	
	return 0;
}


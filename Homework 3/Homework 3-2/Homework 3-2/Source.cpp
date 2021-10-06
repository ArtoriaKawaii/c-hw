#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)    //忽略scanf()的警告訊息

int main(void) {
	
	double temperature;
	char unit;

	printf("Enter the Temperature: ");    //prompting message
	scanf("%lf%c", &temperature, &unit);

	switch (unit) {
		case 'c':
		case 'C':    //when unit == 'c' || unit == 'C' enter here
			printf("\nFahrenheit: %.3fF\n", temperature*9/5+32);
			break;    //out switch
		case 'f':
		case 'F':    //when unit == 'f' || unit == 'F' enter here
			printf("\nCelsius: %.4fC\n", (temperature-32)*5/9);
			break;    //out switch
		default :    //when unit != 'c' && unit != 'C' && unit != 'f' && unit != 'F' enter here
			printf("\nERROR!\n");
	}

	system("pause");
	return 0;
}
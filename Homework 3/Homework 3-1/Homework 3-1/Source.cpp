#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)    //忽略scanf()的警告訊息

int main(void) {

	int salary;
	double earn;

	printf("Enter the value of monthly salary : ");    //prompting message
	scanf("%d", &salary);
	

	if (salary < 0)    //檢驗輸入的月薪金額是否>=0
		printf("error");
	else if (salary <= 30000)    
		earn = salary * (12 + 1.5);
	else if (salary <= 50000 && salary > 30000)
		earn = salary * (12 + 2);
	else if (salary <= 70000 && salary > 50000)
		earn = salary * (12 + 2.5);
	else 
		earn = salary * (12 + 4);

	printf("\nYour annual salary is $%.0f\n", earn);




	system("pause");
	return 0;
}

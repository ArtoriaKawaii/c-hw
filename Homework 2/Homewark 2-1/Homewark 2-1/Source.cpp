#include<stdio.h>
#include<stdlib.h>

int main(void) {

	int a, b, c, d;

	printf("Please input four integer\n");    //prompting message
	scanf("%d %d %d %d", &a, &b, &c, &d);    //輸入4個整數分別到a,b,c,d的記憶體位置
	printf("Num1: %d\nNum2: %d\nNum3: %d\nNum4: %d\n", a, b, c, d);    //第幾個佔位符往後對應到第幾個參數

	printf("%d + %d - %d * %d = %d\n", a, b, c, d, a + b - c * d);    
	printf("%d + %d * %d - %d = %d\n", a, b, c, d, a + b * c - d);
	printf("%d - %d + %d * %d = %d\n", a, b, c, d, a - b + c * d);
	printf("%d - %d * %d + %d = %d\n", a, b, c, d, a - b * c + d);
	printf("%d * %d + %d - %d = %d\n", a, b, c, d, a * b + c - d);
	printf("%d * %d - %d + %d = %d\n", a, b, c, d, a * b - c + d);

	system("pause");
	return 0;
}
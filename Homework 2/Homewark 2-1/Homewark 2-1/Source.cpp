#include<stdio.h>
#include<stdlib.h>

int main(void) {

	int a, b, c, d;

	printf("Please input four integer\n");    //prompting message
	scanf("%d %d %d %d", &a, &b, &c, &d);    //��J4�Ӿ�Ƥ��O��a,b,c,d���O�����m
	printf("Num1: %d\nNum2: %d\nNum3: %d\nNum4: %d\n", a, b, c, d);    //�ĴX�Ӧ���ũ��������ĴX�ӰѼ�

	printf("%d + %d - %d * %d = %d\n", a, b, c, d, a + b - c * d);    
	printf("%d + %d * %d - %d = %d\n", a, b, c, d, a + b * c - d);
	printf("%d - %d + %d * %d = %d\n", a, b, c, d, a - b + c * d);
	printf("%d - %d * %d + %d = %d\n", a, b, c, d, a - b * c + d);
	printf("%d * %d + %d - %d = %d\n", a, b, c, d, a * b + c - d);
	printf("%d * %d - %d + %d = %d\n", a, b, c, d, a * b - c + d);

	system("pause");
	return 0;
}
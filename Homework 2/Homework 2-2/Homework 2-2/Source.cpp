#include<stdio.h>
#include<stdlib.h>	

int main(void) {

	float a, b, c;

	printf("�п�J�@����Ϊ��e��\n");    //prompting message
	scanf("%f %f %f", &a, &b, &c);    //��J3�ӯB�I�Ƥ��O��a,b,c���O�����m
	printf("��: %.6f\n�e: %.6f\n��: %.6f\n", a, b, c);    //��X���G�H�|�ˤ��J���ܤp���I���6��
	printf("�P��: %.4f\n", (a + b + c) * 4);
	printf("���n: %.6f\n", (a * b + a * c + b * c) * 2);
	printf("��n: %.6f\n", a * b * c);

	system("pause");
	return 0;
}
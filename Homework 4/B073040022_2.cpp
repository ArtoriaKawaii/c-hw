#include<stdio.h>
#include<stdlib.h>

int main(void){

	int a, b, c, i = 0;

	do{
		printf("�п�J�T���ΤT�����(���): ");
		scanf("%d %d %d", &a, &b, &c);
		printf("%d %d %d", a, b, c);
		if(a + b > c && a + c > b && b + c > a){
			printf("�i�H�c���T����\n");
			printf("%d %d %d", a, b, c);
			if(a == b && b == c)
				printf("�c���������T����\n\n");
			else if((a == b && a*a + b*b == c*c) || (b == c && b*b + c*c == a*a) || (a == c && a*a + c*c == b*b))	
				printf("�c���������y�����T����\n\n");
			else if(a == b || b == c || a == c)
				printf("�c���������y�T����\n\n");
			else if(a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
				printf("�c�����������T����\n\n");
			else
				printf("�c�������@��T����\n\n");
		}
		else
			printf("���i�H�c���T����\n\n");
		i ++;
	}while(i < 10);
	system("pause");
	return 0;
}

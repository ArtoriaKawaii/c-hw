#include<stdio.h>
#include<stdlib.h>

int main(void){

	int a, b, c, i = 0;

	do{
		printf("請輸入三角形三邊邊長(整數): ");
		scanf("%d %d %d", &a, &b, &c);
		printf("%d %d %d", a, b, c);
		if(a + b > c && a + c > b && b + c > a){
			printf("可以構成三角形\n");
			printf("%d %d %d", a, b, c);
			if(a == b && b == c)
				printf("構成的為正三角形\n\n");
			else if((a == b && a*a + b*b == c*c) || (b == c && b*b + c*c == a*a) || (a == c && a*a + c*c == b*b))	
				printf("構成的為等腰直角三角形\n\n");
			else if(a == b || b == c || a == c)
				printf("構成的為等腰三角形\n\n");
			else if(a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
				printf("構成的為直角三角形\n\n");
			else
				printf("構成的為一般三角形\n\n");
		}
		else
			printf("不可以構成三角形\n\n");
		i ++;
	}while(i < 10);
	system("pause");
	return 0;
}

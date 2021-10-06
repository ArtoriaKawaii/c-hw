#include<stdio.h>
#include<stdlib.h>

void myswap(int *, int *);
int mysubtotal(int, int);

int main(void){
	int num1, num2;
	while(scanf("%d %d", &num1, &num2) != EOF){
		if(num1 > num2)
			myswap(&num1, &num2);	
		printf("%d到%d的總和為：%d\n", num1, num2, mysubtotal(num1, num2));
	}
	return 0;
}

void myswap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int mysubtotal(int a, int b){
	if(a == b)
		return a;
	else
		return a + mysubtotal(a + 1, b);
}

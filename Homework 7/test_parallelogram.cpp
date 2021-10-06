#include<stdio.h>
#include<stdlib.h>

int main(void){

	int input = 1;
	for(int i = 0; i < input; i ++){
		for(int j = 0; j < i; j++)
			printf(" ");
		for(char j = 'A';j < input + 65;j++)
			printf("%c ", j);
		for(char j = input + 65 - 2; j > 64; j--)
			printf("%c ", j);
		printf("\n");
		}
	



	return 0;
}


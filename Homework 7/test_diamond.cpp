#include<stdio.h>
#include<stdlib.h>

int main(void){
	int input = 5;
	for(int i = input - 1; i > -input; i--){
		for(int j = 0; j < (abs(i)) * 2; j++)
			printf(" ");
		for(int j = 0; j < input - abs(i); j++)
			printf("%c ", char(j + 65));
		if(input > 1){
			for(int j = input - abs(i) - 1; j > 0; j--)	
				printf("%c ", char(j + 64));
		}
		printf("\n");
	}




	return 0;
}


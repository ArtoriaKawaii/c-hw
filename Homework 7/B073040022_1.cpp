#include<stdio.h>
#include<stdlib.h>

int check_range(int input);
void draw_parallelogram(int input);
void draw_diamond(int input);

int main(void){
	int n;
	printf("Please input the number N: ");
	scanf("%d", &n);
	n = check_range(n);
	printf("\n");
	draw_parallelogram(n);
	printf("\n");
	draw_diamond(n);
	return 0;
}

int check_range(int input){
	while(1){
		if(input >= 1 && input <= 26)
			break;
		else{
			printf("The number N is out of range. Please input again!!\n\n");
			printf("Please input the number N: ");
			scanf("%d",  &input);
		}
	}
	return input;
}

void draw_parallelogram(int input){
	for(int i = 0; i < input; i ++){
		for(int j = 0; j < i; j++)
			printf(" ");
		for(char j = 'A';j < input + 65;j++)
			printf("%c ", j);
		if(input > 1){
			for(char j = input + 65 - 2; j > 64; j--)
				printf("%c ", j);
			printf("\n");
		}
		else
			printf("\n");
	}
}

void draw_diamond(int input){
	for(int i = input - 1; i > -input; i--){
		for(int j = 0; j < (abs(i)) * 2; j++)
			printf(" ");
		for(int j = 0; j < input - abs(i); j++)
			printf("%c ", char(j + 65));
		if(input > 1){
			for(int j = input - abs(i) - 1; j > 0; j--)	
				printf("%c ", char(j + 64));
		}
		else
			printf("\n");
		printf("\n");
	}
}

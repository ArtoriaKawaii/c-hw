#include<stdio.h>
#include<stdlib.h>

struct Stack{
	Stack* next;
	int data;
};

void mypush(int);
int mypop();
void PrintStack();

Stack *top = NULL;

int main(void){
	int instruction, pushNum, pop;
	PrintStack();
	printf("Please input the instruction:");
	while(scanf("%d", &instruction) != EOF){
		if(instruction == 1){
			scanf(" %d", &pushNum);
			mypush(pushNum);
			printf("push %d into stack.\n", pushNum);
			PrintStack();
		}
		else if(instruction == 2){
			if(top == NULL)
				printf("Error pop.\n");
			else{
				pop = mypop();
				printf("pop %d from stack.\n", pop);
			}
			PrintStack();
		}
		else
			printf("input error!\n");
		fflush(stdin);
		printf("Please input the instruction:");
	}

	free(top);
	return 0;
}

void mypush(int value){
	Stack* s_new;
	s_new = (Stack*)malloc(sizeof(Stack));
	s_new -> data = value;
	s_new -> next = NULL;
	s_new -> next = top;
	top = s_new;
}

int mypop(){
	Stack *temp;
	int num;
	temp = top;
	num = temp -> data;
	top = top -> next;
	free(temp);
	return num;
}

void PrintStack(){
	if(top == NULL)
		printf("Nothing in stack.\n");
	else{
		Stack *current;
		current = top;
		while(current != NULL){
			printf("*\t*\n*%5d  *\n*\t*\n*********\n", current -> data);
			current = current -> next;
		}
	}
}

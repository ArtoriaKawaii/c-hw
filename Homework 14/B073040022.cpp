#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{	//single linked-list, small -> big
	int data;
	NODE *next = NULL;
};

NODE *first = NULL, *last = NULL;	

void myinsert(int num);
int mydelete(int num);
void printList();
NODE *search(int num);

int main(void){
	FILE *fptr = fopen("input.txt", "r");
	int listNum, listElement, orderNum;
	char order[10];
	printf("Insert the original numbers.\n");
	fscanf(fptr, "%d", &listNum);
	for(int i = 0; i < listNum; i++){
		fscanf(fptr, "%d ", &listElement);
		myinsert(listElement);
	}
	printList();
	printf("--------------------\n");
	while(1){
		fscanf(fptr, "%s %d", order, &orderNum);
		if(strcmp(order, "insert") == 0){
			printf("Insert %d.\n", orderNum);
			myinsert(orderNum);
			printList();
		}
		else if(strcmp(order, "delete") == 0){
			printf("Delete %d.\n", orderNum);
			mydelete(orderNum);
			printList();
		}
		if(feof(fptr)){
			printf("--------------------\n");
			printf("Finish total input.\n");
			break;
		}
		printf("--------------------\n");
	}
	


	fclose(fptr);
	return 0;
}

void myinsert(int num){
	if(search(num) == NULL){
		NODE *newNode = (NODE*)malloc(sizeof(NODE)), *current;
		newNode -> data = num;
		newNode -> next = NULL;
		if(first == NULL && last == NULL){
			first = newNode;
			last = newNode;
		}
		else if(first == last){
			if(num <= first -> data){
				first = newNode;
				first -> next = last;
			}
			else{
				last -> next = newNode;
				last = newNode;
			}
		}
		else{
			if(num <= first -> data){
				newNode -> next = first;
				first = newNode;
			}
			else if(num > last -> data){
				last -> next = newNode;
				last = newNode;
			}
			else{
				current = first;
				while(!(num > current -> data && num <= current -> next -> data))
					current = current -> next;
				newNode -> next = current -> next;
				current -> next = newNode;				
			}
		}
	}
	else
		printf("Number %d is in list already.\n", num);
}

int mydelete(int num){
	NODE *temp, *current;
	if(first == NULL && last == NULL){
		printf("The list is already empty.\n");
		return -1;
	}
	else if(search(num) == NULL){
		printf("Number %d is not in list.\n", num);
		return -1;
	}
	else if(first == last && first == search(num)){
		free(first);
		first = NULL;
		last = NULL;
		return 0;	//return 0 if delete successfully
	}
	else if(first -> next == last && search(num) == first){
		free(first);
		first = last;
		return 0;
	}
	else if(first -> next == last && search(num) == last){
		free(last);
		last = first;
		first -> next = NULL;
		return 0;
	}
	else if(search(num) == first){
		temp = first;
		free(first);
		first = temp -> next;
		return 0;
	}
	else if(search(num) == last){
		current = first;
		while(current -> next != last)
			current = current -> next;	
		free(last);
		last = current;
		current -> next = NULL;
		return 0;		
	}
	else{
		current = first;
		temp = search(num);
		while(current -> next != temp)
			current = current -> next;
		current -> next = temp -> next;
		free(temp);
		return 0;	
	}
}

void printList(){
	NODE *current = first;
	printf("List: ");
	while(current != NULL){
		printf("%d ", current -> data);
		current = current -> next;
	}
	printf("\n");
}

NODE *search(int num){
	NODE *current = first;
	while(current != NULL && current -> data != num)
		current = current -> next;
	return current;
}

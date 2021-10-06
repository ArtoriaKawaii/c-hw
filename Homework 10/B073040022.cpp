#include<stdio.h>

int bubble_sort(int *, int, int *);
int selection_sort(int *, int, int *);
int insertion_sort(int *, int, int *);	
void swap(int *a, int *b);
FILE *fptr_bubble, *fptr_selection, *fptr_insertion;	

int main(){
	FILE *fptr;
	int array[2000] = {0}, arraySize = 250, compareTimes_bubble = 0, compareTimes_selection = 0, compareTimes_insertion = 0;  
	fptr_bubble = fopen("bubble.txt", "w");
	fprintf(fptr_bubble, "Bubble sort result:\n");
	fptr_selection = fopen("selection.txt", "w");
	fprintf(fptr_selection, "Selection sort result:\n");
	fptr_insertion = fopen("insertion.txt", "w");
	fprintf(fptr_insertion, "Insertion sort result:\n");
	fptr = fopen("input.txt", "r");
	
	for(int i = 1; i <= 3; i++){
		printf("Sequence %d\tbubble\t\tselection\tinsertion   \n", i);
		for(int j = 0; j < 60; j++)
			printf("-");
		printf("\n");
		arraySize *= 2;
		for(int i = 0; i < arraySize; i++)
			fscanf(fptr, "%d", &array[i]);
		printf("swap times\t%d\t\t%d\t\t%d\n", bubble_sort(array, arraySize, &compareTimes_bubble), selection_sort(array, arraySize, &compareTimes_selection), insertion_sort(array, arraySize, &compareTimes_insertion));
		printf("compare times\t%d\t\t%d\t\t%d\n", compareTimes_bubble, compareTimes_selection, compareTimes_insertion);
		for(int j = 0; j < 60; j++)
			printf("-");
		printf("\n");	
	}
	fclose(fptr);
	fclose(fptr_bubble);
	fclose(fptr_selection);
	fclose(fptr_insertion);
	return 0;
}

int bubble_sort(int array[], int arraySize, int *compareTimes){
	int swapTimes = 0, tempArray[arraySize] = {0}, count = 0;
	for(int i = 0; i < arraySize; i++)
		tempArray[i] = array[i]; 
	for(int i = 0; i < arraySize - 1; i++){
		for(int j = 0; j < arraySize - 1 - i; j++){	//最大往後推 
			count++;
			if(tempArray[j] > tempArray[j + 1]){
				swap(&tempArray[j], &tempArray[j + 1]);
				swapTimes++;
			}
		}
	}
	*compareTimes = count;
	for(int i = 0; i < arraySize; i++)
		fprintf(fptr_bubble, "%d ", tempArray[i]);
	fprintf(fptr_bubble, "\n");
	return swapTimes;
}

int selection_sort(int array[], int arraySize, int *compareTimes){
	int swapTimes = 0, max, tempArray[arraySize] = {0}, count = 0;
	for(int i = 0; i < arraySize; i++)
		tempArray[i] = array[i]; 
	for(int j = 0; j < arraySize - 1; j++){
		max = 0;
		for(int i = 1; i < arraySize - j; i++){	//最大往後推 
			count++;
			if(tempArray[max] <= tempArray[i])
				max = i;
		}
		swap(&tempArray[max], &tempArray[arraySize - 1 - j]);	//自己交換也算 
		swapTimes++;
	}
	*compareTimes = count;
	for(int i = 0; i < arraySize; i++)
		fprintf(fptr_selection, "%d ", tempArray[i]);
	fprintf(fptr_selection, "\n");
	return swapTimes;
}

int insertion_sort(int array[], int arraySize, int *compareTimes){
	int swapTimes = 0, tempIndex, tempArray[arraySize] = {0}, count = 0;
	for(int i = 0; i < arraySize; i++)
		tempArray[i] = array[i]; 
	for(int i = 1; i < arraySize; i++){
		tempIndex = i;
		while(tempIndex > 0 && tempArray[tempIndex - 1] > tempArray[tempIndex]){	//將新增的元素逐漸往前推到正確位置 
			swap(&tempArray[tempIndex - 1], &tempArray[tempIndex]);
			tempIndex--;
			count++;
		}
		swapTimes++;	//每輪會有一個元素移動到正確位置 
	}
	*compareTimes = count;
	for(int i = 0; i < arraySize; i++)
		fprintf(fptr_insertion, "%d ", tempArray[i]);
	fprintf(fptr_insertion, "\n");
	return swapTimes;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


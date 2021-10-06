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
	fptr_selection = fopen("selection.txt", "w");
	fptr_insertion = fopen("insertion.txt", "w");
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
		for(int j = 0; j < arraySize - 1 - i; j++){
			count++;
			if(tempArray[j] > tempArray[j + 1]){
				swap(&tempArray[j], &tempArray[j + 1]);
				swapTimes++;
			}
		}
	}
	*compareTimes = count;
	fprintf(fptr_bubble, "Bubble sort result:\n");
	for(int i = 0; i < arraySize; i++)
		fprintf(fptr_bubble, "%d ", tempArray[i]);
	fprintf(fptr_bubble, "\n");
	return swapTimes;
}

int selection_sort(int array[], int arraySize, int *compareTimes){
	int swapTimes = 0, min, tempArray[arraySize] = {0}, count = 0;
	for(int i = 0; i < arraySize; i++)
		tempArray[i] = array[i]; 
	for(int j = 0; j < arraySize - 1; j++){
		min = j;
		for(int i = j + 1; i < arraySize; i++){
			count++;
			if(tempArray[min] >= tempArray[i])
				min = i;
		}
			swapTimes++;
		if(min != j){
			swap(&tempArray[min], &tempArray[j]);
		}
	}
	*compareTimes = count;
	fprintf(fptr_selection, "Selection sort result:\n");
	for(int i = 0; i < arraySize; i++)
		fprintf(fptr_selection, "%d ", tempArray[i]);
	fprintf(fptr_selection, "\n");
	return swapTimes;
}

int insertion_sort(int array[], int arraySize, int *compareTimes){
	int swapTimes = 0, temp1, temp2, index, tempArray[arraySize] = {0}, count = 0;
	for(int i = 0; i < arraySize; i++)
		tempArray[i] = array[i]; 
	for(int i = 1; i < arraySize; i++){
		if(tempArray[i - 1] > tempArray[i]){
			temp1 = tempArray[i];
			tempArray[i] = tempArray[i - 1];
			index = i - 1;
			temp2 = temp1;
			swapTimes++;
			count++;
			for(int j = 0; j < i - 1; j++){
				if(temp1 < tempArray[j]){
					temp2 = tempArray[j];
					tempArray[j] = temp1;
					index = j + 1;
					count++;
					break;
				}
			}
			for(int j = i - 1; j > index; j--){
				tempArray[j] = tempArray[j - 1];
				count++;
			}
			tempArray[index] = temp2;
		}	
	}
	*compareTimes = count;
	fprintf(fptr_insertion, "Insertion sort result:\n");
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


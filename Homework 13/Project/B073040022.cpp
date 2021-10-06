#include"B073040022.h"

void mysort(int* array, int size){
	for(int i = 0; i < size - 1; i++)
		for(int j = 0; j < size - 1 - i; j++)
			if(array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
}
int myBinarySearch(int* array, int target, int head, int tail){
	int index = (tail + head) / 2;
	if(target == array[index])
		return index;
	else if(target > array[index] && head < tail){
		head = index + 1;
		myBinarySearch(array, target, head, tail);
	}
	else if(target < array[index] && head < tail){
		tail = index - 1;
		myBinarySearch(array, target, head, tail);
	}
	else
		return -1;
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


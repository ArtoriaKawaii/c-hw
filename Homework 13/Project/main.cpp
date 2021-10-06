#include"B073040022.h"

int main(void){
	int arrSize, target, f_index;
	FILE *fptr = fopen("input.txt", "r");
	fscanf(fptr, "%d", &arrSize);
	int arr[arrSize];
	for(int i = 0; i < arrSize; i++)
		fscanf(fptr, "%d", &arr[i]);
	fclose(fptr);
	mysort(arr, arrSize);
	printf("Sorted finish.\n");
	printf("Please input your target:");
/*	for(int i = 0; i < arrSize; i++){	//For ckeck
		target = arr[i];
		f_index = myBinarySearch(arr, target, 0, arrSize - 1);
		if(f_index == -1)
			printf("target not found.\n");
		else
			printf("%d. target found at index %d.\n", i + 1, f_index);
	}*/
	while(scanf("%d", &target) != EOF){
		f_index = myBinarySearch(arr, target, 0, arrSize - 1);
		if(f_index == -1)
			printf("target not found.\n");
		else
			printf("target found at index %d.\n", f_index);
		printf("Please input your target:");
	}
	return 0;
}


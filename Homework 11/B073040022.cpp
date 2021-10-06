#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void binomial(int);
void median(int*);
void magic_square(int);
long long factorial(int);
void swap(int*, int*);

int main(void){
	int bi_pow, nums[11], ms_size;
	printf("Please input number of binomial powers:");
	scanf("%d", &bi_pow);
	binomial(bi_pow);
	printf("\nPlease input 11 numbers:\n");
	fflush(stdin);
	scanf("%d %d %d %d %d %d %d %d %d %d %d", 
	&nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5], 
	&nums[6], &nums[7], &nums[8], &nums[9], &nums[10]);
	
	median(nums);
	printf("\nPlease input the size of magic square: ");
	fflush(stdin);
	scanf("%d", &ms_size);
	magic_square(ms_size);
	return 0;
}

void binomial(int n){
	for(int i = 0; i <= n; i++){
		if(i == 0)
			printf("1");
		else
			for(int j = 0; j <= i; j++)
				printf("%d ", factorial(i) / (factorial(j) * factorial(i - j)));
		printf("\n");
	}
}

void median(int arr[]){
	for(int i = 0; i < 11 - 1; i++)
		for(int j = 0; j < 11 - 1 - i; j++)	//最大往後推 
			if(arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
	for(int i = 0; i < 11; i++)
		printf("%d ", arr[i]);
	printf("\nmedian is : %d\n", arr[5]);
}

void magic_square(int n){
	int arr[n][n];	//arr[0][0] ~ arr[n - 1][n - 1]
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = 0;
	arr[0][n / 2] = 1;
	for(int i = 0, j = n / 2, k = 2;k <= n * n; k++){
		i--;
		j--;
		if(i == -1)
			i = n - 1;
		if(j == -1)
			j = n - 1;
		if(arr[i][j] != 0){
			i += 2;
			if(i > n - 1)
				i -= n;
			j++;
			if(j > n - 1)
				j -= n;
		}
		arr[i][j] = k;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(n < 4)			
				printf("%d ", arr[i][j]);
			else if(n < 10)
				printf("%2d ", arr[i][j]);
			else
				printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

long long factorial(int n){
	if(n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);	
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

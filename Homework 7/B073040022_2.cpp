#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	char searchChar, character;
	int times, arr[1000] = {0}, searchValue, randNum;
	FILE *fptr1;
	
	if((fptr1 = fopen("input1.txt", "w")) == NULL)
		printf("File can not be opened\n");
	else{
		srand(1);
		for(int i = 0; i < 1000; i++){
			randNum = rand() % 52 + 1;
			if(randNum > 26)
				character = randNum - 26 + 97 - 1;
			else
				character = randNum + 65 - 1;
			fprintf(fptr1, "%c", character);
		}
		fclose(fptr1);
		fptr1 = fopen("input1.txt", "r");
		for(int i = 0; i < 1000; i++){
			fscanf(fptr1, "%c", &character);
			if(character >= 'a')
				arr[i] = character - 97 + 1;
			else
				arr[i] = character - 65 + 1;
		}
		fclose(fptr1);
		while(1){
			times = 0;
			fflush(stdin);
			printf("請輸入要尋找的字元: ");
			scanf("%c", &searchChar);
			if(searchChar == '*'){
				printf("結束尋找。\n"); 
				break;
			}
			else if(searchChar >= 'a' && searchChar <= 'z' || searchChar >= 'A' && searchChar <= 'Z'){
				if(searchChar >= 'a')
					searchValue = searchChar - 97 + 1;
				else
					searchValue = searchChar - 65 + 1;
				for(int i = 0; i < 1000; i++){
					if(arr[i] == searchValue)
						times++;				
				}
				printf("字元'%c'一共找到: %d\n\n", searchChar, times);
			}
			else
				printf("輸入錯誤，再試一次。\n\n");
		}
	}
	return 0;
}


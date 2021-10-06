#include<stdio.h>    //加入函式庫以使用輸入函式scanf/輸出函式printf 
#include<stdlib.h>    //加入函式庫以使用system指令 

int main(void){    //主函式不接受參數，並回傳一整數 
	
	char character;    //設字元變數character 
	
	printf("請輸入任一字元：");    //提示輸入字元 
	scanf("%c", &character);    //將輸入字元儲存到變數character的記憶體位置 
	
	printf("\t%7c\n", character);    //先空八格(tab)，再空6格，第7格開始輸出所輸入字元 
	printf("\t%6c%c%c\n", character, character, character);     
	printf("\t%3c%c%c%c%c%c%c%c%c\n", character, character, character, character, character, character, character, character, character);
	printf("\t%5c%c%c%c%c\n", character, character, character, character, character);
	printf("\t%3c%c%c%c%c%c%c%c%c\n", character, character, character, character, character, character, character, character, character);
	printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",character, character, character, character, character, character, character, character, character, character, character, character, character);
	printf("\t%5c%c%c%c%c\n", character, character, character, character, character);
	printf("\t%5c%c%c%c%c\n", character, character, character, character, character);
	/*第10行到第17行同理*/
	
	system("pause");    //程式結束前暫停以觀察結果 
	return 0;    //回傳0表執行正常
}

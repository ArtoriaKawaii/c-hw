#include<stdio.h>    //�[�J�禡�w�H�ϥο�J�禡scanf/��X�禡printf 
#include<stdlib.h>    //�[�J�禡�w�H�ϥ�system���O 

int main(void){    //�D�禡�������ѼơA�æ^�Ǥ@��� 
	
	char character;    //�]�r���ܼ�character 
	
	printf("�п�J���@�r���G");    //���ܿ�J�r�� 
	scanf("%c", &character);    //�N��J�r���x�s���ܼ�character���O�����m 
	
	printf("\t%7c\n", character);    //���ŤK��(tab)�A�A��6��A��7��}�l��X�ҿ�J�r�� 
	printf("\t%6c%c%c\n", character, character, character);     
	printf("\t%3c%c%c%c%c%c%c%c%c\n", character, character, character, character, character, character, character, character, character);
	printf("\t%5c%c%c%c%c\n", character, character, character, character, character);
	printf("\t%3c%c%c%c%c%c%c%c%c\n", character, character, character, character, character, character, character, character, character);
	printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",character, character, character, character, character, character, character, character, character, character, character, character, character);
	printf("\t%5c%c%c%c%c\n", character, character, character, character, character);
	printf("\t%5c%c%c%c%c\n", character, character, character, character, character);
	/*��10����17��P�z*/
	
	system("pause");    //�{�������e�Ȱ��H�[��G 
	return 0;    //�^��0����楿�`
}

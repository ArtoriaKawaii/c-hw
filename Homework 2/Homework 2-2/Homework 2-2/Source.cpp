#include<stdio.h>
#include<stdlib.h>	

int main(void) {

	float a, b, c;

	printf("請輸入一長方形長寬高\n");    //prompting message
	scanf("%f %f %f", &a, &b, &c);    //輸入3個浮點數分別到a,b,c的記憶體位置
	printf("長: %.6f\n寬: %.6f\n高: %.6f\n", a, b, c);    //輸出結果以四捨五入取至小數點後第6位
	printf("周長: %.4f\n", (a + b + c) * 4);
	printf("表面積: %.6f\n", (a * b + a * c + b * c) * 2);
	printf("體積: %.6f\n", a * b * c);

	system("pause");
	return 0;
}
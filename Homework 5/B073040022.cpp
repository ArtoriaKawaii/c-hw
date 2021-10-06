#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265359

int a, b, c, d, e;
int showXRange_start, showXRange_end;
int tangentPointAtX;
double slopeOfTangentLine;
int temp, space;

//自訂函式 
int numDigitWithNeg(int num);	//判斷位數，包含負號 
double 	slopeOfTangentLineAtPointX(int x);	//斜率計算 - 微分
int fuctionResults(int x);	//題目方程式 
int slopeFunc(int x);	//切線方程式 

int main(void){

	printf("請輸入5個係數：");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	while(1 == 1){
		printf("請輸入x軸範圍：");
		scanf("%d %d", &showXRange_start, &showXRange_end);
		if(showXRange_start > showXRange_end){
			temp = showXRange_start;
			showXRange_start = showXRange_end;
			showXRange_end = temp;
			break;
		}
		else if(showXRange_start == showXRange_end)
			printf("error!\n");
		else
			break;
	}
	
	printf("請輸入所求切點的x值：");
	scanf("%d", &tangentPointAtX);
	
	slopeOfTangentLine = slopeOfTangentLineAtPointX(tangentPointAtX);
	printf("實際切線斜率：%lf\n", slopeOfTangentLine);
	
	for(int x = showXRange_start - 1; x <= showXRange_end; x++){
		for(int y = -39; y <= 40 ; y++){
			if(x == showXRange_start - 1){	//印Y軸軸線上的數字 
				if(y < 0){
					if(y >= -36 && y <= -11 && y % 5 == -1){
						printf("%d", y + 1);
						y = y + 2;
					}
					else if(y == -6 || y == -1)
						printf("%d", y + 1);
					else
						printf(" ");
				}
				else if(y > 0){
					if(y == 5)
						printf("%d", y);
					else if(y >= 10 && y <= 35 && y % 5 == 0){
						printf("%d", y);
						y = y + 1;
					}
					else
						printf(" ");
				}
			}
/**/		else if(x == showXRange_start){	//印Y軸軸線 
				if(y == 0){
					if(numDigitWithNeg(showXRange_start) == 1)	//檢測位數 
						printf("%d", x);
					else if(numDigitWithNeg(showXRange_start) == 2){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 1;
						}
						else if(showXRange_start < 0){
							printf("\b");
							printf("%d ", x);
							y = y + 1;
						}
					}
					else if(numDigitWithNeg(showXRange_start) == 3){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 2;
						}
						else{
							printf("\b");
							printf("%d ", x);
							y = y + 2;
						}
					}
					else if(numDigitWithNeg(showXRange_start) == 4){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 3;
						}
						else{
							printf("\b");
							printf("%d ", x);
							y = y + 3;
						}
					}
					else if(numDigitWithNeg(showXRange_start) == 5){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 4;
						}
						else{
							printf("\b");
							printf("%d ", x);
							y = y + 4;
						}
					}
					else if(numDigitWithNeg(showXRange_start) == 6){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 5;
						}
						else{
							printf("\b");
							printf("%d ", x);
							y = y + 5;
						}
					}
					else if(numDigitWithNeg(showXRange_start) == 7){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 6;
						}
						else{
							printf("\b");
							printf("%d ", x);
							y = y + 6;
						}
					}
					else if(numDigitWithNeg(showXRange_start) == 8){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 7;
						}
						else{
							printf("\b");
							printf("%d ", x);
							y = y + 7;
						}
					}
					else if(numDigitWithNeg(showXRange_start) == 9){
						if(showXRange_start > 0){
							printf("%d", x);
							y = y + 8;
						}
						else{
							printf("\b");
							printf("%d ", x);
							y = y + 8;
						}
					}
				}
				else if(y == 40)
					printf("Y");
				else if(y == fuctionResults(x))	//若軸線上需印函數，以圖形為優先 
					printf("*");
				
				else if(y % 5 == 0 && y != 0)
					printf("+");
				else 
					printf("-");
			}
			else{	//印剩下的圖形 
				if(y == fuctionResults(x) && y == 0 && x % 5 != 0)	//印函數圖形  
					printf("*");
				else if(y == 0){	//印X軸軸線 
					if(x % 5 == 0){
						if(y == fuctionResults(tangentPointAtX) && x == tangentPointAtX){
							printf("P ( %d,%d )", x, y);
							y = y + numDigitWithNeg(x) + numDigitWithNeg(y) + 6;
								if(y > 40)
									y = 40;
						}
						else if(numDigitWithNeg(showXRange_start) == 1)	//檢測位數 
							printf("%d", x);
						else if(numDigitWithNeg(showXRange_start) == 2){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 1;
							}
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 1;
							}
						}
						else if(numDigitWithNeg(showXRange_start) == 3){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 2;
							}
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 2;
							}
						}
						else if(numDigitWithNeg(showXRange_start) == 4){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 3;
							}
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 3;
							}
						}
						else if(numDigitWithNeg(showXRange_start) == 5){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 4;
							}
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 4;
							}
						}
						else if(numDigitWithNeg(showXRange_start) == 6){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 5;
							}	
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 5;
							}
						}
						else if(numDigitWithNeg(showXRange_start) == 7){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 6;
							}
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 6;
							}
						}
						else if(numDigitWithNeg(showXRange_start) == 8){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 7;
							}
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 7;
							}
						}
						else if(numDigitWithNeg(showXRange_start) == 9){
							if(showXRange_start > 0){
								printf("%d", x);
								y = y + 8;
							}
							else{
								printf("\b");
								printf("%d ", x);
								y = y + 8;
							}
						}
					}
					else if(y == fuctionResults(x))
						printf("*");
					else 
						printf("|");
				}
				else if(y == fuctionResults(x)){	//印P點+座標 
					if(x == tangentPointAtX){
						if(abs(y) >= numDigitWithNeg(x) + numDigitWithNeg(y) + 7){
							if(y >= 0){
								for(int i = 0; i < numDigitWithNeg(x) + numDigitWithNeg(y) + 6; i++){
									printf("\b");
								}
								printf("( %d,%d ) P", x, y);
							}
							else{
								printf("P ( %d,%d )", x, y);
								y = y + numDigitWithNeg(x) + numDigitWithNeg(y) + 6;
								if(y > 0)
									y = 0;
							}
						}
						else if(abs(y) <= numDigitWithNeg(x) + numDigitWithNeg(y) + 7){
							if(y >= 0){
								printf("P ( %d,%d )", x, y);
								y = y + numDigitWithNeg(x) + numDigitWithNeg(y) + 6;
								if(y > 40)
									y = 40;
							}
							else{
								for(int i = 0; i < numDigitWithNeg(x) + numDigitWithNeg(y) + 6; i++){
									printf("\b");
								}
								printf("( %d,%d ) P", x, y);
							}
						}
					}
					else
						printf("*");
				}
				else if(x != tangentPointAtX && x >= tangentPointAtX - 5 && x <= tangentPointAtX + 5 && ((int)slopeOfTangentLine == 0 || (int)slopeOfTangentLine == -0)){	//印當斜率等於0時的切線 
					if(y == fuctionResults(tangentPointAtX) && x % 5 == 0)
						printf("|");
					else if(y == fuctionResults(tangentPointAtX))	
						printf("|");
					else
						printf(" ");
				}
				else if(x != tangentPointAtX && x >= tangentPointAtX - 5 && x <= tangentPointAtX + 5){	//印在另外三種情況時的切線 
					if(slopeOfTangentLine > 0 && slopeOfTangentLine <= 10){
						if(y == slopeFunc(x) && x % 5 == 0)
							printf("\\");
						else if(y == slopeFunc(x))	
							printf("\\");
						else
							printf(" ");
					}
					else if(slopeOfTangentLine < 0 && slopeOfTangentLine >= -10){
						if(y == slopeFunc(x) && x % 5 == 0)
							printf("/");
						else if(y == slopeFunc(x))	
							printf("/");
						else
							printf(" ");
					}
					else if(slopeOfTangentLine > 10 && slopeOfTangentLine < -10){
						if(y == slopeFunc(x) && x % 5 == 0)
							printf("-");
						else if(y == slopeFunc(x))	
							printf("-");
						else
							printf(" ");
					}	
					else
						printf(" ");
				}
				else 
					printf(" ");
			}	
		}
	}
	return 0;
}

//自訂函式 
int numDigitWithNeg(int num){	//判斷位數，包含負號 
	int numDigit = 1;
	while(1 == 1){
		if(num / (int)pow(10,numDigit) == 0) 
			break;
		numDigit++; 		
	}
	if(num < 0){
		numDigit++;
	}
	return numDigit;
}

double 	slopeOfTangentLineAtPointX(int x){	//斜率計算 - 微分
	double slope;
	slope = (PI * c * d * cos(PI * d * x / 30) - PI * a * b * sin(PI * b * x / 30))/30;
	if((int)slope == 0)
		slope = -slope;
	return slope;	
}

int fuctionResults(int x){	//題目方程式 
	return a * cos(b * PI / 30 * x) + c * sin(d * PI / 30 * x) + e;
}

int slopeFunc(int x){	//切線方程式 
	int y;
	int b;
	b = fuctionResults(tangentPointAtX) - slopeOfTangentLine * tangentPointAtX;
	y = (int)(slopeOfTangentLine * x + b + 0.999999);
	return y;
}

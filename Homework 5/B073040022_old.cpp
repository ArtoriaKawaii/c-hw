#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265359

//�j���� 

int a, b, c, d, e;
int showXRange_start, showXRange_end;
int tangentPointAtX;
double slopeOfTangentLine;
int temp;

//�ۭq�禡 
int numDigitWithNeg(int num);	//�P�_��ơA�]�t�t�� 
double 	slopeOfTangentLineAtPointX(int x);	//�ײv�p�� - �L��
int fuctionResults(int x);	//�D�ؤ�{�� 
int slopeFunc(int x);	//���u��{�� 

int main(void){

	printf("�п�J5�ӫY�ơG");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	while(1 == 1){
		printf("�п�Jx�b�d��G");
		scanf("%d %d", &showXRange_start, &showXRange_end);
		if(showXRange_start > showXRange_end){
			temp = showXRange_start;
			showXRange_start = showXRange_end;
			showXRange_end = temp;
			break;
		}
		else if(showXRange_start == showXRange_end)
			printf("error!");
		else
			break;
	}
	
	printf("�п�J�ҨD���I��x�ȡG");
	scanf("%d", &tangentPointAtX);
	
	slopeOfTangentLine = slopeOfTangentLineAtPointX(tangentPointAtX);
	printf("��ڤ��u�ײv�G%lf\n", slopeOfTangentLine);
	
	for(int x = showXRange_start - 1; x <= showXRange_end; x++){
		for(int y = -39; y <= 40 ; y++){
			if(x == showXRange_start - 1){	//�LY�b�b�u�W���Ʀr 
				if(y <= 0 && y % 5 == -1){
					if(y != -36 && y < -1)
						printf("\b\b%d", y + 1);
					else
						printf("%d", y + 1);
				}
				else if(y > 0 && y % 5 == 0 && y < 40){
					if(y == 5)
						printf("\b%d", y);
					else if(y == 10)
						printf("%d", y);
					else
						printf("\b%d", y);
				}
				else
					printf(" ");	
			}
			else if(x == showXRange_start){	//�LY�b�b�u 
				if((y == fuctionResults(x)) && (y >= 3 || y <= -3))	//�Y�b�u�W�ݦL��ơA�H�ϧά��u�� 
					printf("*");
				else if(y % 5 == 0 && y != 40){		
					if(y == 0){
						if(numDigitWithNeg(showXRange_start) == 3){	
							printf("%d", x);
						}
						else if(numDigitWithNeg(showXRange_start) == 2){
							printf(" %d", x);
						}
						else if(numDigitWithNeg(showXRange_start) == 1){
							printf(" %d ", x);
						}
					}
					else
						printf("+");
				}
				else if(y == 40)
					printf("Y");
				else if(y <= -2 || y >= 2)
					printf("-");
			}
			else{	//�L�ѤU���ϧ� 
				if(y == fuctionResults(x) && y == 0 && x % 5 != 0)	//�L��ƹϧ�  
					printf("*");
				else if(y == fuctionResults(x) && y != 0){	//�L���I�y�� 
					if(x == tangentPointAtX)
							printf("\b\b\b\b\b\b\b\b\b\b\b(%3d,%3d ) P", x, y);
					else
						printf("*");
				}
				else if(y == 0){	//�LX�b�b�u 
					if(x % 5 == 0){
						printf("%d", x);
						if(x >= 10)
							y = y + 1;
					}
					else 
						printf("|");
				}
				else if(x >= tangentPointAtX - 5 && x <= tangentPointAtX + 5 && ((int)slopeOfTangentLine == 0 || (int)slopeOfTangentLine == -0)){	//�L��ײv����0�ɪ����u 
					if(y == fuctionResults(tangentPointAtX) && x % 5 == 0)
						printf("|");
					else if(y == fuctionResults(tangentPointAtX))	
						printf("|");
					else
						printf(" ");
				}
				else if(x >= tangentPointAtX - 5 && x <= tangentPointAtX + 5){	//�L�b�t�~�T�ر��p�ɪ����u 
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
		printf("\n");
	}
	return 0;
}

//�ۭq�禡 
int numDigitWithNeg(int num){	//�P�_��ơA�]�t�t�� 
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

double 	slopeOfTangentLineAtPointX(int x){	//�ײv�p�� - �L��
	double slope;
	slope = (PI * c * d * cos(PI * d * x / 30) - PI * a * b * sin(PI * b * x / 30))/30;
	if((int)slope == 0)
		slope = -slope;
	return slope;	
}

int fuctionResults(int x){	//�D�ؤ�{�� 
	return a * cos(b * PI / 30 * x) + c * sin(d * PI / 30 * x) + e;
}

int slopeFunc(int x){	//���u��{�� 
	int y;
	int b;
	b = fuctionResults(tangentPointAtX) - slopeOfTangentLine * tangentPointAtX;
	y = (int)(slopeOfTangentLine * x + b + 0.999999);
	return y;
}

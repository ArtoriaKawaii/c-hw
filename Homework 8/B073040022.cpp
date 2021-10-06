#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*function
y = a * pow(x, 5) + b * pow(x, 4) + c * pow(x, 3) + d * pow(x, 2) + e * x + f

  differentiable 
y' = 5 * a * pow(a, 4) + 4 * b * pow(x, 3) + 3 * c * pow(x, 2) + 2 * d * x + e

  Derivative
y' = (f(x + dx) - f(x)) / dx

  Antiderivative
Y = a / 6 * pow(x, 6) + b / 5 * pow(x, 5) + c / 4 * pow(x, 4) + d / 3 * pow(x, 3) + e / 2 * pow(x, 2) + f * x + k, (k is a const)	*/

void swap(int*, int*);
double functionInputInt(int);
double functionInputDouble(double);
void drawFunction(void);
void Differential_1(int);
void Differential_2(int);
void Integral_1(int,int);
void Integral_2(int,int);

double a, b, c, d, e, f;
int px;

int main(void){
	int x1, x2, temp;
	printf("Please input 6 coefficients: ");
	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
	fflush(stdin);
	printf("Please input the range of x-axis: ");
	scanf("%d %d", &x1, &x2);
	fflush(stdin);
	if(x1 > x2)		//let x2 >= x1
		swap(&x1, &x2);
	printf("Please input the x-axis coordinate of tangent point P: ");
	scanf("%d", &px);
	drawFunction();
	Differential_1(px);
	Differential_2(px);
	Integral_1(x1, x2);
	Integral_2(x1, x2);
	return 0;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

double functionInputInt(int x){
	return a * pow(x, 5) + b * pow(x, 4) + c * pow(x, 3) + d * pow(x, 2) + e * x + f;
}

double functionInputDouble(double x){
	return a * pow(x, 5) + b * pow(x, 4) + c * pow(x, 3) + d * pow(x, 2) + e * x + f;
}

void drawFunction(void){
	for(int x = -10; x <= 10; x++){
		for(int y = -39; y <= 40; y++){
			if(x == px && y == (int)functionInputInt(px))
				printf("P");
			else if(y == (int)functionInputInt(x))
				printf("*");
			else if(y == -1 && x == -10 && (int)functionInputInt(x) != -1 && (int)functionInputInt(x) != 0 && (int)functionInputInt(x) != 1){
				printf("%d", x);
				y += 2;
			}
			else if(y == -1 && x == -5 && (int)functionInputInt(x) != -1 && (int)functionInputInt(x) != 0){
				printf("%d", x);
				y++;
			}
			else if(y == 0 && (x == 5 || x == 0) && (int)functionInputInt(x) != 0)
				printf("%d", x);	
			else if(y == 0 && x == 10 && (int)functionInputInt(x) != 0 && (int)functionInputInt(x) != 1){
				printf("%d", x);
				y++;
			}
			else if(abs(x) % 5 != 0 && y == 0)
				printf("|");
			else if(x == 0 && y == 40)
				printf("Y");
			else if(abs(y) % 5 == 0 && x == 0)
				printf("+");
			else if(x == 0)
				printf("-");				
			else
				printf(" ");
		}
	}
}

void Differential_1(int px){
	printf("The result using Derivative\n");
	for(double dx = 0.1; dx >= 0.01; dx -= 0.01){
		printf("    delta x = %lf, result is %lf\n", dx, (functionInputDouble(px + dx) - functionInputDouble(px)) / dx);
	}
}

void Differential_2(int px){
	printf("The result using Differential is: %lf\n",	
	5 * a * pow(px, 4) + 4 * b * pow(px, 3) + 3 * c * pow(px, 2) + 2 * d * px + e);
}

void Integral_1(int x1,int x2){
	double funcSum;
	printf("The result using Riemann Integral\n");
	for(double dx = 0.1; dx >= 0.01; dx -= 0.01){
		funcSum = 0;
		for(double n = 0; n < (x2 - x1) / dx; n++){
			funcSum += functionInputDouble(x1 + n * dx);
		}
		printf("delta x = %lf, result is %lf\n", dx, dx * funcSum);	
	}
}

void Integral_2(int x1,int x2){
	printf("The result using Integral is: %lf\n",
	(a / 6 * pow(x2, 6) + b / 5 * pow(x2, 5) + c / 4 * pow(x2, 4) + d / 3 * pow(x2, 3) + e / 2 * pow(x2, 2) + f * x2)
	 - (a / 6 * pow(x1, 6) + b / 5 * pow(x1, 5) + c / 4 * pow(x1, 4) + d / 3 * pow(x1, 3) + e / 2 * pow(x1, 2) + f * x1));
}


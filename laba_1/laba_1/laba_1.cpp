

#include <iostream>
#include <time.h>
#include "laba_1.h"
using namespace std;

int processArray(int arrX[], int arrC[], int n, int a, int b)
{
	srand(time(0));
	int numberNegativeNumbers = 0;
	for (int i = 0; i < n;++i)
	{
		int r = rand() % (b-a)+a;
		if (i % 2) arrX[i] *= r;
		if (arrX[i] < 0)
		{
			arrC[i] = arrX[i];
			numberNegativeNumbers++;
		}
	}

	return numberNegativeNumbers;
}

void printArray(int arrX[], int arrC[], int n)
{
	for (int i = 0; i < n;++i)
	{
		printf("%i ",arrX[i]);
	}
	printf("\n");
	for (int i = 0; i < n;++i)
	{
		if(arrC[i] !=0 ) printf("%i ", arrC[i]);
	}
}

int main()
{
	
	const int n = 15; //размер массива равен 15
	int x[n] = {};//создание массива
	int c[n] = {};//создаем выходной массив
	int a;
	int b;
	for (int i = 0; i < n;i++)
	{
		x[i] = 1;
	}
	cout << "Enter an even number less than 0";
	cin >> a;
	cout << "Enter an even number greater than 0";
	cin >> b;
	cout << "b =  " << b << endl;
	cout << "a =  " << a << endl;

	srand(0);//инициализация генератора слуайных чисел
	int numberNegativeNumbers  = processArray(x,c, n, a, b);
	printArray(x,c,n);
	cout << "\nNumber Negative Numbers =  " << numberNegativeNumbers << endl;


}



//2. Написать программу, которая преобразует одномерный массив(1D) в двумерный(2D)
//(или наоборот), в соответствии с вариантом.Необходимо оформить в отдельных
//функциях код следующих действий : 1) инициализация массива; 2) вывод массива; 3)
//преобразование массива(создание нового массива с другой структурой).Память под
//массивы выделять динамически и для доступа к элементам использовать указатели.
//Ввод - вывод данных организовать средствами iostream и iomanip.
//Полищук Нилищук Алексеевич
//Вариант 1



#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

void initializeArray(float* arr, int n)
{
	if (n > 0)
	{
		*arr = 1.0;
	}

	if (n > 1)
	{
		*(arr + 1) = 1.0;
	}

	for (int i = 0;i < n;i++)
	{
		*(arr + i) = i * sin(M_PI * i / 25);
	}
}



float** makeArray2D(float* arr1D, int a, int b)
{
	float** arr2D = new float* [a];

	for (int i = 0; i < a;++i)
	{
		*(arr2D + i) = new float[b];
	}
	for (int i = 0;i < a;++i)
	{
		for (int j = 0;j < b;++j)
		{
			*(*(arr2D + i) + j) = *(arr1D + i * b + j);
		}
	}
	return arr2D;
}

void multiplicationFirstElement(float** arr, int N, int M)
{
	for (int i = 0;i < N;i++)
	{
		float sum=0;
		for (int j = 1;j < M;j++)
		{

			sum += arr[i][j];
			
		}
		arr[i][0] = sum;
	}
}

void printArray1D(float arr[], int n)
{
	for (int i = 0; i < n;++i)
	{
		printf("%f"" ", arr[i]);
	}
	
}

void printArray2D(float** arr, int N, int M)
{
	for (int i = 0;i < N;i++)
	{
		
		for (int j = 0;j < M;j++)
		{
			printf("%f"" ", arr[i][j]);
		}
		printf("\n");
	}
}

void freeArray1D(float arr[], int len)
{
	delete[] arr;
}

void freeArray2D(float** arr)
{
	delete[] arr;
}

	int main()
	{
		const int LEN = 25; //задаем параметры массивов
		const int N = 5;
		const int M = 5;

		float* arr = new float[LEN]; //выделяем память под массив

		initializeArray(arr, LEN);// Инициализируем массив

		printArray1D(arr, LEN); //вывод в консоль массива 1D
		cout << "\n";
		cout << "\n";
		//конвертируем 1 мерный массив в 2 мерный
		float** arr2D = makeArray2D(arr, N, M);
		multiplicationFirstElement(arr2D, N, M);
		printArray2D(arr2D, N, M);
		freeArray1D(arr, LEN);
		freeArray2D(arr2D);
	}

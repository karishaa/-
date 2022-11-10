#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int rrand(int min, int max) {
	return min + rand() % (max - min + 1); //генерируем случайные числа
}
int Output(int mass[], int x, char *str) {
	cout << str;
	for (int i = 0; i < x; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int const a = 10, b = 15, c = 20;
	int const d = a + b + c;
	int mass1[a], mass2[b], mass3[c];
	int arr[d];
	char str1[] = "1 массив: ", str2[] = "2 массив: ", str3[] = "3 массив: ",
		str4[] = "Не отсортированный массив: ", str5[] = "Отсортированный массив: ";

	srand(time(NULL));

	for (int i = 0; i < a; i++) {
		mass1[i] = rrand(1, 100);

	}
	Output(mass1, a, str1);
	for (int i = 0; i < b; i++) {
		mass2[i] = rrand(1, 100);

	}
	Output(mass2, b, str2);
	for (int i = 0; i < c; i++) {
		mass3[i] = rrand(1, 100);
	}
	Output(mass3, c, str3);
	for (int i = 0; i < d; i++) {
		if (i < a)
			arr[i] = mass1[i];
		else if (i < a + b)
			arr[i] = mass2[i - a];
		else
			arr[i] = mass3[i - (a + b)];

	}
	Output(arr, d, str4);
	for (int i = 0; i < d; i++) {
		bool t = false;
		for (int j = 0; j < d - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				t = true;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
				//swap(arr[j], arr[j + 1]); Можно Использовать функцию SWAP для обмена значения переменных
			}
		}
		if (!t) break;
	}
	Output(arr, d, str5);
	return(0);
}

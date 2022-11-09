#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int rrand(int min, int max) {
	return rand() % 100; //генерируем случайные числа 
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
	for (int i = 1; i < d; i++) {
		for (int j = 0; j + i < d; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	Output(arr, d, str5);
	return(0);
}

#include "pch.h"
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
int main()
{
	setlocale(LC_ALL, "Russian");
	int const a = 10, b = 15, c = 20;
	int const d = a + b + c;
	int mass1[a], mass2[b], mass3[c];
	int arr[d];

	srand(time(NULL));
	cout << "1 массив: ";
	for (int i = 0; i < a; i++) {
		mass1[i] = rrand(1, 100);
		cout << mass1[i] << " ";
	}
	cout << endl;
	cout << "2 массив: ";
	for (int i = 0; i < b; i++) {
		mass2[i] = rrand(1, 100);
		cout << mass2[i] << " ";

	}
	cout << endl;
	cout << "3 массив: ";
	for (int i = 0; i < c; i++) {
		mass3[i] = rrand(1, 100);
		cout << mass3[i] << " ";
	}
	cout << endl;
	cout << "Не отсортированный массив: ";
	for (int i = 0; i < d; i++) {
		if (i < a)
			arr[i] = mass1[i];
		else if (i < a + b)
			arr[i] = mass2[i - a];
		else
			arr[i] = mass3[i - (a + b)];
		cout << arr[i] << " ";

	}
	cout << endl;
	cout << "Отсортированный массив: ";
	for (int i = 1; i < d; i++) {
		for (int j = 0; j + i < d; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < d; i++) {

		cout << arr[i] << " ";
	}
	cout << endl;


	return(0);
}


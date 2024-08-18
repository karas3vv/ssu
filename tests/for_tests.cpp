#include <iostream>

using namespace std;

void f1(int* arr, int l) {
	for (int i = 0; i < l; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void f2(int arr[][3], int l, int w) {
	for (int i = 0; i < l; i++)
		for (int j = 0; j < w; j++)
			cout << arr[i][j] << " ";
	cout << endl;
}

void f3(int** arr, int l, int w) {
	for (int i = 0; i < l; i++)
		for (int j = 0; j < w; j++)
			cout << arr[i][j] << " ";
	cout << endl;
}

int main() {
	//работа со статическим одномерным массивом
	int arr[] = { 1, 2, 3 };

	int l1 = sizeof(arr) / sizeof(arr[0]);

	cout << l1 << endl;

	f1(arr, l1);

	//работа со статическим двумерным массивом
	int arr2[][3] = { {0, 1, 2}, {3, 4, 5} };

	int w2 = sizeof(arr2[0]) / sizeof(arr2[0][0]);
	int l2 = sizeof(arr2) / sizeof(arr2[0]);

	cout << l2 << endl;
	cout << w2 << endl;

	f2(arr2, l2, w2);

	//работа с динамическим двумерным массивом (копируем данные со статического двумерного)
	int l3 = 2, w3 = 3;

	int** arr3 = new int* [l3];
	for (int i = 0; i < l3; i++)
		arr3[i] = new int[w3];

	for (int i = 0; i < l3; i++)
		for (int j = 0; j < w3; j++)
			arr3[i][j] = arr2[i][j];

	f3(arr3, l3, w3);
}
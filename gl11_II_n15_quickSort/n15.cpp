#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void QuickSort(vector<int> &A, int L, int R) {
	int i = L; //левый элемент
	int j = R; //правый элемент
	int piv = A[(i + j) / 2];
	while (i <= j) {
		while (A[i] < piv)
			i++;
		while (A[j] > piv)
			j--;
		if (i <= j) {
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}
	if (L < j)
		QuickSort(A, L, j);
	if (i < R)
		QuickSort(A, i, R);
}

void sortColumns(vector<vector<int>>& matrix) {
	int n = matrix.size();

	for (int i = 0; i < n; ++i) {
		vector<int> column;
		for (int j = 0; j < n; ++j) {
			column.push_back(matrix[j][i]);
		}
		if (i % 2 == 0) {
			QuickSort(column, 0, n - 1); // Сортировка в столбцах с четными индексами
		}
		else {
			QuickSort(column, 0, n - 1); // Сортировка в столбцах с нечетными индексами
			reverse(column.begin(), column.end());
		}
		for (int j = 0; j < n; ++j) {
			matrix[j][i] = column[j];
		}
	}
}

void readMatrixFromFile(const string& filename, vector<vector<int>>& matrix) {
	ifstream file(filename);
	if (file.is_open()) {
		int n;
		file >> n;

		matrix.resize(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				file >> matrix[i][j];
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}

void writeMatrixToFile(const string& filename, const vector<vector<int>>& matrix) {
	ofstream file(filename);
	if (file.is_open()) {
		int n = matrix.size();
		file << n << endl;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				file << matrix[i][j] << " ";
			}
			file << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}

int main() {
	string in = "input.txt";
	string out = "output.txt";

	vector<vector<int>> matrix;

	readMatrixFromFile(in, matrix);
	sortColumns(matrix);
	writeMatrixToFile(out, matrix);

	cout << "Matrix sotrted and saved to " << out << endl;

	return 0;
}
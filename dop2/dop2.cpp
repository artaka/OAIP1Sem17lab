//var11
#include <iostream>
using namespace std;

void deleteElement(int A[], int pos, int endArr) {
	for (int i = pos;i < endArr - 1;++i) {
		A[i] = A[i + 1];
	}
}

int& task1(int A[]) {
	int len = 15;
	for (int i = 0;i < len;++i) {
		if (A[i] % 2 != 0) {
			deleteElement(A, i, len);
			--i;
			--len;
		}
	}

	return len;
}

int& task2(int* B[], int size) {
	int sum = 0;
	for (int i = 0;i != size;++i) {
		for (int j = 0;j != size;++j) {
			sum += B[i][j];
		}
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, "RU");

	cout << "Выберите задание(1,2): ";

	int choice;
	int reslen = 0;
	int size = 0;
	int* A;

	cin >> choice;
	switch (choice)
	{
	case 1:
		A = new int[15];

		for (int i = 0;i != 15;++i) {
			A[i] = rand() % 200;
		}

		cout << "Массив до изменений: " << endl;
		for (int i = 0;i != 15;++i) {
			cout << A[i] << "(" << i+1 << ") ";
		}
		cout << endl;
		reslen = task1(A);

		cout << "Массив после изменений:" << endl;
		for (int i = 0;i != reslen;++i) {
			cout << A[i] << "(" << i+1 << ") ";
		}

		delete[] A;
		break;
	case 2:
		int** B;
		cout << "Введите размер: ";
		cin >> size;

		B = new int* [size];
		for (int i = 0; i != size; i++)
		{
			B[i] = new int[size];
		}

		for (int i = 0;i != size;++i) {
			for (int j = 0;j != size;++j) {
				cout << "B[" << i << "][" << j << "]: ";
				cin >> B[i][j];
			}
		}

		int ressum = task2(B, size);

		cout << "Сумма: " << ressum;

		for (int i = 0; i != size; i++)
		{
			delete[] B[i];
		}
		delete[] B;
	}

}
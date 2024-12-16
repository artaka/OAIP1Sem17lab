#include <iostream>
using namespace std;

int& task1(int A[]) {
	int* B = new int[10];
	for (int i = 0,j=0;i <= 20;i += 2) {
		if (A[i] > 0) {
			B[j++] = A[i];
		}
	}

	int sum = 0;
	for (int i = 0;i != 10;++i) {
		sum += B[i] * B[i];
	}
	return sum;
}

int* getMin(int* B[], int size) {
	int* minPtr = B[0];
	for (int i = 0;i != size;++i) {
		for (int j = 0;j != size;++j) {
			if (B[i][j] > *minPtr) {
				minPtr = B[i] + j;
			}
		}
	}
	return minPtr;
}

int main() {
	setlocale(LC_ALL, "RU");

	cout << "Выберите задание(1,2): ";

	int choice;
	int res=0;
	int size=0;
	int* A;

	cin >> choice;
	switch (choice)
	{
	case 1:
		A = new int[20];
		
		for (int i = 0;i != 20;++i) {
			cout << "A[" << i << "]: ";
			cin >> A[i];
		}
		
		res = task1(A);

		cout << "Сумма квадратов: " << res;
		
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

		int* min = getMin(B, size);
		
		for (int i = 0;i != size;++i) {
			for (int j = 0;j != size;++j) {
				if ((B[i] + j) == min) {
					cout << "Индексы: " << i << " " << j << endl << "Значение: " << *min;
				}
			}
		}

		for (int i = 0; i != size; i++)
		{
			delete[] B[i];
		}
		delete[] B;
	}
	
}
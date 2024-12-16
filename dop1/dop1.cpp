//var6
#include <iostream>
using namespace std;

int& task1(int A[]) {
	int min = A[0];
	for (int i = 0;i != 15;++i) {
		if (A[i] < min) {
			min = A[i];
		}
	}

	int max = A[0];
	for (int i = 0;i != 15;++i) {
		if (A[i] > max) {
			max = A[i];
		}
	}

	int sum = max + min;

	return sum;
}

bool task2(int* B[], int size) {
	for (int i = 0;i != size;++i) {
		int counter = 0;
		for (int j = 0;j != size;++j) {
			if (B[i][j] == 0) {
				++counter;
			}
		}
		if (counter == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "RU");

	cout << "Выберите задание(1,2): ";

	int choice;
	int res = 0;
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

		res = task1(A);

		cout << "Сумма: " << res;

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

		bool isTrue = task2(B, size);

		if (!isTrue) {
			for (int i = 0;i != size;++i) {
				for (int j = 0;j != size;++j) {
					if (B[i][j] < 0) {
						B[i][j] = 0;
					}
				}
			}
		}

		for (int i = 0;i != size;++i) {
			for (int j = 0;j != size;++j) {
				cout << B[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i != size; i++)
		{
			delete[] B[i];
		}
		delete[] B;
	}

}
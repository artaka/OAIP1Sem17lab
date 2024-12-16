//var4
#include <iostream>
using namespace std;

int& task1(int A[]) {
	int sum = 0;
	for (int i = 0;i != 15;++i) {
		sum += A[i];
	}
	return sum;
}

int& getPos(int* B[], int size) {
	int row = 0;
	for (int i = 0;i != size;++i) {
		for (int j = 0;j != size;++j) {
			if (B[i][j] > 0) {
				row = i;
			}
		}
	}
	return row;
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

		int row = getPos(B, size);
		int pos = row == 0 ? size - 1 : row - 1;
		for (int i = 0;i != size;++i) {
			B[pos][i] *= -1;
		}

		cout << "Индекс строки: " << row << endl;

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
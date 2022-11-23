#include <iostream>
#include <Windows.h>

using namespace std;
const int ROW_COUNT = 8;
const int COL_COUNT = 9;

void Create(int** C, const int HIGH, const int LOW, const int ROW_COUNT, const int COL_COUNT);
void Print(int** C, const int ROW_COUNT, const int COL_COUNT);
void Calc(int** C, const int ROW_COUNT, const int COL_COUNT, int& suma, int& count);
void Sort(int** C, const int ROW_COUNT, const int COL_COUNT);
void Change(int** C, const int row1, const int row2, const int COL_COUNT);

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int HIGH = 74;
	const int LOW = 11;
	const int ROW_COUNT = 8;
	const int COL_COUNT = 9;

	int** C = new int* [ROW_COUNT];
	for (int i = 0; i < ROW_COUNT; i++)
		C[i] = new int[COL_COUNT];

	cout << "F: " << "\n";
	Create(C, HIGH, LOW, ROW_COUNT, COL_COUNT);
	Print(C, ROW_COUNT, COL_COUNT);
	cout << "D: " << "\n";
	Sort(C, ROW_COUNT, COL_COUNT);
	Print(C, ROW_COUNT, COL_COUNT);

	int suma = 0;
	int count = 0;
	Calc(C, ROW_COUNT, COL_COUNT, suma, count);
	cout << "S: " << suma << "\n" << "\n";
	cout << "N: " << count << "\n" << "\n";
	cout << "H: " << "\n";
	Print(C, ROW_COUNT, COL_COUNT);


	for (int i = 0; i < ROW_COUNT; i++)
		delete[] C[i];
	delete[] C;

	system("pause");
	return 0;

}
void Create(int** C, const int HIGH, const int LOW, const int ROW_COUNT, const int COL_COUNT)
{
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
			C[i][j] = LOW + rand() % (HIGH - LOW + 1);
	}
}
void Print(int** C, const int ROW_COUNT, const int COL_COUNT)
{
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
		{
			cout << C[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}
void Calc(int** C, const int ROW_COUNT, const int COL_COUNT, int& suma, int& count)
{
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
		{
			if (C[i][j] % 6 == 0 && (i + j) % 5 != 0)
			{
				suma += C[i][j];
				count++;
				C[i][j] = 0;
			}
		}
	}
}
void Change(int** C, const int row1, const int row2, const int COL_COUNT)
{
	int tmp;
	for (int j = 0; j < COL_COUNT; j++)
	{
		tmp = C[row1][j];
		C[row1][j] = C[row2][j];
		C[row2][j] = tmp;
	}
}
void Sort(int** C, const int ROW_COUNT, const int COL_COUNT)
{
	for (int i0 = 0; i0 < ROW_COUNT - 1; i0++)
		for (int i1 = 0; i1 < ROW_COUNT - i0 - 1; i1++)
			if ((C[i1][0] < C[i1 + 1][0])
				||
				(C[i1][0] == C[i1 + 1][0] &&
					C[i1][1] < C[i1 + 1][1])
				||
				(C[i1][0] == C[i1 + 1][0] &&
					C[i1][1] == C[i1 + 1][1] &&
					C[i1][3] < C[i1 + 1][3]))
				Change(C, i1, i1 + 1, COL_COUNT);
}

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

//void InputRow(int**& a, int rowNo, int colCount, int low, int hight, int colNo)
//{
//	cout << "a[" << rowNo << "][" << colNo << "] = ";
//	cin >> a[rowNo][colNo];
//	if (colNo < colCount - 1)
//	{
//		InputRow(a, rowNo, colCount, low, hight, colNo + 1);
//	}
//}
//
//void InputRows(int**& a, int rowCount, int colCount, int low, int hight, int rowNo)
//{
//	InputRow(a, rowNo, colCount, low, hight, 0);
//	if (rowNo < rowCount - 1)
//	{
//		InputRows(a, rowCount, colCount, low, hight, rowNo + 1);
//	}
//}

void CreateRow(int**& a, int rowNo, int colCount, int low, int hight, int colNo) 
{
	a[rowNo][colNo] = low + rand() % (hight - low + 1);
	if (colNo < colCount - 1) 
	{
		CreateRow(a, rowNo, colCount, low, hight, colNo + 1);
	}
}

void CreateRows(int** &a, int rowCount, int colCount, int low, int hight, int rowNo) 
{
	CreateRow(a, rowNo, colCount, low, hight, 0);
	if (rowNo < rowCount - 1) 
	{
		CreateRows(a, rowCount, colCount, low, hight, rowNo + 1);
	}
}

void PrintRow(int** &a, int rowNo, int colCount, int colNo) 
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
}
void PrintRows(int** &a, int rowCount, int colCount, int rowNo) 
{
	PrintRow(a, rowNo, colCount, 0);
	cout << endl;
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
}

int Sum(int** &a, int rowCount, int colCount, int rowNo, int colNo, int* &kilk)
{
	
	if (a[rowNo][colNo] > 0) 
	{
		kilk[colNo] += a[rowNo][colNo];
	}
	if (a[rowNo][colNo] < 0) 
	{
		kilk[colNo]=0;
	}
	if (rowNo < rowCount - 1) 
	{
		Sum(a, rowCount, colCount, rowNo + 1, colNo, kilk);	
		return *kilk; //Не знаю, як заставити функцію Sum перестати повертати значення, після проходження по всіх стовбчиках, щоб вона не повертала одне й теж значення
	}
	if (colNo < colCount - 1)
	{
		Sum(a, rowCount, colCount, 0 , colNo + 1, kilk);
	}
}

int main()
{
	srand(unsigned(time(NULL)));
	int Low;
	int Hight;
	int n;
	int k;
	cout << "Low = ";
	cin >> Low;
	cout << "Hight = ";
	cin >> Hight;
	cout << "RowCount = ";
	cin >> n;
	cout << "ColCount = ";
	cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];

	CreateRows(a, n, k, Low, Hight, 0);

	cout << endl;
	PrintRows(a, n, k, 0);

	int* kilk = new int [k];
	for (int j = 0; j < k; j++)
		kilk[j] = 0;

	cout << endl;

	int S = Sum(a, n, k, 0, 0, kilk);

	for (int j = 0; j < k; j++)
		cout << setw(4) << S;
	cout << endl;

	delete[] kilk;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
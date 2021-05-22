#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int**& a, const int n, int low, int hight)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = low + rand() % (hight - low + 1);
}

void Print(int**& a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
	}
	cout << endl;
}

void Fill_b(int** &a, int* &b, int n) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			b[i + j] += abs(a[i][j]);
			//cout << setw(4) << b[i+j];
		}
	}
}

void MinSum(int* &b, int n, int& min)
{
	for (int j = 0; j < n + n - 1; j++)
	{
		if (b[j] < min)
		{
			min = b[j];
		}
	}
}

void Cout_b(int* b, int n) 
{
	cout << endl << "  Sums of modules, members, side diagonals:";
	for (int i = 0; i < n + n - 1; i++)
	{
		cout << setw(4) << b[i];
	}
}

int main()
{
	srand(unsigned(time(NULL)));

	int Low;
	int Hight;
	int n;
	cout << "Low = ";
	cin >> Low;
	cout << "Hight = ";
	cin >> Hight;
	cout << "Row&Col_Count = ";
	cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	Create(a, n, Low, Hight);
	Print(a, n);

	int* b = new int[n+n];
	for (int i = 0; i < n + n; i++)
	{
		b[i] = 0;
	}

	Fill_b(a, b, n);
	int min = b[0];
	Cout_b(b, n);

	MinSum(b, n, min);
	cout << endl <<"  Min from diagonals = " << min;

	delete[] b;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}
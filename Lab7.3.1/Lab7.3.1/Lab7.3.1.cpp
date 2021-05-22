#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** &a, const int n, const int k, int low, int hight)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = low + rand() % (hight - low + 1);
}

void Print(int**& a, const int n, const int k)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
	}
	cout << endl;
}

int Sum(int**& a, const int n, const int k, int* &kilk)
{
	int count = 0;
	for (int j = 0; j < k; j++) 
	{
		kilk[j] = 0;
		for (int i = 0; i < n; i++) 
		{
			if (a[i][j] < 0)
			{
				kilk[j] = 0;
				break;
			}
			kilk[j] = kilk[j] + a[i][j];
		}
	}
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i][j] > 0)
			{
				count++;
			}
		}
	}
	return count;
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

	Create(a, n, k, Low, Hight);
	Print(a, n, k);

	int* kilk = new int[k];

	int count = Sum(a, n, k, kilk);

	cout << endl << endl;

	for (int j = 0; j < k; j++)
		cout << setw(4) << kilk[j];

	cout << endl << endl;

	cout << "  Positive numbers amount: " << count << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}
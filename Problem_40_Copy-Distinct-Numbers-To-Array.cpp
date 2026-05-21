#include <iostream>
using namespace std;
void fillArray(int ar[], int& size)
{
	int ar1Length = 10;
	ar1[0] = 10;
	ar1[1] = 10;
	ar1[2] = 10;
	ar1[3] = 50;
	ar1[4] = 50;
	ar1[5] = 70;
	ar1[6] = 70;
	ar1[7] = 70;
	ar1[8] = 70;
	ar1[9] = 90;
}
bool isNumberInArray(int ar[], int num, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (num == ar[i])
		{
			return true;
		}
	}
	return false;
}
void addArrayElement(int Number, int arr[100], int& ar2Length)
{
	ar2Length++;
	arr[ar2Length - 1] = Number;
}
void copyDistinctNumbers(int ar1[], int ar2[], int ar1Length, int& ar2Length)
{
	addArrayElement(ar1[0], ar2, ar2Length);
	for (int i = 1; i < ar1Length; i++)
	{
		if (!isNumberInArray(ar2, ar1[i], ar2Length))
		{
			addArrayElement(ar1[i], ar2, ar2Length);
		}
	}
}
void printArray(int ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}
int main()
{
	int ar1[100];
	int ar1Length = 0;
	fillArray(ar1, ar1Length);
	cout << "Array 1 elements: " << endl;
	printArray(ar1, ar1Length);
	int ar2[100];
	int ar2Length = 0;
	copyDistinctNumbers(ar1, ar2, ar1Length, ar2Length);
	cout << "\nArray 2 distinct elements: " << endl;
	printArray(ar2, ar2Length);
	return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int readNumber(string text)
{
	int num;
	cout << text << endl;
	cin >> num;
	return num;
}
int getRandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void fillArrayRandomly(int ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = getRandomNumber(1, 100);
	}
}
void addArrayElement(int Number, int arr[100], int& ar2Length)
{
	ar2Length++;
	arr[ar2Length - 1] = Number;
}
void copyOddNumbers(int ar1[], int ar2[], int ar1Length, int& ar2Length)
{
	for (int i = 0; i < ar1Length; i++)
	{
		if (ar1[i] % 2 != 0)
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
	srand((unsigned)time(NULL));
	int ar1[100];
	int ar1Length = readNumber("Enter the size of the array");
	fillArrayRandomly(ar1, ar1Length);
	cout << "\nArray 1 elements:" << endl;
	printArray(ar1, ar1Length);
	int ar2[100];
	int ar2Length = 0;
	copyOddNumbers(ar1, ar2, ar1Length, ar2Length);
	cout << "\nArray 2 elements:" << endl;
	printArray(ar2, ar2Length);
	return 0;
}
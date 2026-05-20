#include <iostream>
#include <string>
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
void fillArrayRandomly(int ar[100], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = getRandomNumber(1, 100);
	}
}
void printArray(int ar[100], int size, string text)
{
	cout << text << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}
void sumOfTwoArray(int ar1[100], int ar2[100], int ar3[100], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar3[i] = ar1[i] + ar2[i];
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int ar1[100], ar2[100], ar3[100];
	int size = readNumber("Enter the size of the array");
	fillArrayRandomly(ar1, size);
	printArray(ar1, size, "\nArray 1 elements:");
	fillArrayRandomly(ar2, size);
	printArray(ar2, size, "\nArray 2 elements:");
	sumOfTwoArray(ar1, ar2, ar3, size);
	printArray(ar3, size, "\nSum of array1 and array2 elements:");
	return 0;
}
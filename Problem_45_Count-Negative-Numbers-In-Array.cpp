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
void fillArrayRandomly(int ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = getRandomNumber(-100, 100);
	}
}
int countNegativeNumbers(int ar[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (ar[i] < 0)
		{
			count++;
		}
	}
	return count;
}
void printArray(int ar[], int size)
{
	cout << "\nArray elements: ";
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}
int main()
{
	srand((unsigned)time(NULL));
	int ar[100];
	int size = readNumber("Enter the size of the array:");
	fillArrayRandomly(ar, size);
	printArray(ar, size);
	cout << "\nNegative numbers in array: " << countNegativeNumbers(ar, size) << endl;
	return 0;
}
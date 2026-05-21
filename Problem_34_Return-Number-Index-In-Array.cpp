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
void printArray(int ar1[100], int size, string text)
{
	cout << text << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ar1[i] << " ";
	}
	cout << endl;
}
short findNumberPositionInArray(int ar[], int size, int num)
{
	int index;
	bool isFound = false;
	for (int i = 0; i < size; i++)
	{
		if (ar[i] == num)
		{
			index = i;
			isFound = true;
			break;
		}
	}
	if (isFound)
	{
		return index;
	}
	return -1;
}
int main()
{
	srand((unsigned)time(NULL));
	int ar[100];
	int size = readNumber("Enter the number of element:");
	fillArrayRandomly(ar, size);
	printArray(ar, size, "\nArray elements:");
	int num = readNumber("\nEnter a number to search for:");
	int index = findNumberPositionInArray(ar, size, num);
	if (index != -1)
	{
		cout << "\nThe number found at position: " << index << endl;
		cout << "The number found its order  : " << index + 1 << endl;
	}
	else
	{
		cout << "\nThe number is not found :-(" << endl;
	}
	return 0;
}
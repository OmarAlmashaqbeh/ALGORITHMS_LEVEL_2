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
void fillArray(int ar[100], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = i + 1;
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
void swap(int& num1, int& num2)
{
	int x = num1;
	num1 = num2;
	num2 = x;
}
void shuffleArray(int ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(ar[(getRandomNumber(0, size - 1))], ar[(getRandomNumber(0, size - 1))]);
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int ar[100];
	int size = readNumber("Enter the size of the array");
	fillArray(ar, size);
	printArray(ar, size, "Array elements before shuffle:");
	shuffleArray(ar, size);
	printArray(ar, size, "Array elements after shuffle:");
	return 0;
}
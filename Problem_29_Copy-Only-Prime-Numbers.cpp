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
bool checkPrime(int num)
{
	bool isPrime = true;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}
void copyOnlyPrimeNumbers(int ar1[100], int ar2[100], int size1, int& size2)
{
	for (int i = 0; i < size1; i++)
	{
		if (checkPrime(ar1[i]))
		{
			ar2[size2++] = ar1[i];
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int ar1[100], ar2[100];
	int size1 = readNumber("Enter the size of thr array");
	int size2 = 0;
	fillArrayRandomly(ar1, size1);
	printArray(ar1, size1, "\nArray 1 elements:");
	copyOnlyPrimeNumbers(ar1, ar2, size1, size2);
	printArray(ar2, size2, "\nPrime numbers in array2:");
	return 0;
}
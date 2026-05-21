#include <iostream>
using namespace std;
void fillArray(int ar[], int& size)
{
	size = 6;
	ar[0] = 10;
	ar[1] = 20;
	ar[2] = 30;
	ar[3] = 30;
	ar[4] = 20;
	ar[5] = 10;
}
bool isPalindromeArray(int ar[], int size)
{
	for (int i = 0; i <= size / 2; i++)
	{
		if (ar[i] != ar[size - i - 1])
		{
			return false;
		}
	}
	return true;
}
void printArray(int ar[], int size)
{
	cout << "Array elements:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}
int main()
{
	int ar[100];
	int size = 0;
	fillArray(ar, size);
	printArray(ar, size);
	if (isPalindromeArray(ar, size))
	{
		cout << "\nYes array is Palindrome" << endl;
	}
	else
	{
		cout << "\nNO array is NOT Palindrome" << endl;
	}
	return 0;
}
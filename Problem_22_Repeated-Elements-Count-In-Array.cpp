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
void fillArray(int ar[], int size)
{
	cout << "\nEnter array elements:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "element [" << (i + 1) << "] : ";
		cin >> ar[i];
	}
}
void printArray(int ar[], int size)
{
	cout << "\nOriginal array: ";
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}
void checkNumber(int ar[], int size, int num)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (num == ar[i])
		{
			count++;
		}
	}
	cout << "\n" << num << " is repeated " << count << " time(s)" << endl;
}
int main()
{
	int ar[100];
	int size = readNumber("Enter the size of the array");
	fillArray(ar, size);
	int numberToCheck = readNumber("\nEnter the number you want to check:");
	printArray(ar, size);
	checkNumber(ar, size, numberToCheck);
	return 0;
}
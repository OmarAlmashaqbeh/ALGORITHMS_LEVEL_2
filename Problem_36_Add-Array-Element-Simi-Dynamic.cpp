#include <iostream>
#include <string>
using namespace std;
int readNumber(string text)
{
	int num;
	cout << text;
	cin >> num;
	return num;
}
void fillArray(int ar[], int& size)
{
	for (int i = 0; i < 100; i++)
	{
		bool addMore;
		ar[i] = readNumber("\nEnter a number: ");
		size++;
		cout << "\nDo you want to add more numbers? [0]:No,[1]:yes  ";
		cin >> addMore;
		if (addMore)
		{
			break;
		}
	}
}
void addArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
	bool AddMore = true;
	do
	{
		addArrayElement(readNumber("Enter a number: "), arr, arrLength);
		cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
		cin >> AddMore;
	} while (AddMore);
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
int main()
{
	int ar[100], size = 0;
	fillArray(ar, size);
	cout << "\nArray length: " << size << endl;
	printArray(ar, size, "Array elements: ");
	return 0;
}
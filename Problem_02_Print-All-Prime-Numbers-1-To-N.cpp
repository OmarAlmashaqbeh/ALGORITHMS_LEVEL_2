#include <iostream>
#include <string>
using namespace std;
int readPositiveNumber(string text)
{
	int num;
	do
	{
		cout << text << endl;
		cin >> num;
	} while (num <= 0);
	return num;
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
void printPrimeNumbersFrom1toN(int num)
{
	cout << "\nPrime numbers from 1 to " << num << " are:" << endl;
	for (int i = 1; i <= num; i++)
	{
		if (checkPrime(i))
		{
			cout << i << endl;
		}
	}
}
int main()
{
	printPrimeNumbersFrom1toN(readPositiveNumber("Enter a positive number:"));
	return 0;
}
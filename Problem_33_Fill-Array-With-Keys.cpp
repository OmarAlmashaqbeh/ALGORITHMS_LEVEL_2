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
char getRandomCharacter()
{
	int randNum = rand() % (90 - 65 + 1) + 65;
	return (char)randNum;
}
string getRandomKey()
{
	string key = "";
	for (int i = 1; i <= 16; i++)
	{
		key += getRandomCharacter();
		if (i % 4 == 0 && i < 16)
		{
			key += '-';
		}
	}
	return key;
}
void fillArrayWithRandomKey(string ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = getRandomKey();
	}
}
void printStringArray(string ar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Array[" << i << "] : " << ar[i] << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	string ar[100];
	int size = readNumber("How many keys do you want to generate?");
	fillArrayWithRandomKey(ar, size);
	printStringArray(ar, size);
	return 0;
}
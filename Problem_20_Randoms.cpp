#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enCharType { smallLetter = 1, capitalLetter = 2, specialCharacter = 3, digit = 4 };
int printRandomCharacter(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
char getRandomCharacter(enCharType charType)
{
	switch (charType)
	{
	case smallLetter:
		return (char)(printRandomCharacter(97, 122));
	case capitalLetter:
		return (char)(printRandomCharacter(65, 90));
	case specialCharacter:
		return (char)(printRandomCharacter(33, 47));
	case digit:
		return (char)(printRandomCharacter(48, 57));
	}
	return '\0';
}
int main()
{
	srand((unsigned)time(NULL));
	cout << getRandomCharacter(enCharType::smallLetter) << endl;
	cout << getRandomCharacter(enCharType::capitalLetter) << endl;
	cout << getRandomCharacter(enCharType::specialCharacter) << endl;
	cout << getRandomCharacter(enCharType::digit) << endl;
	return 0;
}
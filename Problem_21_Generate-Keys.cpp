#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enCharType { samallLetter = 1, capitalLetter = 2, specialCharacter = 3, digit = 4 };
int getRandomNumber(int from, int to)
{
    int num = rand() % (to - from + 1) + from;
    return num;
}
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
char getRandomCharacter(enCharType charType)
{
    switch (charType)
    {
    case enCharType::samallLetter:
        return char(getRandomNumber(97, 122));
    case enCharType::capitalLetter:
        return char(getRandomNumber(65, 90));
    case enCharType::specialCharacter:
        return char(getRandomNumber(33, 47));
    case enCharType::digit:
        return char(getRandomNumber(48, 57));
    }
    return '\0';
}
string generateWord(enCharType charType, short length)
{
    string word = "";
    for (int i = 1; i <= length; i++)
    {
        word += getRandomCharacter(charType);
    }
    return word;
}
string generateKey()
{
    string key = "";
    for (int i = 1; i <= 4; i++)
    {
        key += generateWord(enCharType::capitalLetter, 4);
        key += (i == 4) ? "" : "-";
    }
    return key;
}
void generateKeys(short num)
{
    for (int i = 1; i <= num; i++)
    {
        cout << "Key [" << i << "] : " << generateKey() << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    generateKeys(readPositiveNumber("Enter how many keys to generate:"));
    return 0;
}
#include <iostream>
#include <string>
#include <cmath>
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
int reverseNumber(int num)
{
    int newNumber = 0;
    while (num != 0)
    {
        newNumber *= 10;
        newNumber += num % 10;
        num /= 10;
    }
    return newNumber;
}
void printDigits(int num)
{
    while (num != 0)
    {
        cout << num % 10 << endl;
        num /= 10;
    }
}
int main()
{
    printDigits(reverseNumber(readPositiveNumber("Enter a positive number")));
    return 0;
}
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
int reverseNumber(int num)
{
    int newNumber = 0;
    while (num != 0)
    {
        newNumber = (newNumber * 10) + (num % 10);
        num /= 10;
    }
    return newNumber;
}
int main()
{
    int reversedNumber = reverseNumber(readPositiveNumber("Enter a positive number:"));
    cout << "\nReverse is: " << reversedNumber << endl;
    return 0;
}
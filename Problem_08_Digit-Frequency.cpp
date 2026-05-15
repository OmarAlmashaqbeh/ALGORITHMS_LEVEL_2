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
int countDigitFrequency(int num, short digitToCheck)
{
    int count = 0;
    while (num != 0)
    {
        if (num % 10 == digitToCheck)
        {
            count++;
        }
        num /= 10;
    }
    return count;
}
int main()
{
    int num = readPositiveNumber("Enter a positive number:");
    short digitToCheck = readPositiveNumber("\nEnter one digit to check:");
    cout << "\nDigit " << digitToCheck << " Frequency is " << countDigitFrequency(num, digitToCheck) << " Time(s)." << endl;
    return 0;
}
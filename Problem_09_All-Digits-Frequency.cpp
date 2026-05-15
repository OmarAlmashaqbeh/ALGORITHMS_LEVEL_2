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
void countDigitFrequency(int num, short digitToCheck)
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
    if (count != 0)
    {
        cout << "Digit " << digitToCheck << " Frequency is " << count << " Time(s)." << endl;
    }
}
int main()
{
    int num = readPositiveNumber("Enter a positive number");
    for (int i = 0; i <= 9; i++)
    {
        countDigitFrequency(num, i);
    }
    return 0;
}
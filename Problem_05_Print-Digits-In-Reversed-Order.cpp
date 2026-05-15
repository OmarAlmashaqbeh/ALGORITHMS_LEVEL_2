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
void printDigits(int num)
{
    int digit = 0;
    while (num > 0)
    {
        digit = num % 10;
        num /= 10;
        cout << digit << endl;
    }
}
int main()
{
    printDigits(readPositiveNumber("Enter a positive number:"));
    return 0;
}
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
        newNumber *= 10;
        newNumber += num % 10;
        num /= 10;
    }
    return newNumber;
}
bool isPalindromeNumber(int num)
{
    return reverseNumber(num) == num;
}
int main()
{
    if (isPalindromeNumber(readPositiveNumber("Please enter a positive number?")))
    {
        cout << "\nYes , it is a Palindrome number." << endl;
    }
    else
    {
        cout << "\nNo , it is NOT a Palindrome number." << endl;
    }
    return 0;
}
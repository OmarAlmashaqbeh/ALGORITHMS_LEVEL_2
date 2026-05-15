#include <iostream>
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
bool isPerfectNumber(int num)
{
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return (sum == num);
}
void printResult(int num)
{
    if (isPerfectNumber(num))
    {
        cout << num << " is perfect number" << endl;
    }
    else
    {
        cout << num << " is not perfect number" << endl;
    }
}
int main()
{
    printResult(readPositiveNumber("Enter a positive number:"));
    return 0;
}
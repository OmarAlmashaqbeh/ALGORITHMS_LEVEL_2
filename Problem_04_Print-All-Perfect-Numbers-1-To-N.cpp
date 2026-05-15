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
void printPerfectNumbersFrom1ToN(int num)
{
    for (int i = 2; i <= num; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            cout << i << endl;
        }
    }
}
int main()
{
    printPerfectNumbersFrom1ToN(readPositiveNumber("Enter a positive number:"));
    return 0;
}
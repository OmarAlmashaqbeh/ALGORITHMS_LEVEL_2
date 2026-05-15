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
void printInvertedNumberPattern(int num)
{
    for (int i = num; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
int main()
{
    printInvertedNumberPattern(readPositiveNumber("Enter a positive number"));
    return 0;
}
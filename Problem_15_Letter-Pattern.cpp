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
void printLetterPattern(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (char)(i + 64);
        }
        cout << endl;
    }
}
int main()
{
    printLetterPattern(readPositiveNumber("Enter a positive number"));
    return 0;
}
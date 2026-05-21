#include <iostream>
#include <cmath>
using namespace std;
double readNumber(string text)
{
    double num;
    cout << text << endl;
    cin >> num;
    return num;
}
int myRound(double num)
{
    int IntPart = (int)num;
    double FractionsPart = num - (int)num;
    if (abs(FractionsPart) >= 0.5)
    {
        if (num > 0)
        {
            return ++IntPart;
        }
        return --IntPart;
    }
    return IntPart;
}
int main()
{
    double num = readNumber("Enter a number:");
    cout << "\nMy round result: " << myRound(num) << endl;
    cout << "\nC++ round result: " << round(num) << endl;
    return 0;
}
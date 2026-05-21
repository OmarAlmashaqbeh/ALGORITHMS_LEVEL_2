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
double myABS(double num)
{
	if (num >= 0)
	{
		return num;
	}
	return (-1 * num);
}
int main()
{
	double num = readNumber("Enter a number:");
	cout << "\nMy abs result: " << myABS(num) << endl;
	cout << "\nC++ abs result: " << abs(num) << endl;
	return 0;
}
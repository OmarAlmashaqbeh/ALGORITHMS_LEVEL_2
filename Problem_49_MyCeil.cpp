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
int myCeil(double num)
{
	if (num > 0 && num != (int)num)
	{
		return (int)num + 1;
	}
	return (int)num;
}
int main()
{
	double num = readNumber("Enter a number:");
	cout << "\nMy ceil result: " << myCeil(num) << endl;
	cout << "\nC++ ceil result: " << ceil(num) << endl;
	return 0;
}
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
int myFloor(double num)
{
	if (num == (int)num || num > 0)
	{
		return (int)num;
	}
	return (int)num - 1;
}
int main()
{
	double num = readNumber("Enter a number:");
	cout << "\nMy floor result: " << myFloor(num) << endl;
	cout << "\nC++ floor result: " << floor(num) << endl;
	return 0;
}
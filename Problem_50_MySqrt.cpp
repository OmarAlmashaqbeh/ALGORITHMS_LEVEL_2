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
double mySqrt(double num)
{
	return pow(num, 0.5);
}
int main()
{
	double num = readNumber("Enter a number:");
	cout << "\nMy sqrt result: " << mySqrt(num) << endl;
	cout << "\nC++ sqrt result: " << sqrt(num) << endl;
	return 0;
}
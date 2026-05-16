#include <iostream>
using namespace std;
void printTableHeader()
{
	cout << "\t\t\tMultiplication Table From 1 to 10\n\n";
	for (int i = 1; i <= 10; i++)
	{
		cout << "\t" << i;
	}
	cout << "\n___________________________________________________________________________________\n";
}
string separator(int num)
{
	return (num < 10) ? "   | " : "  | ";
}
void printMultiplicationTable()
{
	printTableHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << separator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}
int main()
{
	printMultiplicationTable();
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
string readPassword()
{
    string password;
    cout << "Enter a 3-Letter Password (all capital)" << endl;
    cin >> password;
    return password;
}
void guessPassword(string password)
{
    string word = "";
    int trial = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word += (char)(i);
                word += (char)(j);
                word += (char)(k);
                cout << "Trial [" << ++trial << "] : " << word << endl;
                if (word == password)
                {
                    cout << "Password is " << word << endl;
                    cout << "Found after " << trial << " Trial[s]" << endl;
                    return;
                }
                word = "";
            }
        }
    }
}
int main()
{
    guessPassword(readPassword());
}
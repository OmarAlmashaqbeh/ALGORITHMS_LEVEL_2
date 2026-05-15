#include <iostream>
#include <string>
using namespace std;
string readText()
{
    string text;
    getline(cin, text);
    return text;
}
string encrypt(string& text, int ENCRYPTION_KEY)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] += ENCRYPTION_KEY;
    }
    return text;
}
string decrypt(string& text, int ENCRYPTION_KEY)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] -= ENCRYPTION_KEY;
    }
    return text;
}
int main()
{
    const int ENCRYPTION_KEY = 2;
    cout << "Enter the Text" << endl;
    string text = readText();
    cout << "Text before encryption : " << text << endl;
    cout << "Text after encryption  : " << encrypt(text, ENCRYPTION_KEY) << endl;
    cout << "Text after decryption  : " << decrypt(text, ENCRYPTION_KEY) << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string caesarCipher(const string &message, int shift) 
{
    string encryptedMessage = "";

    for (char ch : message) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            char encryptedChar = (ch - base + shift) % 26 + base;
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += ch;
        }
    }

    return encryptedMessage;
}

int main() {
    string message;
    int shift;

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter the shift value: ";
    cin >> shift;

    string encryptedMessage = caesarCipher(message, shift);

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << encryptedMessage << endl;

    return 0;
}

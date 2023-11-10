/* Encrypt pain text "HI" using rsa algoritham for the given data p=53,q=59 */
#include <bits/stdc++.h>
using namespace std;

int power(int x, int y, int p)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    int m = 0;
    string pt;
    cout << "Enter plain text : ";
    cin >> pt;

    string ptm;
    for (int i = 0; i < pt.length(); i++)
    {
        ptm += to_string((int)(pt[i] - 'a'));
    }

    m = stoi(ptm);

    cout << "your plain text in number is : " << m << endl;

    int p, q, d;
    cout << "Enter value of p : ";
    cin >> p;
    cout << "Enter value of q : ";
    cin >> q;

    int n, fn, e = 2;

    n = p * q;
    fn = (p - 1) * (q - 1);

    // gcd(fn,e)=17
    while (true)
    {
        if (__gcd(fn, e) == 1)
        {
            break;
        }
        e++;
    }

    cout << "e is : " << e << endl;

    // e*d = 1 mod fn
    // find using inverse module function

    int t1 = 0;
    int t2 = 1;

    int a = fn;
    int b = e;

    int r, qo, t;

    do
    {
        qo = a / b;
        r = a % b;
        t = t1 - (t2 * qo);
        a = b;
        b = r;
        t1 = t2;
        t2 = t;
    } while (r != 0);

    d = t1;

    if (d < 0)
    {
        d = fn + d;
    }
    cout << "d is : " << d << endl;

    cout << "Public key : { " << e << " , " << n << " }" << endl;
    cout << "Private key : { " << d << " , " << n << " }" << endl;

    // Encryption

    // c=m^e mod n

    int c;
    c = power(m, e, n);

    string cstr;
    string cipher;
    cstr = to_string(c);
    if (cstr.length() == 2)
    {
        cipher.push_back((char)(cstr[0] - '0' + 'a'));
        cipher.push_back((char)(cstr[1] - '0' + 'a'));
        cout << "Cipher text is : " << cipher << endl;
        cout << "Cipher text is : " << c << endl;
    }
    else if (cstr.length() == 3)
    {
        cout << "Can't convert into text." << endl;
        cout << "Cipher text is : " << c << endl;
    }
    else
    {
        int x, y;
        x = ((int)(cstr[0] - '0') * 10) + (int)(cstr[1] - '0');
        y = ((int)(cstr[2] - '0') * 10) + (int)(cstr[3] - '0');
        x = x % 26;
        y = y % 26;
        cipher.push_back((char)(x + 'a'));
        cipher.push_back((char)(y + 'a'));
        cout << "Cipher text is : " << cipher << endl;
        cout << "Cipher text is : " << c << endl;
    }

    // Decryption

    // m=c^d mod n

    int m1;

    m1 = power(c, d, n);

    // cout << "Plain text is : " << m1 << endl;

    string plain;
    cstr = to_string(m1);
    if (cstr.length() == 2)
    {
        plain.push_back((char)(cstr[0] - '0' + 'a'));
        plain.push_back((char)(cstr[1] - '0' + 'a'));
        cout << "Plain text is : " << plain << endl;
        cout << "Plain text is : " << m1 << endl;
    }
    else if (cstr.length() == 3)
    {
        cout << "Can't convert into text." << endl;
        cout << "Plain text is : " << m1 << endl;
    }
    else
    {
        int x, y;
        x = ((int)(cstr[0] - '0') * 10) + (int)(cstr[1] - '0');
        y = ((int)(cstr[2] - '0') * 10) + (int)(cstr[3] - '0');
        x = x % 26;
        y = y % 26;
        plain.push_back((char)(x + 'a'));
        plain.push_back((char)(y + 'a'));
        cout << "Plain text is : " << plain << endl;
        cout << "Plain text is : " << m1 << endl;
    }

    return 0;
}
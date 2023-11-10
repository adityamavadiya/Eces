#include <bits/stdc++.h>
using namespace std;

int power(int x, int y, int p)
{
    int res = 1; 
    x = x % p;

    if (x == 0)
        return 0; 

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    int alpha, p, xa, xb, ya, yb, ka, kb;
    cout << "Enter p : ";
    cin >> p;
    cout << "Enter alpha : ";
    cin >> alpha;
    cout << "Enter private key of user A : ";
    cin >> xa;
    cout << "Enter private key of user B : ";
    cin >> xb;

    ya = power(alpha, xa, p);
    yb = power(alpha, xb, p);
    ka = power(yb, xa, p);
    kb = power(ya, xb, p);

    cout << "YA : " << ya << endl;
    cout << "YB : " << yb << endl;
    cout << "KA : " << ka << endl;
    cout << "KB : " << kb << endl;
    return 0;
}
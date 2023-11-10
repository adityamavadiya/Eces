#include <bits/stdc++.h>
using namespace std;

int findRowColS1(int s1[4][4], string a)
{
    int i, j;
    if (a[1] == '0' && a[2] == '0')
    {
        i = 0;
    }
    else if (a[1] == '1' && a[2] == '0')
    {
        i = 2;
    }
    else if (a[1] == '0' && a[2] == '1')
    {
        i = 1;
    }
    else
    {
        i = 3;
    }

    if (a[0] == '0' && a[3] == '0')
    {
        j = 0;
    }
    else if (a[0] == '1' && a[3] == '0')
    {
        j = 2;
    }
    else if (a[0] == '0' && a[3] == '1')
    {
        j = 1;
    }
    else
    {
        j = 3;
    }

    return s1[j][i];
}

int findRowColS0(int s0[4][4], string a)
{
    int i, j;
    if (a[1] == '0' && a[2] == '0')
    {
        i = 0;
    }
    else if (a[1] == '1' && a[2] == '0')
    {
        i = 2;
    }
    else if (a[1] == '0' && a[2] == '1')
    {
        i = 1;
    }
    else
    {
        i = 3;
    }

    if (a[0] == '0' && a[3] == '0')
    {
        j = 0;
    }
    else if (a[0] == '1' && a[3] == '0')
    {
        j = 2;
    }
    else if (a[0] == '0' && a[3] == '1')
    {
        j = 1;
    }
    else
    {
        j = 3;
    }

    return s0[j][i];
}

string xorString(string a, string b, int n)
{
    string ans;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] == '0' && b[i] == '0') || (a[i] == '1' && b[i] == '1'))
        {
            ans.push_back('0');
        }
        else
        {
            ans.push_back('1');
        }
    }
    return ans;
}
int main()
{
    // 00001011
    string pt, keyTemp;
    cout << "Enter plain text : ";
    cin >> pt;
    cout << "Enter key : ";
    cin >> keyTemp;

    string key;
    vector<int> p10(10);
    cout << "Enter p10 (in 10 number): ";
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        p10[i] = x;
        key.push_back(keyTemp[x - 1]);
    }

    // 10 bit key partition

    string fbit = key.substr(0, 5);
    string sbit = key.substr(5, 5);

    // 1 shifting
    string lcs1fbit, lcs1sbit;
    for (int i = 0; i < 5; i++)
    {
        lcs1fbit.push_back(fbit[(i + 1) % 5]);
        lcs1sbit.push_back(sbit[(i + 1) % 5]);
    }
    string lcs1 = lcs1fbit + lcs1sbit;
    // 2 shifting
    string lcs2fbit, lcs2sbit;
    for (int i = 0; i < 5; i++)
    {
        lcs2fbit.push_back(lcs1fbit[(i + 2) % 5]);
        lcs2sbit.push_back(lcs1sbit[(i + 2) % 5]);
    }
    string lcs2 = lcs2fbit + lcs2sbit;

    // calculating k1,k2
    string k1, k2;
    vector<int> p8(8);

    cout << "Enter P8 (in 8 number): ";
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        p8[i] = x;
        k1.push_back(lcs1[x - 1]);
        k2.push_back(lcs2[x - 1]);
    }

    cout << "k1 : " << k1 << endl;
    cout << "k2 : " << k2 << endl;

    // Encryption

    vector<int> ip(8);
    string ptip;
    cout << "Enter IP (in 8 number) : ";
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        ip[i] = x;
        ptip.push_back(pt[x - 1]);
    }

    vector<int> exp(8);
    string rightExp;
    cout << "Enter expanded permutation (in 8 number) : ";
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        exp[i] = x;
        rightExp.push_back(ptip[x - 1 + 4]);
    }

    // rightExp XOR k1
    string afterf1 = xorString(rightExp, k1, 8);
    int s0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
    int s1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

    int a, b;
    a = findRowColS0(s0, afterf1.substr(0, 4));
    b = findRowColS1(s1, afterf1.substr(4, 4));
    cout << "a b : " << a << " " << b << endl;

    string afterS0S1;

    if (a == 0)
    {
        afterS0S1.push_back('0');
        afterS0S1.push_back('0');
    }
    else if (a == 1)
    {
        afterS0S1.push_back('0');
        afterS0S1.push_back('1');
    }
    else if (a == 2)
    {
        afterS0S1.push_back('1');
        afterS0S1.push_back('0');
    }
    else
    {
        afterS0S1.push_back('1');
        afterS0S1.push_back('1');
    }

    if (b == 0)
    {
        afterS0S1.push_back('0');
        afterS0S1.push_back('0');
    }
    else if (b == 1)
    {
        afterS0S1.push_back('0');
        afterS0S1.push_back('1');
    }
    else if (b == 2)
    {
        afterS0S1.push_back('1');
        afterS0S1.push_back('0');
    }
    else
    {
        afterS0S1.push_back('1');
        afterS0S1.push_back('1');
    }
    cout << "afterS0S1 : " << afterS0S1 << endl;
    cout << "Enter p4 (in 4 number) : ";
    vector<int> p4(4);
    string rightWithoutXor;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        p4[i] = x;
        rightWithoutXor.push_back(afterS0S1[x - 1]);
    }

    string finalRight = xorString(rightWithoutXor, ptip.substr(0, 4), 4);
    cout << "finalRight : " << finalRight << endl;

    // swap done
    string afterFun1 = ptip.substr(4, 4) + finalRight;

    cout << "afterFun1 : " << afterFun1 << endl;

    // now ptip is afterFun1
    ptip = afterFun1;
    string rightExp2;
    for (int i = 0; i < 8; i++)
    {
        rightExp2.push_back(ptip[exp[i] - 1 + 4]);
    }

    cout << "rightExp2 : " << rightExp2 << endl;

    string afterf2 = xorString(rightExp2, k2, 8);
    cout << "afterf2 : " << afterf2 << endl;

    a = findRowColS0(s0, afterf2.substr(0, 4));
    b = findRowColS1(s1, afterf2.substr(4, 4));

    string afterS0S12nd;

    if (a == 0)
    {
        afterS0S12nd.push_back('0');
        afterS0S12nd.push_back('0');
    }
    else if (a == 1)
    {
        afterS0S12nd.push_back('0');
        afterS0S12nd.push_back('1');
    }
    else if (a == 2)
    {
        afterS0S12nd.push_back('1');
        afterS0S12nd.push_back('0');
    }
    else
    {
        afterS0S12nd.push_back('1');
        afterS0S12nd.push_back('1');
    }

    if (b == 0)
    {
        afterS0S12nd.push_back('0');
        afterS0S12nd.push_back('0');
    }
    else if (b == 1)
    {
        afterS0S12nd.push_back('0');
        afterS0S12nd.push_back('1');
    }
    else if (b == 2)
    {
        afterS0S12nd.push_back('1');
        afterS0S12nd.push_back('0');
    }
    else
    {
        afterS0S12nd.push_back('1');
        afterS0S12nd.push_back('1');
    }

    cout << "afterS0S12nd : " << afterS0S12nd << endl;

    string rightWithoutXor2nd;
    for (int i = 0; i < 4; i++)
    {
        rightWithoutXor2nd.push_back(afterS0S12nd[p4[i] - 1]);
    }
    cout << "rightWithoutXor2nd : " << rightWithoutXor2nd << endl;

    string finalRight2nd = xorString(rightWithoutXor2nd, ptip.substr(0, 4), 4);
    cout << "finalRight2nd : " << finalRight2nd << endl;

    string afterFun2 = finalRight2nd + ptip.substr(4, 4);
    cout << "afterFun2 : " << afterFun2 << endl;

    string ans;
    cout << "Enter IP^(-1) : ";
    vector<int> ip1(8);
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        ip1[i] = x;
        ans.push_back(afterFun2[x - 1]);
    }

    cout << "Final Encryption is : " << ans << endl;

    return 0;
}
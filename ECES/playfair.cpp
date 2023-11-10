#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pt, key;
    cout << "Enter plain text : ";
    getline(cin, pt);
    cout << "Enter key : ";
    getline(cin, key);

    // matrix creation
    vector<int> keyCheck(26, 0);
    vector<pair<int, int>> indexMat(26);
    vector<vector<char>> mat(5, vector<char>(5));
    int a = 0, b = 0;
    for (int i = 0; i < key.length(); i++)
    {
        if (key[i] == 'i' || key[i] == 'j')
        {
            if (key[i] == 'i' && keyCheck[key[i] - 'a'] != 1)
            {
                mat[a][b] = key[i];
                indexMat[key[i] - 'a'] = {a, b};
                b++;
                if (b == 5)
                {
                    b = 0;
                    a++;
                }
                keyCheck['i' - 'a'] = 1;
                keyCheck['j' - 'a'] = 1;
            }
            else if (key[i] == 'j' && keyCheck[key[i] - 'a'] != 1)
            {
                mat[a][b] = 'i';
                indexMat[key[i] - 'a'] = {a, b};
                b++;
                if (b == 5)
                {
                    b = 0;
                    a++;
                }
                keyCheck['i' - 'a'] = 1;
                keyCheck['j' - 'a'] = 1;
            }
        }
        else
        {
            if (key[i] >= 'a' && key[i] <= 'z' && keyCheck[key[i] - 'a'] != 1)
            {
                mat[a][b] = key[i];
                indexMat[key[i] - 'a'] = {a, b};
                b++;
                if (b == 5)
                {
                    b = 0;
                    a++;
                }
                keyCheck[key[i] - 'a'] = 1;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (keyCheck[i] != 1)
        {
            if (i == 8)
            {
                mat[a][b] = 'i';
                indexMat[i] = {a, b};
                b++;
                if (b == 5)
                {
                    b = 0;
                    a++;
                }
                keyCheck[i] = 1;
                keyCheck[i + 1] = 1;
            }
            mat[a][b] = (char)(i + 'a');
            indexMat[i] = {a, b};
            b++;
            if (b == 5)
            {
                b = 0;
                a++;
            }
            keyCheck[i] = 1;
        }
    }

    cout << "\nMatrix is : \n"
         << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // encryption

    string ans;
    char a1, a2;
    for (int i = 0; i < pt.length(); i++)
    {
        a1 = '$';
        a2 = '$';
        while (pt[i] == ' ' && i < pt.length())
        {
            i++;
        }
        if (i >= pt.length())
        {
            break;
        }
        a1 = pt[i];
        i++;
        while (pt[i] == ' ' && i < pt.length())
        {
            i++;
        }
        if (i == pt.length())
        {
            a2 = 'x';
        }
        else if (pt[i] == a1)
        {
            a2 = 'x';
            i--;
        }
        else
        {
            a2 = pt[i];
        }
        // cout<<a1<<a2<<" ";
        auto t1 = indexMat[a1 - 'a'];
        auto t2 = indexMat[a2 - 'a'];
        if (t1.first == t2.first)
        {
            ans.push_back(mat[t1.first][(t1.second + 1) % 5]);
            ans.push_back(mat[t2.first][(t2.second + 1) % 5]);
        }
        else if (t1.second == t2.second)
        {
            ans.push_back(mat[(t1.first + 1) % 5][t1.second]);
            ans.push_back(mat[(t2.first + 1) % 5][t2.second]);
        }
        else
        {
            ans.push_back(mat[t1.first][t2.second]);
            ans.push_back(mat[t2.first][t1.second]);
        }
    }

    cout << "\nYour encryption is : ";
    cout << ans;

    string decans;
    cout<< "\nYour decryption is : ";
    for (int i = 0; i < ans.length(); i++)
    {
        a1 = '$';
        a2 = '$';
        while (ans[i] == ' ' && i < ans.length())
        {
            i++;
        }
        if (i >= ans.length())
        {
            break;
        }
        a1 = ans[i];
        i++;
        while (ans[i] == ' ' && i < ans.length())
        {
            i++;
        }
        if (i == ans.length())
        {
            a2 = 'x';
        }
        else if (ans[i] == a1)
        {
            a2 = 'x';
            i--;
        }
        else
        {
            a2 = ans[i];
        }
        auto t1 = indexMat[a1 - 'a'];
        auto t2 = indexMat[a2 - 'a'];
        if (t1.first == t2.first)
        {
            decans.push_back(mat[t1.first][((t1.second - 1)==-1)?4:(t1.second - 1)]);
            decans.push_back(mat[t2.first][((t2.second - 1)==-1)?4:(t2.second - 1)]);
        }
        else if (t1.second == t2.second)
        {
            decans.push_back(mat[((t1.first - 1)==-1)?4:(t1.first-1)][t1.second]);
            decans.push_back(mat[((t2.first - 1)==-1)?4:(t2.first-1)][t2.second]);
        }
        else
        {
            decans.push_back(mat[t1.first][t2.second]);
            decans.push_back(mat[t2.first][t1.second]);
        }
    }
    cout<<decans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int determinantOfMatrix(int mat[2][2], int n)
{
int num1, num2, det = 1, index, total = 1; // Initialize result
// temporary array for storing row
int temp[n + 1];
// loop for traversing the diagonal elements
for (int i = 0; i < n; i++)
{
index = i; // initialize the index
// finding the index which has non zero value
while (index < n && mat[index][i] == 0)
{
index++;
}
if (index == n) // if there is non zero element
{
// the determinant of matrix as zero
continue;
}
if (index != i)
{
// loop for swapping the diagonal element row and
// index row
for (int j = 0; j < n; j++)
{
swap(mat[index][j], mat[i][j]);
}
// determinant sign changes when we shift rows
// go through determinant properties
det = det * pow(-1, index - i);
}
// storing the values of diagonal row elements
for (int j = 0; j < n; j++)
{
temp[j] = mat[i][j];
}
// traversing every row below the diagonal element
for (int j = i + 1; j < n; j++)
{
num1 = temp[i]; // value of diagonal element
num2 = mat[j][i]; // value of next row element
// traversing every column of row
// and multiplying to every row
for (int k = 0; k < n; k++)
{
// multiplying to make the diagonal
// element and next row element equal
mat[j][k] = (num1 * mat[j][k]) - (num2 * temp[k]);
}
total = total * num1; // Det(kA)=kDet(A);
}
}
// multiplying the diagonal elements to get determinant
for (int i = 0; i < n; i++)
{
det = det * mat[i][i];
}
return (det / total); // Det(kA)/k=Det(A);
}
int main()
{
string pt;
string key;
cout << "Enter plain text : ";
getline(cin, pt);
cout << "Enter key text(4 character) : ";
getline(cin, key);
string s;
for (int i = 0; i < pt.length(); i++)
{
if (pt[i] >= 'a' && pt[i] <= 'z')
{
s.push_back(pt[i]);
}
}
string ct;
for (int i = 0; i < s.length(); i += 2)
{
if (i + 1 == s.length())
{
s.push_back('x');
}
if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
{
int ans = ((s[i] - 'a') * (key[0] - 'a')) + ((s[i + 1] - 'a') * (key[2] - 'a'));
ans = ans % 26;
ct.push_back((char)(ans + 'a'));
ans = ((s[i] - 'a') * (key[1] - 'a')) + ((s[i + 1] - 'a') * (key[3] - 'a'));
ans = ans % 26;
ct.push_back((char)(ans + 'a'));
}
}
cout << "\nYour Encryption is : " << ct << "\n"
<< endl;
// for (int i = 0; i < ct.length(); i += 2)
// {
// cout << (ct[i] - 'a') << " " << (ct[i + 1] - 'a') << endl;
// }clear
int q, a, b, r, t1, t2, t;
a = 26;
int mat[2][2] = {{(key[0] - 'a'), (key[1] - 'a')}, {(key[2] - 'a'), (key[3] - 'a')}};
b = determinantOfMatrix(mat, 2);
t1 = 0;
t2 = 1;
do
{    
q = a / b;
r = a % b;
t = t1 - (t2 * q);
a = b;
b = r;
t1 = t2;
t2 = t;
} while (r != 0);
// cout << t1 << endl;
s = ct;
string pta;
for (int i = 0; i < s.length(); i += 2)
{
if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
{
int ans = ((s[i] - 'a') * (key[3] - 'a')) + ((s[i + 1] - 'a') * (-1) * (key[2] - 'a'));
ans *= t1;
ans = ans % 26;
if (ans < 0)
{
ans = 26 + ans;
}
// cout << ans << " ";
pta.push_back((char)(ans + 'a'));
ans = ((s[i] - 'a') * (-1) * (key[1] - 'a')) + ((s[i + 1] - 'a') * (key[0] - 'a'));
ans *= t1;
ans = ans % 26;
if (ans < 0)
{
ans = 26 + ans;
}
// cout << ans << " ";
pta.push_back((char)(ans + 'a'));
}
}
cout << "\nYour plain text : " << pta << "\n"
<< endl;
return 0;
}
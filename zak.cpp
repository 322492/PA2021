#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string b;
    cin >> n >> b;
    int n1 = 0;
    int n0 = 0;
    for (int i = 0; i < 8 * n; i++)
        if (b[i] == '1')
            n1++;
        else
            n0++;

    string w = "";

    bool czy = true;

    while (czy)
    {
        czy = false;

        if (n >= 1 && n1 >= 3 * n0 && n0>=2 && n1>=6)
        {
            w += "o";
            n0 -= 2;
            n1 -= 6;
            n--;
            czy = true;
        }
        else if (n >= 2 && 5 * n1 >= 11 * n0 && n0>=5 && n1>=11)
        {
            w += "go";
            n0 -= 5;
            n1 -= 11;
            n -= 2;
            czy = true;
        }
        else if (n >= 1 && 3 * n1 >= 5 * n0 && n0>=3 && n1>=5)
        {
            w += "g";
            n0 -= 3;
            n1 -= 5;
            n--;
            czy = true;
        }
        else if (n >= 3 && 5 * n1 >= 7 * n0 && n0>=10 && n1>=14)
        {
            w += "ago";
            n0 -= 10;
            n1 -= 14;
            n -= 3;
            czy = true;
        }
        else if (n >= 2 && 7 * n1 >= 9 * n0 && n0>=7 && n1>=9)
        {
            w += "ao";
            n0 -= 7;
            n1 -= 9;
            n -= 2;
            czy = true;
        }
        else if (n >= 3 && 11 * n1 >= 13 * n0 && n0>=11 && n1>=13)
        {
            w += "aco";
            n0 -= 11;
            n1 -= 13;
            n -= 3;
            czy = true;
        }
        else if (n >= 1 && n1 >= n0 && n0>=4 && n1>=4)
        {
            w += "c";
            n0 -= 4;
            n1 -= 4;
            n -= 1;
            czy = true;
        }
        else if (n >= 2 && 9 * n1 >= 7 * n0 && n0>=9 && n1>=7)
        {
            w += "ac";
            n0 -= 9;
            n1 -= 7;
            n -= 2;
            czy = true;
        }
        else if (n >= 1 && 5 * n1 >= 3 * n0 && n0>=5 && n1>=3)
        {
            w += "a";
            n0 -= 5;
            n1 -= 3;
            n -= 1;
            czy = true;
        }
    }

    if (n == 0 && n0 == 0 && n1 == 0)
        cout << w;
    else
        cout << "NIE";

    return 0;
}
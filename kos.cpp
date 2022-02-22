#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;
    int t[2005];

    for (int i = 0; i < n; i++)
        cin >> t[i];

    sort(t, t + n);

    for (int i = n - 1 - k; i >= 0; i--)
    {
        if (t[i] == t[i + 1])
            k++;
        else
            break;
    }

    cout << k;

    return 0;
}
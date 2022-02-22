#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

int n;
long long res = 0;
const int MAX = 1'000'006;
int tab[MAX];
int gdzie[MAX];

int policz(int a, int b, int dl) // ile jest przedzialow o dlugosci dl zawierajacych przedzial [a, b]
{
    if (b - a + 1 > dl)
        return 0;

    if (b - a + 1 == dl)
        return 1;

    int prawo = min(n, a + dl - 1);
    int lewo = max(1, b - dl + 1);

    return prawo - lewo + 1 - dl + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        gdzie[tab[i]] = i;
    }

    int a = gdzie[n], b = gdzie[n];
    int ile = 1;

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ile++;
            a = min(a, gdzie[n - ile + 1]);
            b = max(b, gdzie[n - ile + 1]);
        }
        res += policz(a, b, i);
    }

    cout << 2 * n + 1 << " " << res + 1;

    return 0;
}

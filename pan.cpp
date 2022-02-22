#include <bits/stdc++.h>

#define f first
#define s second
using namespace std;

int a, b;              // dlugosc poczatkowego i koncowego odcinka zer
bool pusto;            // czy caly ciag jest zerowy
priority_queue<int> q; // dlugosci kolejnych odcinkow zer
const int INF = 2 * 1000006;

void wyczysc()
{
    a = 0;
    b = 0;
    pusto = false;
    while (!q.empty())
        q.pop();
}

void pocz(int n, string c) // zliczanie ciagow zer i konstrukcja kolejki
{
    for (int i = 0; i < n; i++, a++)
        if (c[i] == '1')
            break;

    if (a == n)
    {
        pusto = true;
        return;
    }
    for (int i = n - 1; i >= 0; i--, b++)
        if (c[i] == '1')
            break;

    int licznik = 0;
    for (int i = a + 1; i <= n - 1 - b; i++)
    {
        if (c[i] == '0')
            licznik++;
        else
        {
            if (licznik > 0)
                q.push(licznik);
            licznik = 0;
        }
    }

    return;
}

int policz()
{
    int x;
    int wynik = 0;
    int ile = 0;
    if (b > a)
        swap(a, b);
    if (b == 0)
        b = -INF;
    if (a == 0)
        a = -INF;

    while (!q.empty())
    {
        x = q.top();
        x = x - 2 * ile;

        if (a >= x)
        {
            if (a > 0)
                wynik += a;
            a = b;
            b = -INF;
        }
        else if (x == 3 && a == 2)
        {
            wynik += 3;
            ile++;
            b--;
            a = -INF;
            q.pop();
        }
        else if (2 * a >= x)
        {
            if (a > 0)
                wynik += a;
            a = b;
            b = -INF;
        }
        else
        {
            if (x == 1)
                wynik += 1;

            else if (x > 0)
            {
                wynik += x - 1;
                ile++;
                a--;
                b--;
            }

            q.pop();
        }

        ile++;
        a--;
        b--;
    }
    if (a > 0)
    {
        wynik += a;
        a = -INF;
        b--;
    }
    if (b > 0)
    {
        wynik += b;
        b = -INF;
    }
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, res;
    string c;

    cin >> t;

    for (int p = 0; p < t; p++)
    {
        cin >> n >> c;
        wyczysc();
        pocz(n, c);
        if (pusto)
        {
            cout << "0\n";
            continue;
        }

        res = policz();
        cout << n - res << "\n";
    }

    return 0;
}
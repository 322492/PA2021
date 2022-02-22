#include <bits/stdc++.h>

using namespace std;

int n;
const int MOD = 1'000'000'007;
const int MAX = 300'005;
int wej[MAX];
int sumy[MAX];
int DP[MAX];
const int b = 1 << 19; // podstawa drzewa
int P[2 * b];          // drzewo sum parzystych
int NP[2 * b];         // drzewo sun nieparzystych

vector<int> format; // wektor, do którego wczytuję wszystkie wartości

int FIND(int x) // zwraca jaką liczbą jest liczba x po przeformatowaniu
{
    int a = 0;
    int b = format.size();
    int s;

    while (b - a != 1)
    {
        s = (a + b) / 2;
        if (format[s] > x)
            b = s;
        else
            a = s;
    }

    return a+1;
}

void wstaw_p(int i, int x)
{
    i += b;
    P[i] = (P[i]+x)%MOD;
    i /= 2;

    while (i > 0)
    {
        P[i] = (P[i * 2] + P[2 * i + 1]) % MOD;
        i /= 2;
    }

    return;
}

void wstaw_np(int i, int x)
{
    i += b;
    NP[i] = (NP[i]+x)%MOD;
    i /= 2;

    while (i > 0)
    {
        NP[i] = (NP[i * 2] + NP[2 * i + 1]) % MOD;
        i /= 2;
    }

    return;
}

int query_p(int p, int k) // p, k - poczatek i koniec przedzialu
{
    p += b;
    k += b;

    int w = P[p] % MOD;
    if (p != k)
        w = (w + P[k]) % MOD;

    while (k / 2 != p / 2)
    {
        if (p % 2 == 0)
            w = (w + P[p + 1]) % MOD;
        if (k % 2 == 1)
            w = (w + P[k - 1]) % MOD;
        p /= 2;
        k /= 2;
    }

    return w;
}

int query_np(int p, int k) // p, k - poczatek i koniec przedzialu
{
    p += b;
    k += b;

    int w = NP[p] % MOD;
    if (p != k)
        w = (w + NP[k]) % MOD;

    while (k / 2 != p / 2)
    {
        if (p % 2 == 0)
            w = (w + NP[p + 1]) % MOD;
        if (k % 2 == 1)
            w = (w + NP[k - 1]) % MOD;
        p /= 2;
        k /= 2;
    }

    return w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> wej[i];
        sumy[i] = (sumy[i - 1] + wej[i]) % MOD;
        format.push_back(sumy[i]);
    }

    format.push_back(0);

    sort(format.begin(), format.end());
    format.resize(unique(format.begin(), format.end()) - format.begin());
    // funckje zwracają mi wektor wartości bez powtórzeń posortowany rosnąco

    DP[0] = 1;
    wstaw_p(0, 1);

    for (int i = 1; i <= n; i++)
    {
        int akt=0;

        if (sumy[i] % 2 == 1)
        {
            akt = (query_np(0, FIND(sumy[i])) + query_p(FIND((sumy[i]+1)% MOD), format.size()))%MOD;
            wstaw_np(FIND(sumy[i]), akt);
        }
        else
        {
            akt = (query_p(0, FIND(sumy[i]))+ query_np(FIND((sumy[i]+1)% MOD), format.size()))%MOD;
            wstaw_p(FIND(sumy[i]), akt);
        }
        DP[i] = akt;
    }

    cout << DP[n];

    return 0;
}
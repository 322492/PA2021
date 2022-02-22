#include <bits/stdc++.h>

#define f first
#define s second
using namespace std;

long long tab[500005];
long long wej[500005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> wej[i];
        tab[i] = wej[i];
    }

    sort(tab, tab + n);

    long long w = tab[n - 1] + 1;
    long long w_sumie = tab[0];
    long long akt = tab[0];
    bool czy = false;

    for (int i = 1; i < n; i++)
    {
        if (akt < tab[i])
        {
            akt = w_sumie + tab[i];
            w = tab[i];
            czy = true;
        }
        else if (akt > tab[i])
        {
            akt += tab[i];
            czy = true;
        }
        else if (akt == tab[i] && czy == true)
        {
            akt = w_sumie + tab[i];
            w = tab[i];
        }
        w_sumie += tab[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (wej[i] < w)
            cout << "N";
        else
            cout << "T";
    }

    return 0;
}
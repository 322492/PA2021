#include <bits/stdc++.h>

using namespace std;

int n = 0, a, b;
const int MAX = 100005;
vector<int> tab[MAX]; // drzewo
string sp, sk;        // stan poczatkowy i stan koncowy drzewa
string cp, ck;        // ciagi kolorow jesli drzewa sa sciezkami

void wyczysc()
{
    for (int i = 0; i <= n; i++)
        tab[i].clear();
    cp = "";
    ck = "";
}

bool jeden_kolor(string s)
{
    for (int i = 2; i <= n; i++)
        if (s[i] != s[i - 1])
            return false;
    return true;
}

bool kazda_para_rozna(string s)
{
    for (int i = 1; i <= n; i++)
        for (int v : tab[i])
            if (s[i] == s[v])
                return false;

    return true;
}

bool ma_wierzcholek_o_stopniu_3()
{
    for (int i = 1; i <= n; i++)
        if (tab[i].size() >= 3)
            return true;
    return false;
}

int znajdz_poczatek()
{
    for (int i = 1; i <= n; i++)
        if (tab[i].size() == 1)
            return i;

    return n;
}

void skonstruuj_ciagi()
{
    int v = znajdz_poczatek();

    cp += sp[v];
    ck += sk[v];
    int p = v;           // rodzic
    int akt = tab[v][0]; // aktualny wierzcholek

    while (tab[akt].size() != 1)
    {
        if (sp[akt] != sp[p])
            cp += sp[akt];
        if (sk[akt] != sk[p])
            ck += sk[akt];

        if (tab[akt][0] != p)
        {
            p = akt;
            akt = tab[akt][0];
        }
        else if (tab[akt][1] != p)
        {
            p = akt;
            akt = tab[akt][1];
        }
    }

    if (sp[akt] != sp[p])
        cp += sp[akt];
    if (sk[akt] != sk[p])
        ck += sk[akt];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int l = 0; l < t; l++)
    {
        wyczysc();
        cin >> n;
        cin >> sp >> sk;
        sp = " " + sp;
        sk = " " + sk;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            tab[a].push_back(b);
            tab[b].push_back(a);
        }

        if (sp == sk) // poczatkowy i koncowy stan drzewa sa takie same
            cout << "TAK\n";

        else if (jeden_kolor(sp)) // poczatkowe drzewo jest jednokolorowe
            cout << "NIE\n";

        else if (kazda_para_rozna(sk)) // w koncowym drzewie kazda para sasiadujacych wierzcholkow jest roznych kolorow (nie mozna wybrac ostatniej pary do zmiany)
            cout << "NIE\n";

        else if (ma_wierzcholek_o_stopniu_3()) // jesli w drzewie jest wierzcholek o stopniu co najmniej 3
            cout << "TAK\n";

        else // zatem nasze drzewo jest sciezka
        {
            skonstruuj_ciagi();

            if (cp == ck) // ciagi kolorow sa takie same
                cout << "TAK\n";

            else if (cp[0] == ck[0] && cp.length() >= ck.length())
                cout << "TAK\n";

            else if (cp[0] != ck[0] && cp.length() > ck.length())
                cout << "TAK\n";

            else
                cout << "NIE\n";
        }
    }

    return 0;
}
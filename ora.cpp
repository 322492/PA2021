#include <iostream>

using namespace std;

int n, k;
bool bylo[500005];
int tab[500005];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> tab[i];

    long long w = 0;
    bool czy = 0;
    int j = 1;
    for (int i = 0; i < k; i++, j++)
    {
        if (bylo[tab[i]] == true)
        {
            while (j <= n)
            {

                if (j < n && bylo[tab[j]] == false)
                {
                    swap(tab[i], tab[j]);
                    w += (j - i);
                    break;
                }
                j++;
            }
        }
        if (j == n + 1)
        {
            czy = 1;
            break;
        }
        bylo[tab[i]] = true;
    }

    if (czy)
        cout << "-1";
    else
        cout << w;

    return 0;
}
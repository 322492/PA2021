#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

const int MAX = 100005;
int res[MAX];
const int INF = 1e9;
int A, B, C;

struct jest
{
    int a, b, c, ile;
};
set<pair<int, pair<int, int> > >visited;
queue<jest> kolejka;
jest x;

void sprawdz(jest stan)
{
    res[stan.a] = min(res[stan.a], stan.ile);
    res[stan.b] = min(res[stan.b], stan.ile);
    res[stan.c] = min(res[stan.c], stan.ile);
}


void przelej(jest stan)
{
    // a-->b
    if (stan.a != 0 && stan.b != B)
    {
        if (stan.a >= B - stan.b)
        {
            if (visited.find({stan.a - (B - stan.b), {B, stan.c}}) == visited.end())
            {
                visited.insert({stan.a - (B - stan.b), {B, stan.c}});
                kolejka.push({stan.a - (B - stan.b), B, stan.c, stan.ile + 1});
            }
        }
        else
        {
            if (visited.find({0, {stan.b + stan.a, stan.c}}) == visited.end())
            {
                visited.insert({0, {stan.b + stan.a, stan.c}});
                kolejka.push({0, stan.b + stan.a, stan.c, stan.ile + 1});
            }
        }
    }

    // b-->a
    if (stan.b != 0 && stan.a != A)
    {

        if (stan.b >= A - stan.a)
        {
            if (visited.find({A, {stan.b - (A - stan.a), stan.c}}) == visited.end())
            {
                visited.insert({A, {stan.b - (A - stan.a), stan.c}});
                kolejka.push({A, stan.b - (A - stan.a), stan.c, stan.ile + 1});
            }
        }
        else
        {
            if (visited.find({stan.a + stan.b, {0, stan.c}}) == visited.end())
            {
                visited.insert({stan.a + stan.b, {0, stan.c}});
                kolejka.push({stan.a + stan.b, 0, stan.c, stan.ile + 1});
            }
        }
    }

    // a-->c
    if (stan.a != 0 && stan.c != C)
    {

        if (stan.a >= C - stan.c)
        {

            if (visited.find({stan.a - (C - stan.c), {stan.b, C}}) == visited.end())
            {
                visited.insert({stan.a - (C - stan.c), {stan.b, C}});
                kolejka.push({stan.a - (C - stan.c), stan.b, C, stan.ile + 1});
            }
        }
        else
        {

            if (visited.find({0, {stan.b, stan.c + stan.a}}) == visited.end())
            {
                visited.insert({0, {stan.b, stan.c + stan.a}});
                kolejka.push({0, stan.b, stan.c + stan.a, stan.ile + 1});
            }
        }
    }

    // c-->a
    if (stan.c != 0 && stan.a != A)
    {

        if (stan.c >= A - stan.a)
        {
            if (visited.find({A, {stan.b, stan.c - (A - stan.a)}}) == visited.end())
            {
                visited.insert({A, {stan.b, stan.c - (A - stan.a)}});
                kolejka.push({A, stan.b, stan.c - (A - stan.a), stan.ile + 1});
            }
        }
        else
        {
            if (visited.find({stan.a+stan.c, {stan.b, 0}}) == visited.end())
            {
                visited.insert({stan.a+stan.c, {stan.b, 0}});
                kolejka.push({stan.a + stan.c, stan.b, 0, stan.ile + 1});
            }
        }
    }

    // b-->c
    if (stan.b != 0 && stan.c != C)
    {

        if (stan.b >= C - stan.c)
        {
            if (visited.find({stan.a, {stan.b - (C - stan.c), C}}) == visited.end())
            {
                visited.insert({stan.a, {stan.b - (C - stan.c), C}});
                kolejka.push({stan.a, stan.b - (C - stan.c), C, stan.ile + 1});
            }
        }
        else
        {
            if (visited.find({stan.a, {0, stan.b + stan.c}}) == visited.end())
            {
                visited.insert({stan.a, {0, stan.b + stan.c}});
                kolejka.push({stan.a, 0, stan.c + stan.b, stan.ile + 1});
            }
        }
    }

    // c-->b
    if (stan.c != 0 && stan.b != B)
    {

        if (stan.c >= B - stan.b)
        {
            if (visited.find({stan.a, {B, stan.c - (B - stan.b)}}) == visited.end())
            {
                visited.insert({stan.a, {B, stan.c - (B - stan.b)}});
                kolejka.push({stan.a, B, stan.c - (B - stan.b), stan.ile + 1});
            }
        }
        else
        {
            if (visited.find({stan.a, {stan.b+stan.c, 0}}) == visited.end())
            {
               visited.insert({stan.a, {stan.b+stan.c, 0}});
                kolejka.push({stan.a, stan.b + stan.c, 0, stan.ile + 1});
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int pa, pb, pc;
    cin >> A >> B >> C;
    cin >> pa >> pb >> pc;

    for (int i = 0; i <= C; i++)
        res[i] = INF;

    kolejka.push({pa, pb, pc, 0});

    visited.insert({pa, {pb, pc}});

    while (!kolejka.empty())
    {
        x = kolejka.front();
        kolejka.pop();

        sprawdz(x);
        przelej(x);
    }

    for (int i = 0; i <= C; i++)
    {
        if (res[i] == INF)
            cout << "-1 ";
        else
            cout << res[i] << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

template <typename T>
using PTT = pair<T, T>;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define ROF(i, n) for (int i = n - 1; i >= 0; i--)

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (m <= n)
    {
        if (k == 1)
        {
            cout << "1\n";
        }
        else if (k == 2)
        {
            cout << m << "\n";
        }
        else
        {
            cout << "0\n";
        }
        return;
    }
    else
    {
        // number of multiples of n >n i.e 2n, 3n, 4n, 5n...... <= m
        int num = m / n - 1;

        if (k == 1)
        {
            cout << "1\n";
        }
        else if (k == 2)
        {
            cout << n + num << "\n";
        }
        else if (k == 3)
        {
            cout << m - n - num << "\n";
        }
        else
        {
            cout << "0\n";
        }
        return;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        LLI a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a += x;
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            b += x;
        }

        if (a > b)
        {
            cout << "Tsondu\n";
        }
        else if (a < b)
        {
            cout << "Tenzing\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
    return 0;
}
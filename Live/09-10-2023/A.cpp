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
    int n;
    cin >> n;
    if (n < 7 || n == 9)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (n % 3 != 0)
    {
        cout << "1 2 " << n - 3 << "\n";
        return;
    }
    else
    {
        cout << "1 4 " << n - 5 << "\n";
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
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

template <typename S>
ostream &operator<<(ostream &os, const VEC<S> &vector)
{
    for (auto element : vector)
        os << element << " ";
    os << "\n";
    return os;
}

void solve()
{
    int n;
    cin >> n;
    VEC<LLI> a(2 * n, 0);
    FOR(i, 2 * n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    LLI ans = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        ans += a[i + 1] - a[i];
        ans += a[i + 1 + n] - a[i + n];
    }
    cout << ans << "\n";
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " " << a[n + i] << "\n";
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
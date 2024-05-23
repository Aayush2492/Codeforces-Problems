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
    int n, k;
    cin >> n >> k;
    VEC<LLI> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int count = 1;
    LLI max_ans = 0;
    while (count <= k)
    {
        max_ans += a[n - 2 * count];
        count += 1;
    }

    LLI min_ans = 0;
    for (int i = 0; i < k - 1; i++)
    {
        min_ans += a[i];
    }
    min_ans += a[n - k - 1];

    cout << min_ans << " " << max_ans << "\n";
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
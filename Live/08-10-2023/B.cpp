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
    LLI n, p;
    cin >> n >> p;
    VEC<PTT<LLI>> ba;
    VEC<LLI> a(n, 0);
    VEC<LLI> b(n, 0);
    FOR(i, n)
    {
        cin >> a[i];
    }
    FOR(i, n)
    {
        cin >> b[i];
    }

    FOR(i, n)
    {
        ba.push_back({b[i], a[i]});
    }

    sort(ba.begin(), ba.end());

    LLI cost = 0;
    if (ba[0].first >= p) // least cost >= p
    {
        cost = n * p;
        cout << cost << "\n";
        return;
    }

    LLI remaining = n - 1;
    cost += p;

    FOR(i, n)
    {
        if (ba[i].first >= p || remaining <= 0)
        {
            break;
        }

        if (ba[i].second >= remaining)
        {
            cost += ba[i].first * remaining;
            remaining = 0;
            break;
        }
        else
        {
            // ba[i].second < remaining
            cost += ba[i].first * ba[i].second; // announce to next least costlier person and others
            remaining -= ba[i].second;
        }
    }

    if (remaining < 0)
        remaining = 0;
    cost += remaining * p;
    cout << cost << "\n";
    return;
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
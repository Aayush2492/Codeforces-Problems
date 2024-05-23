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

double distance(PTT<LLI> &x, PTT<LLI> &y)
{
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

void solve()
{
    PTT<LLI> p, a, b;
    cin >> p.first >> p.second;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    PTT<LLI> og = {0, 0};

    double ans = min(max(distance(p, a), distance(og, a)), max(distance(p, b), distance(og, b)));

    double rad = distance(a, b) / 2.0;

    if (distance(a, og) > rad && distance(b, og) > rad)
    {
        rad = min(distance(a, og), distance(b, og));
    }

    if (distance(a, p) > rad && distance(b, p) > rad)
    {
        rad = min(distance(a, p), distance(b, p));
    }
    ans = min(rad, ans);

    cout << fixed << setprecision(10);
    cout << ans << "\n";
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
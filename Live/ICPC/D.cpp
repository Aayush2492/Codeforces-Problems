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
    int k;
    cin >> k;

    string s;
    cin >> s;
    int start = 0;
    int dir = 1;

    for (auto c : s)
    {
        // cout << start << "\n";
        if (c == 'U')
        {
            start = (start + dir + n) % n;
        }
        else if (c == 'S')
        {
            start = (start + dir * 2 + n) % n;
        }
        else if (c == 'R')
        {
            dir *= -1;
            start = (start + dir + n) % n;
        }
    }
    // if (start == 0)
    //     start = n;
    cout << start + 1 << "\n";
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
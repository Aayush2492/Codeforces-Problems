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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LLI n, k, x;
        cin >> n >> k >> x;
        LLI ans;
        if (n < k || k - 1 > x)
        {
            ans = -1;
        }
        else
        {
            ans = k * (k - 1) / 2;
            if (k != x)
                ans += x * (n - k);
            else
                ans += (x - 1) * (n - k);
        }
        cout << ans << "\n";
    }
    return 0;
}
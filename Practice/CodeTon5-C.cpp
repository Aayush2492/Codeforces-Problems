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
        int n;
        cin >> n;
        VEC<int> a(n, 0);

        FOR(i, n)
        {
            cin >> a[i];
        }

        VEC<int> pos(n, -1);
        // pos[i] => index of i + 1 encountered before.

        VEC<int> dp(n, 0);
        // dp[i] => ans for a[0...i]

        FOR(i, n)
        {
            int elem = a[i];
            if (pos[elem - 1] != -1)
            {
                if (pos[elem - 1] != 0)
                {
                    int len = i - pos[elem - 1] + 1;
                    dp[i] = max(dp[i - 1], len + dp[pos[elem - 1] - 1]);
                }
                else
                {
                    int len = i + 1;
                    dp[i] = len;
                }
            }
            else
            {
                dp[i] = dp[i - 1];
            }
            pos[elem - 1] = i;
        }

        cout << dp[n - 1] << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = pair<int, int>;

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n, k, d;
        cin >> n >> k >> d;
        VV<LLI> dp(n + 1, VEC<LLI>(2, 0));

        // dp[i][0] = Number of ways to get sum i with all elements < d
        // dp[i][1] = Number of ways to get sum i with atleast one element >= d
        // ans = dp[n][1]

        dp[0][0] = 1;
        dp[0][1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= min(i, k); j++)
            {
                if (j < d)
                {
                    dp[i][0] = (dp[i][0] + dp[i - j][0]) % 1000000007;
                    dp[i][1] = (dp[i][1] + dp[i - j][1]) % 1000000007;
                }
                else
                {
                    // j in [d, i]
                    dp[i][1] = (dp[i][1] + dp[i - j][0] + dp[i - j][1]) % 1000000007;
                }
            }
        }

        cout << dp[n][1] << "\n";
    }
    return 0;
}
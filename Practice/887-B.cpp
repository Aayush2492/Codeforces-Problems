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
        int n, k;
        cin >> n >> k;
        if (k > 30)
        {
            cout << "0\n";
        }
        else
        {
            VV<int> dp(n + 1, VEC<int>(k + 1, 0));
            // dp[i][j] = number of fib seq of length j with jth term = i
            // dp[i][0] => useless
            // dp[i][1] => 1 for all i
            for (int i = 0; i <= n; i++)
            {
                dp[i][1] = 1;
                dp[i][2] = i + 1;
            }

            // for (int i = 3; i <= k; i++)
            // {
            //     dp[0][i] = 1;
            //     dp[1][i] = 0;
            // }
            dp[1][3] = 1;
            for (int j = 3; j <= k; j++)
            {
                for (int i = 0; i <= n; i++)
                {
                    for (int l = 0; l <= (int)floor(i / 2.0); l++)
                    {
                        // (j - 2)th term is l
                        // (j - 1)th term is i - l
                        // i - l >= l ==> l <= floor(i / 2)
                        dp[i][j] += dp[l][j - 2];
                    }
                }
            }

            for (int i = 0; i <= n; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    cout << dp[i][j] << " ";
                }
                cout << "\n";
            }
            cout << dp[n][k] << "\n";
        }
    }
    return 0;
}
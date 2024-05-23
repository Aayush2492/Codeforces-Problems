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

VEC<LLI> fact(200000 + 1, 1);

int main()
{
    for (int i = 2; i <= 200000; i++)
    {
        fact[i] = (fact[i - 1] * i) % 998244353;
    }

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        VEC<int> freq;
        freq.push_back(1);
        int n = s.length();
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                freq[freq.size() - 1] += 1;
            }
            else
            {
                freq.push_back(1);
            }
        }
        int ans1 = 0;
        LLI ans2 = 1;
        for (int i = 0; i < freq.size(); i++)
        {
            ans1 += freq[i] - 1;
            ans2 = (ans2 * freq[i]) % 998244353;
        }
        ans2 = (ans2 * fact[ans1]) % 998244353;

        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
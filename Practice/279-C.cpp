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
        string s;
        cin >> s;
        int a, b;
        cin >> a >> b;

        int n = s.length();
        VEC<int> A(n, 0);
        // A[i] => Remainder when s0, s1, .... s[i] is divided by a
        VEC<int> B(n, 0);
        // B[i] => Remainder when si, si+1, .... s[n-1] is divided by b
        VEC<int> pow10mod(n, 0);
        // pow10mod[i] => 10 ^ i % b

        A[0] = (s[0] - 48) % a;
        for (int i = 1; i < n; i++)
        {
            A[i] = (((10 % a) * A[i - 1]) % a + (s[i] - 48) % a) % a;
        }

        pow10mod[0] = 1;
        for (int i = 1; i < n; i++)
        {
            pow10mod[i] = ((10 % b) * pow10mod[i - 1]) % b;
        }

        B[n - 1] = (s[n - 1] - 48) % b;
        for (int i = n - 2; i >= 0; i--)
        {
            B[i] = (B[i + 1] + (((s[i] - 48) % b) * pow10mod[n - i - 1]) % b) % b;
        }

        // Find i such that A[i] = 0 and B[i + 1] = 0, i in [0, n-2]
        int idx = -1;
        for (int i = 0; i <= n - 2; i++)
        {
            if (A[i] == 0 && B[i + 1] == 0)
            {
                idx = i;
                if (s[i + 1] - 48 != 0)
                    break;
            }
        }

        if (idx == -1 || s[idx + 1] == '0')
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << s.substr(0, idx + 1) << "\n";
            cout << s.substr(idx + 1, n - idx - 1) << "\n";
        }
    }
    return 0;
}
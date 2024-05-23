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
        int n, m;
        cin >> n >> m;
        VEC<int> a(n, 0);
        VEC<int> b(m, 0);
        int min_x;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                min_x = a[0];
            else
                min_x ^= a[i];
        }
        int max_x = min_x;
        int b_or = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            max_x |= b[i];
            b_or |= b[i];
        }
        if (n % 2)
        {
            cout << min_x << " " << max_x << "\n";
        }
        else
        {
            int ans;
            ans = a[0] | b_or;
            for (int i = 1; i < n; i++)
            {
                ans ^= (a[i] | b_or);
            }
            cout << ans << " " << min_x << "\n";
        }
    }
    return 0;
}
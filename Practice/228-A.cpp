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
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        VEC<int> a(n, 0);
        FOR(i, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int count = 0;
        VEC<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            int curr = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (visited[j])
                {
                    continue;
                }
                if (a[j] >= curr)
                {
                    curr += 1;
                    visited[j] = true;
                }
            }
            if (curr > 0)
            {
                count += 1;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
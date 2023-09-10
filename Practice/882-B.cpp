#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

template <typename T>
using PTT = pair<T, T>;

#define FOR(start, end, inc) for (int i = start; i < end; i += inc)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        VEC<LLI> a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        VEC<LLI> post_and(n, 0);
        // post_and[i] = a[i] & a[i + 1] ... & a[n - 1]
        post_and[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            post_and[i] = post_and[i + 1] & a[i];
        }

        int count = 1;
        LLI required_sum = post_and[0];
        LLI curr = a[0];
        for (int i = 1; i < n; i++)
        {
            // curr => till i - 1
            if (curr + post_and[i] == required_sum)
            {
                // found a seq till ..i-1
                count += 1;
                required_sum -= curr;
                curr = a[i];
                // cout << "Index: " << i << "\n";
            }
            else
            {
                curr &= a[i];
            }
        }
        cout << count << "\n";
    }
    return 0;
}
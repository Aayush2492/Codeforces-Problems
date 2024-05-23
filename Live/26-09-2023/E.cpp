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

int range_query(int l, int r, VV<int> &prefix_count)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int x;
        if (l == 0)
            x = prefix_count[i][r];
        else
            x = prefix_count[i][r] - prefix_count[i][l - 1];
        if (x == r - l + 1)
            ans = (ans | (1 << i));
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n;
        VEC<int> a(n, 0);
        FOR(i, n)
        {
            cin >> a[i];
        }

        VV<int> prefix_count(32, VEC<int>(n, 0));
        for (int i = 0; i < 32; i++)
        {
            prefix_count[i][0] = ((a[0] >> i) & 1);
            for (int j = 1; j < a.size(); j++)
            {
                prefix_count[i][j] = ((a[j] >> i) & 1);
                prefix_count[i][j] += prefix_count[i][j - 1];
            }
        }

        cin >> q;
        VEC<int> ans;
        FOR(i, q)
        {
            int l, k;
            cin >> l >> k;

            // O(n) => not optimal
            int r = -1;
            // for (int j = n - 1; j >= l - 1; j--)
            // {
            //     if (range_query(l - 1, j, prefix_count) >= k)
            //     {
            //         r = j + 1;
            //         break;
            //     }
            // }

            // O(log n)
            int low = l - 1;
            int high = n - 1;

            if (k > a[l - 1])
            {
                r = -1;
            }
            else
            {
                while (low <= high)
                {
                    int mid = (low + high) / 2;
                    int mid_elem = range_query(l - 1, mid, prefix_count);
                    if (mid_elem >= k)
                    {
                        low = mid + 1;
                    }
                    else if (mid_elem < k)
                    {
                        high = mid - 1;
                    }
                }
                r = low - 1 + 1;
            }
            ans.push_back(r);
        }
        FOR(i, q)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
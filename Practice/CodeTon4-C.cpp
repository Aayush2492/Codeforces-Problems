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
        LLI n, c, d;
        cin >> n >> c >> d;
        VEC<int> a(n, 0);
        FOR(i, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        int count = 0;
        int curr = a[0];
        VEC<int> arr;
        arr.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] == curr)
            {
                count++;
            }
            else
            {
                arr.push_back(a[i]);
                curr = a[i];
            }
        }

        LLI base_cost = count * c;
        if (arr[0] != 1)
        {
            base_cost += d;
            arr.insert(arr.begin(), 1);
        }

        LLI insertion_cost = 0, deletion_cost = 0;
        deletion_cost = arr.size() * c;
        LLI ans = LLONG_MAX;
        FOR(i, arr.size())
        {
            if (i == 0)
            {
                insertion_cost += 0;
            }
            else
            {
                // insertion cost of element from arr[i] to arr[i - 1]
                insertion_cost += (arr[i] - arr[i - 1] - 1) * d;
            }
            deletion_cost -= c;
            ans = min(ans, insertion_cost + deletion_cost);
            // cout << insertion_cost + deletion_cost + base_cost << "\n";
        }
        cout << ans + base_cost << "\n";
    }
    return 0;
}
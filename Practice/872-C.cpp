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
        VEC<int> b;
        map<int, bool> present;
        int count_left = 0, count_right = 0;
        FOR(i, n)
        {
            cin >> a[i];
            if (a[i] == -1)
            {
                count_left += 1;
            }
            else if (a[i] == -2)
            {
                count_right += 1;
            }
            else if (!present[a[i]])
            {
                b.push_back(a[i]);
                present[a[i]] = true;
            }
        }
        sort(b.begin(), b.end());
        // b is a sorted array containing distint elements from 1 to m.
    }
    return 0;
}
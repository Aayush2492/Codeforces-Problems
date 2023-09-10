#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/467/B
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(m + 1, 0);
    for (int i = 0; i < m + 1; i++)
        cin >> x[i];

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (__builtin_popcount(x[i] ^ x[m]) <= k)
            count += 1;
    }
    cout << count << endl;
    return 0;
}
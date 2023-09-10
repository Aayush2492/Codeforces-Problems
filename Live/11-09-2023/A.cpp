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
        int n;
        cin >> n;
        VEC<PTT<int>> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back({x, i + 1});
        }

        sort(a.begin(), a.end());
        VEC<PTT<int>> b;
        for (int i = 0; i < a.size(); i++)
        {
            b.push_back({a[i].second, n - i});
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i].second << " ";
        }
        cout << "\n";
    }
    return 0;
}
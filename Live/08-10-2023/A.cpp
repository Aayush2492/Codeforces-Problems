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
        int n;
        cin >> n;
        VEC<int> a(n - 1, 0);
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        cout << -sum << "\n";
    }
    return 0;
}
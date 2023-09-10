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
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b < n - 1 || (a == n && b == n))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
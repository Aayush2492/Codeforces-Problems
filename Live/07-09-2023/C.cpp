#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = pair<int, int>;

int get_nearest_multiple_4(int n)
{
    int rem = n % 4;
    if (rem == 0)
    {
        return n;
    }
    else if (rem == 1)
    {
        return n - 1;
    }
    else if (rem == 2)
    {
        return n - 2;
    }
    else
    {
        return n + 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int a = get_nearest_multiple_4(l) / 2;
        int b = get_nearest_multiple_4(r) / 2;

        if (a == 0 || b == 0 || a + b < l || a + b > r)
            cout << "-1\n";
        else
            cout << a << " " << b << "\n";
    }
    return 0;
}
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
        LLI n;
        cin >> n;
        LLI count = 1;
        while (true)
        {
            if (n % count == 0)
            {
                count += 1;
            }
            else
            {
                break;
            }
        }
        cout << count - 1 << "\n";
    }
    return 0;
}
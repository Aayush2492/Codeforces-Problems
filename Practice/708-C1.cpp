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
        int n, k;
        cin >> n >> k;
        if (n % 3 == 0)
        {
            int ans = n / 3;
            cout << ans << " " << ans << " " << ans << "\n";
        }
        else if (n % 3 == 1)
        {
            int q = n / 3;
            if (q % 2 == 0)
            {
                int ans = (n - 1) / 2;
                cout << "1 " << ans << " " << ans << "\n";
            }
            else
            {
                int ans = (n - 2) / 2;
                cout << "2 " << ans << " " << ans << "\n";
            }
        }
        else if (n % 3 == 2)
        {
            int q = n / 3;
            if (q % 2 == 0)
            {
                int ans = (n - 2) / 2;
                cout << "2 " << ans << " " << ans << "\n";
            }
            else
            {
                int ans = (n - 1) / 2;
                cout << "1 " << ans << " " << ans << "\n";
            }
        }
    }
    return 0;
}
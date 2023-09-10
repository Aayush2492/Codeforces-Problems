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
        int n, x;
        cin >> n >> x;
        VEC<int> A(n, 0);
        VEC<int> B(n, 0);
        VEC<int> C(n, 0);
        int fin = 0;
        bool a_ = false, b_ = false, c_ = false;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            int y = x | A[i];
            if (a_ == false && y != x)
            {
                a_ = true;
            }
            if (!a_)
            {
                fin |= A[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
            int y = x | B[i];
            if (b_ == false && y != x)
            {
                b_ = true;
            }
            if (!b_)
            {
                fin |= B[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> C[i];
            int y = x | C[i];
            if (c_ == false && y != x)
            {
                c_ = true;
            }
            if (!c_)
            {
                fin |= C[i];
            }
        }
        if (fin == x || x == 0)
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
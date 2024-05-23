#include <bits/stdc++.h>

template <typename T>
using VEC = std::vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        VEC<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    return 0;
}
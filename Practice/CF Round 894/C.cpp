#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = pair<int, int>;

template <typename S>
std::ostream &operator<<(std::ostream &os, const std::vector<S> &vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector)
    {
        os << element << " ";
    }
    os << "\n";
    return os;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        VEC<int> a(n, 0);
        VEC<int> rev(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            rev[i] = a[n - i - 1];
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = pair<int, int>;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector)
{
    for (auto element : vector)
    {
        os << element << " ";
    }
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
        VEC<int> b(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        VEC<int> a;
        a.push_back(b[0]);
        for (int i = 1; i < n; i++)
        {
            if (b[i - 1] > b[i])
            {
                // x <= b[i], x < []
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
            else
            {
                a.push_back(b[i]);
            }
        }
        cout << a.size() << endl;
        cout << a;
        cout << "\n";
    }
    return 0;
}
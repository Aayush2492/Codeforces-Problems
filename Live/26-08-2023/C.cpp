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
    for (auto element : vector)
    {
        os << element << " ";
    }
    os << "\n";
    return os;
}

bool solve(int x, VEC<int> &factors, unordered_map<int, int> &m)
{
    if (x == 1)
    {
        return true;
    }
    for (int i = x; i >= 1; i--)
    {
        if (x % i == 0)
        {
            factors.push_back(x - i);
            if (m[i] < 2)
            {
                m[i] += 1;
                int curr_size = factors.size();
                bool status = solve(x - i, factors, m);
                // cout << x << " " << x - i << " " << status << "\n";
                if (status)
                {
                    return true;
                }
                else
                {
                    factors.resize(curr_size);
                    m[i] -= 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        VEC<int> ans;
        ans.push_back(x);
        unordered_map<int, int> m;
        solve(x, ans, m);
        cout << ans.size() << "\n";
        cout << ans;
    }
    return 0;
}
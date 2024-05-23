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

void solve()
{
    string s;
    cin >> s;
    VEC<int> b_pos;
    int count_a = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
        {
            b_pos.push_back(count_a);
            count_a = 0;
        }
        else
        {
            count_a += 1;
        }
    }

    if (s[s.length() - 1] == 'B')
    {
        b_pos.push_back(0);
    }
    else
    {
        b_pos.push_back(count_a);
    }

    int sum = accumulate(b_pos.begin(), b_pos.end(), 0);
    int min = *min_element(b_pos.begin(), b_pos.end());
    cout << sum - min << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
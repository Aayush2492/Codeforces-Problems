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
ostream &operator<<(ostream &os, const VEC<S> &vector)
{
    for (auto element : vector)
        os << element << " ";
    os << "\n";
    return os;
}

void solve()
{
    int n;
    cin >> n;
    VEC<int> arr(n, 0);
    map<int, int> freq;
    int sum = 0;
    FOR(i, n)
    {
        cin >> arr[i];
        freq[arr[i]] += 1;
    }

    int count_2 = 0;
    for (auto x : freq)
    {
        // if (x.second > 3)
        // {
        //     cout << "-1\n";
        //     return;
        // }

        if (x.second >= 2)
            count_2++;
    }

    if (count_2 <= 1)
    {
        cout << "-1\n";
        return;
    }

    map<int, int> status;
    int flag = 0;
    FOR(i, n)
    {

        if (status[arr[i]] + 1 == 2 && flag == 0)
        {
            flag = arr[i];
            status[arr[i]] = 2;
        }

        cout << status[arr[i]] + 1 << " ";

        if (arr[i] == flag)
        {
            status[arr[i]] = 2;
        }
        else
        {
            status[arr[i]] = min(1, status[arr[i]] + 1);
        }
    }
    cout << "\n";
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
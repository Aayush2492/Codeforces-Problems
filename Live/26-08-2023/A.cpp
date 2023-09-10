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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n;
        cin >> x >> y >> n;
        VEC<int> arr(n, 0);
        arr[0] = x;
        arr[n - 1] = y;
        int diff = 1;
        int flag = 0;
        int min = arr[0];
        for (int i = n - 2; i >= 0; i--)
        {
            arr[i] = arr[i + 1] - diff;
            diff += 1;
        }
        if (arr[0] < min)
        {
            flag = -1;
        }
        if (flag == -1)
        {
            cout << "-1\n";
        }
        else
        {
            arr[0] = min;
            cout << arr;
        }
    }
    return 0;
}
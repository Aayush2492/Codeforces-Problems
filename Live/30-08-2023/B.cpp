#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = pair<int, int>;

int solve(vector<int> &arr)
{
    if (arr.size() == 2)
    {
        if (arr[0] > arr[1])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (arr.size() == 1)
    {
        return 0;
    }

    int mid;
    int min = *min_element(arr.begin(), arr.end());
    int len = arr.size();
    if (len % 2 == 0)
        mid = min + (len) / 2;
    else
        mid = min + (len + 1) / 2;
    vector<int> lower, upper;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < mid)
            lower.push_back(arr[i]);
        else
            upper.push_back(arr[i]);
    }
    int a1 = solve(lower);
    int a2 = solve(upper);
    cout << mid << "===" << a1 << " " << a2 << "\n";
    return a1 + a2 + 1ˀzzz;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a) << "\n";
    }
    return 0;
}
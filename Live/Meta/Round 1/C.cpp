#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

template <typename T>
using PTT = pair<T, T>;

bool **dp;

VV<int> ans;

void printSubsetsRec(VEC<int> &arr, int i, int sum, vector<int> &p)
{
    if (i == 0 && sum != 0 && dp[0][sum])
    {
        p.push_back(arr[i]);
        if (arr[i] == sum)
            ans.push_back(p);
        return;
    }

    if (i == 0 && sum == 0)
    {
        ans.push_back(p);
        return;
    }

    if (dp[i - 1][sum])
    {
        vector<int> b = p;
        printSubsetsRec(arr, i - 1, sum, b);
    }

    if (sum >= arr[i] && dp[i - 1][sum - arr[i]])
    {
        p.push_back(arr[i]);
        printSubsetsRec(arr, i - 1, sum - arr[i], p);
    }
}

void printAllSubsets(VEC<int> &arr, int sum)
{
    int n = arr.size();
    if (n == 0 || sum < 0)
        return;

    dp = new bool *[n];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = new bool[sum + 1];
        dp[i][0] = true;
    }

    if (arr[0] <= sum)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < sum + 1; ++j)
            dp[i][j] = (arr[i] <= j) ? dp[i - 1][j] ||
                                           dp[i - 1][j - arr[i]]
                                     : dp[i - 1][j];
    if (dp[n - 1][sum] == false)
    {
        return;
    }

    vector<int> p;
    printSubsetsRec(arr, n - 1, sum, p);
}

void solve()
{
    int p;
    cin >> p;
    VEC<int> divisors;
    for (int i = 0; i <= 41; i++)
    {
        if (p % i == 0)
        {
            divisors.push_back(i);
        }
    }
    printAllSubsets(divisors, 41);

    if (ans.size() == 0)
    {
        cout << "-1\n";
    }
    else
    {
        for (int i = 0; i < ans[0].size(); i++)
        {
            cout << ans[0][i] << " ";
        }
        cout << "\n";
    }
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
#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

template <typename T>
using PTT = pair<T, T>;

#define FOR(i, n) for (LLI i = 0; i < n; i++)
#define ROF(i, n) for (LLI i = n - 1; i >= 0; i--)

void solve()
{
    string s;
    LLI pos;
    cin >> s >> pos;
    int n = s.length();

    LLI which_string = -1;
    LLI index_in_string = -1;

    LLI start = 1, end = n, running_index = 1, running_length = n;
    while (true)
    {
        if (start > end)
        {
            break;
        }
        if (pos >= start && pos <= end)
        {
            which_string = running_index;
            index_in_string = pos - start + 1;
            break;
        }
        else
        {
            running_index += 1;
            running_length -= 1;
            start = end + 1;
            end = start + running_length - 1;
        }
    }
    // which_string, index_in_string >= 1, <= n

    if (which_string == 1)
    {
        cout << s[index_in_string];
        return;
    }

    // ans represents s_j with each iteration
    string ans = ""; // ans = s_{which_string}
    FOR(i, n)
    {
        if (ans.back() > s[i])
        {
            ans.pop_back();
            which_string--;

            if (which_string == 1)
            {
                break;
            }

            while (true)
            {
                        }
        }
        else
        {
            ans += s[i];
        }
    }

    // cout << ans[index_in_string - 1];
    cout << ans << "\n";
    return;
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
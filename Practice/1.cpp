#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1335/B
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        string ans = "";
        // b <= min(a, 26)
        int pos = 0;
        vector<int> count(26, 0);
        for (int i = 0; i < a; i++)
        {
            ans += ((char)(pos + 97));
            pos = (pos + 1) % b;
            count[pos] += 1;
        }
        for (int i = a; i < n; i++)
        {
            // check char at (i - a)th position
            char char_to_remove = ans[i - a];

            count[(int)char_to_remove - 97] -= 1;

            int num_unique = 0;
            for (int j = 0; j < 26; j++)
            {
                if (count[j] > 0)
                    num_unique += 1;
            }

            if (num_unique == b)
            {
                ans += ans[i - 1];
                count[(int)ans[i - 1] - 97] += 1;
            }
            else
            {
                ans += char_to_remove;
                count[(int)char_to_remove - 97] += 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
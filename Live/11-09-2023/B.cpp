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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int len = s.length();

        string ans = "";
        for (int i = 0; i <= n; i++)
        {
            ans += "0";
        }

        if (n != 1)
        {
            int count_same = 0, count_diff = 0;
            for (int i = 0; i < len / 2; i++)
            {
                if (s[i] == s[len - i - 1])
                {
                    count_same += 1;
                }
                else
                {
                    count_diff += 1;
                }
            }

            VEC<int> indices;
            for (int i = 0; i <= count_same; i++)
            {
                indices.push_back(2 * i);
            }
            if (indices.size() == 0)
            {
                indices.push_back(0);
            }

            for (int i = 0; i < indices.size(); i++)
            {
                indices[i] += count_diff;
            }

            for (const int &index : indices)
            {
                ans[index] = '1';
                if (len % 2 == 1)
                {
                    if (index + 1 <= n)
                        ans[index + 1] = '1';
                }
            }
            cout << ans << "\n";
        }
        else
        {
            cout << "11\n";
        }
    }
    return 0;
}
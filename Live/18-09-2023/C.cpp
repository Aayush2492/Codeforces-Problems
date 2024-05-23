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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        VEC<int> a(n, 0);

        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i] - 1].push_back(i);
        }

        VEC<bool> indices_used(n, false);
        // int l = 0, r = n - 1;
        int max = *max_element(a.begin(), a.end());
        int l = a[max - 1][0];
        int r = a[max - 1][0];
        VEC<int> answer;
        for (int i = k; i >= 1; i--)
        {
            if (mp[i - 1].size() > 0)
            {
                int ans = 2 * (r - l + 1);
                // cout << ans << " ";
                answer.push_back(ans);

                for (auto elem : mp[i - 1])
                {
                    indices_used[elem] = true;
                }

                for (int j = l; j < n; j++)
                {
                    if (indices_used[j] == false)
                    {
                        l = j;
                        break;
                    }
                }

                for (int j = r; j >= 0; j--)
                {
                    if (indices_used[j] == false)
                    {
                        r = j;
                        break;
                    }
                }
            }
            else
            {
                // cout << "0 ";
                answer.push_back(0);
            }
        }

        reverse(answer.begin(), answer.end());
        FOR(i, k)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
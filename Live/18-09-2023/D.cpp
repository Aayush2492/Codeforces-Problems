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
        LLI n;
        cin >> n;
        VEC<LLI> a(n, 0);
        map<LLI, LLI> last_index;
        FOR(i, n)
        {
            cin >> a[i];
            last_index[a[i]] = i + 1;
        }
        LLI k;
        cin >> k;

        VEC<PTT<LLI>> arr;
        for (auto x : last_index)
        {
            arr.push_back({x.first, x.second});
        }
        sort(arr.begin(), arr.end());

        VEC<PTT<LLI>> new_arr;

        new_arr.push_back(arr[0]);
        LLI curr_index = new_arr[0].second;
        for (LLI i = 1; i < arr.size(); i++)
        {
            if (arr[i].second < curr_index)
            {
                continue;
            }
            else
            {
                new_arr.push_back(arr[i]);
                curr_index = arr[i].second;
            }
        }
        // new_arr is now sorted by 2nd param(index of cost) as well

        LLI q = k / new_arr[0].first;
        if (q == 0)
        {
            for (LLI i = 0; i < n; i++)
            {
                cout << "0 ";
            }
            cout << "\n";
        }
        else
        {
            LLI freq_of_least_cost = q - 1;
            LLI remaining_cost = new_arr[0].first + k % new_arr[0].first;
            // cout << "Remaining cost: " << remaining_cost << "\n";
            LLI other_cost_index = -1;
            for (LLI i = 0; i < new_arr.size(); i++)
            {
                if (remaining_cost >= new_arr[i].first)
                {
                    other_cost_index = i;
                }
            }
            // cout << "Other cost index: " << other_cost_index << "\n";

            VEC<LLI> ans(n, 0);
            for (LLI i = 0; i < new_arr[0].second; i++)
            {
                ans[i] += freq_of_least_cost;
            }
            for (LLI i = 0; i < new_arr[other_cost_index].second; i++)
            {
                ans[i] += 1;
            }

            FOR(i, ans.size())
            {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }

        // for (LLI i = 0; i < new_arr.size(); i++)
        // {
        //     if (new_arr[i].first <= 2 * new_arr[0].first - 1)
        //     {
        //         cout << new_arr[i].first << " " << new_arr[i].second << "\n";
        //     }
        // }
    }
    return 0;
}
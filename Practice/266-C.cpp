#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = pair<int, int>;

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        VEC<LLI> arr(n, 0);
        // LLI sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            // sum += arr[i];
        }
        LLI sum = accumulate(arr.begin(), arr.end(), 0LL);
        // cout << "Sum: " << sum << "\n";
        if (sum % 3 == 0 && n >= 3)
        {
            LLI required_sub_sum = sum / 3;

            VEC<LLI> prefix_sum(n, 0);
            VEC<LLI> suffix_sum(n, 0);
            VEC<LLI> count_prefix(n, 0);
            VEC<LLI> count_suffix(n, 0);

            prefix_sum[0] = arr[0];
            if (prefix_sum[0] == required_sub_sum)
                count_prefix[0] = 1;
            for (int i = 1; i < n; i++)
            {
                prefix_sum[i] = prefix_sum[i - 1] + arr[i];
                if (prefix_sum[i] == required_sub_sum)
                {
                    count_prefix[i] = count_prefix[i - 1] + 1;
                }
                else
                {
                    count_prefix[i] = count_prefix[i - 1];
                }
            }

            suffix_sum[n - 1] = arr[n - 1];
            if (suffix_sum[n - 1] == required_sub_sum)
                count_suffix[n - 1] = 1;
            for (int i = n - 2; i >= 0; i--)
            {
                suffix_sum[i] = suffix_sum[i + 1] + arr[i];
                if (suffix_sum[i] == required_sub_sum)
                {
                    count_suffix[i] = count_suffix[i + 1] + 1;
                }
                else
                {
                    count_suffix[i] = count_suffix[i + 1];
                }
            }

            LLI count = 0;
            if (count_prefix[0] == 1)
            {
                count += count_suffix[2];
            }
            for (int i = 1; i <= n - 3; i++)
            {
                if (count_prefix[i] - count_prefix[i - 1] == 1)
                {
                    // [0...i] subarray has required_sub_sum

                    // number of subarrays in [i+2...n-1] with required sum = count_suffix[i+2]
                    count += count_suffix[i + 2];
                }
            }
            cout << count << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
    return 0;
}
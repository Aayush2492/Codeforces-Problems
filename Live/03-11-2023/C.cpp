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
    map<PTT<int>, LLI> len_sum_count;
    map<int, string> strings;
    map<int, int> sums;
    FOR(i, n)
    {
        string s;
        cin >> s;
        int sum = 0;
        FOR(j, s.length())
        {
            sum += ((int)s[j] - 48);
        }
        len_sum_count[{s.length(), sum}] += (LLI)1;
        sums[i] = sum;
        strings[i] = s;
    }

    LLI ans = 0;
    FOR(i, n)
    {
        int len = strings[i].length();

        int half_len_of_conc_string = len + len;
        half_len_of_conc_string /= 2;
        string si = strings[i];
        int half_sum = 0;
        FOR(k, half_len_of_conc_string)
        {
            half_sum += ((int)si[k] - 48);
        }
        int rem_sum = sums[i] - half_sum;
        int req_sum = half_sum - rem_sum;
        int req_len = len;
        ans += len_sum_count[{req_len, req_sum}];

        for (int j = len - 2; j >= 1; j -= 2)
        {
            // len > j
            // checking for pair i, strings with length j
            half_len_of_conc_string = len + j;
            half_len_of_conc_string /= 2;
            string si = strings[i];
            half_sum = 0;
            FOR(k, half_len_of_conc_string)
            {
                half_sum += ((int)si[k] - 48);
            }
            rem_sum = sums[i] - half_sum;
            req_sum = half_sum - rem_sum;
            req_len = j;
            ans += len_sum_count[{req_len, req_sum}];

            reverse(si.begin(), si.end());
            half_sum = 0;
            FOR(k, half_len_of_conc_string)
            {
                half_sum += ((int)si[k] - 48);
            }
            rem_sum = sums[i] - half_sum;
            req_sum = half_sum - rem_sum;
            req_len = j;
            ans += len_sum_count[{req_len, req_sum}];
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
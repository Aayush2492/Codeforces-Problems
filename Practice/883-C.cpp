#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = pair<int, int>;
using PLL = pair<LLI, LLI>;

PLL get_score(VEC<LLI> &player, LLI h, LLI m)
{
    PLL score;
    LLI total_time = accumulate(player.begin(), player.end(), 0);
    sort(player.begin(), player.end());
    VEC<LLI> cum_sum = player;
    LLI pos = -1;
    for (LLI j = 1; j < m; j++)
    {
        cum_sum[j] += cum_sum[j - 1];
        if (pos == -1 && cum_sum[j] > h)
        {
            pos = j - 1;
        }
    }
    if (total_time <= h)
    {
        score = make_pair(m, accumulate(cum_sum.begin(), cum_sum.end(), 0));
    }
    else
    {
        // total_time = cum_sum[m - 1] > h
        score = make_pair(pos + 1, accumulate(cum_sum.begin(), cum_sum.begin() + pos, 0));
    }
    return score;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LLI n, m, h;
        cin >> n >> m >> h;
        VV<LLI> arr(n, VEC<LLI>(m, 0));
        for (LLI i = 0; i < n; i++)
        {
            for (LLI j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        PLL base_score = get_score(arr[0], h, m);
        int rank = 1;
        for (LLI i = 1; i < n; i++)
        {
            PLL score = get_score(arr[i], h, m);

            if (score.first > base_score.first)
            {
                rank += 1;
            }
            else if (score.first == base_score.first)
            {
                if (score.second < base_score.second)
                {
                    rank += 1;
                }
            }
        }
        cout << rank << endl;
    }
    return 0;
}
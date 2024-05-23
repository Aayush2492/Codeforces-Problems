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

PTT<LLI> intersection(PTT<LLI> a, PTT<LLI> b)
{
    PTT<LLI> ans = {-1, -1};

    LLI a1 = a.first;
    LLI a2 = a.second;
    LLI b1 = b.first;
    LLI b2 = b.second;

    if (a2 < b1 || b2 < a1)
    {
        // no intersection
        return ans;
    }

    ans.first = max(a1, b1);
    ans.second = min(a2, b2);

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        PTT<LLI> current_interval = {-1, LLONG_MAX};
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                LLI a, b, n;
                cin >> a >> b >> n;
                PTT<LLI> temp_interval;
                if (n == 1)
                {
                    temp_interval = {1, a};
                }
                else
                {
                    temp_interval = {n * (a - b) - a + 2 * b + 1, n * (a - b) + b};
                }
                PTT<LLI> interval_intersection = intersection(current_interval, temp_interval);
                if (interval_intersection.first != -1)
                {
                    current_interval = interval_intersection;
                    cout << "1 ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            else if (type == 2)
            {
                LLI a, b;
                cin >> a >> b;

                LLI lower_n, upper_n;
                if (current_interval.first >= 1 && current_interval.second <= a)
                {
                    lower_n = upper_n = 1;
                }
                else
                {
                    lower_n = ceil((current_interval.first - b) / ((double)(a - b)));
                    upper_n = ceil((current_interval.second - b) / ((double)(a - b)));
                }

                if (lower_n == upper_n)
                {
                    cout << lower_n << " ";
                }
                else
                {
                    cout << "-1 ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
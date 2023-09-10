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
    cin >> t;
    while (t--)
    {
        LLI n, x, y;
        cin >> n >> x >> y;

        LLI x_score = 0, y_score = 0;
        if (x == 1 && y == 1)
        {
            x_score = y_score = 0;
        }

        if (x == 1 && y != 1)
        {
            x_score = n * (n + 1) / 2;
        }

        if (y == 1 && x != 1)
        {
            y_score = n * (n + 1) / 2;
        }

        if (x != 1)
        {
            LLI max_n = n;
            LLI curr_x = x;
            while (true)
            {
                if (curr_x > n)
                    break;
                if (curr_x % y != 0 || y == 1)
                {
                    x_score += max_n;
                    max_n -= 1;
                }
                curr_x += x;
            }
        }

        if (y != 1)
        {
            LLI min_n = 1;
            LLI curr_y = y;
            while (true)
            {
                if (curr_y > n)
                    break;
                if (curr_y % x != 0 || x == 1)
                {
                    y_score += min_n;
                    min_n += 1;
                }
                curr_y += y;
            }
        }

        cout << x_score - y_score << "\n";
    }
    return 0;
}
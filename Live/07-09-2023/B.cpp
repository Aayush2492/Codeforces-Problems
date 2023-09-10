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
        int n;
        cin >> n;
        VEC<int> rooms(200, 201);
        // VEC<int> d(n, 0);
        // VEC<int> s(n, 0);
        for (int i = 0; i < n; i++)
        {
            int di, si;
            cin >> di >> si;
            rooms[di - 1] = min(rooms[di - 1], si);
        }

        int first_trap = -1;
        for (int i = 0; i < 200; i++)
        {
            if (rooms[i] != 201)
            {
                first_trap = i;
                break;
            }
        }

        int index = 0;
        int max_reachable_index = first_trap + (int)floor((rooms[first_trap] - 1) / 2.0);
        while (true)
        {
            if (index == max_reachable_index || index == 200)
            {
                break;
            }

            if (rooms[index] != 201)
            {
                max_reachable_index = min(max_reachable_index, index + (int)floor((rooms[index] - 1) / 2.0));
            }
            index += 1;
        }
        cout << max_reachable_index + 1 << "\n";
    }
    return 0;
}
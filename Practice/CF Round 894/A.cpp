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
        int n, m;
        cin >> n >> m;
        VV<char> arr(n, VEC<char>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        string name = "vika";
        int curr = -1;
        for (int i = 0; i < m; i++)
        {
            // find name[curr+1]
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] == name[curr + 1])
                {
                    curr += 1;
                    break;
                }
            }
            if (curr == 3)
                break;
        }
        if (curr == 3)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
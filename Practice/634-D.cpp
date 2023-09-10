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
        VV<int> board(9, VEC<int>(9, 0));
        for (int i = 0; i < 9; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = s[j] - 48;
            }
        }

        // for (int i = 0; i < 9; i++)
        // {
        //     for (int j = 0; j < 9; j++)
        //     {
        //         cout << board[i][j];
        //     }
        //     cout << "\n";
        // }
        VEC<int> indx = {0, 3, 6, 1, 4, 7, 2, 5, 8};

        for (int i = 0; i < 9; i++)
        {
            int j = indx[i];
            if (board[i][j] != 9)
                board[i][j] += 1;
            else
                board[i][j] = 1;
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
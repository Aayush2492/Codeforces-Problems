#include <bits/stdc++.h>
// #include <vector>
// #include <iostream>
// #include <iomanip>
// #include <float.h>
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

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

template <typename S>
ostream &operator<<(ostream &os, const VEC<S> &vector)
{
    for (auto element : vector)
        os << element << " ";
    os << "\n";
    return os;
}

bool isValid(VV<int> &group_num, int row, int col, int r, int c)
{
    if (row < 0 || col < 0 || row >= r || col >= c)
        return false;

    if (group_num[row][col] != -1)
        return false;

    return true;
}

bool isInBounds(int row, int col, int r, int c)
{
    if (row < 0 || col < 0 || row >= r || col >= c)
        return false;
    return true;
}

void solve(int t_)
{
    int r, c;
    cin >> r >> c;
    VV<char> board(r, VEC<char>(c, '.'));

    FOR(i, r)
    {
        FOR(j, c)
        {
            cin >> board[i][j];
        }
    }

    VV<int> group_num(r, VEC<int>(c, -1));
    int curr_group = 1;
    map<int, VEC<PTT<int>>> group_to_pair;
    FOR(i, r)
    {
        FOR(j, c)
        {
            if (board[i][j] != 'W' || group_num[i][j] != -1)
            {
                continue;
            }

            queue<pair<int, int>> q;
            q.push({i, j});
            group_num[i][j] = curr_group;
            group_to_pair[curr_group].push_back({i, j});

            while (!q.empty())
            {
                pair<int, int> curr = q.front();
                int x = curr.first;
                int y = curr.second;

                q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int adjx = x + dRow[dir];
                    int adjy = y + dCol[dir];

                    if (isValid(group_num, adjx, adjy, r, c))
                    {
                        if (board[adjx][adjy] != 'W' || group_num[adjx][adjy] != -1)
                        {
                            continue;
                        }

                        q.push({adjx, adjy});
                        group_num[adjx][adjy] = curr_group;
                        group_to_pair[curr_group].push_back({adjx, adjy});
                    }
                }
            }
            curr_group += 1;
        }
    }

    // cout << group_num << "\n";
    // for (int grp = 1; grp < curr_group; grp++)
    // {
    //     cout << grp << "\n";
    //     for (int k = 0; k < group_to_pair[grp].size(); k++)
    //     {
    //         PTT<int> curr = group_to_pair[grp][k];
    //         int x = curr.first;
    //         int y = curr.second;

    //         cout << x << " " << y << "\n";
    //     }
    // }

    bool ans = false;
    map<int, bool> group_vis;
    FOR(i, r)
    {
        FOR(j, c)
        {
            if (board[i][j] != '.')
            {
                continue;
            }
            board[i][j] = 'B';

            // int valid_group = -1;
            for (int grp = 1; grp < curr_group; grp++)
            {
                bool is_group_safe = false;
                for (int k = 0; k < group_to_pair[grp].size(); k++)
                {
                    PTT<int> curr = group_to_pair[grp][k];
                    int x = curr.first;
                    int y = curr.second;
                    // cout << board[x][y] << "\n";
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int adjx = x + dRow[dir];
                        int adjy = y + dCol[dir];

                        if (isInBounds(adjx, adjy, r, c))
                        {
                            is_group_safe = is_group_safe || (board[adjx][adjy] == '.');
                        }
                    }
                }

                if (!is_group_safe)
                {
                    ans = ans || true;
                }
            }
            board[i][j] = '.';
        }
    }

    if (ans)
    {
        cout << "Case #" << t_ << ":"
             << " YES\n";
    }
    else
    {
        cout << "Case #" << t_ << ":"
             << " NO\n";
    }
}

int main()
{
    int t;
    cin >> t;
    int t_ = 1;
    while (t--)
    {
        solve(t_);
        t_ += 1;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/478/B
int main()
{
    // cin >> t;
    int t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        // For max
        long long int max_team_size = n - m + 1;
        long long int b = (long long int)(max_team_size * (max_team_size - 1) / 2.0);

        // For min
        long long int base_team_size = n / m;
        long long int extras = n % m;

        // extras teams have base_team_size + 1 members
        // m - extras have base_team_size members

        long long int a1 = (extras) * ((long long int)(base_team_size + 1) * base_team_size / 2.0);
        long long int a2 = (m - extras) * ((long long int)(base_team_size - 1) * base_team_size / 2.0);
        long long int a = a1 + a2;

        cout << a << " " << b << endl;
    }
}
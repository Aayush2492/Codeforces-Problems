#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n * (n - 1) / 2, 0);
        for (int i = 0; i < n * (n - 1) / 2; i++)
        {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n - 1; i++)
        {
            int index = i * n - ((i * (i + 1)) / 2);
            cout << b[index] << " ";
        }
        cout << b[b.size() - 1] << endl;
    }
    return 0;
}
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
        vector<long long int> a(n, 0);
        vector<long long int> b(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            a[i] = a[i] - b[i];
        }

        vector<long long int> a_copy(a);
        sort(a_copy.begin(), a_copy.end());
        vector<int> ans;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == a_copy[a_copy.size() - 1])
            {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << endl;
        for (auto a : ans)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
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
        vector<int> even;
        vector<int> odd;
        for (int i = 0; i < n; i++)
        {
            int elem;
            cin >> elem;
            if (elem % 2 == 0)
            {
                even.push_back(elem);
            }
            else
            {
                odd.push_back(elem);
            }
        }

        if (even.size() % 2 == 0 && odd.size() % 2 == 0)
            cout << "YES\n";
        else
        {
            int flag = 0;
            for (int i = 0; i < even.size(); i++)
            {
                for (int j = 0; j < odd.size(); j++)
                {
                    if (abs(even[i] - odd[j]) == 1)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
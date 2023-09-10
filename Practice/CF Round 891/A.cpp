#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        int num_even = 0, num_odd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                num_even++;
            else
                num_odd++;
        }

        if (num_even == 0)
        {
            if (num_odd % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (num_odd == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (num_odd % 2 == 0)
                cout << "YES" << endl;
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
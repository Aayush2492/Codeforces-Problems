#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli n, k;
        cin >> n >> k;

        if (n % 2 == 1 && k % 2 == 0)
        {
            cout << "NO\n";
        }
        else if (n % 2 == 0 && k % 2 == 1)
        {
            // all even
            if (n >= 2 * k)
            {
                cout << "YES\n";
                // (k - 1) 2s and last one to be very large
                for (lli i = 1; i <= k - 1; i++)
                {
                    cout << "2 ";
                }
                cout << n - 2 * (k - 1) << endl;
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (n % 2 == 1 && k % 2 == 1)
        {
            // all odd
            if (n >= k)
            {
                cout << "YES\n";
                // k - 1 1s and last one acc
                for (lli i = 1; i <= k - 1; i++)
                {
                    cout << "1 ";
                }
                cout << n - (k - 1) << endl;
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if (n >= k)
            {
                cout << "YES\n";
                for (lli i = 1; i <= k - 1; i++)
                {
                    cout << "1 ";
                }
                cout << n - (k - 1) << endl;
            }
            else if (n >= 2 * k)
            {
                cout << "YES\n";
                for (lli i = 1; i <= k - 1; i++)
                {
                    cout << "2 ";
                }
                cout << n - 2 * (k - 1) << endl;
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
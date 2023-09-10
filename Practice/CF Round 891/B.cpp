#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string round(string n, int k)
{
    // round at kth position
    // we know (k + 1)th position is >= 5

    if (k == -1)
    {
        string ans = "1";
        for (int i = 0; i < n.length(); i++)
        {
            ans += "0";
        }
        return ans;
    }
    else
    {
        if (n[k] - 48 != 9)
        {
            string ans = n;
            ans[k] = (char)((int)n[k] + 1);
            for (int i = k + 1; i < n.length(); i++)
            {
                ans[i] = '0';
            }
            return ans;
        }
        else
        {
            for (int i = k - 1; i >= 0; i--)
            {
                if (n[i] - 48 != 9)
                {
                    string ans = n;
                    ans[i] = (char)((int)n[i] + 1);
                    for (int j = i + 1; j < n.length(); j++)
                    {
                        ans[j] = '0';
                    }
                    return ans;
                }
            }
            string ans = "1";
            for (int j = 0; j < n.length(); j++)
            {
                ans += "0";
            }
            return ans;
        }
    }
}

string get_ans(string n)
{
    int length = n.length();
    for (int i = length - 1; i >= 0; i--)
    {
        char c = n[i];
        if ((int)c - 48 >= 5)
        {
            n = round(n, i - 1);
        }
    }
    return n;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        string ans = get_ans(n);
        cout << ans << endl;
    }
    return 0;
}
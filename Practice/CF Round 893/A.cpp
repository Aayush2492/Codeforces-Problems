#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int anna = a + ceil(c / 2.0);
        int katie = b + floor(c / 2.0);
        if (anna > katie)
        {
            cout << "First\n";
        }
        else
        {
            cout << "Second\n";
        }
    }
    return 0;
}
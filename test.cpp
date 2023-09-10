#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

template <typename T>
using PTT = pair<T, T>;

#define FOR(i, n) for (int i = 0; i < n; i++)

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        // int n;
        // cin >> n;
        int a = 0;
        int b = 1;
        VEC<int> numbers;
        numbers.push_back(a);
        numbers.push_back(b);
        while (true)
        {
            int c = a + b;
            if (c > 200000)
            {
                break;
            }
            numbers.push_back(c);
            a = b;
            b = c;
        }
        int len = numbers.size();
        cout << "Length: " << len << "\n";
        cout << numbers[len - 1] << "\n";
    }
    return 0;
}
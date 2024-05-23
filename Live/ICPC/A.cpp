#include <bits/stdc++.h>
using namespace std;

using LLI = long long int;

template <typename T>
using VEC = vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

template <typename T>
using PTT = pair<T, T>;

template <typename T>
using VVVV = VEC<VEC<VEC<VEC<T>>>>;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define ROF(i, n) for (int i = n - 1; i >= 0; i--)

template <typename S>
ostream &operator<<(ostream &os, const VEC<S> &VEC)
{
    for (auto element : VEC)
        os << element << " ";
    os << "\n";
    return os;
}

LLI mod = 1000000007;

long long GCD(long long x, long long y)
{
    if (y == 0)
        return x;
    return GCD(y, x % y);
}

LLI prob(VVVV<LLI> &A, VVVV<LLI> &B, int N, int b, int x, int w, bool virat, bool virat_out)
{
    if ((b == 0 && N > 0) || w == 0)
    {
        return 0;
    }

    if (N <= 0)
    {
        if (x > 0)
        {
            return 0;
        }
        return 1;
    }

    if (x < 0)
        x = 0;

    // N > 0, b > 0, w > 0, x >= 0

    if (virat_out)
    {
        if (B[N][b][w][x] != -1)
        {
            return B[N][b][w][x];
        }
        LLI ans = 0;
        ans += prob(A, B, N - 1, b - 1, x, w, false, true); // 1
        ans += prob(A, B, N - 2, b - 1, x, w, false, true); // 2
        ans += prob(A, B, N - 3, b - 1, x, w, false, true); // 3
        ans += prob(A, B, N - 4, b - 1, x, w, false, true); // 4
        ans += prob(A, B, N - 6, b - 1, x, w, false, true); // 6
        ans += prob(A, B, N, b - 1, x, w - 1, false, true); // W
        ans %= mod;
        return B[N][b][w][x] = ans;
    }
    else
    {
        if (virat)
        {
            if (A[N][b][w][x] != -1)
            {
                return A[N][b][w][x];
            }

            if (b % 6 == 1)
            {
                virat = !virat;
            }
            LLI ans = 0;
            // cout << "Here\n";
            ans += prob(A, B, N - 1, b - 1, x - 1, w, !virat, false);   // 1
            ans += prob(A, B, N - 2, b - 1, x - 2, w, virat, false);    // 2
            ans += prob(A, B, N - 3, b - 1, x - 3, w, !virat, false);   // 3
            ans += prob(A, B, N - 4, b - 1, x - 4, w, virat, false);    // 4
            ans += prob(A, B, N - 6, b - 1, x - 6, w, virat, false);    // 6
            ans += prob(A, B, N - 0, b - 1, x - 0, w - 1, false, true); // W
            ans %= mod;
            return A[N][b][w][x] = ans;
        }
        else
        {
            if (B[N][b][w][x] != -1)
            {
                return B[N][b][w][x];
            }

            if (b % 6 == 1)
            {
                virat = !virat;
            }

            LLI ans = 0;
            ans += prob(A, B, N - 1, b - 1, x, w, !virat, false);    // 1
            ans += prob(A, B, N - 2, b - 1, x, w, virat, false);     // 2
            ans += prob(A, B, N - 3, b - 1, x, w, !virat, false);    // 3
            ans += prob(A, B, N - 4, b - 1, x, w, virat, false);     // 4
            ans += prob(A, B, N - 6, b - 1, x, w, virat, false);     // 6
            ans += prob(A, B, N - 0, b - 1, x, w - 1, virat, false); // W
            ans %= mod;
            return B[N][b][w][x] = ans;
        }
    }
}

LLI count_(VEC<VEC<VEC<LLI>>> &total, int N, int b, int w)
{
    if (b == 0 || w == 0 || N <= 0)
    {
        return 1;
    }

    if (total[N][b][w] != -1)
    {
        return total[N][b][w];
    }
    // N > 0, b > 0, w > 0

    LLI ans = 0;
    ans += count_(total, N - 1, b - 1, w);
    ans += count_(total, N - 2, b - 1, w);
    ans += count_(total, N - 3, b - 1, w);
    ans += count_(total, N - 4, b - 1, w);
    ans += count_(total, N - 6, b - 1, w);
    ans += count_(total, N - 0, b - 1, w - 1);
    ans %= mod;

    return total[N][b][w] = ans;
}

int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int modInverse(int a, int m)
{
    int x, y;
    int gcd = extendedGCD(a, m, x, y);

    if (gcd != 1)
    {
        // doesnt exist
        return -1;
    }
    else
    {
        return (x % m + m) % m;
    }
}

void solve()
{
    int N, b, w, x;
    cin >> N >> b >> w >> x;

    VVVV<LLI> A(N + 1, VEC<VEC<VEC<LLI>>>(b + 1, VEC<VEC<LLI>>(10 - w + 1, VEC<LLI>(x + 1, -1))));
    VVVV<LLI> B(N + 1, VEC<VEC<VEC<LLI>>>(b + 1, VEC<VEC<LLI>>(10 - w + 1, VEC<LLI>(x + 1, -1))));

    VEC<VEC<VEC<LLI>>> total(N + 1, VEC<VEC<LLI>>(b + 1, VEC<LLI>(10 - w + 1, -1)));

    LLI count_win = prob(A, B, N, b, 100 - x, 10 - w, true, false);
    LLI count_total = count_(total, N, b, 10 - w);

    LLI d;
    d = GCD(count_win, count_total);
    count_win /= d;
    count_total /= d;

    // cout << count_win << " " << count_total << "\n";

    LLI inv = modInverse(count_total, mod);
    inv %= mod;
    if (inv < 0)
    {
        cout << "0-";
    }
    LLI ans = (count_win * inv) % mod;
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
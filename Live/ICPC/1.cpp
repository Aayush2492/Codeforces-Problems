#include <iostream>
#include <vector>

using namespace std;

using LLI = long long int;

template <typename T>
using VEC = std::vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

int get_min_flips_to_sort(VEC<int> &a, int l, int r)
{
    int n = r - l + 1;
    int num_zeroes = count(a.begin() + l, a.begin() + r + 1, 0);
    int num_ones_so_far = 0;
    int ans = num_zeroes; // all 0s flipped to 1s

    // indices <= pivot are 0
    // indices > pivot are 1
    for (int pivot = l; pivot <= r; pivot++)
    {
        // flip indices <= pivot to 0 and indices > pivot to 1
        if (a[pivot] == 1)
        {
            num_ones_so_far++;
        }
        else
        {
            num_zeroes--;
        }
        ans = min(ans, num_ones_so_far + num_zeroes);
    }

    return ans;
}

int main()
{
    int n, q, m;
    cin >> n >> q >> m;
    VEC<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    VV<int> queries(q, VEC<int>(3));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    LLI sum = 0;
    for (int i = 0; i < q; i++)
    {
        int type = queries[i][0];
        if (type == 1)
        {
            int index_to_flip = queries[i][1] - 1;
            a[index_to_flip] = 1 - a[index_to_flip];
        }
        else if (type == 2)
        {
            int l = queries[i][1] - 1;
            int r = queries[i][2] - 1;
            int ans = get_min_flips_to_sort(a, l, r);
            sum += ans;
        }
    }
    cout << sum << "\n";
    return 0;
}
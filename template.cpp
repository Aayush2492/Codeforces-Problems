#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

#define REC(i, j)                                               \
    if ((i) < m && grid[(i)][(j)] == '1' && !visited[(i)][(j)]) \
    {                                                           \
        q.push({(i), (j)});                                     \
        visited[(i)][(j)] = true;                               \
    }

template <typename T>
using VEC = std::vector<T>;

template <typename T>
using VV = VEC<VEC<T>>;

using PII = std::pair<int, int>;

template <typename S>
std::ostream &operator<<(std::ostream &os, const std::vector<S> &vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector)
    {
        os << element << " ";
    }
    os << "\n";
    return os;
}

struct Comp
{
    bool operator()(const std::vector<int> &a, const std::vector<int> &b)
    {
        return a[0] + a[1] < b[0] + b[1]; // max heap
    }
};

std::priority_queue<int, std::vector<int>, std::greater<int>> large; // min heap
std::priority_queue<int, std::vector<int>> small;                    // max heap

// Ascending order sort
bool cmp(const std::vector<int> &a, const std::vector<int> &b)
{
    return a[0] < b[0];
}
// std::sort(intervals.begin(), intervals.end(), cmp);

class UnionFind
{
private:
    VEC<int> parent;
    VEC<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        rank.resize(n, 1);
    }
    int find(int x)
    {
        while (parent[x] != x)
            x = parent[x];
        return parent[x];
    }
    void _union(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            if (rank[px] > rank[py])
                parent[py] = px;
            else if (rank[px] < rank[py])
                parent[px] = py;
            else
            {
                parent[py] = px;
                rank[px]++;
            }
        }
        else
            std::cout << "Error: Already connected\n";
    }
};

void kmp_matcher(const std::string &s, const std::string &t)
{
}

using namespace std;
class Trie
{
public:
    Trie() {}

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (!node->next[ch])
            {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (!node->next[ch])
            {
                return false;
            }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (!node->next[ch])
            {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }

private:
    Trie *next[26] = {};
    bool isword = false;
};

// Regex

// string a = "(A,S) (S,V) (R,T) ";
// regex b("\\([A-Z],[A-Z]\\)");

// smatch sm;

// while (regex_search(a, sm, b))
// {
//     cout << sm[0];
//     std::cout << std::endl;
//     a = sm.suffix().str();
// }
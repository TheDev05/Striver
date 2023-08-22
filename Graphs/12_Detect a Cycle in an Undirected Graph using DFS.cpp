#include <bits/stdc++.h>
using namespace std;

bool traverse(int index, std::vector<int> num[], std::vector<int> &vis)
{
    vis[index] = 1;

    int count = 0;
    for (auto i : num[index])
    {
        if (vis[i])
            count++;
        else if (traverse(i, num, vis))
            return true;
    }

    if (count > 1)
        return true;

    return false;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num[i] = temp;
    }

    std::vector<int> vis(n, 0);

    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            ok |= traverse(i, num, vis);
    }

    std::cout << ok;
}
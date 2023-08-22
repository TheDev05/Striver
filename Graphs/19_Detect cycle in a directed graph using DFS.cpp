#include <bits/stdc++.h>
using namespace std;

bool traverse(std::vector<int> num[], int n, std::vector<int> &vis, std::vector<int> &path, int index)
{
    vis[index] = 1;
    path[index] = 1;

    for (auto i : num[index])
    {
        if (vis[i] == 0)
        {
            if (traverse(num, n, vis, path, i))
                return true;
        }
        else if (path[i])
            return true;
    }

    path[index] = 0;
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

    std::vector<int> vis(n, 0), path(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (traverse(num, n, vis, path, i))
                return true;
        }
    }

    return false;
}
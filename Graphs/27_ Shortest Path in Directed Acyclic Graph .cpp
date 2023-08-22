#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> temp(3);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    std::vector<std::pair<int, int>> store[n];
    std::vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++)
    {
        store[num[i][0]].push_back({num[i][1], num[i][2]});
    }

    for (auto i : store)
    {
        for (auto j : i)
            indeg[j.first]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    std::vector<int> res;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        res.push_back(local);

        for (auto i : store[local])
        {
            indeg[i.first]--;
            if (indeg[i.first] == 0)
                inox.push(i.first);
        }
    }

    std::vector<int> dist(n, 1e6);
    dist[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto j : store[res[i]])
        {
            dist[j.first] = std::min(dist[j.first], dist[res[i]] + j.second);
        }
    }

    for (auto &i : dist)
        if (i == 1e6)
            i = -1;

    for (auto i : dist)
        std::cout << i << " ";
}

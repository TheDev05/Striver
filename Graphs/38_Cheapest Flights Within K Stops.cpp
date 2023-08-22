#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    std::cin >> m;

    std::vector<std::vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> temp(3);
        for (auto &j : temp)
            std::cin >> j;

        adj.push_back(temp);
    }

    int n, src, dst, k;
    std::cin >> n >> src >> dst >> k;

    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < m; i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
    }

    std::queue<std::pair<int, std::pair<int, int>>> inox;
    std::vector<int> dist(n, 1e7);

    inox.push({src, {0, 0}});
    dist[src] = 0;

    while (inox.size())
    {
        int node = inox.front().first;
        int len = inox.front().second.first;
        int val = inox.front().second.second;

        inox.pop();

        if (len > k)
            continue;

        for (auto i : num[node])
        {
            int adjNode = i.first;
            int adjLen = i.second;

            if (val + adjLen < dist[adjNode])
            {
                dist[adjNode] = val + adjLen;
                inox.push({adjNode, {len + 1, dist[adjNode]}});
            }
        }
    }

    for (auto i : dist)
        std::cout << i << " ";
}
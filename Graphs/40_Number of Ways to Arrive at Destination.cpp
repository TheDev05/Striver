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

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < m; i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
        num[adj[i][1]].push_back({adj[i][0], adj[i][2]});
    }

    std::vector<int> dist(n, 1e5);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, greater<std::pair<int, int>>> inox;

    inox.push({0, 0});
    dist[0] = 0;

    // dist, node

    std::map<std::pair<int, int>, int> data;
    data[{0, 0}] = 1;

    while (inox.size())
    {
        auto it = inox.top();
        inox.pop();

        int node = it.second;
        int wt = it.first;

        for (auto i : num[node])
        {
            int adjNode = i.first;
            int adjWt = i.second;

            if (wt + adjWt < dist[adjNode])
            {
                dist[adjNode] = wt + adjWt;
                inox.push({dist[adjNode], adjNode});
            }

            data[{wt + adjWt, adjNode}] = data[{wt, node}];
        }
    }

    std::cout << data[{dist[n - 1], n - 1}];
}
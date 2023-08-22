#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, src;
    std::cin >> v >> src;

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<std::vector<int>> temp;
        for (int j = 0; j < m; j++)
        {
            std::vector<int> dash(2, 0);
            for (auto &k : dash)
                std::cin >> k;

            temp.push_back(dash);
        }

        adj[i] = temp;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> inox;
    std::vector<int> dist(v, 1e5 + 1);

    // dist, node
    inox.push({0, src});
    dist[src] = 0;

    while (inox.size())
    {
        int local = inox.top().second;
        int val = inox.top().first;

        inox.pop();

        for (auto it : adj[local])
        {
            int node = it[0];
            int wt = it[1];

            if (dist[local] + wt < dist[node])
            {
                dist[node] = dist[local] + wt;
                inox.push({dist[node], node});
            }
        }
    }

    for (auto i : dist)
        std::cout << i << " ";
}
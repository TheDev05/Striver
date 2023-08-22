#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, src;
    std::cin >> v >> src;

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<std::vector<int>> temp;
        for (int j = 0; j < m; j++)
        {
            std::vector<int> local(2, 0);
            for (auto &p : local)
                std::cin >> p;

            temp.push_back(local);
        }

        num[i] = temp;
    }

    std::vector<int> dist(v, 1e5 + 1);
    std::set<std::pair<int, int>> inox;

    inox.insert({0, src});
    dist[src] = 0;

    while (inox.size())
    {
        int node = inox.begin()->second;
        int wt = inox.begin()->first;

        inox.erase(inox.begin());

        for (auto it : num[node])
        {
            int adj_node = it[0];
            int adj_wt = it[1];

            if (dist[node] + adj_wt < dist[adj_node])
            {
                if (inox.count({dist[adj_node], adj_node}))
                    inox.erase({dist[adj_node], adj_node});

                dist[adj_node] = dist[node] + adj_wt;
                inox.insert({dist[adj_node], adj_node});
            }
        }
    }

    for (auto i : dist)
        std::cout << i << " ";
}
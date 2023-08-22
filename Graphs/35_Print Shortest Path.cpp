#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> adj;
    for (int i = 0; i < k; i++)
    {
        std::vector<int> temp(3);
        for (auto &j : temp)
            std::cin >> j;

        adj.push_back(temp);
    }

    n++;

    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
        num[adj[i][1]].push_back({adj[i][0], adj[i][2]});
    }

    std::vector<std::pair<int, int>> dist(n, std::pair<int, int>(1e7 + 1, 0));
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> inox;

    inox.push({0, 1});
    dist[1] = {0, 0};

    while (inox.size())
    {
        int node = inox.top().second;
        int wt = inox.top().first;

        inox.pop();

        for (auto it : num[node])
        {
            int adj_node = it.first;
            int adj_wt = it.second;

            if (dist[node].first + adj_wt < dist[adj_node].first)
            {
                dist[adj_node] = {dist[node].first + adj_wt, node};
                inox.push({dist[adj_node].first, adj_node});
            }
        }
    }

    std::vector<int> res;
    int temp = n - 1;

    while (temp)
    {
        res.push_back(temp);
        temp = dist[temp].second;
    }

    reverse(res.begin(), res.end());

    for (auto i : res)
        std::cout << i << " ";
}
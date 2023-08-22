#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    std::cin >> m;

    std::vector<std::vector<int>> adj[m];
    for (int i = 0; i < m; i++)
    {
        int k;
        std::cin >> k;

        std::vector<std::vector<int>> temp(k, std::vector<int>(2, 0));
        for (int j = 0; j < k; j++)
        {
            std::cin >> temp[j][0] >> temp[j][1];
        }

        adj[i] = temp;
    }

    int n;
    std::cin >> n;

    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, greater<std::pair<int, std::pair<int, int>>>> inox;

    std::vector<int> vis(n, 0);
    std::vector<std::pair<int, int>> mst;

    // {wt, node, parent}

    inox.push({0, {0, -1}});
    int sum = 0;

    while (inox.size())
    {
        auto it = inox.top();
        inox.pop();

        int node = it.second.first;
        int parent = it.second.second;
        int wt = it.first;

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;
        mst.push_back({parent, node});

        for (auto i : adj[node])
        {
            int adjNode = i[0];
            int adjWt = i[1];

            if (vis[adjNode] == 0)
                inox.push({adjWt, {adjNode, node}});
        }
    }

    std::cout << sum;
}
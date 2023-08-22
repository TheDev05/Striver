#include <bits/stdc++.h>
using namespace std;

class dsu
{
    std::vector<int> cmp_size, parent;

public:
    dsu(int n)
    {
        parent.resize(n + 1, 0);
        cmp_size.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            cmp_size[i] = 1;
        }
    }

    int getParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = getParent(parent[u]);
    }

    void getUnion(int u, int v)
    {
        int parent_u = parent[u];
        int parent_v = parent[v];

        if (parent_u == parent_v)
            return;

        if (cmp_size[parent_u] < cmp_size[parent_v])
        {
            parent[parent_u] = parent_v;
            cmp_size[parent_v] += cmp_size[parent_u];
        }
        else
        {
            parent[parent_v] = parent_u;
            cmp_size[parent_u] += cmp_size[parent_v];
        }
    }
};

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

    dsu ds(n);
    std::vector<std::pair<int, std::pair<int, int>>> num(n);

    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            int adjNode = j[0];
            int adjWt = j[1];
            int node = i;

            num[i].first = adjWt;
            num[i].second.first = node;
            num[i].second.second = adjNode;
        }
    }

    std::sort(num.begin(), num.end());

    int sum = 0;
    for (auto i : num)
    {
        int adjNode = i.first;
        int node = i.second.first;
        int adjWt = i.second.second;

        if (ds.getParent(node) != ds.getParent(adjNode))
        {
            ds.getUnion(node, adjNode);
            sum += adjWt;
        }
    }

    std::cout << sum;
}
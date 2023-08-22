#include <bits/stdc++.h>
using namespace std;

class dsu
{
    std::vector<int> parent, cmp_size;

public:
    dsu(int n)
    {
        parent.resize(n + 1, 0);
        cmp_size.resize(n + 1, 0);

        for (int i = 0; i < parent.size(); i++)
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

    void setUnion(int u, int v)
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
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(n);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    dsu ds(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (num[i][j])
            {
                if (ds.getParent(i) != ds.getParent(j))
                {
                    ds.setUnion(i, j);
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == ds.getParent(i))
            count++;
    }

    std::cout << count;
}
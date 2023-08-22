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

    std::vector<std::vector<int>> num(m, std::vector<int>(2, 0));
    for (int i = 0; i < m; i++)
    {
        std::cin >> num[i][0] >> num[i][1];
    }

    int n;
    std::cin >> n;

    dsu ds(n);

    for (int i = 0; i < n; i++)
    {
        int u = num[i][0];
        int v = num[i][1];

        if (ds.getParent(u) != ds.getParent(v))
            ds.setUnion(u, v);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.getParent(i) == i)
            count++;
    }

    std::cout << count - 1;
}
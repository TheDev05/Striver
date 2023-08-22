#include <bits/stdc++.h>
using namespace std;

class dsu
{
    std::vector<int> parent, cmp_size;

public:
    dsu(int n)
    {
        cmp_size.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
            cmp_size[i] = 1;
        }
    }

    int getParent(int vertex)
    {
        if (parent[vertex] == vertex)
            return vertex;

        return parent[vertex] = getParent(parent[vertex]);
    }

    void unionBySize(int u, int v)
    {
        int parent_u = getParent(u);
        int parent_v = getParent(v);

        if (parent_u == parent_v)
            return;

        if (cmp_size[parent_u] > cmp_size[parent_v])
        {
            parent[parent_v] = parent_u;
            cmp_size[parent_u] += cmp_size[parent_v];
        }
        else
        {
            parent[parent_u] = parent_v;
            cmp_size[parent_v] += cmp_size[parent_u];
        }
    }
};

int main()
{
    dsu ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.getParent(3) == ds.getParent(7))
        std::cout << "Same\n";
    else
        std::cout << "Not Same\n";

    ds.unionBySize(3, 7);

    if (ds.getParent(3) == ds.getParent(7))
        std::cout << "Same\n";
    else
        std::cout << "Not Same\n";
}
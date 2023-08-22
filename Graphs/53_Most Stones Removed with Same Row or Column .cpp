#include <bits/stdc++.h>
using namespace std;

class dsu
{
public:
    std::vector<int> parent, _size;

    dsu(int n)
    {
        parent.resize(n + 1, 0);
        _size.resize(n + 1, 0);

        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
            _size[i] = 1;
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
        int unode = parent[u];
        int vnode = parent[v];

        if (unode != vnode)
        {
            if (_size[unode] > _size[vnode])
                std::swap(unode, vnode);

            parent[unode] = vnode;
            _size[vnode] += _size[unode];
        }
    }
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i][0] >> num[i][1];
    }

    std::map<std::pair<int, int>, int> inox;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        inox[{num[i][0], num[i][1]}] = count;
    }

    dsu ds(count);

    for (int i = 0; i < n; i++)
    {
        int row = num[i][0];
        int col = num[i][1];

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int trow = num[j][0];
                int tcol = num[j][1];

                if (row == trow || col == tcol)
                {
                    int u = inox[{row, col}];
                    int v = inox[{trow, tcol}];

                    if (ds.getParent(u) != ds.getParent(v))
                        ds.setUnion(u, v);
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        if (ds.getParent(i) == i)
            sum += ds._size[i] - 1;
    }

    std::cout << sum;
}
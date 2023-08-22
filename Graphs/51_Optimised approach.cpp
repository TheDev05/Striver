#include <bits/stdc++.h>
using namespace std;

class dsu
{
public:
    std::vector<int> parent, cmp_size;
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
        int root_u = parent[u];
        int root_v = parent[v];

        if (root_u == root_v)
            return;

        if (cmp_size[root_u] < cmp_size[root_v])
        {
            parent[root_u] = root_v;
            cmp_size[root_v] += cmp_size[root_u];
        }
        else
        {
            parent[root_v] = root_u;
            cmp_size[root_u] += cmp_size[root_v];
        }
    }
};

int main()
{
    int k;
    std::cin >> k;

    std::vector<std::vector<int>> query(k, std::vector<int>(2, 0));
    for (int i = 0; i < k; i++)
    {
        std::cin >> query[i][0] >> query[i][1];
    }

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> num(n, std::vector<int>(m, 0));
    std::vector<int> res;

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    dsu ds(n * m);

    std::map<std::pair<int, int>, int> inox;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            inox[{i, j}] = count;
            count++;
        }
    }

    count = 0;
    for (int i = 0; i < k; i++)
    {
        int row = query[i][0];
        int col = query[i][1];

        if (num[row][col])
        {
            res.push_back(count);
            continue;
        }

        num[row][col] = 1;
        count++;

        for (int j = 0; j < 4; j++)
        {
            int trow = row + r[j];
            int tcol = col + c[j];

            if (trow >= 0 && tcol >= 0 && trow < n && tcol < m && num[trow][tcol])
            {
                int u = inox[{trow, tcol}];
                int v = inox[{row, col}];

                if (ds.getParent(u) != ds.getParent(v))
                {
                    count--;
                    ds.setUnion(u, v);
                }
            }
        }

        res.push_back(count);
    }

    for (auto i : res)
        std::cout << i << " ";
}
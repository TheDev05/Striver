#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    std::cin >> m;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> temp(3);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    int n, src;
    std::cin >> n >> src;

    std::vector<int> dist(n, 1e7);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[num[j][0]] + num[j][2] < dist[num[j][1]])
                dist[num[j][1]] = dist[num[j][0]] + num[j][2];
        }
    }

    bool ok = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[num[j][0]] + num[j][2] < dist[num[j][1]])
                ok = true;
        }
    }

    if (ok)
        std::cout << "Negative cycle detected\n";

    for (auto i : dist)
        std::cout << i << " ";
}
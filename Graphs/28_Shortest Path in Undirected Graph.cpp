#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;

    int src;
    std::cin >> src;

    std::vector<std::vector<int>> num(m, std::vector<int>(2, 0));
    for (int i = 0; i < m; i++)
    {
        std::cin >> num[i][0] >> num[i][1];
    }

    std::vector<int> store[n];
    for (int i = 0; i < m; i++)
    {
        store[num[i][0]].push_back(num[i][1]);
        store[num[i][1]].push_back(num[i][0]);
    }

    std::vector<int> dist(n, 1e5 + 1), vis(n, 0);

    std::queue<int> inox;
    inox.push(src);

    dist[src] = 0;
    vis[src] = 1;

    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        for (auto it : store[local])
        {
            dist[it] = std::min(dist[it], dist[local] + 1);

            if (vis[it] == 0)
            {
                inox.push(it);
                vis[it] = 1;
            }
        }
    }

    for (auto &i : dist)
        if (i == 1e5 + 1)
            i = -1;

    for (auto i : dist)
        std::cout << i << " ";
}
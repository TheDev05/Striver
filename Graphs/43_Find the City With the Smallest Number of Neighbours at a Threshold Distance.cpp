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

    int n, lim;
    std::cin >> n >> lim;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, 1e7));
    for (int i = 0; i < n; i++)
    {
        dist[num[i][0]][num[i][1]] = num[i][2];
        dist[num[i][1]][num[i][0]] = num[i][2];
    }

    for (int v = 0; v < n; v++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = std::min(dist[i][j], dist[i][v] + dist[v][j]);
            }
        }
    }

    std::vector<int> inox(n, 0);

    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] && dist[i][j] <= lim)
                count++;
        }

        inox[i] = count;
        min = std::min(min, count);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (inox[i] == min)
            max = std::max(max, i);
    }

    std::cout << max;
}
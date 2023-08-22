#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(m, 1e7));
    priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, greater<std::pair<int, std::pair<int, int>>>> inox;

    // dist, row, col

    inox.push({0, {0, 0}});
    dist[0][0] = 0;

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    while (inox.size())
    {
        auto it = inox.top();
        inox.pop();

        int val = it.first;

        int row = it.second.first;
        int col = it.second.second;

        for (int j = 0; j < 4; j++)
        {
            int trow = row + r[j];
            int tcol = col + c[j];

            if (trow >= 0 && tcol >= 0 && trow < n && tcol < m && dist[trow][tcol] > std::max(val, abs(num[row][col] - num[trow][tcol])))
            {
                dist[trow][tcol] = std::max(val, abs(num[row][col] - num[trow][tcol]));
                inox.push({dist[trow][tcol], {trow, tcol}});
            }
        }
    }

    std::cout << dist[n - 1][m - 1];
}
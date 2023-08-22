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

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> inox;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == 2)
            {
                inox.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    int count = 0;
    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            int row = inox.front().first;
            int col = inox.front().second;

            inox.pop();

            if (row - 1 >= 0 && num[row - 1][col] == 1 && vis[row - 1][col] == 0)
            {
                inox.push({row - 1, col});
                vis[row - 1][col] = 1;
            }

            if (row + 1 < n && num[row + 1][col] == 1 && vis[row + 1][col] == 0)
            {
                inox.push({row + 1, col});
                vis[row + 1][col] = 1;
            }

            if (col - 1 >= 0 && num[row][col - 1] == 1 && vis[row][col - 1] == 0)
            {
                inox.push({row, col - 1});
                vis[row][col - 1] = 1;
            }

            if (col + 1 < m && num[row][col + 1] == 1 && vis[row][col + 1] == 0)
            {
                inox.push({row, col + 1});
                vis[row][col + 1] = 1;
            }
        }

        if (inox.size())
            count++;
    }

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] && vis[i][j] == 0)
                count = -1;
            if (num[i][j])
                ok = false;
        }
    }

    if (ok)
        count = 0;

    std::cout << count;
}
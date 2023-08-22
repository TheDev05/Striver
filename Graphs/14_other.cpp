#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<char> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> test;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == m - 1 || i == n - 1 || j == 0)
            {
                if (num[i][j] == 'O')
                {
                    test.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    while (test.size())
    {
        int row = test.front().first;
        int col = test.front().second;

        test.pop();

        for (int k = 0; k < 4; k++)
        {
            int trow = row + r[k];
            int tcol = col + c[k];

            if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] == 'O' && vis[trow][tcol] == 0)
            {
                vis[trow][tcol] = 1;
                test.push({trow, tcol});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j])
                num[i][j] = 'O';
            else
                num[i][j] = 'X';
        }
    }

    for (auto i : num)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}
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

    std::vector<std::vector<char>> vis(n, std::vector<char>(m, 0));
    std::vector<std::vector<char>> result(n, std::vector<char>(m, 'X'));

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && num[i][j] == 'O')
            {
                std::queue<std::pair<int, int>> test;
                std::vector<std::pair<int, int>> local;

                test.push({i, j});
                vis[i][j] = 1;

                bool ok = true;
                while (test.size())
                {
                    int row = test.front().first;
                    int col = test.front().second;

                    test.pop();
                    local.push_back({row, col});

                    for (int k = 0; k < 4; k++)
                    {
                        int trow = row + r[k];
                        int tcol = col + c[k];

                        if (trow < 0 || trow >= n || tcol < 0 || tcol >= m)
                            ok = false;

                        if (trow >= 0 && trow < n && tcol >= 0 && tcol < m)
                        {
                            if (vis[trow][tcol] == 0 && num[trow][tcol] == 'O')
                            {
                                vis[trow][tcol] = 1;
                                test.push({trow, tcol});
                            }
                        }
                    }
                }

                if (ok)
                    for (auto p : local)
                        num[p.first][p.second] = 'X';
            }
        }
    }

    for (auto i : num)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}
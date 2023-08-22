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

    std::set<std::set<std::pair<int, int>>> inox;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] && vis[i][j] == 0)
            {
                std::queue<std::pair<int, int>> temp;
                std::set<std::pair<int, int>> store;

                temp.push({i, j});
                vis[i][j] = 1;

                int left = i, right = j;
                while (temp.size())
                {
                    int row = temp.front().first;
                    int col = temp.front().second;

                    temp.pop();
                    store.insert({abs(row - left), (col - right)});

                    for (int k = 0; k < 4; k++)
                    {
                        int trow = row + r[k];
                        int tcol = col + c[k];

                        if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] && !vis[trow][tcol])
                        {
                            vis[trow][tcol] = 1;
                            temp.push({trow, tcol});
                        }
                    }
                }

                inox.insert(store);
            }
        }
    }

    std::cout << inox.size();
}
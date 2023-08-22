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

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == '1')
            {
                count++;

                std::queue<std::pair<int, int>> temp;

                temp.push({i, j});
                num[i][j] = '0';

                while (temp.size())
                {
                    int row = temp.front().first;
                    int col = temp.front().second;

                    temp.pop();

                    if (row - 1 >= 0 && num[row - 1][col] == '1')
                    {
                        temp.push({row - 1, col});
                        num[row - 1][col] = '0';
                    }

                    if (row + 1 < n && num[row + 1][col] == '1')
                    {
                        temp.push({row + 1, col});
                        num[row + 1][col] = '0';
                    }

                    if (col - 1 >= 0 && num[row][col - 1] == '1')
                    {
                        temp.push({row, col - 1});
                        num[row][col - 1] = '0';
                    }

                    if (col + 1 < m && num[row][col + 1] == '1')
                    {
                        temp.push({row, col + 1});
                        num[row][col + 1] = '0';
                    }
                }
            }
        }
    }

    std::cout << count;
}
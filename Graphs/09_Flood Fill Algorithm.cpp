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

    int sr, sc;
    std::cin >> sr >> sc;

    int img;
    std::cin >> img;

    std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> inox;

    inox.push({sr, sc});
    visited[sr][sc] = 1;

    while (inox.size())
    {
        int row = inox.front().first;
        int col = inox.front().second;

        int val = num[row][col];
        inox.pop();

        if (row - 1 >= 0 && num[row - 1][col] == val && visited[row - 1][col] == 0)
        {
            visited[row - 1][col] = 1;
            inox.push({row - 1, col});
        }

        if (row + 1 < n && num[row + 1][col] == val && visited[row + 1][col] == 0)
        {
            visited[row + 1][col] = 1;
            inox.push({row + 1, col});
        }

        if (col - 1 >= 0 && num[row][col - 1] == val && visited[row][col - 1] == 0)
        {
            visited[row][col - 1] = 1;
            inox.push({row, col - 1});
        }
        if (col + 1 < m && num[row][col + 1] == val && visited[row][col + 1] == 0)
        {
            visited[row][col + 1] = 1;
            inox.push({row, col + 1});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                num[i][j] = img;
        }
    }
}
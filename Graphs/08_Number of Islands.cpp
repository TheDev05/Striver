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

    std::map<std::pair<int, int>, int> data;
    int inox = 1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == '1')
                data[{i, j}] = inox;

            inox++;
        }
    }

    std::vector<int> adj[(n * m) + 1];
    for (auto k : data)
    {
        int i = k.first.first, j = k.first.second;
        int index = k.second;

        if (data.count({i + 1, j + 1}))
            adj[index].push_back(data[{i + 1, j + 1}]);
        if (data.count({i - 1, j - 1}))
            adj[index].push_back(data[{i - 1, j - 1}]);

        if (data.count({i + 1, j - 1}))
            adj[index].push_back(data[{i + 1, j - 1}]);
        if (data.count({i - 1, j + 1}))
            adj[index].push_back(data[{i - 1, j + 1}]);

        if (data.count({i + 1, j}))
            adj[index].push_back(data[{i + 1, j}]);
        if (data.count({i - 1, j}))
            adj[index].push_back(data[{i - 1, j}]);

        if (data.count({i, j + 1}))
            adj[index].push_back(data[{i, j + 1}]);
        if (data.count({i, j - 1}))
            adj[index].push_back(data[{i, j - 1}]);

        if (adj[index].empty())
            adj[index].push_back(-1);
    }

    std::vector<int> visited((n * m) + 1, 0);

    int count = 0;
    for (int i = 1; i <= (n * m); i++)
    {
        if (adj[i].size() && !visited[i])
        {
            count++;
            if (adj[i][0] == -1)
                continue;

            std::queue<int> temp;

            temp.push(i);
            visited[i] = 1;

            while (temp.size())
            {
                int dash = temp.front();
                temp.pop();

                for (auto j : adj[dash])
                {
                    if (!visited[j])
                    {
                        visited[j] = 1;
                        temp.push(j);
                    }
                }
            }
        }
    }

    std::cout << count;
}
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

    std::vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != j && num[i][j])
                adj[i + 1].push_back(j + 1);
        }
    }

    std::vector<int> visited(n + 1, 0);

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            std::queue<int> inox;

            visited[i] = 1;
            inox.push(i);

            while (inox.size())
            {
                int temp = inox.front();
                inox.pop();

                for (auto j : adj[temp])
                {
                    if (!visited[j])
                    {
                        visited[j] = 1;
                        inox.push(j);
                    }
                }
            }
        }
    }


    std::cout << count << '\n';
}
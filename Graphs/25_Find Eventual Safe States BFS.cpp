#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    std::vector<int> store[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < num[i].size(); j++)
        {
            store[num[i][j]].push_back(i);
        }
    }

    std::vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < store[i].size(); j++)
        {
            indeg[store[i][j]]++;
        }
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    std::vector<int> result;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        result.push_back(local);

        for (auto i : store[local])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }

    std::sort(result.begin(), result.end());
    for (auto i : result)
        std::cout << i << " ";
}
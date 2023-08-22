#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num->push_back(temp);
    }

    std::vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : num[i])
            indegree[j]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            inox.push(i);
    }

    std::vector<int> result;
    while (inox.size())
    {
        int local = inox.front();

        result.push(local);
        inox.pop();

        for (auto i : num[local])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                inox.push(i);
        }
    }

    for (auto i : result)
        std::cout << i << " ";
}
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

        num[i] = temp;
    }

    std::vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : num[i])
            indeg[j]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    int count = 0;
    while (inox.size())
    {
        int local = inox.front();

        count++;
        inox.pop();

        for (auto i : num[local])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }

    if (count != n)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}
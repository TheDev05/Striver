#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(n);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    for (auto &i : num)
    {
        for (auto &j : i)
        {
            if (j == -1)
                j = 1e7;
        }
    }

    for (int v = 0; v < n; v++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                num[i][j] = std::min(num[i][j], num[i][v] + num[v][j]);
                if (i == j)
                    num[i][j] = 0;
            }
        }
    }

    bool ok = false;
    for (auto i : num)
    {
        for (auto j : i)
            if (j < 0)
                ok = true;
    }

    if (ok)
        std::cout << "Neg Wt cycle found\n";

    for (auto i : num)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}
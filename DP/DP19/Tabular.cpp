#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> value[i];
    }

    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(k + 1, -1));
    for (int i = 0; i < storage[0].size(); i++)
    {
        storage[storage.size() - 1][i] = 0;
    }

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j - weight[i] >= 0)
                val1 = value[i] + storage[i + 1][j - weight[i]];
            val2 = storage[i + 1][j];

            storage[i][j] = std::max(val1, val2);
        }
    }

    std::cout << storage[0][k];
}
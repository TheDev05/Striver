#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(k + 1, false));
    storage[storage.size() - 1][0] = true;

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            bool val1 = false, val2 = false;
            if (j - num[i] >= 0)
                val1 = storage[i + 1][j - num[i]];
            val2 = storage[i + 1][j];

            storage[i][j] = val1 | val2;
        }
    }

    std::cout << storage[0][k];
}
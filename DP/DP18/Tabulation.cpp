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

    int total = 0;
    for (auto i : num)
        total += i;

    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(total + 1, 0));

    for (int i = 0; i < storage[0].size(); i++)
    {
        if (i - (total - i) == k)
            storage[storage.size() - 1][i] = 1;
    }

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j + num[i] < storage[0].size())
                val1 = storage[i + 1][j + num[i]];
            val2 = storage[i + 1][j];

            storage[i][j] = val1 + val2;
        }
    }

    std::cout << storage[0][0];
}
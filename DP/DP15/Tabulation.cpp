#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    int k = accumulate(num.begin(), num.end(), 0);
    // if (k & 1)
    //     return false;

    k = k / 2;

    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(k + 1, false));
    storage[storage.size() - 1][storage[0].size() - 1] = true;

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            bool val1 = false, val2 = false;
            if ((num[i] + j) < storage[0].size())
                val1 = storage[i + 1][num[i] + j];
            val2 = storage[i + 1][j];

            storage[i][j] = val1 | val2;
        }
    }

    std::cout << storage[0][0];
}
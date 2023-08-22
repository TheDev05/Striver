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

    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(num.size() + 1, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            int val1 = 0, val2 = 0;
            if (j == 0 || num[i] > num[j - 1])
                val1 = 1 + storage[i + 1][i + 1];
            val2 = storage[i + 1][j];

            storage[i][j] = std::max(val1, val2);
        }
    }

    std::cout << storage[0][0];
}
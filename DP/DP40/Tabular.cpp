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

    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(2, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j)
            {
                int val1 = 0, val2 = 0;
                val1 = (storage[i + 1][0] - num[i]) - k;
                val2 = storage[i + 1][j];

                storage[i][j] = std::max(val1, val2);
            }
            else
            {
                int val1 = 0, val2 = 0;
                val1 = num[i] + storage[i + 1][1];
                val2 = storage[i + 1][j];

                storage[i][j] = std::max(val1, val2);
            }
        }
    }

    std::cout << storage[0][1];
}
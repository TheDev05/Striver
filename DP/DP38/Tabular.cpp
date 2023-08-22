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

    std::vector<std::vector<std::vector<int>>> storage(num.size() + 1, std::vector<std::vector<int>>(2, std::vector<int>(k + 1, 0)));

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int p = 0; p < k + 1; p++)
            {
                if (j)
                {
                    int val1 = 0, val2 = 0;
                    if (p > 0)
                        val1 = storage[i + 1][0][p - 1] - num[i];
                    val2 = storage[i + 1][j][p];

                    storage[i][j][p] = std::max(val1, val2);
                }
                else
                {
                    int val1 = 0, val2 = 0;
                    val1 = num[i] + storage[i + 1][1][p];
                    val2 = storage[i + 1][j][p];

                    storage[i][j][p] = std::max(val1, val2);
                }
            }
        }
    }

    std::cout << storage[0][1][k];
}
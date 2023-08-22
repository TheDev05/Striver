#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(3);
        for (int j = 0; j < 3; j++)
        {
            std::cin >> temp[j];
        }

        num.push_back(temp);
    }

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(3, -1));
    for (int i = 0; i < 3; i++)
    {
        storage[n - 1][i] = num[n - 1][i];
    }

    int max = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            int localMax = 0;
            for (int k = 0; k < 3; k++)
            {
                if (j != k)
                {
                    localMax = std::max(localMax, storage[i + 1][k]);
                }
            }

            storage[i][j] = num[i][j] + localMax;
            max = std::max(max, storage[i][j]);
        }
    }

    std::cout << max;
}
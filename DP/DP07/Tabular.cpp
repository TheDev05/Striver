#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < 3; i++)
    {
        std::vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            std::cin >> temp[j];
        }

        num.push_back(temp);
    }

    std::vector<std::vector<int>> temp;
    for (int j = 0; j < num[0].size(); j++)
    {
        std::vector<int> demo;
        for (int i = 0; i < n; i++)
        {
            demo.push_back(num[i][j]);
        }

        temp.push_back(demo);
    }

    /* Tabular Approach */
    std::vector<std::vector<int>> storage(3, std::vector<int>(n, -1));
    for (int i = 0; i < 3; i++)
    {
        storage[i][n - 1] = temp[i][n - 1];
    }

    int result = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            int max = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    max = std::max(max, temp[j][i] + storage[k][i + 1]);
                }
            }

            storage[j][i] = max;
            result = std::max(result, storage[j][i]);
        }
    }

    std::cout << result;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(m);
        for (int j = 0; j < m; j++)
        {
            std::cin >> temp[j];
        }

        num.push_back(temp);
    }

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num[0].size(), -1));
    storage[num.size() - 1][num[0].size() - 1] = num[num.size() - 1][num[0].size() - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = num[0].size() - 1; j >= 0; j--)
        {
            if (i == num.size() - 1 && j == num[0].size() - 1)
                continue;
            int down = INT_MAX, right = INT_MAX;

            if (i != num.size() - 1)
                down = storage[i + 1][j];
            if (j != num[0].size() - 1)
                right = storage[i][j + 1];

            storage[i][j] = std::min(right, down) + num[i][j];
        }
    }

    std::cout << storage[0][0];
}
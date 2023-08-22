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
    for (int i = 0; i < num[0].size(); i++)
    {
        storage[storage.size() - 1][i] = num[num.size() - 1][i];
    }

    for (int i = num.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            int left = INT_MIN, right = INT_MIN, down = INT_MIN;
            if (j != 0)
                left = storage[i + 1][j - 1];
            if (j != storage[0].size() - 1)
                right = storage[i + 1][j + 1];
            down = storage[i + 1][j];

            storage[i][j] = std::max({left, right, down}) + num[i][j];
        }
    }

    std::cout << *max_element(storage[0].begin(), storage[0].end());
}
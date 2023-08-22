#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++)
        {
            std::cin >> temp[j];
        }

        num.push_back(temp);
    }

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num.size(), -1));
    for (int i = 0; i < storage[storage.size() - 1].size(); i++)
    {
        storage[storage.size() - 1][i] = num[num.size() - 1][i];
    }

    for (int i = num.size() - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = storage[i + 1][j];
            int diagonal = storage[i + 1][j + 1];

            storage[i][j] = std::min(down, diagonal) + num[i][j];
        }
    }

    std::cout << storage[0][0];
}
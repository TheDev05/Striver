#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &storage, int i, int j)
{
    if (i >= num.size() || j >= num[0].size())
        return INT_MAX;
    if (i == num.size() - 1 && j == num[0].size() - 1)
        return num[i][j];

    if (storage[i][j] == -1)
    {
        int right = getCount(num, storage, i, j + 1);
        int down = getCount(num, storage, i + 1, j);

        storage[i][j] = std::min(right, down) + num[i][j];
    }

    return storage[i][j];
}

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

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(m, -1));
    std::cout << getCount(num, storage, 0, 0);
}
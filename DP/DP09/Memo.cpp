#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &storage, int i, int j)
{
    if (i >= num.size() || j >= num[0].size())
        return 0;
    if (num[i][j] == 1)
        return 0;
    if (i == num.size() - 1 && j == num[0].size() - 1)
        return 1;

    if (storage[i][j] == -1)
    {
        storage[i][j] = getCount(num, storage, i + 1, j) + getCount(num, storage, i, j + 1);
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
        std::vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            std::cin >> temp[j];
        }

        num.push_back(temp);
    }

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num[0].size(), -1));
    // if (num[0][0] == 1 || num[num.size() - 1][num[0].size() - 1] == 1)
    //     return 0;

    std::cout << getCount(num, storage, 0, 0);
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &storage, int i, int j)
{
    if (j < 0 || j > num[0].size() - 1)
        return INT_MIN;
        
    if (i == num.size() - 1)
        return num[i][j];

    if (storage[i][j] == -1)
    {
        int left = getCount(num, storage, i + 1, j - 1);
        int right = getCount(num, storage, i + 1, j + 1);
        int down = getCount(num, storage, i + 1, j);

        storage[i][j] = std::max({left, right, down}) + num[i][j];
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

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(num[0].size(), -1));

    int max = INT_MIN;
    for (int i = 0; i < num[0].size(); i++)
    {
        max = std::max(max, getCount(num, storage, 0, i));
    }

    std::cout << max;
}
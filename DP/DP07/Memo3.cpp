#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<std::vector<int>> &num, std::vector<std::vector<int>> &storage, int skip, int row)
{
    if (row >= num.size())
        return 0;

    int max = 0;
    for (int col = 0; col < 3; col++)
    {
        if (col != skip)
        {
            if (storage[row][col] == -1)
                storage[row][col] = num[row][col] + getCount(num, storage, col, row + 1);

            max = std::max(max, storage[row][col]);
        }
    }

    return max;
}

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
    std::cout << getCount(num, storage, -1, 0);
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, bool buy, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index][buy] == -1)
    {
        int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
        if (buy)
        {
            val1 = getCount(num, storage, 0, index + 1) - num[index];
            val2 = getCount(num, storage, buy, index + 1);
        }
        else 
        {
            val3 = num[index] + getCount(num, storage, 1, index + 1);
            val4 = getCount(num, storage, buy, index + 1);
        }

        storage[index][buy] = std::max({val1, val2, val3, val4});
    }

    return storage[index][buy];
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(2, -1));
    std::cout << getCount(num, storage, 1, 0);
}
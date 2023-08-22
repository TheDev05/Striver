#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<std::vector<int>>> &storage, int buy, int sell, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index][buy][sell] == -1)
    {
        if (buy)
        {
            int val1 = 0, val2 = 0;
            if (sell)
                val1 = getCount(num, storage, 0, 0, index + 1) - num[index];
            val2 = getCount(num, storage, buy, 1, index + 1);

            storage[index][buy][sell] = std::max(val1, val2);
        }
        else
        {
            int val1 = 0, val2 = 0;
            val1 = num[index] + getCount(num, storage, 1, 0, index + 1);
            val2 = getCount(num, storage, buy, 1, index + 1);

            storage[index][buy][sell] = std::max(val1, val2);
        }
    }

    return storage[index][buy][sell];
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

    std::vector<std::vector<std::vector<int>>> storage(num.size(), std::vector<std::vector<int>>(2, std::vector<int>(2, -1)));
    std::cout << getCount(num, storage, 1, 1, 0);
}
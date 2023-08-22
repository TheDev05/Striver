#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<std::vector<int>>> &storage, bool buy, int k, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index][buy][k] == -1)
    {
        if (buy)
        {
            int val1 = 0, val2 = 0;
            if (k > 0)
                val1 = getCount(num, storage, 0, k - 1, index + 1) - num[index];
            val2 = getCount(num, storage, buy, k, index + 1);

            storage[index][buy][k] = std::max(val1, val2);
        }
        else
        {
            int val1 = 0, val2 = 0;
            val1 = num[index] + getCount(num, storage, 1, k, index + 1);
            val2 = getCount(num, storage, buy, k, index + 1);

            storage[index][buy][k] = std::max(val1, val2);
        }
    }

    return storage[index][buy][k];
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<std::vector<std::vector<int>>> storage(num.size(), std::vector<std::vector<int>>(2, std::vector<int>(k + 1, -1)));
    std::cout << getCount(num, storage, 1, k, 0);
}
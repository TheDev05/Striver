#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= num.size())
    {
        if (k == 0)
            return 0;

        return INT_MAX - 1;
    }

    if (storage[index][k] == -1)
    {
        int val1 = INT_MAX, val2 = INT_MAX;
        if (k - num[index] >= 0)
        {
            val1 = 1 + getCount(num, storage, k - num[index], index);
        }

        val2 = getCount(num, storage, k, index + 1);
        storage[index][k] = std::min(val1, val2);
    }

    return storage[index][k];
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

    std::vector<std::vector<int>> storage(n, std::vector<int>(k + 1, -1));
    int res = getCount(num, storage, k, 0);

    std::cout << res;
}
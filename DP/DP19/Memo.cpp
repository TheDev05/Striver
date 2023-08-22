#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &weight, std::vector<int> &value, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= weight.size())
        return 0;

    if (storage[index][k] == -1)
    {
        int val1 = 0, val2 = 0;
        if (k - weight[index] >= 0)
            val1 = value[index] + getCount(weight, value, storage, k - weight[index], index + 1);
        val2 = getCount(weight, value, storage, k, index + 1);

        storage[index][k] = std::max(val1, val2);
    }

    return storage[index][k];
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> value[i];
    }

    std::vector<std::vector<int>> storage(n, std::vector<int>(k + 1, -1));
    std::cout << getCount(weight, value, storage, k, 0);
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= num.size())
    {
        if (k == 0)
            return true;
        return false;
    }

    if (storage[index][k] == -1)
    {
        bool val1 = false, val2 = false;
        if (k - num[index] >= 0)
            val1 = getCount(num, storage, k - num[index], index + 1);
        val2 = getCount(num, storage, k, index + 1);

        storage[index][k] = val1 | val2;
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
    std::cout << getCount(num, storage, k, 0);
}
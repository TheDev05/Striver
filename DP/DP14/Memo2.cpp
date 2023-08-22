#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int k, int index)
{
    if (index >= num.size())
    {
        if (sum == k)
            return true;
        return false;
    }

    if (storage[index][sum] == -1)
    {
        bool val1 = false, val2 = false;

        if (sum + num[index] <= k)
            val1 = getCount(num, storage, sum + num[index], k, index + 1);
        val2 = getCount(num, storage, sum, k, index + 1);

        storage[index][sum] = val1 | val2;
    }

    return storage[index][sum];
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
    std::cout << getCount(num, storage, 0, k, 0);
}
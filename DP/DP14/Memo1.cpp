#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int k, int sum, int index)
{
    if (index >= num.size())
    {
        if (sum == k)
            return 1;
        return 0;
    }

    if (storage[index][sum] == -1)
    {
        int val1 = 0;
        if (sum + num[index] <= k)
            val1 = getCount(num, storage, k, sum + num[index], index + 1);
        int val2 = getCount(num, storage, k, sum, index + 1);

        storage[index][sum] = std::max(val1, val2);
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
    std::cout << getCount(num, storage, k, 0, 0);
}
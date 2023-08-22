#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int total, int k, int index)
{
    if (index >= num.size())
        return (sum - (total - sum) == k) ? 1 : 0;

    if (storage[index][sum] == -1)
    {
        int val1 = 0, val2 = 0;
        if (sum - num[index] >= 0)
            val1 = getCount(num, storage, sum - num[index], total, k, index + 1);
        val2 = getCount(num, storage, sum, total, k, index + 1);

        storage[index][sum] = val1 + val2;
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

    int total = 0;
    for (auto i : num)
        total += i;

    std::vector<std::vector<int>> storage(n, std::vector<int>(total + 1, -1));
    std::cout << getCount(num, storage, total, total, k, 0);
}
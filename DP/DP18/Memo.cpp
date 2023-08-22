#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int k, int total, int index)
{
    if (index >= num.size())
    {
        if (sum - (total - sum) == k)
            return 1;
        return 0;
    }

    if (storage[index][sum] == -1)
    {
        int val1 = getCount(num, storage, sum + num[index], k, total, index + 1);
        int val2 = getCount(num, storage, sum, k, total, index + 1);

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
    std::cout << getCount(num, storage, 0, k, total, 0);
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int index)
{
    if (index >= num.size())
        return (sum == 0) ? 1 : 0;

    if (storage[index][sum] == -1)
    {
        int val1 = 0, val2 = 0;
        if (sum - num[index] >= 0)
            val1 = getCount(num, storage, sum - num[index], index + 1);
        val2 = getCount(num, storage, sum, index + 1);

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

    int total = 0, sum = 0;
    for (auto i : num)
        total += i;

    if (k < -total || k > total)
        cout << 0;

    if ((total + k) % 2 == 0)
    {
        sum = (total + k) / 2;
    }
    else if ((total - k) % 2 == 0)
    {
        sum = (total - k) / 2;
    }
    else
        sum = 0;

    std::vector<std::vector<int>> storage(n, std::vector<int>(sum + 1, -1));
    std::cout << getCount(num, storage, sum, 0);
}
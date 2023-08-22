#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int index)
{
    if (index >= num.size())
    {
        if (sum == 0)
            return true;
        return false;
    }

    if (storage[index][sum] == -1)
    {
        bool val1 = false, val2 = false;
        if (sum - num[index] >= 0)
            val1 = getCount(num, storage, sum - num[index], index + 1);
        val2 = getCount(num, storage, sum, index + 1);

        storage[index][sum] = val1 | val2;
    }

    return storage[index][sum];
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

    int sum = 0;
    for (auto i : num)
        sum += i;

    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(sum + 1, false));
    storage[storage.size() - 1][0] = true;

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < storage[0].size(); j++)
        {
            bool val1 = false, val2 = false;
            if (j - num[i] >= 0)
                val1 = storage[i + 1][j - num[i]];
            val2 = storage[i + 1][j];

            storage[i][j] = val1 | val2;
        }
    }

    int min = INT_MAX;
    for (int i = 0; i < storage[0].size(); i++)
    {
        if (storage[0][i])
            min = std::min(min, abs(i - (sum - i)));
    }

    std::cout << min;
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index][k] == -1)
    {
        int val1 = 0, val2 = 0;
        if (k - (index + 1) >= 0)
            val1 = num[index] + getCount(num, storage, k - (index + 1), index);
        val2 = getCount(num, storage, k, index + 1);

        storage[index][k] = std::max(val1, val2);
    }

    return storage[index][k];
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

    std::vector<std::vector<int>> storage(n, std::vector<int>(n + 1, -1));
    std::cout << getCount(num, storage, n, 0);
}
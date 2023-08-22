#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<int> &storage, int buy, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index] == -1)
    {
        int val1 = 0, val2 = 0, val3 = 0;
        if (buy >= 0 && num[index] >= buy)
        {
            val1 = num[index] - buy;
        }

        val3 = getCount(num, storage, num[index], index + 1);
        val2 = getCount(num, storage, buy, index + 1);

        storage[index] = std::max(val1 + val3, val2);
    }

    return storage[index];
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

    std::vector<int> storage(n, -1);
    std::cout << getCount(num, storage, -1, 0);
}
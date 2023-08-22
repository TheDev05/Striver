#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<int> &storage, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index] == -1)
    {
        int max = 0;
        for (int j = index + 1; j < num.size(); j++)
        {
            if (num[j] > num[index])
                max = std::max(max, getCount(num, storage, j));
        }

        storage[index] = 1 + max;
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

    int max = 0;
    std::vector<int> storage(num.size(), -1);

    for (int i = 0; i < num.size(); i++)
    {
        max = std::max(max, getCount(num, storage, i));
    }

    std::cout << max;
}
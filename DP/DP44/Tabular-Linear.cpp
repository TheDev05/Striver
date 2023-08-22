#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    sort(num.begin(), num.end());
    std::vector<int> storage(num.size(), 1), hash(num.size(), 0);

    int lastIndex = 0;
    for (int i = 0; i < num.size(); i++)
    {
        hash[i] = i;

        int max = 0, index = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[i] % num[j] == 0 || num[j] % num[i] == 0)
            {
                if (storage[j] > max)
                {
                    max = storage[j];
                    index = j;
                }
            }
        }

        storage[i] = 1 + max;
        hash[i] = index;

        if (storage[i] > storage[lastIndex])
            lastIndex = i;
    }

    std::vector<int> result;
    while (1)
    {
        result.push_back(num[lastIndex]);
        if (hash[lastIndex] == lastIndex)
            break;
        lastIndex = hash[lastIndex];
    }

    reverse(result.begin(), result.end());

    for (auto i : result)
        std::cout << i << " ";
}
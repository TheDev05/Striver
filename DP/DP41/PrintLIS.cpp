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

    std::vector<int> storage(num.size(), 1), hash(num.size(), 0);

    int result = 0, prevIndex = 0;
    for (int i = 0; i < num.size(); i++)
    {
        hash[i] = i;

        int max = 0, index = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j] < num[i])
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

        if (storage[i] > result)
        {
            result = storage[i];
            prevIndex = i;
        }
    }

    std::vector<int> temp;

    while (1)
    {
        temp.push_back(num[prevIndex]);
        if (hash[prevIndex] == prevIndex)
            break;

        prevIndex = hash[prevIndex];
    }

    reverse(temp.begin(), temp.end());

    for (auto i : temp)
        std::cout << i << " ";
}
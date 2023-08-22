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

    int sum = 0;
    for (auto i : num)
        sum += i;

    // if (sum & 1)
    //     return false;
    sum = sum / 2;

    std::vector<std::vector<int>> storage(num.size() + 1, std::vector<int>(sum + 1, false));
    storage[storage.size() - 1][0] = true;

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int k = 0; k < storage[0].size(); k++)
        {
            bool val1 = false, val2 = false;
            if (k - num[i] >= 0)
                val1 = storage[i + 1][k - num[i]];
            val2 = storage[i + 1][k];

            storage[i][k] = val1 | val2;
        }
    }

    std::cout << storage[0][sum];
}
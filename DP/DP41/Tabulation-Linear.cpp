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

    std::vector<int> storage(num.size(), 1);

    int result = 0;
    for (int i = 0; i < num.size(); i++)
    {
        int max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j] < num[i])
                max = std::max(max, storage[j]);
        }

        storage[i] = 1 + max;
        result = std::max(result, storage[i]);
    }

    std::cout << result;
}
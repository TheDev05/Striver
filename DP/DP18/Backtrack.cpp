#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int sum, int k, int total, int index)
{
    if (index >= num.size())
    {
        if (sum - (total - sum) == k)
            return 1;
        return 0;
    }

    int val1 = getCount(num, sum + num[index], k, total, index + 1);
    int val2 = getCount(num, sum, k, total, index + 1);

    return val1 + val2;
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

    std::cout << getCount(num, 0, k, total, 0);
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int sum, int total, int k, int index)
{
    if (index >= num.size())
        return (sum - (total - sum) == k) ? 1 : 0;

    int val1 = getCount(num, sum - num[index], total, k, index + 1);
    int val2 = getCount(num, sum, total, k, index + 1);

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

    std::cout << getCount(num, total, total, k, 0);
}
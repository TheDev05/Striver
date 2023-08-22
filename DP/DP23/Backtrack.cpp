#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &profit, std::vector<int> &weight, int &max, int k, int sum, int index)
{
    if (index >= weight.size())
    {
        max = std::max(max, sum);
        return 0;
    }

    if (k - weight[index] >= 0)
        getCount(profit, weight, max, k - weight[index], sum + profit[index], index);
    getCount(profit, weight, max, k, sum, index + 1);

    return 0;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> profit[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> weight[i];
    }

    int max = INT_MIN;
    getCount(profit, weight, max, k, 0, 0);

    std::cout << max;
}
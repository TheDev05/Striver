#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &weight, std::vector<int> &value, int k, int sum, int &max, int index)
{
    if (index >= weight.size())
    {
        max = std::max(max, sum);
        return 0;
    }

    if (k - weight[index] >= 0)
        getCount(weight, value, k - weight[index], sum + value[index], max, index + 1);
    getCount(weight, value, k, sum, max, index + 1);

    return 0;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> value[i];
    }

    int max = 0;
    getCount(weight, value, k, 0, max, 0);

    std::cout << max;
}
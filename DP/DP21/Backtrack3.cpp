#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<std::vector<int>> &storage, int sum, int index)
{
    if (index >= num.size())
        return (sum == 0) ? 1 : 0;

    int val1 = getCount(num, storage, sum - num[index], index + 1);
    int val2 = getCount(num, storage, sum, index + 1);

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

    int total = 0, sum = 0;
    for (auto i : num)
        total += i;

    if ((total + k) % 2 == 0)
    {
        sum = (total + k) / 2;
    }
    else if ((total - k) % 2 == 0)
    {
        sum = (total - k) / 2;
    }
    else
        sum = 0;

    std::cout << getCount(num, storage, sum, 0);
}
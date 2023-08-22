#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int sum, int total, int &min, int index)
{
    if (index >= num.size())
    {
        min = std::min(min, (int)(abs(sum - (total - sum))));
        return 0;
    }

    getCount(num, sum + num[index], total, min, index + 1);
    getCount(num, sum, total, min, index + 1);

    return 0;
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

    int total = 0;
    for (auto i : num)
        total += i;

    int min = INT_MAX;
    getCount(num, 0, total, min, 0);

    std::cout << min;
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, bool buy, int count, int index)
{
    if (index >= num.size())
        return 0;

    int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
    if (buy)
    {
        if (count > 0)
            val1 = getCount(num, 0, count - 1, index + 1) - num[index];
        val2 = getCount(num, buy, count, index + 1);
    }
    else
    {
        val3 = num[index] + getCount(num, 1, count, index + 1);
        val4 = getCount(num, buy, count, index + 1);
    }

    return std::max({val1, val2, val3, val4});
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

    std::cout << getCount(num, 1, 2, 0);
}
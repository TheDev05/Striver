#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int buy, int sell, int index)
{
    if (index >= num.size())
        return 0;

    if (buy)
    {
        int val1 = 0, val2 = 0;
        if (sell)
            val1 = getCount(num, 0, 0, index + 1) - num[index];
        val2 = getCount(num, buy, 1, index + 1);

        return std::max(val1, val2);
    }
    else
    {
        int val1 = 0, val2 = 0;
        val1 = num[index] + getCount(num, 1, 0, index + 1);
        val2 = getCount(num, buy, 1, index + 1);

        return std::max(val1, val2);
    }
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

    std::cout << getCount(num, 1, 1, 0);
}
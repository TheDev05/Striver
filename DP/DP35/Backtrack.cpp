#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int stock, int index)
{
    if (index >= num.size())
        return 0;

    int val1 = 0, val2 = 0, val3 = 0;
    if (stock >= 0)
        val1 = num[index] - stock;

    val2 = getCount(num, stock, index + 1);
    val3 = getCount(num, num[index], index + 1);

    return std::max({val1, val2, val3});
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

    std::cout << getCount(num, -1, 0);
}
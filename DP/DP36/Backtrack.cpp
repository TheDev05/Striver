#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int buy, int index)
{
    if (index >= num.size())
        return 0;

    int val1 = 0, val2 = 0, val3 = 0;
    if (buy >= 0 && num[index] >= buy)
    {
        val1 = num[index] - buy;
    }

    val3 = getCount(num, num[index], index + 1);
    val2 = getCount(num, buy, index + 1);

    return std::max(val1 + val3, val2);
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
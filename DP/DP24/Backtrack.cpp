#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int k, int index)
{
    if (index >= num.size())
        return 0;

    int val1 = 0, val2 = 0;
    if (k - (index + 1) >= 0)
        val1 = num[index] + getCount(num, k - (index + 1), index);
    val2 = getCount(num, k, index + 1);

    return std::max(val1, val2);
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

    std::cout << getCount(num, n, 0);
}
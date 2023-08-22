#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int k, int index)
{
    if (index >= num.size())
        return (k == 0) ? 1 : 0;

    int val1 = 0, val2 = 0;
    if (k - num[index] >= 0)
        val1 = getCount(num, k - num[index], index);
    val2 = getCount(num, k, index + 1);

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

    std::cout << getCount(num, k, 0);
}
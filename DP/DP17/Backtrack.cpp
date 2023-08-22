#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int k, int index)
{
    if (index >= num.size())
    {
        if (k == 0)
            return 1;
        return 0;
    }

    int val1 = getCount(num, k - num[index], index + 1);
    int val2 = getCount(num, k, index + 1);

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
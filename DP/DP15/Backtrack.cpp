#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int sum, int total, int index)
{
    if (index >= num.size())
    {
        if (total - sum == sum)
            return true;
        return false;
    }

    bool val1 = getCount(num, sum + num[index], total, index + 1);
    bool val2 = getCount(num, sum, total, index + 1);

    if (val1 || val2)
        return true;

    return false;
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

    int total = accumulate(num.begin(), num.end(), 0);
    std::cout << getCount(num, 0, total, 0);
}
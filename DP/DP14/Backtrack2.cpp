#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int sum, int k, int index)
{
    if (index >= num.size())
    {
        if (sum == k)
            return true;
        return false;
    }

    sum += num[index];
    if (getCount(num, sum, k, index + 1))
        return true;
    sum -= num[index];
    if (getCount(num, sum, k, index + 1))
        return true;

    return false;
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

    std::cout << getCount(num, 0, k, 0);
}
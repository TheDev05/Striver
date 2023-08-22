#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int sum, int k, int index)
{
    for (int i = index; i < num.size(); i++)
    {
        if (sum + num[i] <= k)
            if (getCount(num, sum + num[i], k, i + 1))
                return true;
    }

    if (sum == k)
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
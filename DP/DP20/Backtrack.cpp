#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int k, int &min, int count, int index)
{
    if (index >= num.size())
    {
        if (k == 0)
            min = std::min(min, count);

        return 0;
    }

    if (k - num[index] >= 0)
    {
        getCount(num, k - num[index], min, count + 1, index);
    }

    getCount(num, k, min, count, index + 1);
    return 0;
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

    int min = INT_MAX;
    getCount(num, k, min, 0, 0);

    std::cout << min;
}
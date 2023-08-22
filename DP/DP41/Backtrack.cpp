#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int index)
{
    if (index >= num.size())
        return 0;

    int max = 0;
    for (int j = index + 1; j < num.size(); j++)
    {
        if (num[j] > num[index])
            max = std::max(max, getCount(num, j));
    }

    return 1 + max;
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

    int max = 0;
    for (int i = 0; i < num.size(); i++)
    {
        max = std::max(max, getCount(num, i));
    }

    std::cout << max;
}

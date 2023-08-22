#include <bits/stdc++.h>
using namespace std;

bool traverse(std::vector<std::vector<int>> &num, std::vector<int> &inox, int index)
{
    for (auto i : num[index])
    {
        if (inox[i] == -1)
        {
            inox[i] = (inox[index]) ? 0 : 1;
            if (traverse(num, inox, i))
                return true;
        }
        else if (inox[index] == inox[i])
            return true;
    }

    return false;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> num;
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        std::vector<int> temp(m);
        for (auto &j : temp)
            std::cin >> j;

        num.push_back(temp);
    }

    std::vector<int> inox(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (inox[i] == -1)
        {
            inox[i] = 0;
            if (traverse(num, inox, i))
                return false;
        }
    }

    return true;
}
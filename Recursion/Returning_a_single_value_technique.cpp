// Returning a single value technique

#include <bits/stdc++.h>
using namespace std;

bool getSum(std::vector<int> num, int sum, int index, int k)
{
    if (index >= num.size())
    {
        if (sum == k)
            return true;
        else
            return false;
    }

    sum += num[index];
    if (getSum(num, sum, index + 1, k))
        return true;

    sum -= num[index];
    if (getSum(num, sum, index + 1, k))
        return true;

    return false;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n);
    std::iota(num.begin(), num.end(), 1);

    std::cout << getSum(num, 0, 0, k);
}
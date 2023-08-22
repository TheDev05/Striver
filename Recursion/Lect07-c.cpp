#include <bits/stdc++.h>
using namespace std;

// Return after geeting a specific sum

bool sumThem(vector<int> num, int sum, int index)
{
    if (index >= num.size())
    {
        if (sum == 6)
        {
            return true;
        }
        else
            return false;
    }

    sum += num[index];
    if (sumThem(num, sum, index + 1))
    {
        return true;
    }

    sum -= num[index];
    if (sumThem(num, sum, index + 1))
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n), disk;
    iota(num.begin(), num.end(), 1);

    std::cout << sumThem(num, 0, 0);
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    int total = 0, sum = 0;
    for (auto i : num)
        total += i;

    if (k < -total || k > total)
        cout << 0;

    if ((total + k) % 2 == 0)
    {
        sum = (total + k) / 2;
    }
    else if ((total - k) % 2 == 0)
    {
        sum = (total - k) / 2;
    }
    else
        sum = 0;

    std::vector<int> prev(sum + 1, 0);
    prev[0] = 1;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = prev.size()-1; j >= 0; j--)
        {
            int val1 = 0, val2 = 0;
            if (j - num[i] >= 0)
                val1 = prev[j - num[i]];
            val2 = prev[j];

            prev[j] = val1 + val2;
        }
    }

    std::cout << prev[sum];
}
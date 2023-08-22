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

    int total = 0;
    for (auto i : num)
        total += i;

    std::vector<int> prev(total + 1, 0), curr(total + 1, 0);
    for (int i = 0; i < total + 1; i++)
    {
        if (i - (total - i) == k)
            prev[i] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < total + 1; j++)
        {
            int val1 = 0, val2 = 0;
            if (j + num[i] < total + 1)
                val1 = prev[j + num[i]];
            val2 = prev[j];

            curr[j] = val1 + val2;
        }

        prev = curr;
    }

    std::cout << curr[0];
}
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

    std::vector<int> prev(k + 1, 1e8), curr(k + 1, 1e8);
    prev[0] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < k + 1; j++)
        {
            int val1 = 1e8, val2 = 1e8;
            if (j - num[i] >= 0)
                val1 = 1 + curr[j - num[i]];
            val2 = prev[j];

            curr[j] = std::min(val1, val2);
        }

        prev = curr;
    }

    std::cout << curr[k];
}
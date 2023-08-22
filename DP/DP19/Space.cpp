#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> value[i];
    }

    std::vector<int> prev(k + 1, 0), curr(k + 1, 0);
    for (int i = 0; i < k + 1; i++)
    {
        prev[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < k + 1; j++)
        {
            int val1 = 0, val2 = 0;
            if (j - weight[i] >= 0)
                val1 = value[i] + prev[j - weight[i]];
            val2 = prev[j];

            curr[j] = std::max(val1, val2);
        }

        prev = curr;
    }

    std::cout << curr[k];
}
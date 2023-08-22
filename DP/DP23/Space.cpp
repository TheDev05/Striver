#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> p(n), w(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
    }

    std::vector<int> prev(k + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j - w[i] >= 0)
                val1 = p[i] + prev[j - w[i]];
            val2 = prev[j];

            prev[j] = std::max(val1, val2);
        }
    }

    std::cout << prev[k];
}
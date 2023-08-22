#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<int> prev(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j - (i + 1) >= 0)
                val1 = num[i] + prev[j - (i + 1)];
            val2 = prev[j];

            prev[j] = std::max(val1, val2);
        }
    }

    std::cout << prev[n];
}
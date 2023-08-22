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

    std::vector<int> prev(num.size() + 1, 0);
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size() - 1; j++)
        {
            int val1 = 0, val2 = 0;
            if (j == 0 || num[i] > num[j - 1])
                val1 = 1 + prev[i + 1];
            val2 = prev[j];

            prev[j] = std::max(val1, val2);
        }
    }

    std::cout << prev[0];
}
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

    std::vector<int> prev(2, 0), curr(2, 0);
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
            if (j)
            {
                val1 = prev[0] - num[i];
                val2 = prev[j];
            }
            else
            {
                val3 = num[i] + prev[1];
                val4 = prev[j];
            }

            curr[j] = std::max({val1, val2, val3, val4});
        }

        prev = curr;
    }

    std::cout << curr[1];
}
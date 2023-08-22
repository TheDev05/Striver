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

    std::vector<std::vector<int>> prev(2, std::vector<int>(k + 1, 0)), curr(2, std::vector<int>(k + 1, 0));
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int p = 0; p < k + 1; p++)
            {
                if (j)
                {
                    int val1 = 0, val2 = 0;
                    if (p > 0)
                        val1 = prev[0][p - 1] - num[i];
                    val2 = prev[j][p];

                    curr[j][p] = std::max(val1, val2);
                }
                else
                {
                    int val1 = 0, val2 = 0;
                    val1 = num[i] + prev[1][p];
                    val2 = prev[j][p];

                    curr[j][p] = std::max(val1, val2);
                }
            }
        }

        prev = curr;
    }

    std::cout << curr[1][k];
}
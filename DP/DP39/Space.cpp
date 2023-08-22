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

    std::vector<std::vector<int>> prev(2, std::vector<int>(2, 0)), curr(2, std::vector<int>(2, 0));
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (j)
                {
                    int val1 = 0, val2 = 0;
                    if (k)
                        val1 = prev[0][0] - num[i];
                    val2 = prev[j][1];

                    curr[j][k] = std::max(val1, val2);
                }
                else
                {
                    int val1 = 0, val2 = 0;
                    val1 = num[i] + prev[1][0];
                    val2 = prev[j][1];

                    curr[j][k] = std::max(val1, val2);
                }
            }
        }

        prev = curr;
    }

    std::cout << curr[1][1];
}
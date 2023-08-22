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

    std::vector<int> left(num.size(), 1), right(num.size() + 1, 1);
    for (int i = 0; i < num.size(); i++)
    {
        int max = 0;
        for (int j = i - 1; j > 0; j--)
        {
            if (num[j] <= num[i])
                max = std::max(max, left[j]);
        }

        left[i] = max + 1;
    }

    int result = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int max = 0;
        for (int j = i + 1; j < num.size(); j++)
        {
            if (num[j] < num[i])
                max = std::max(max, right[j]);
        }

        right[i] = 1 + max;
        result = std::max(result, (left[i] + right[i]) - 1);
    }

    std::cout << result;
}
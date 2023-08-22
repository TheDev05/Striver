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

    int min = num[0], max = 0;
    for (int i = 0; i < n; i++)
    {
        max = std::max(max, num[i] - min);
        min = std::min(min, num[i]);
    }

    std::cout << max;
}
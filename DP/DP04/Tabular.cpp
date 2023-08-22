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

    std::vector<int> store(n, -1);
    store[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int min = INT_MAX;
        for (int j = i + 1; j <= i + k && j < n; j++)
        {
            min = std::min(min, abs(num[i] - num[j]) + store[j]);
        }

        store[i] = min;
    }

    std::cout << store[0] << '\n';
}
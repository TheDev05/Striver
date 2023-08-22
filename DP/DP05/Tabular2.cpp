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

    std::vector<int> store(n, -1);
    store[n - 1] = num[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        int last2 = num[i];
        if (i + 2 < n)
            last2 += store[i + 2];

        store[i] = std::max(store[i + 1], last2);
    }

    std::cout << store[0];
}
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

    std::vector<int> store(n + 1, -1);
    store[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int val1 = store[i + 1] + abs(num[i] - num[i + 1]);
        int val2 = INT_MAX;

        if (i < n - 2)
            val2 =  store[i + 2] + abs(num[i] - num[i + 2]);

        store[i] = std::min(val1, val2);
    }

    std::cout << store[0] << '\n';
}
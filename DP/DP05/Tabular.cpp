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
        int max = 0;
        for (int j = i + 2; j < num.size(); j++)
        {
            max = std::max(max, store[j]);
        }

        store[i] = num[i] + max;
    }

    std::cout << std::max(store[0], store[1]);
}
#include <bits/stdc++.h>
using namespace std;

int fillStore(std::vector<int> &num, std::vector<int> &store, int k, int index)
{
    if (index >= num.size() - 1)
        return 0;

    if (store[index] == -1)
    {
        int min = INT_MAX;
        for (int i = index + 1; i <= index + k; i++)
        {
            if (i < num.size())
                min = std::min(min, fillStore(num, store, k, i) + abs(num[index] - num[i]));
        }

        store[index] = min;
    }

    return store[index];
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::vector<int> store(n + 1, -1);
    int local = fillStore(num, store, k, 0);

    std::cout << local << '\n';
}
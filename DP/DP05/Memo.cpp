#include <bits/stdc++.h>
using namespace std;

int fillStore(std::vector<int> &num, std::vector<int> &store, int index)
{
    if (index >= num.size())
        return 0;

    if (store[index] == -1)
    {
        int max = 0;
        for (int i = index + 2; i < num.size(); i++)
        {
            max = std::max(max, fillStore(num, store, i));
        }

        store[index] = num[index] + max;
    }

    return store[index];
}

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
    std::cout << std::max(fillStore(num, store, 0), fillStore(num, store, 1));
}
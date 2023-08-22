#include <bits/stdc++.h>
using namespace std;

int fillStore(std::vector<int> &num, std::vector<int> &store, int index)
{
    if (index >= num.size())
        return 0;

    if (store[index] == -1)
    {
        store[index] = std::max(fillStore(num, store, index + 2) + num[index], fillStore(num, store, index + 1));
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
    std::cout << fillStore(num, store, 0);
}
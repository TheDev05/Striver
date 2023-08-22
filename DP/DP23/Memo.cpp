#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &p, std::vector<int> &w, std::vector<std::vector<int>> &storage, int k, int index)
{
    if (index >= p.size())
        return 0;

    if (storage[index][k] == -1)
    {
        int val1 = 0, val2 = 0;
        if (k - w[index] >= 0)
            val1 = p[index] + getCount(p, w, storage, k - w[index], index);
        val2 = getCount(p, w, storage, k, index + 1);

        storage[index][k] = std::max(val1, val2);
    }

    return storage[index][k];
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> p(n), w(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
    }

    std::vector<std::vector<int>> storage(n, std::vector<int>(k + 1, -1));
    std::cout << getCount(p, w, storage, k, 0);
}
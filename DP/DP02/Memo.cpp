#include <bits/stdc++.h>
using namespace std;

long long getCount(int n, std::vector<long long> &storage)
{
    if (n == 0)
        return 1;

    if (storage[n] == -1)
    {
        long long val1 = 0, val2 = 0;

        if (n > 1)
            val1 = getCount(n - 2, storage);
        val2 = getCount(n - 1, storage);

        storage[n] = val1 + val2;
    }

    return storage[n];
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<long long> storage(n + 1, -1);
    std::cout << getCount(n, storage) << '\n';
}
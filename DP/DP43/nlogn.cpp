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

    std::vector<int> storage;
    for (int i = 0; i < num.size(); i++)
    {
        if (i == 0 || num[i] > storage.back())
            storage.push_back(num[i]);
        else
        {
            auto it = lower_bound(storage.begin(), storage.end(), num[i]);
            storage[it - storage.begin()] = num[i];
        }
    }

    std::cout << storage.size();
}
#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<int> &temp, std::vector<int> &storage, int index)
{
    if (index >= num.size())
    {
        if (temp.size() > storage.size())
            storage = temp;
        return 0;
    }

    bool ok = true;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] % num[index] != 0 && num[index] % temp[i] != 0)
            ok = false;
    }

    if (ok)
    {
        temp.push_back(num[index]);
        getCount(num, temp, storage, index + 1);
        temp.pop_back();
    }

    getCount(num, temp, storage, index + 1);
    return 0;
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

    std::vector<int> storage, temp;
    getCount(num, temp, storage, 0);

    for (auto i : storage)
        std::cout << i << " ";
}
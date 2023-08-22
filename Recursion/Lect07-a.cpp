#include <bits/stdc++.h>
using namespace std;

// Subset generation

void GenSubs(vector<int> num, vector<int> res, int index)
{
    if (index >= num.size())
    {
        for (auto i : res)
            std::cout << i << " ";

        std::cout << '\n';
        return;
    }

    res.push_back(num[index]);
    GenSubs(num, res, index + 1);

    res.pop_back();
    GenSubs(num, res, index + 1);
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n), container;
    iota(num.begin(), num.end(), 1);

    GenSubs(num, container, 0);
}
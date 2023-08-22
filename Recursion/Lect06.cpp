#include <bits/stdc++.h>
using namespace std;

void genSubs(vector<int> num, vector<int> res, int index)
{
    if (index >= num.size())
    {
        if (res.empty())
        {
            std::cout << "{}\n";
            return;
        }

        for (auto i : res)
            std::cout << i << " ";

        std::cout << '\n';
        return;
    }

    res.push_back(num[index]);
    genSubs(num, res, index + 1);

    res.pop_back();
    genSubs(num, res, index + 1);
}

int main()
{
    vector<int> num(3), container;
    iota(num.begin(), num.end(), 1);

    genSubs(num, container, 0);
}
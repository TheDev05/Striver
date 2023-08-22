/* Generating all subsets */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
void generate(vector<int> &temp, int index, vector<int> &num)
{
    if (index == num.size())
    {
        result.push_back(temp);
        return;
    }

    temp.push_back(num[index]);
    generate(temp, index + 1, num);
    temp.pop_back();

    generate(temp, index + 1, num);
}

int main()
{
    vector<int> num(3), temp;
    iota(num.begin(), num.end(), 1);

    generate(temp, 0, num);

    std::cout << "Size: "
              << " " << result.size() << '\n';
    for (auto j : result)
    {
        for (auto i : j)
            std::cout << i << " ";
        std::cout << '\n';
    }
}
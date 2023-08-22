/* Genearte all subsets */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
void get(vector<int> &temp, int index, vector<int> &num)
{
    if (index == num.size())
    {
        result.push_back(temp);
        return;
    }

    temp.push_back(num[index]);
    get(temp, index + 1, num);
    temp.pop_back();

    get(temp, index + 1, num);
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n), temp;
    iota(num.begin(), num.end(), 1);

    get(temp, 0, num);

    std::cout << "SIZE: " << result.size() << '\n';
    for (auto j : result)
    {
        for (auto i : j)
            std::cout << i << " ";
        std::cout << '\n';
    }
}
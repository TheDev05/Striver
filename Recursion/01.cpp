#include <bits/stdc++.h>
using namespace std;

// Generate subsets & store

void sub(vector<int> num, vector<int> temp, vector<vector<int>> *data, int index)
{
    if (index >= num.size())
    {
        data->push_back(temp);
        return;
    }

    temp.push_back(num[index]);
    sub(num, temp, data, index + 1);

    temp.pop_back();
    sub(num, temp, data, index + 1);
}

int main()
{
    vector<int> num = {1, 2, 3}, temp;
    vector<vector<int>> data;

    sub(num, temp, &data, 0);

    for (auto i : data)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}
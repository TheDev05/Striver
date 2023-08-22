#include <bits/stdc++.h>
using namespace std;

void getSum(vector<int> num, vector<int> *data, int sum, int index)
{
    if (index >= num.size())
    {
        data->push_back(sum);
        return;
    }

    // sum += num[index];
    // getSum(num, data, sum, index + 1);

    // sum -= num[index];
    // getSum(num, data, sum, index + 1);

    getSum(num, data, sum + num[index], index + 1);
    getSum(num, data, sum, index + 1);
}

int main()
{
    // Sum of all subsets in asxending order

    int n;
    std::cin >> n;

    vector<int> num(n), data;
    iota(num.begin(), num.end(), 1);

    getSum(num, &data, 0, 0);

    sort(data.begin(), data.end());
    for (auto i : data)
        std::cout << i << " ";
}
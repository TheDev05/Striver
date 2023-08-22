#include <bits/stdc++.h>
using namespace std;

// Sum of subsets

void sumSubs(vector<int> num, vector<int> disk, int index, int sum)
{
    if (index >= num.size())
    {
        for (auto i : disk)
            std::cout << i << " ";
        std::cout <<": "<< sum << '\n';

        return;
    }

    disk.push_back(num[index]);
    sum += num[index];

    sumSubs(num, disk, index + 1, sum);

    disk.pop_back();
    sum -= num[index];

    sumSubs(num, disk, index + 1, sum);
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n), disk;
    iota(num.begin(), num.end(), 1);

    sumSubs(num, disk, 0, 0);
}
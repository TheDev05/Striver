#include <bits/stdc++.h>
using namespace std;

// Count of SubSets

int countSubs(vector<int> num, vector<int> disk, int index)
{
    if (index >= num.size())
    {
        return (1);
    }

    disk.push_back(num[index]);
    int left = countSubs(num, disk, index + 1);

    disk.pop_back();
    int right = countSubs(num, disk, index + 1);

    return (left + right);
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n), disk;
    iota(num.begin(), num.end(), 1);

    std::cout << countSubs(num, disk, 0);
}
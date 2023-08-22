#include <bits/stdc++.h>
using namespace std;

int dodo(vector<int> num, int index, int maxi)
{
    if (index == num.size())
        return (1);

    maxi = std::max(maxi, num[index]);
    dodo(num, index + 1, maxi);

    std::cout << maxi << "\n";
    return (maxi);
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    int maxi = dodo(num, 0, 0);
    std::cout << maxi;

    return (0);
}
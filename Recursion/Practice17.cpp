/* Find maximum in array */
#include <bits/stdc++.h>
using namespace std;

int get(vector<int> num, int index, int large)
{
    if (index == num.size())
    {
        return (large);
    }

    large = std::max(num[index], large);
    return (get(num, index + 1, large));
}

int main()
{
    int n;
    std::cin >> n;

    vector<int> num(n);

    iota(num.begin(), num.end(), 5);
    reverse(num.begin(), num.end());

    for (auto i : num)
        std::cout << i << " ";

    std::cout << get(num, 0, INT_MIN);
    return (0);
}
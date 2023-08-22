/* Reverse an Array */

#include <bits/stdc++.h>
using namespace std;

int foo(int i, vector<int> &num)
{
    if (i >= num.size() / 2)
    {
        return (1);
    }

    swap(num[i], num[num.size() - 1 - i]);
    foo(i + 1, num);

    return (1);
}

int main()
{
    vector<int> num(5);
    for (int i = 0; i < 5; i++)
    {
        std::cin >> num[i];
    }

    int i = 0;
    foo(i, num);

    for (auto i : num)
        std::cout << i << " ";
}
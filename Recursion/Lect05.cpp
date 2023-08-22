#include <bits/stdc++.h>
using namespace std;

int getFib(int n)
{
    if (n == 1)
    {
        return (1);
    }

    if (n == 0)
    {
        return (0);
    }

    return (getFib(n - 1) + getFib(n - 2));
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << getFib(n);
}
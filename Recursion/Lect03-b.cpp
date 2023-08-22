#include <bits/stdc++.h>
using namespace std;

int getFact(int n)
{
    if (n == 0)
    {
        return (1);
    }

    return (n * getFact(n - 1));
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << getFact(n) << '\n';
}
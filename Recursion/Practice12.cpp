/* Digits Sum*/

#include <bits/stdc++.h>
using namespace std;

int get(int n)
{
    if (n <= 0)
    {
        return (0);
    }

    return ((n % 10) + get(n / 10));
}

int main()
{
    int n;
    std::cin >> n;

    // find: 234=(2+4+3)= ??

    std::cout << get(n) << '\n';
}
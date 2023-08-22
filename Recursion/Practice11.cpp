/* Sum of n numbers */

#include <bits/stdc++.h>
using namespace std;

int get(int n)
{
    if (n == 1)
    {
        return (1);
    }

    return (n + get(n - 1));
}

int main()
{

    int n;
    std::cin >> n;

    // find: 1+2+3....+n = ??

    std::cout << get(n) << '\n';
}
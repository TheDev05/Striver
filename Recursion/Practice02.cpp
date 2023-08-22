/* Sum of n numbers */

#include <bits/stdc++.h>

int sum = 0;
int foo(int n)
{
    if (n == 0)
    {
        return (0);
    }

    sum += n + foo(n - 1);
    return (0);
}

int main()
{
    int n = 5;
    foo(n);

    std::cout << sum << '\n';
}
/* Print 1 to n */

#include <bits/stdc++.h>

int count = 1;
int foo(int n)
{
    if (count == n + 1)
    {
        return (0);
    }

    std::cout << count << '\n';
    count++;

    foo(n);
    return (0);
}

int main()
{
    int n;
    std::cin >> n;

    foo(n);
}